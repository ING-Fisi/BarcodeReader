#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "barcodereaderserver.h"
#include "editdialog.h"
#include "waitingdialog.h"
#include <QProcess>
#include <QDateTime>
#include <QPixmap>
#include <QThread>
#include <QDir>
#include <QFileInfoList>
#include <QImage>
#include <QRegExp>
#include <QFile>
#include <QTextStream>
#include <QIcon>
#include <QMessageBox>
#include <QTimer>
#include <QRandomGenerator>


/*******************************************
 * QR Code di configurazione
 *******************************************/
#define CONFIGURATOR "ConfQrCode"
/*******************************************/

/*********************************************************************
 * Pseudo-QRCode di stato
 * MAC del reader da aprire
 *********************************************************************/
#define READER_STATUS "SYNC"
QString toOpenMAC;
int iStatusReader=0;
/*********************************************************************/

/***************************************************
 * Define per l'ok allo sblocco della serratura
 ***************************************************/
#define QRCODE_ENABLED "0xQRENABLED"
#define QRCODE_DISABLED "0xQRDISABLED"
/***************************************************/

/***************************************************************************************************************************
 * Files directories
 ***************************************************************************************************************************/
//QString fileshomedirectory = "/home/tinylap/";
//QString filesDirectory = fileshomedirectory + "BarcodeReaderFiles";
//QString associationsDirectory = filesDirectory+"/Associations"; //"/home/fisitron/BarcodeReaderFiles/Associations";
//QString logsDirectory = filesDirectory+"/Logs";                 //"/home/fisitron/BarcodeReaderFiles/Logs";
//QString qrCodesDirectory = filesDirectory+"/QRCodes";           //"/home/fisitron/BarcodeReaderFiles/QRCodes";
//QString readersDirectory = filesDirectory+"/Readers";           //"/home/fisitron/BarcodeReaderFiles/Readers";
//QString downloadFolderPath = fileshomedirectory + "Downloads";
//QString settingsDirectory = filesDirectory+"/Settings";
/***************************************************************************************************************************/

/*************************************************
 * Booleano per il check del login
 *************************************************/
bool loginChecked=false;
/*************************************************/


/*********************************************************************************************************************************************************/
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , addReaderTimer(new QTimer(this))
    , waitingTimer(new QTimer(this))
{
    ui->setupUi(this);
    setWindowTitle("QR CODE READER MANAGER");


    //***************************************************************//
    //    ui->tableWidget_qrcode_content->setColumnCount(3);
    //    ui->tableWidget_qrcode_content->setRowCount(1);

    //    DatePicker* picker1 = new DatePicker(this,DayType);
    //    picker1->setEditable(true);
    //    picker1->setTimeEditable(true);
    //    picker1->setTimePeriod(QTime(0, 0, 0), QTime(22, 59, 59));
    //    picker1->setTimeInputFormat("hh:mm:ss");

    //    DatePickerHumanReadableFormater *formater = new DatePickerHumanReadableFormater();
    //    // setup period delimeters in date string representation
    //    formater->setDateFromWord(QString::null);
    //    formater->setDateToWord("-");
    //    // disable showing words "today"/"yesterday"/"tomorrow" instead of date
    //    formater->setSpecialDayWordShown(true);
    //    // formater is used for date string representation in date picker label
    //    picker1->setFormater(formater);

    //    QLabel* QRCode_name = new QLabel("PN342334");
    //    QPushButton *stronzo = new QPushButton("STRONZO");

    //    ui->tableWidget_qrcode_content->setCellWidget(0,0,QRCode_name);
    //    ui->tableWidget_qrcode_content->setCellWidget(0,1,picker1);
    //    ui->tableWidget_qrcode_content->setCellWidget(0,2,stronzo);
    //*******************************************************************//



    //    Ajs5qdSg.png
    //    Fisitron_Backdrop.PNG
    //    Fisitron_biglietto_da_visita.PNG
    //    Fisitron_biglietto_da_visita_rev1.PNG
    //    Fisitron_Cofanetto.PNG
    //    Fisitron_Logo.PNG
    //    FISITRON_LOGO_2.png

    ui->page->setStyleSheet("QWidget#page {"
                            "border-image: url(/home/fisitron/BarcodeReaderFiles/Background/Fisitron_biglietto_da_visita.PNG) 0 0 0 0 stretch stretch;"
                            //"background-image:url(/home/fisitron/BarcodeReaderFiles/Background/Fisitron_biglietto_da_visita.PNG);"
                            //"background-repeat: no-repeat;"
                            //"background-position: center;"
                            "}");

    ui->page_2->setStyleSheet("QWidget#page_2 {"
                              "border-image: url(/home/fisitron/BarcodeReaderFiles/Background/Fisitron_biglietto_da_visita.PNG) 0 0 0 0 stretch stretch;"
                              //"background-image:url(/home/fisitron/BarcodeReaderFiles/Background/Fisitron_Cofanetto.PNG);"
                              //"background-repeat: no-repeat;"
                              //"background-position: center;"
                              "}");

    ui->label_8->setStyleSheet("QLabel{color: white; }");
    ui->label->setStyleSheet("QLabel{color: black; }");
    ui->l_Name->setStyleSheet("QLabel{color: black; }");
    ui->label_2->setStyleSheet("QLabel{color: black; }");
    ui->l_Surname->setStyleSheet("QLabel{color: black; }");
    ui->label_3->setStyleSheet("QLabel{color: black; }");
    ui->l_Email->setStyleSheet("QLabel{color: black; }");
    ui->label_6->setStyleSheet("QLabel{color: black; }");
    ui->l_StartDate->setStyleSheet("QLabel{color: black; }");
    ui->label_7->setStyleSheet("QLabel{color: black; }");
    ui->l_StartTime->setStyleSheet("QLabel{color: black; }");
    ui->label_4->setStyleSheet("QLabel{color: black; }");
    ui->l_ExpDate->setStyleSheet("QLabel{color: black; }");
    ui->label_5->setStyleSheet("QLabel{color: black; }");
    ui->l_ExpTime->setStyleSheet("QLabel{color: black; }");
    ui->l_QrCodeImage->setStyleSheet("QLabel{color: white; }");

    /***************************************************************
     * Setta opportunamente pB_FWD e pB_BWD
     ***************************************************************/
    int currentIndex=ui->stackedWidget->currentIndex();
    if(currentIndex==0){
        ui->pB_BWD->setEnabled(false);
    }else{
        ui->pB_FWD->setEnabled(false);
    }
    /***************************************************************/

    //*********************** Init lista QRCodeReader *****************************//
    QrcodeReader_list.clear();

    //QRCode QRCode_pluto;
    //QRCode_pluto.qrcode_param_instance.name = "pippo";

    //QRCodeReader QRCodeReader_pippo;
    //QRCodeReader_pippo.Qrcode_list.append(QRCode_pluto);
    /******************************************************************************/


    /******************************************************************************
     * Avvia il server http
     ******************************************************************************/
    //BarcodeReaderServer_Instance = new BarcodeReaderServer();
    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 8080);
    /******************************************************************************/

    /*************************************************************************
     * Controlla che le directories esistano e, in caso contrario, le crea
     *************************************************************************/
    checkDirectories();
    /*************************************************************************/

    /*********************************
     * Aggiorna la MainWindow
     *********************************/
    updateMainWindow();
    /*********************************/


    RefreshTimer=new QTimer(this);
    connect(RefreshTimer,&QTimer::timeout,this,&MainWindow::onRefreshTimerTimeout);
    RefreshTimer->start(100);


    /*****************************************************************************************************************
     * Apre la Waiting Dialog
     *****************************************************************************************************************/
    //openWaitingDialog();
    /*****************************************************************************************************************/


}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
MainWindow::~MainWindow()
{
    delete ui;
}
/*********************************************************************************************************************************************************/

void MainWindow::onRefreshTimerTimeout(){

    //QRCodeReader* qrcode_reader_catch = NULL;
    //QString readerToFind = "Unknown";
    foreach (QRCodeReader* var, QrcodeReader_list) {

        QColor color=QColor("white");

        if(var->warning_status != no_error)
        {
            color=QColor("red");
        }
        else
        {
            if(var->door_status == DOOR_OPEN)
            {
                color=QColor("green");
            }
            if(var->door_status == DOOR_CLOSE)
            {
                color=QColor("yellow");
            }
        }


        /********************************************************************************
         * Itera sugli item di listWidget_Readers_2 al fine di trovare readerToFind
         * per cambiare il colore di background
         ********************************************************************************/
        for(int i=0; i<ui->listWidget_Readers_2->count(); ++i){
            QListWidgetItem* item=ui->listWidget_Readers_2->item(i);
            if(item->text()==var->reader_id){
                item->setBackground(color);
                break;
            }
        }
    }
}

/*********************************************************************************************************************************************************/
/**************************************************************************
 * Funzione che richiama checkDirectory(QString directoryPath)
 **************************************************************************/
void MainWindow::checkDirectories()
{
    checkDirectory(filesDirectory);
    checkDirectory(associationsDirectory);
    checkDirectory(logsDirectory);
    checkDirectory(qrCodesDirectory);
    checkDirectory(readersDirectory);
    checkDirectory(readersDirectory);
    checkDirectory(settingsDirectory);
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/************************************************************************************
 * Funzione che controlla l'esistenza della directory contenuta in directoryPath
 * e, nel caso non esistesse, la crea
 ************************************************************************************/
void MainWindow::checkDirectory(QString directoryPath)
{
    QDir dir(directoryPath);
    if(!dir.exists()){
        qDebug()<<"Directory "+directoryPath+" does not exist, creating...";
        if(dir.mkpath(directoryPath)){
            qDebug()<<"Directory "+directoryPath+" successfully created";
        } else {
            qDebug()<<"Failed to create directory "+directoryPath;
        }
    } else {
        qDebug()<<"Directory "+directoryPath+" already exists";
    }
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/***************************************************************************************************
 * Apre la finestra di dialogo WaitingDialog per 60 secondi
 ***************************************************************************************************/
void MainWindow::openWaitingDialog(){
    connect(waitingTimer,&QTimer::timeout,this,&MainWindow::onWaitingFinished);
    waitingTimer->start(60*1000);
    waitDialog = new WaitingDialog(this);
    waitDialog->show();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*******************************************************************
 * Chiude la finestra di dialogo WaitingDialog
 *******************************************************************/
void MainWindow::onWaitingFinished(){
    waitDialog->close();
    waitingTimer->stop();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*******************************************************
 * Callback per l'aggiunta di un nuovo QR Code Reader
 *******************************************************/
void MainWindow::on_pB_addReader_clicked()
{
    //    loginDialog = new LoginDialog(this);
    //    connect(loginDialog, &LoginDialog::LoginValid, this, &MainWindow::onLoginValid);
    //    connect(loginDialog, &QDialog::finished, loginDialog, &QObject::deleteLater);
    //    loginDialog->exec(); //loginDialog->show();

    //    qDebug()<<"loginChecked: "<<loginChecked;

    //    if(loginChecked==true){
    //        openAddReaderDialog();
    //    }

    //    /********************************
    //     * resetta loginChecked
    //     ********************************/
    //    loginChecked=false;
    //    /********************************/

    openAddReaderDialog();

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/***************************************************************************************************
 * Quando viene clickato il pulsante pB_addReader si apre la finestra di dialogo addReaderDialog
 * che resta in attesa di ricevere il QR Code di configurazione entro 15 secondi
 ***************************************************************************************************/
void MainWindow::openAddReaderDialog(){
    ui->pB_addReader->setEnabled(false);
    connect(addReaderTimer,&QTimer::timeout,this,&MainWindow::onTimerTimeout);
    addReaderTimer->start(15*1000);
    qDebug()<<"openAddReaderDialog: addReaderTimer STARTED";
    addReaderDialog = new AddReader(this);
    addReaderDialog->show();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*******************************************************************
 * Chiude la finestra di dialogo addReaderDialog
 *******************************************************************/
void MainWindow::onTimerTimeout(){
    addReaderDialog->close();
    ui->pB_addReader->setEnabled(true);
    addReaderTimer->stop();
    qDebug()<<"onTimerTimeout: addReaderTimer STOPED";
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************
 * In questa funzione vengono richiamate le funzioni per
 * l'update delle due QWidgetList
 **************************************************************/
void MainWindow::updateMainWindow(){

    /************************************************************************
     * Aggiorna la lista dei reader
     ************************************************************************/
    updateReaderList(readersDirectory);
    /************************************************************************/

    /************************************************************************
     * Aggiorna la lista dei QR Codes generati
     ************************************************************************/
    updateQrCodeList(qrCodesDirectory);
    /************************************************************************/

}
/*********************************************************************************************************************************************************/


bool MainWindow::receive_sync_packet(QString receivedMacAddr)
{
    bool qrEnabledFlag = false;
    /***********************************************************************************************************************/
    QRCodeReader* qrcode_reader_catch = NULL;
    QString readerToFind = "Unknown";
    foreach (QRCodeReader* var, QrcodeReader_list) {

        if(var->reader_mac_address==receivedMacAddr){

            var->door_status = iStatusReader;

            var->warning_status = no_error;

            if(var->ControlTime->isActive()){
                qDebug()<<"ControlTime Active => STOP";
                var->ControlTime->stop();
            }
            //if(!var->ControlTime->isActive()){
            qDebug()<<"ControlTime Not Active => START";
            var->ControlTime->start(60*1000);
            //}

            qrcode_reader_catch = var;
            readerToFind = qrcode_reader_catch->reader_id;
            break;
        }
    }
    /*************************************************************************
     * DEBUG
     *************************************************************************/
    qDebug()<<"handleRequest: readerToFind:"<<readerToFind;
    /************************************************************************/
    /***************************************************************
     * Definisce il colore di background in base a iStatusReader
     * Se iStatusReader==0 la porta è aperta quindi setta il verde
     * Se iStatusReader==1 la porta è chiusa quindi setta il giallo
     ***************************************************************/
    //    QColor color=QColor("white");
    //    if(qrcode_reader_catch != NULL)
    //    {
    //        if(qrcode_reader_catch->door_status == DOOR_OPEN)
    //        {
    //            color=QColor("green");
    //        }
    //        if(qrcode_reader_catch->door_status == DOOR_CLOSE)
    //        {
    //            color=QColor("yellow");
    //        }
    //    }


    //    /********************************************************************************
    //     * Itera sugli item di listWidget_Readers_2 al fine di trovare readerToFind
    //     * per cambiare il colore di background
    //     ********************************************************************************/
    //    for(int i=0; i<ui->listWidget_Readers_2->count(); ++i){
    //        QListWidgetItem* item=ui->listWidget_Readers_2->item(i);
    //        if(item->text()==readerToFind){
    //            item->setBackground(color);
    //            break;
    //        }
    //    }

    //    /********************************************************************************/
    //    /***********************************************************************************
    //     * Se il MAC address coincide con toOpenMAC, mette a true qrEnabledFlag
    //     * per abilitare l'apertura da remoto e resetta toOpenMAC.
    //     * Altrimenti mette a false qrEnabledFlag
    //     ***********************************************************************************/
    if(receivedMacAddr==toOpenMAC){
        qrEnabledFlag=true;
        toOpenMAC="";
    }else{
        qrEnabledFlag=false;
    }

    return qrEnabledFlag;
    /***********************************************************************************/
}


/*********************************************************************************************************************************************************/
/**********************************************************************************************
 * Funzione che gestisce la richiesta asincrona da parte del QR Code Reader
 **********************************************************************************************/
void MainWindow::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{

    QByteArray body;
    Q_UNUSED(req);
    /***************************************
     * Converte in QString req->url()
     ***************************************/
    QUrl url = req->url();
    QString request = url.toString();
    qDebug()<<"request"<<request;
    /***************************************/

    /********************************************************
     * Toglie il '/' iniziale; si può fare anche con
     * request=request.remove('/'); ma toglie tutti gli '/'
     * oppure con request=request.remove(0,1);
    *********************************************************/
    request = request.mid(1);
    /********************************************************/

    /****************************************************************************************
     * Separa il QR Code dall'indirizzo MAC. Il carattere scelto per la separazione è "_"
     ****************************************************************************************/
    QString receivedQrCode;
    QString receivedMacAddr;
    QString receivedStatus;
    QStringList parts = request.split('_');
    if(parts.size()==2){
        receivedQrCode = parts.at(0);
        receivedMacAddr = parts.at(1);
        qDebug()<< "handleRequest: Received QRCode = "<<receivedQrCode;
        qDebug()<< "handleRequest: Received MAC Address = "<<receivedMacAddr;
    }
    else if(parts.size()==3){
        receivedQrCode = parts.at(0);
        receivedStatus = parts.at(1);
        iStatusReader = receivedStatus.toInt();
        receivedMacAddr = parts.at(2);
        qDebug()<< "handleRequest: Received QRCode = "<<receivedQrCode;
        qDebug()<< "handleRequest: Received Status = "<<iStatusReader;
        qDebug()<< "handleRequest: Received MAC Address = "<<receivedMacAddr;
    }
    else{
        qDebug()<< "handleRequest: Received DATA = "<<request;
        qDebug()<< "handleRequest: QR CODE NOT VALID";


        body = QRCODE_DISABLED;
        resp->setHeader("Content-Length", QString::number(body.size()));
        resp->writeHead(200);
        resp->end(body);

        return;
    }
    /****************************************************************************************/

    /********************************************************************************************
     * matchFlag: flag che indica se è stato trovato un match nell'associationsFile.txt
     * qrEnabledFlag: flag che indica se il QR Code letto è attivo o no
     * macAddr, readerID, qrCode: variabili di appoggio per MAC address, reader ID e  QR Code
     ********************************************************************************************/
    bool matchFlag=false;
    bool qrEnabledFlag=false;
    QString macAddr, readerID, qrCode;
    /********************************************************************************************/

    /********************************************************************************************************
     * Se siamo in modalità di configurazione
     ********************************************************************************************************/
    if(addReaderTimer->isActive())
    {
        bool MacChecked=false;
        if(receivedQrCode==CONFIGURATOR)
        {
            /*************************************************************
             * Verifica che il reader non sia stato già aggiunto andando
             * a controllare l'indirizzo mac ricevuto attraverso la
             * funzione checkMAC(receivedMacAddr)
             *************************************************************/
            MacChecked = checkMAC(receivedMacAddr);
            if(MacChecked==false){
                /*********************************************************
                 * Apre la finestra di errore per idicare che il
                 * reader che si sta tentando di aggiungere esiste già
                 *********************************************************/
                errorMessage2Dialog = new errormessage2(this);
                errorMessage2Dialog->show();
                /*********************************************************/
            }
            else{

                /**************************************************************************************
                 * Apre la finestra di configurazione del nuovo reader
                 **************************************************************************************/
                EditDialog *dialog=new EditDialog(receivedMacAddr, receivedQrCode, this);
                connect(dialog, &EditDialog::saveClicked, this, &MainWindow::onDialogSaveClicked);
                connect(dialog, &QDialog::finished, dialog, &QObject::deleteLater);
                dialog->show();
                /**************************************************************************************/

            }
            /***********************************************************/
        }
        else if(receivedQrCode==READER_STATUS){
            qrEnabledFlag = receive_sync_packet(receivedMacAddr);
        }
        else {
            /***********************************************
             * Apre la finestra di errore nel caso in cui
             * viene letto un QR Code diverso da quello di
             * configurazione
             ***********************************************/
            errorMessageDialog = new ErrorMessage(this);
            errorMessageDialog->show();
            /***********************************************/
        } // END OF if(receivedQrCode==CONFIGURATOR) + else

    } // END OF if(addReaderTimer->isActive())
    /*********************************************************************************************************
     * Se siamo in modalità di funzionamento normale (non di configurazione)
     *********************************************************************************************************/
    else
    {
        /***********************************************************************************
         * Se è arrivato il segnale di stato (SYNC)
         ***********************************************************************************/
        if(receivedQrCode==READER_STATUS)
        {
            qrEnabledFlag = receive_sync_packet(receivedMacAddr);
        }
        //END OF if(receivedQrCode==READER_STATUS)
        else{
            /**************************************************************************************************************
             * Legge il file associationsFile.txt e cerca il match
             **************************************************************************************************************/
            //QString associationsDirectory = "/home/fisitron/BarcodeReaderFiles/Associations";
            QString associationsFileName = associationsDirectory+"/"+"associationsFile.txt";

            QFile associationsFile(associationsFileName);
            if(associationsFile.open(QIODevice::ReadOnly | QIODevice::Text)){

                QTextStream in(&associationsFile);

                while( (!in.atEnd()) && (matchFlag==false) ){
                    QString line = in.readLine();
                    parseLine(line, macAddr, readerID, qrCode);
                    if( (macAddr==receivedMacAddr) && (qrCode==receivedQrCode) ){
                        matchFlag=true;
                    }
                }
                associationsFile.close();
                if(matchFlag==false){
                    qDebug()<<"handleRequest: NO MATCH FOUND";
                }
            }else{
                qWarning("handleRequest: Impossible to read associationsFile.txt");
                matchFlag=false; //return;
            }
            /**************************************************************************************************************/
        }// END OF if(receivedQrCode==READER_STATUS) + else

    } // END OF if(addReaderTimer->isActive()) + else

    /*****************************************************************************************************
     * Se è stato trovato un match nell'associationsFile.txt
     *****************************************************************************************************/
    if(matchFlag==true){
        qDebug()<<"handleRequest: MATCH FOUND";
        qDebug()<<"handleRequest: macAddr matched = "<<macAddr;
        qDebug()<<"handleRequest: readerID matched = "<<readerID;
        qDebug()<<"handleRequest: qrCode matched = "<<qrCode;
        /*************************************************************************************
         * Ricava le date di validità del QR Code e le confronta con la data corrente
         *************************************************************************************/
        int posStrD = qrCode.indexOf("!StrD!");
        int posStrT = qrCode.indexOf("!StrT!");
        int posExpD = qrCode.indexOf("!ExpD!");
        int posExpT = qrCode.indexOf("!ExpT!");
        if( (posStrD != -1) && (posStrT != -1) && (posExpD != -1) && (posExpT != -1) ){
            QString startingDate=qrCode.mid(posStrD+6, posStrT-(posStrD+6));
            QString startingTime=qrCode.mid(posStrT+6, posExpD-(posStrT+6));
            QString expiringDate=qrCode.mid(posExpD+6, posExpT-(posExpD+6));
            QString expiringTime=qrCode.mid(posExpT+6);

            qDebug()<<"handleRequest: Starting Date&Time = "<<startingDate<<""<<startingTime;
            qDebug()<<"handleRequest: Expiring Date&Time = "<<expiringDate<<""<<expiringTime;

            QDate startDate=QDate::fromString(startingDate,"dd/MM/yyyy");
            QTime startTime=QTime::fromString(startingTime,"hh:mm");
            QDateTime startDateTime(startDate,startTime);

            QDate expDate=QDate::fromString(expiringDate,"dd/MM/yyyy");
            QTime expTime=QTime::fromString(expiringTime,"hh:mm");
            QDateTime expDateTime(expDate,expTime);

            QDateTime currentDateTime = QDateTime::currentDateTime();

            if(currentDateTime>=startDateTime && currentDateTime<=expDateTime){
                qDebug()<<"handleRequest: QR CODE ENABLED";
                qrEnabledFlag=true;
            }else{
                qDebug()<<"handleRequest: QR CODE DISABLED";
                qrEnabledFlag=false;
            }

        } //END OF if( (posStrD != -1) && (posStrT != -1) && (posExpD != -1) && (posExpT != -1) )

        //legge il file qrInfo.txt


    } //END OF if(matchFlag==true)
    /*****************************************************************************************************/

    /*****************************************************************************************************
     * Se non è stato trovato un match nell'associationsFile.txt o se l'associationsFile.txt non esiste
     * ricava l'ID del reader a partire dal receivedMacAddr al fine di scrivere il file dei log
     *****************************************************************************************************/
    if(matchFlag==false){
        readerID = getReaderID(receivedMacAddr);
    }//END OF if(matchFlag==false)
    /*****************************************************************************************************/


    /************************************************************************************************
     * Risponde al QR Code Reader. Se il QR Code letto è abilitato allora body=QRCODE_ENABLED,
     * altrimenti body=QRCODE_DISABLED
     ************************************************************************************************/
    //QByteArray body;

    if(qrEnabledFlag==true){
        /******************************************************************
         * Lancia il messaggio per sbloccare la serratura
         ******************************************************************/
        body = QRCODE_ENABLED;
        /******************************************************************/

    }else{
        /******************************************************************
         * Lancia il messaggio per non sbloccare la serratura
         ******************************************************************/
        body = QRCODE_DISABLED;
        /******************************************************************/
    }

    resp->setHeader("Content-Length", QString::number(body.size()));
    resp->writeHead(200);
    resp->end(body);
    /************************************************************************************************/


    /************************************************************************************************
     * Aggiorna/crea il file dei log tenendo traccia della lettura effettuata dal
     * QR Code Reader e se il QR Code letto è abilitato oppure no.
     * Le pseudo-letture dovute al READER_STATUS vengono bypassate. Viene però salvato il log nel
     * caso in cui era stata prenotata l'apertura e questa avviene effettivamente.
     ************************************************************************************************/
    if(receivedQrCode!=READER_STATUS){
        updateLogFile("QRCodeRead", logsDirectory, receivedQrCode, receivedMacAddr, readerID);
    }

    if(qrEnabledFlag==true){
        updateLogFile("QRCodeEnabled", logsDirectory, receivedQrCode, receivedMacAddr, readerID);
    }else{
        if(receivedQrCode!=READER_STATUS){
            updateLogFile("QRCodeDisabled", logsDirectory, receivedQrCode, receivedMacAddr, readerID);
        }
    }

    /************************************************************************************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************************************
 * Funzione che controlla se il mac address relativo al QR Code Reader che si sta tentando di aggiungere
 * è già stato censito oppure no. Se il mac address esiste già restituisce false, altrimenti true
 *********************************************************************************************************/
bool MainWindow::checkMAC(QString receivedMacAddr){

    bool MacChecked=true;

    /**************************************************************************
     * Se la directory non esiste esce dalla funzione
     **************************************************************************/
    QDir dir(readersDirectory);
    if(!dir.exists()){
        qWarning()<<"checkMAC: Directory does not exist:"<<readersDirectory;
        MacChecked = false;
        return MacChecked;
    }
    /**************************************************************************/

    /**************************************************************************************
     * Ottiene la lista delle cartelle dei singoli reader
     **************************************************************************************/
    QStringList readerFolders = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    /**************************************************************************************/

    /*****************************************************************************************
     * Per ogni cartella contenuta nella directory dei Readers va a leggere il readerInfo.txt
     * al fine di ricavare il readerMAC. Se viene trovato un match significa che il QR Code
     * Reader è già stato censito quindi la funzione restituisce false
     *****************************************************************************************/
    QString readerMAC, readerID;
    for(const QString &readerFolder : readerFolders){

        QString readerFolderPath = dir.filePath(readerFolder);
        QDir readerFolderDir(readerFolderPath);
        QString readerInfoFileName = readerFolderDir.filePath("readerInfo.txt");
        QFile readerInfoFile(readerInfoFileName);

        if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&readerInfoFile);
            readerMAC = in.readLine();
            if(!in.atEnd()){
                readerID = in.readLine();
            }
            readerInfoFile.close();

            if(readerMAC==receivedMacAddr){
                MacChecked = false;
                return MacChecked;
            }

        }

    }
    /*****************************************************************************************/

    /**********************************************************************
     * Restituisce true nel caso in cui non sia stato trovato alcun match
     **********************************************************************/
    return MacChecked;
    /**********************************************************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************************************
 * Funzione che ricava il readerID a partire dall'indirizzo MAC letto dal QR Code Reader.
 * Se il lettore non è stato ancora censito (e quindi non esiste la cartella) restituisce Unknown
 *********************************************************************************************************/
QString MainWindow::getReaderID(QString receivedMacAddr){

    QString readerMAC, readerID;

    /********************************************************************************
     * Se la directory non esiste esce dalla funzione
     ********************************************************************************/
    QDir dir(readersDirectory);
    if(!dir.exists()){
        qWarning()<<"getReaderID: Directory does not exist:"<<readersDirectory;
        return "Unknown";
    }
    /********************************************************************************/

    /**************************************************************************************
     * Ottiene la lista delle cartelle dei signgoli reader
     **************************************************************************************/
    QStringList readerFolders = dir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    /**************************************************************************************/

    /**************************************************************************************
     * Scansiona le cartelle presenti alla ricerca del match rispetto al MAC Address.
     * Se viene trovato, restituisce il readerID
     **************************************************************************************/
    for(const QString &readerFolder : readerFolders){

        QString readerFolderPath = dir.filePath(readerFolder);
        QDir readerFolderDir(readerFolderPath);
        QString readerInfoFileName = readerFolderDir.filePath("readerInfo.txt");
        QFile readerInfoFile(readerInfoFileName);

        if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&readerInfoFile);
            readerMAC = in.readLine();
            if(!in.atEnd()){
                readerID = in.readLine();
            }
            readerInfoFile.close();

            if(readerMAC==receivedMacAddr){
                return readerID;
            }

        }

    }
    /*****************************************************************************************/

    return "Unknown";

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*************************************************************************************************************************
 * Funzione che effettua il parsing della riga letta dal file associationsFile.txt e ricava macAddr, readerID e qrCode.
 * Restituisce true se il parse va a buon fine, altrimenti restituisce false
 *************************************************************************************************************************/
bool MainWindow::parseLine(const QString &line, QString &macAddr, QString &readerID, QString &qrCode){

    //    QRegExp regex("(.*)-(.*)-!N!(.*)!SN!(.*)!EM!(.*)!StrD!(\\d{2}/\\d{2}/\\d{4})!StrT!(\\d{2}:\\d{2})!ExpD!(\\d{2}/\\d{2}/\\d{4})!ExpT!(\\d{2}:\\d{2})");
    QRegExp regex("(.*)-(.*)-(.*)");

    if(regex.indexIn(line) != -1){
        macAddr=regex.cap(1);
        readerID=regex.cap(2);
        qrCode=regex.cap(3);
        return true;
    }else{
        qDebug()<<"parseLine: Impossible to parse the line";
        return false;
    }

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************************************************************
 * Callback che:
 * 1) controlla se esiste già un reader con il readerID appena editato. Se sì apre un messaggio di warning, altrimenti prosegue
 * 2) richiama la funzione createReaderFile per creare il file readerInfo.txt
 * 3) aggiorna la lista dei reader (funzione updateReaderList)
 * 4) aggiorna il file dei log (funzione updateLogFile)
 ********************************************************************************************************************************/
void MainWindow::onDialogSaveClicked(const QString &strMAC, const QString &strQR, const QString &editedStr){
    qDebug()<<"onDialogSaveClicked: Ricevuti dalla dialog Add Reader:";
    qDebug()<<"onDialogSaveClicked: MAC ADDRESS = "<<strMAC;
    qDebug()<<"onDialogSaveClicked: QR CODE = "<<strQR;
    qDebug()<<"onDialogSaveClicked: READER ID = "<<editedStr;

    bool readerIDCheck = checkReaderID(editedStr);
    //qDebug()<<"readerIDCheck "<<readerIDCheck;
    if(readerIDCheck==false){
        qDebug()<<"Reader with ReaderID "<<editedStr<<" already exists";
        QMessageBox::warning(this, "Attenzione","ID Lettore "+editedStr+" già esistente.\n    Scegliere un altro ID."); //QMessageBox::warning(this, "Warning","ReaderID "+editedStr+" already exists.\n    Please choose another ID.");
    }
    else{
        /************************************************************************
         * Salva le informazioni ricevute in un file
         ************************************************************************/
        createReaderFile(strMAC, editedStr);
        /************************************************************************/

        /************************************************************************
         * Aggiorna la lista dei reader
         ************************************************************************/
        //QString readersDirectory = "/home/fisitron/BarcodeReaderFiles/Readers";
        updateReaderList(readersDirectory);
        /************************************************************************/

        /************************************************************************************
         * Aggiorna/crea il file dei log
         ************************************************************************************/
        updateLogFile("ReaderAdd", logsDirectory, "dummyQrCode", strMAC, editedStr);
        /************************************************************************************/

        /*****************************************************************************************************************
         * Apre la Waiting Dialog
         *****************************************************************************************************************/
        //openWaitingDialog();
        /*****************************************************************************************************************/

    }

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************
 * Funzione che controlla se esiste già un reader al quale è stato associato
 * il readerID appena scritto nella editDialog.
 * Il controllo viene effettuato sulla directory: se esiste già allora restituisce
 * false, altrimenti restituisce true
 *********************************************************************************/
bool MainWindow::checkReaderID(const QString editedStr)
{

    QString readerFolder = readersDirectory+"/"+editedStr;
    QDir dir;
    if(dir.exists(readerFolder)){
        return false;
    }
    else{
        return true;
    }

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/************************************************************************************************
 * Funzione che crea il file readerInfo.txt relativo al reader appena aggiunto
 ************************************************************************************************/
void MainWindow::createReaderFile(const QString &strMAC, const QString &editedStr){

    //QString readersDirectory = "/home/fisitron/BarcodeReaderFiles/Readers";
    QString readerFolder = readersDirectory+"/"+editedStr;
    QDir dir;
    if(!dir.exists(readerFolder)){
        if(!dir.mkpath(readerFolder)){
            qWarning("createReaderFile: Impossible to create folder");
            return;
        }
    }

    //QString fileName = readerFolder+"/"+strMAC+".txt";
    QString fileName = readerFolder+"/"+"readerInfo.txt";

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qWarning("createReaderFile: Impossible to open file for writing");
        return;
    }
    QTextStream out(&file);
    out<<strMAC<<"\n";
    out<<editedStr<<"\n";
    file.close();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************************************************************
 * Callback richiamata al click su pushB_NewQrCode. Apre l'interfaccia per la creazione del QR Code
 **************************************************************************************************************/
void MainWindow::on_pushB_NewQrCode_clicked()
{
    newQrCodeDialog = new NewQrCodeDialog(this);
    connect(newQrCodeDialog, &NewQrCodeDialog::QRCodeGenerated, this, &MainWindow::onQRCodeGenerated);
    connect(newQrCodeDialog, &QDialog::finished, newQrCodeDialog, &QObject::deleteLater);
    newQrCodeDialog->show();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************************************************
 * Funzione richiamata a seguito della generazione di un nuovoQR Code.
 * L'omonimia viene gestita inserendo un _ ed un numero progressivo
 ********************************************************************************************************************/
//void MainWindow::onQRCodeGenerated(const QString &Name, const QString &Surname, const QString &PhoneNumber,const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime)
void MainWindow::onQRCodeGenerated(const QString &Name, const QString &Surname, const QString &PhoneNumber, const QString &Email, const QString &QrType, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime,
                                   const QString &monday, const QString &StartingTimeMonday, const QString &ExpiringTimeMonday,
                                   const QString &tuesday, const QString &StartingTimeTuesday, const QString &ExpiringTimeTuesday,
                                   const QString &wednsday, const QString &StartingTimeWednsday, const QString &ExpiringTimeWednsday,
                                   const QString &thursday, const QString &StartingTimeThursday, const QString &ExpiringTimeThursday,
                                   const QString &friday, const QString &StartingTimeFriday, const QString &ExpiringTimeFriday,
                                   const QString &saturday, const QString &StartingTimeSaturday, const QString &ExpiringTimeSaturday,
                                   const QString &sunday, const QString &StartingTimeSunday, const QString &ExpiringTimeSunday)
{
    /**************************************************************
     * Variabile di appoggio per poter eventualmente
     * modificare il contenuto del QR Code nel caso di omonimia
     **************************************************************/
    QString mSurname = Surname;
    /**************************************************************/

    /****************************************************************************
     * Ottiene la data e l'ora corrente per usarle nel nome del file
     ****************************************************************************/
    QDateTime currentDateTime = QDateTime::currentDateTime();
    QString formattedDateTime = currentDateTime.toString("yyyyMMddhhmmss");
    /****************************************************************************/

    /****************************************************************************
     * Costruisce il nome ed il percorso al file .png
     ****************************************************************************/
    //QString qrCodesDirectory = "/home/fisitron/BarcodeReaderFiles/QRCodes";
    //QString imageName = formattedDateTime+".png";
    //QString imageName = Name+Surname+formattedDateTime+".png";
    QString imageName = Name+Surname+".png";
    //QString ExpDate=ExpiringDate.remove('/');
    //QString ExpTime=ExpiringTime.remove(':');
    //QString imageName = Name+Surname+ExpDate+ExpTime+".png";
    //qDebug()<<"Formatted ExpiringDate"<<ExpDate;
    //qDebug()<<"Formatted ExpiringTime"<<ExpTime;
    QString imagePath = QDir(qrCodesDirectory).filePath(imageName);
    /****************************************************************************/

    /**************************************************************
     * Se il file è già esistente modifica imagePath e mSurname
     * aggiungendo un underscore ed un numero incrementale
     **************************************************************/
    int index=0;
    QString strIndex;
    while(QFile::exists(imagePath)){
        imagePath = imagePath.remove(".png");
        QChar lastChar = imagePath.back();
        while(lastChar.isDigit()){
            imagePath.remove(lastChar);
            lastChar = imagePath.back();
        }
        if(lastChar=="_"){
            imagePath.remove(lastChar);
        }
        index++;
        strIndex=QString::number(index);
        imagePath = imagePath+"_"+strIndex+".png";
        mSurname = Surname+"_"+strIndex;
    }
    /**************************************************************/

    /********************************************************************************************************
     * Lancia il programma qrencode sul Raspberry per generare il QR Code
     ********************************************************************************************************/
    QString program = "qrencode";
    //QString program = "/home/tinylap/PROGETTI/BarcodeReader_SERVER/libqrencode/build/qrencode";
    QStringList arguments;

    const QString fixedPart = "fisiQR!";
    QString PartNumber = generateRandomString(25);
    QString qrCode = fixedPart+PartNumber;
    arguments << qrCode << "-o" << imagePath;

    //arguments << "!N!" + Name
    //             + "!SN!" + mSurname
    //             + "!EM!" + Email
    //             + "!StrD!" + StartingDate
    //             + "!StrT!" + StartingTime
    //             + "!ExpD!" + ExpiringDate
    //             + "!ExpT!" + ExpiringTime
    //          << "-o" << imagePath; //<< "-o" << formattedDateTime + ".png"; //<< "-o output.png";

    QProcess *myProcess = new QProcess(this);
    myProcess->start(program, arguments);
    myProcess->waitForFinished();
    myProcess->close();
    /********************************************************************************************************/

    /******************************************************************************************************************
     * Crea il file associato al QR Code generato sull'interfaccia
     ******************************************************************************************************************/
    //createQRInfoFile(Name, mSurname, PhoneNumber, Email, StartingDate, StartingTime, ExpiringDate, ExpiringTime);
    createQRInfoFile(Name, mSurname, PhoneNumber, Email, QrType, StartingDate, StartingTime, ExpiringDate, ExpiringTime,
                     monday, StartingTimeMonday, ExpiringTimeMonday,
                     tuesday, StartingTimeTuesday, ExpiringTimeTuesday,
                     wednsday, StartingTimeWednsday, ExpiringTimeWednsday,
                     thursday, StartingTimeThursday, ExpiringTimeThursday,
                     friday, StartingTimeFriday, ExpiringTimeFriday,
                     saturday, StartingTimeSaturday, ExpiringTimeSaturday,
                     sunday, StartingTimeSunday, ExpiringTimeSunday);
    /******************************************************************************************************************/



    /**************************************************************
     * Visualizza il QR Code generato sull'interfaccia
     **************************************************************/
    showQRcode(imagePath);
    /**************************************************************/

    /**************************************************************
     * Aggiorna la lista dei QR Codes generati
     **************************************************************/
    updateQrCodeList(qrCodesDirectory);
    /**************************************************************/

    /************************************************************************************
     * Aggiorna/crea il file dei log
     ************************************************************************************/
    //QString qrCode="!N!"+Name+"!SN!"+mSurname+"!EM!"+Email+"!StrD!"+StartingDate+"!StrT!"+StartingTime+"!ExpD!"+ExpiringDate+"!ExpT!"+ExpiringTime;
    updateLogFile("QRCodeGenerated", logsDirectory, qrCode, "dummyReaderMAC", "dummyReaderID");
    /************************************************************************************/

}
/*********************************************************************************************************************************************************/


/*********************************************************************************************************************************************************
 * Funzione per la generazione della parte random del QR Code
 *********************************************************************************************************************************************************/
QString MainWindow::generateRandomString(int length){
    const QString chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    QString randomString;
    for(int i=0; i<length; i++){
        int index = QRandomGenerator::global()->bounded(chars.length());
        randomString.append(chars.at(index));
    }
    return randomString;
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/************************************************************************************************
 * Funzione che crea il file qrInfo.txt relativo al QR Code appena generato
 ************************************************************************************************/
//void MainWindow::createQRInfoFile(const QString &Name, const QString &mSurname, const QString &PhoneNumber,const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime)
void MainWindow::createQRInfoFile(const QString &Name, const QString &mSurname, const QString &PhoneNumber, const QString &Email, const QString &QrType, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime,
                                  const QString &monday, const QString &StartingTimeMonday, const QString &ExpiringTimeMonday,
                                  const QString &tuesday, const QString &StartingTimeTuesday, const QString &ExpiringTimeTuesday,
                                  const QString &wednsday, const QString &StartingTimeWednsday, const QString &ExpiringTimeWednsday,
                                  const QString &thursday, const QString &StartingTimeThursday, const QString &ExpiringTimeThursday,
                                  const QString &friday, const QString &StartingTimeFriday, const QString &ExpiringTimeFriday,
                                  const QString &saturday, const QString &StartingTimeSaturday, const QString &ExpiringTimeSaturday,
                                  const QString &sunday, const QString &StartingTimeSunday, const QString &ExpiringTimeSunday)
{

    //QString readersDirectory = "/home/fisitron/BarcodeReaderFiles/Readers";
    QString qrFolder = qrCodesDirectory+"/"+Name+mSurname;
    QDir dir;
    if(!dir.exists(qrFolder)){
        if(!dir.mkpath(qrFolder)){
            qWarning("createReaderFile: Impossible to create folder");
            return;
        }
    }


    QString fileName = qrFolder+"/"+"qrInfo.txt";

    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Text)){
        qWarning("createReaderFile: Impossible to open file for writing");
        return;
    }
    QTextStream out(&file);
    out<<Name<<"\n";
    out<<mSurname<<"\n";
    out<<PhoneNumber<<"\n";
    out<<Email<<"\n";

    out<<QrType<<"\n";

    out<<StartingDate<<"\n";
    out<<StartingTime<<"\n";
    out<<ExpiringDate<<"\n";
    out<<ExpiringTime<<"\n";

    out<<monday<<"\n";
    out<<StartingTimeMonday<<"\n";
    out<<ExpiringTimeMonday<<"\n";
    out<<tuesday<<"\n";
    out<<StartingTimeTuesday<<"\n";
    out<<ExpiringTimeTuesday<<"\n";
    out<<wednsday<<"\n";
    out<<StartingTimeWednsday<<"\n";
    out<<ExpiringTimeWednsday<<"\n";
    out<<thursday<<"\n";
    out<<StartingTimeThursday<<"\n";
    out<<ExpiringTimeThursday<<"\n";
    out<<friday<<"\n";
    out<<StartingTimeFriday<<"\n";
    out<<ExpiringTimeFriday<<"\n";
    out<<saturday<<"\n";
    out<<StartingTimeSaturday<<"\n";
    out<<ExpiringTimeSaturday<<"\n";
    out<<sunday<<"\n";
    out<<StartingTimeSunday<<"\n";
    out<<ExpiringTimeSunday<<"\n";


    file.close();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/****************************************************************************
 * Funzione che consente la visualizzazione del QR Code sull'interfaccia
 ****************************************************************************/
void MainWindow::showQRcode(QString imagePath)
{
    /***********************************************************************************************************************
     * Visualizza sull'interfaccia il QR Code generato o quello selezionato
     ***********************************************************************************************************************/
    QPixmap qrImage(imagePath);
    if(qrImage.isNull()){
        ui->l_QrCodeImage->setText("QR Code Not Available");
        const char* NA = "Not Available";
        ui->l_Name->setText(NA);
        ui->l_Surname->setText(NA);
        ui->l_phoneNumber->setText(NA);
        ui->l_Email->setText(NA);
        ui->l_StartDate->setText(NA);
        ui->l_StartTime->setText(NA);
        ui->l_ExpDate->setText(NA);
        ui->l_ExpTime->setText(NA);
    }else{
        ui->l_QrCodeImage->setPixmap(qrImage);
        /********************************************************************************
         * Decodifica il QR Code lanciando il programma zbarimg sul Raspberry
         ********************************************************************************/
        //        QProcess *process = new QProcess(this);;
        //        process->start("zbarimg", QStringList() << "--quiet" <<"--raw" << imagePath);
        //        process->waitForFinished();
        //        QString decodedQR = process->readAllStandardOutput().trimmed();
        //        qDebug()<<"showQRcode: decodedQR = "<<decodedQR;
        //        process->close();
        //        /********************************************************************************/

        //        /***********************************************************************************************
        //         * Parsing di decodedQR per riempire i campi dell'interfaccia
        //         ***********************************************************************************************/
        //        QString name, surname, email, startDate, startTime, expDate, expTime;
        //        if( parseDecodedQR(decodedQR, name, surname, email, startDate, startTime, expDate, expTime) ){
        //            ui->l_Name->setText(name);
        //            ui->l_Surname->setText(surname);
        //            ui->l_Email->setText(email);
        //            ui->l_StartDate->setText(startDate);
        //            ui->l_StartTime->setText(startTime);
        //            ui->l_ExpDate->setText(expDate);
        //            ui->l_ExpTime->setText(expTime);
        //        }else{
        //            const char* NA = "Not Available";
        //            ui->l_Name->setText(NA);
        //            ui->l_Surname->setText(NA);
        //            ui->l_Email->setText(NA);
        //            ui->l_StartDate->setText(NA);
        //            ui->l_StartTime->setText(NA);
        //            ui->l_ExpDate->setText(NA);
        //            ui->l_ExpTime->setText(NA);
        //        }
        /***********************************************************************************************/


        /************************************************************************************************
         * legge il file qrInfo.txt relativo al QR Code selezionato
         * Questo codice è alternativo alla decodifica ed al parsing scritti sopra
         ************************************************************************************************/
        if(imagePath.contains("/Readers/")){
            int lastSlashIndex=imagePath.lastIndexOf('/');
            QString result=imagePath.mid(lastSlashIndex+1);
            imagePath=qrCodesDirectory+"/"+result;
        }

        QString qrFolderPath=imagePath;
        qrFolderPath.chop(4);

        QString Name, Surname, phoneNumber, Email, StartDate, StartTime, ExpDate, ExpTime;
        QString qrInfoFileName = qrFolderPath+"/qrInfo.txt";
        qDebug()<<"showQRcode(): qrInfoFileName = "<<qrInfoFileName;
        QFile qrInfoFile(qrInfoFileName);
        if(qrInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&qrInfoFile);

            //Name = in.readLine();
            //Surname = in.readLine();
            //phoneNumber = in.readLine();
            //Email = in.readLine();
            //StartDate = in.readLine();
            //StartTime = in.readLine();
            //ExpDate = in.readLine();
            //ExpTime = in.readLine();


            Name = in.readLine();
            Surname = in.readLine();
            phoneNumber = in.readLine();
            Email = in.readLine();
            QString qrType = in.readLine();
            StartDate = in.readLine();
            StartTime = in.readLine();
            ExpDate = in.readLine();
            ExpTime = in.readLine();

            QString sMondayChecked = in.readLine();
            QString sMondayStartingTime = in.readLine();
            QString sMondayExpiringTime = in.readLine();
            QString sTuesdayChecked = in.readLine();
            QString sTuesdayStartingTime = in.readLine();
            QString sTuesdayExpiringTime = in.readLine();
            QString sWednsdayChecked = in.readLine();
            QString sWednsdayStartingTime = in.readLine();
            QString sWednsdayExpiringTime = in.readLine();
            QString sThursdayChecked = in.readLine();
            QString sThursdayStartingTime = in.readLine();
            QString sThursdayExpiringTime = in.readLine();
            QString sFridayChecked = in.readLine();
            QString sFridayStartingTime = in.readLine();
            QString sFridayExpiringTime = in.readLine();
            QString sSaturdayChecked = in.readLine();
            QString sSaturdayStartingTime = in.readLine();
            QString sSaturdayExpiringTime = in.readLine();
            QString sSundayChecked = in.readLine();
            QString sSundayStartingTime = in.readLine();
            QString sSundayExpiringTime = in.readLine();


            qrInfoFile.close();

            ui->l_Name->setText(Name);
            ui->l_Surname->setText(Surname);
            ui->l_phoneNumber->setText(phoneNumber);
            ui->l_Email->setText(Email);
            //ui->l_StartDate->setText(StartDate);
            //ui->l_StartTime->setText(StartTime);
            //ui->l_ExpDate->setText(ExpDate);
            //ui->l_ExpTime->setText(ExpTime);

            if(qrType=="WithDeadline"){
                ui->l_StartDate->setText(StartDate);
                ui->l_StartTime->setText(StartTime);
                ui->l_ExpDate->setText(ExpDate);
                ui->l_ExpTime->setText(ExpTime);
            }
            if(qrType=="NoDeadline"){
                ui->l_StartDate->setText("Periodico");
                ui->l_StartTime->setText("No Deadline");
                ui->l_ExpDate->setText("Periodico");
                ui->l_ExpTime->setText("No Deadline");
            }



        }else{
            qWarning("showQRcode(): Impossible to read qrInfo.txt");

            const char* NA = "Not Available";
            ui->l_Name->setText(NA);
            ui->l_Surname->setText(NA);
            ui->l_phoneNumber->setText(NA);
            ui->l_Email->setText(NA);
            ui->l_StartDate->setText(NA);
            ui->l_StartTime->setText(NA);
            ui->l_ExpDate->setText(NA);
            ui->l_ExpTime->setText(NA);

            return;
        }
        /************************************************************************************************/


    }
    /***********************************************************************************************************************/
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************************************
 * Funzione che effettua l'aggiornamento della lista dei QR Code reader
 **************************************************************************************/
void MainWindow::updateReaderList(const QString &readersDirectory){

    /******************************************************************
     * Se la directory non esiste esce dalla funzione
     ******************************************************************/
    QDir dir(readersDirectory);
    if(!dir.exists()){
        qWarning()<<"updateReaderList: Directory does not exist:"<<readersDirectory;
        return;
    }
    /******************************************************************/

    /******************************************************************
     * Pulisce la lista esistente
     ******************************************************************/
    ui->listWidget_Readers->clear();
    ui->listWidget_Readers_2->clear();
    /******************************************************************/

    /*****************************************************************************************
     * Popola la listWidget_Readers
     *****************************************************************************************/
    dir.setFilter(QDir::Dirs | QDir::NoDotAndDotDot);
    QFileInfoList folderList = dir.entryInfoList();

    QIcon folderIcon = QIcon::fromTheme("folder");

    QrcodeReader_list.clear();

    for(const QFileInfo& fileInfo : folderList){
        QListWidgetItem* item = new QListWidgetItem(fileInfo.fileName()); //QListWidgetItem* item = new QListWidgetItem(folderIcon, fileInfo.fileName());
        item->setData(Qt::UserRole,fileInfo.filePath());
        item->setData(Qt::UserRole+1,"folder");
        ui->listWidget_Readers->addItem(item);


        //qDebug()<<item; //numero esadecimale
        //qDebug()<<item->data(Qt::UserRole); //percorso alla cartella del reader
        //qDebug()<<item->data(Qt::UserRole+1); //tipo ("folder")

        /**************************************************************************************************/
        QString readerFolderPath=item->data(Qt::UserRole).toString();

        /*********************************************************************************
         * Legge l'indirizzo MAC e l'ID del reader dal file readerInfo.txt
         *********************************************************************************/
        QString readerMAC, readerID;
        QString readerInfoFileName = readerFolderPath+"/readerInfo.txt";
        qDebug()<<"updateReaderList: readerInfoFileName = "<<readerInfoFileName;
        QFile readerInfoFile(readerInfoFileName);
        if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&readerInfoFile);
            readerMAC = in.readLine();
            if(!in.atEnd()){
                readerID = in.readLine();
                qDebug()<<"updateReaderList: readerID = "<<readerID;
            }
            readerInfoFile.close();
            qDebug()<<"updateReaderList: readerMAC = "<<readerMAC;
        }else{
            qWarning("updateReaderList: Impossible to read readerInfo.txt");
            return;
        }
        /*********************************************************************************/

        /************************************************************************
         * Aggiunge il nome del reader alla lista listWidget_Readers_2
         ************************************************************************/
        QListWidgetItem* item2 = new QListWidgetItem(readerID);
        //item2->setBackground(Qt::red);
        ui->listWidget_Readers_2->addItem(item2);
        /************************************************************************/


        QRCodeReader* QRCodeReader_i = new QRCodeReader();

        QRCodeReader_i->reader_id=readerID;
        QRCodeReader_i->reader_mac_address=readerMAC;

        qDebug()<<"updateReaderList: QRCodeReader_i.reader_id"<<QRCodeReader_i->reader_id;
        qDebug()<<"updateReaderList: QRCodeReader_i.reader_mac_address"<<QRCodeReader_i->reader_mac_address;

        QrcodeReader_list.append(QRCodeReader_i);

        /**************************************************************************************************/


    }
    /*****************************************************************************************/


    /***********************************************************************************************************************
     * DEBUG
     ***********************************************************************************************************************/
    qDebug()<<"updateReaderList: QrcodeReader_list"<<QrcodeReader_list;
    for(int it=0; it<QrcodeReader_list.size(); ++it){
        qDebug()<<"QrcodeReader_list.at("<<it<<"): "<<QrcodeReader_list.at(it);
        qDebug()<<"QrcodeReader_list.at("<<it<<")->reader_id: "<<QrcodeReader_list.at(it)->reader_id;
        qDebug()<<"QrcodeReader_list.at("<<it<<")->reader_mac_address: "<<QrcodeReader_list.at(it)->reader_mac_address;
        if(QrcodeReader_list.at(it)->ControlTime->isActive()){
            qDebug()<<"QrcodeReader_list.at("<<it<<")->ControlTime Active";
        }
    }
    /***********************************************************************************************************************/


}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************************************
 * Funzione che effettua l'aggiornamento della lista dei QR Code generati
 **************************************************************************************/
void MainWindow::updateQrCodeList(const QString &qrCodesDirectory){

    /**************************************************************************************
     * Se la directory non esiste esce dalla funzione
     **************************************************************************************/
    QDir dir(qrCodesDirectory);
    if(!dir.exists()){
        qWarning()<<"updateQrCodeList: Directory does not exist:"<<qrCodesDirectory;
        return;
    }
    /**************************************************************************************/

    /******************************************************************
     * Ottiene la lista dei file JPG nella directory
     ******************************************************************/
    QStringList filters;
    filters<<"*.png"; //filters<<"*.clnt"; //filters<<"*.png";
    QFileInfoList fileList = dir.entryInfoList(filters,QDir::Files);
    /******************************************************************/

    /******************************************************************
     * Pulisce la lista esistente su listWidget_QrCodes
     ******************************************************************/
    ui->listWidget_QrCodes->clear();
    /******************************************************************/

    /******************************************************************
     * Pulisce la lista QRCodeListTotal
     ******************************************************************/
    QRCodeListTotal.clear();
    /******************************************************************/

    /********************************************************************************************************
     * Aggiorna la listWidget_QrCodes e QRCodeListTotal
     ********************************************************************************************************/
    foreach(const QFileInfo &fileInfo, fileList){
        QListWidgetItem* item = new QListWidgetItem(fileInfo.fileName());
        item->setData(Qt::UserRole,fileInfo.filePath());
        qDebug()<<"updateQrCodeList: item = "<<item->data(Qt::UserRole).toString();
        ui->listWidget_QrCodes->addItem(item);


        /*************************************************************************************************
         * legge il file qrInfo.txt relativo all'i-esimo QR Code
         *************************************************************************************************/
        QString qrFolderPath=fileInfo.filePath();
        qrFolderPath.chop(4);
        QString qrInfoFileName = qrFolderPath+"/qrInfo.txt";
        qDebug()<<"showQRcode(): qrInfoFileName = "<<qrInfoFileName;
        QFile qrInfoFile(qrInfoFileName);
        if(qrInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){

            QTextStream in(&qrInfoFile);

            QRCode *QRcodeinstance = new QRCode(this);



            QRcodeinstance->name = in.readLine();
            QRcodeinstance->surname = in.readLine();
            QRcodeinstance->phonenumber = in.readLine();
            QRcodeinstance->email = in.readLine();

            QString qrType = in.readLine();
            QString sStartingDate = in.readLine();
            QString sStartingTime = in.readLine();
            QString sExpiringDate = in.readLine();
            QString sExpiringTime = in.readLine();

            QString sMondayChecked = in.readLine();
            QString sMondayStartingTime = in.readLine();
            QString sMondayExpiringTime = in.readLine();
            QString sTuesdayChecked = in.readLine();
            QString sTuesdayStartingTime = in.readLine();
            QString sTuesdayExpiringTime = in.readLine();
            QString sWednsdayChecked = in.readLine();
            QString sWednsdayStartingTime = in.readLine();
            QString sWednsdayExpiringTime = in.readLine();
            QString sThursdayChecked = in.readLine();
            QString sThursdayStartingTime = in.readLine();
            QString sThursdayExpiringTime = in.readLine();
            QString sFridayChecked = in.readLine();
            QString sFridayStartingTime = in.readLine();
            QString sFridayExpiringTime = in.readLine();
            QString sSaturdayChecked = in.readLine();
            QString sSaturdayStartingTime = in.readLine();
            QString sSaturdayExpiringTime = in.readLine();
            QString sSundayChecked = in.readLine();
            QString sSundayStartingTime = in.readLine();
            QString sSundayExpiringTime = in.readLine();

            DatePickerType type;
            if(qrType == "WithDeadline"){
                type=PeriodType;
            }
            if(qrType == "NoDeadline"){
                type=DaysType;
            }

            QRcodeinstance->qrcode_datepicker_instance = new DatePicker(this,QRcodeinstance->name + " " + QRcodeinstance->surname,type);

            //define  WD "WithDeadline"

            if(qrType == "WithDeadline"){
                QString sStartingDateTime=sStartingDate+" "+sStartingTime;
                QString sExpiringDateTime=sExpiringDate+" "+sExpiringTime;
                QString format = "dd/MM/yyyy hh:mm";
                QDateTime StartingDateTime=QDateTime::fromString(sStartingDateTime,format);
                QDateTime ExpiringDateTime=QDateTime::fromString(sExpiringDateTime,format);
                QRcodeinstance->qrcode_datepicker_instance->setDateTimePeriod(StartingDateTime,ExpiringDateTime);
            }

            if(qrType == "NoDeadline"){
                QString format = "hh:mm";
                if(sMondayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[0]=true;
                    QTime StartingTime=QTime::fromString(sMondayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sMondayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[0]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[1]=ExpiringTime;
                }
                if(sTuesdayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[1]=true;
                    QTime StartingTime=QTime::fromString(sTuesdayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sTuesdayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[2]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[3]=ExpiringTime;
                }
                if(sWednsdayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[2]=true;
                    QTime StartingTime=QTime::fromString(sWednsdayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sWednsdayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[4]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[5]=ExpiringTime;
                }
                if(sThursdayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[3]=true;
                    QTime StartingTime=QTime::fromString(sThursdayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sThursdayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[6]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[7]=ExpiringTime;
                }
                if(sFridayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[4]=true;
                    QTime StartingTime=QTime::fromString(sFridayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sFridayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[8]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[9]=ExpiringTime;
                }
                if(sSaturdayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[5]=true;
                    QTime StartingTime=QTime::fromString(sSaturdayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sSaturdayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[10]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[11]=ExpiringTime;
                }
                if(sSundayChecked=="YES"){
                    QRcodeinstance->qrcode_datepicker_instance->daysOfWeek[6]=true;
                    QTime StartingTime=QTime::fromString(sSundayStartingTime,format);
                    QTime ExpiringTime=QTime::fromString(sSundayExpiringTime,format);
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[12]=StartingTime;
                    QRcodeinstance->qrcode_datepicker_instance->daysRanges[13]=ExpiringTime;
                }


            }

            /****************************************************
             * Aggiorna QRCodeListTotal
             ****************************************************/
            QRCodeListTotal.append(QRcodeinstance);
            /****************************************************/

        }
        /*************************************************************************************************/
    }
    /********************************************************************************************************/


    /**************************************************************************************
     * Aggiorna tableWidget_qrcode_content
     **************************************************************************************/
    int numOfQRCode=QRCodeListTotal.length();
    int index=0;
    ui->tableWidget_qrcode_content->setColumnCount(2);
    ui->tableWidget_qrcode_content->setRowCount(numOfQRCode);

    foreach(QRCode* qrCode_i, QRCodeListTotal){

        QString qrCodeName=qrCode_i->name;
        QString qrCodeSurname=qrCode_i->surname;

        qDebug()<<qrCodeName;
        qDebug()<<qrCodeSurname;

        QLabel* QRCode_name = new QLabel(qrCodeName+qrCodeSurname);
        DatePicker* picker = qrCode_i->qrcode_datepicker_instance;
        picker->setEditable(true);
        picker->setTimeEditable(true);
        picker->setTimeInputFormat("hh:mm");

        //        DatePickerHumanReadableFormater *formater = new DatePickerHumanReadableFormater();
        //        // setup period delimeters in date string representation
        //        formater->setDateFromWord(QString()); //formater->setDateFromWord(QString::null);
        //        formater->setDateToWord("-");
        //        // disable showing words "today"/"yesterday"/"tomorrow" instead of date
        //        formater->setSpecialDayWordShown(true);
        //        // formater is used for date string representation in date picker label
        //        picker->setFormater(formater);


        QPushButton *pB_Button = new QPushButton("BUTTON");
        ui->tableWidget_qrcode_content->setCellWidget(index,0,picker);
        ui->tableWidget_qrcode_content->setCellWidget(index,1,pB_Button);

        index++;

    }
    /**************************************************************************************/


    ui->tableWidget_qrcode_content->setSizePolicy(
                QSizePolicy::Expanding, QSizePolicy::Preferred);
    ui->tableWidget_qrcode_content->setWordWrap(true);
    ui->tableWidget_qrcode_content->horizontalHeader()
            ->setSectionResizeMode(QHeaderView::Stretch );
    ui->tableWidget_qrcode_content->verticalHeader()
            ->setSectionResizeMode(QHeaderView::ResizeToContents);

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************************************
 * Funzione che effettua il parsing del QR Code per ricavare i dati
 **************************************************************************************/
bool MainWindow::parseDecodedQR(const QString &decodedQR, QString &name, QString &surname, QString &email, QString &startDate, QString &startTime, QString &expDate, QString &expTime){

    QRegExp regex("!N!(.*)!SN!(.*)!EM!(.*)!StrD!(\\d{2}/\\d{2}/\\d{4})!StrT!(\\d{2}:\\d{2})!ExpD!(\\d{2}/\\d{2}/\\d{4})!ExpT!(\\d{2}:\\d{2})");

    if(regex.indexIn(decodedQR) != -1){
        name=regex.cap(1);
        surname=regex.cap(2);
        email=regex.cap(3);
        startDate=regex.cap(4);
        startTime=regex.cap(5);
        expDate=regex.cap(6);
        expTime=regex.cap(7);
        return true;
    }else{
        qDebug()<<"parseDecodedQR: QR Code Content Not Valid";
        return false;
    }

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/****************************************************************************************************
 * Callback che effettua il download del QR Code visualizzato all'interno della cartella Download
 ****************************************************************************************************/
void MainWindow::on_pB_downloadQR_clicked()
{

    if(ui->l_Name->text()=="Not Available" || ui->l_Surname->text()=="Not Available"){
        QMessageBox::warning(this, "Attenzione","Selezionare un QR Code per il Download."); //QMessageBox::warning(this, "Warning","Please select a QR Code to Download.");
    } else {
        QString name=ui->l_Name->text();
        QString surname=ui->l_Surname->text();

        QString qrCodeFilePath=qrCodesDirectory+"/"+name+surname+".png";
        QFileInfo qrCodeFileInfo(qrCodeFilePath);
        QString destinationFilePath = downloadFolderPath+"/"+qrCodeFileInfo.fileName();
        if(QFile::copy(qrCodeFilePath,destinationFilePath)){
            qDebug()<<"File SuccessfullyDownloaded";
            QMessageBox::information(this, "Successo","File Scaricato Con Successo"); //QMessageBox::information(this, "Success","File Successfully Downloaded");
        }else{
            QMessageBox::warning(this, "Attenzione","          Download Non Avvenuto.\n"
                                                    ""+qrCodeFileInfo.fileName()+" potrebbe già essere presente\n nella cartella Download.\n"
                                                                                 "Verificare prego.");
            //QMessageBox::warning(this, "Warning","          Failed To Download The QR Code.\n"
            //                                     ""+qrCodeFileInfo.fileName()+" could already be present\n in the download folder.\n"
            //                                                                  "Please check it.");
        }
    }

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**********************************************************************************************
 * Callback richiamata al click su un elemento della listWidget_Readers
 **********************************************************************************************/
void MainWindow::on_listWidget_Readers_itemClicked(QListWidgetItem *item)
{

    QString itemType = item->data(Qt::UserRole+1).toString();
    if(itemType=="file"){
        QString itemPath = item->data(Qt::UserRole).toString();
        qDebug()<<"on_listWidget_Readers_itemClicked: File path = "<<itemPath;
        showQRcode(itemPath);
    }else if(itemType=="folder"){
        int row = ui->listWidget_Readers->row(item)+1;
        bool alreadyExpanded = false;
        if(row<ui->listWidget_Readers->count() && ui->listWidget_Readers->item(row)->data(Qt::UserRole+1).toString()=="file"){
            alreadyExpanded=true;
        }
        if(alreadyExpanded){
            collapseReaderFolder(item);
        }else{
            expandReaderFolder(item);
        }
    }

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************************
 * Funzione per l'espansione della cartella relativa al singolo reader
 ********************************************************************************************/
void MainWindow::expandReaderFolder(QListWidgetItem *folderItem)
{
    QString folderPath = folderItem->data(Qt::UserRole).toString();
    qDebug()<<"expandReaderFolder: folderPath = "<<folderPath;
    QDir dir(folderPath);

    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);

    dir.setNameFilters(QStringList()<<"*.png"); //dir.setNameFilters(QStringList()<<"**.clnt"); //dir.setNameFilters(QStringList()<<"*.png");
    QFileInfoList list = dir.entryInfoList();

    QIcon fileIcon = QIcon::fromTheme("image-jpg");

    int row = ui->listWidget_Readers->row(folderItem)+1;

    for(const QFileInfo& fileInfo : list){
        QListWidgetItem* item = new QListWidgetItem("      "+fileInfo.fileName()); //QListWidgetItem* item = new QListWidgetItem(fileIcon, "      "+fileInfo.fileName());
        item->setData(Qt::UserRole,fileInfo.filePath());
        item->setData(Qt::UserRole+1,"file");
        ui->listWidget_Readers->insertItem(row++,item);
    }
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************************
 * Funzione per il collapse della cartella relativa al singolo reader
 ********************************************************************************************/
void MainWindow::collapseReaderFolder(QListWidgetItem *folderItem)
{
    int row = ui->listWidget_Readers->row(folderItem)+1;
    while(row<ui->listWidget_Readers->count() && ui->listWidget_Readers->item(row)->data(Qt::UserRole+1).toString()=="file"){
        delete ui->listWidget_Readers->takeItem(row);
    }
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************************************
 * Callback richiamata al click su un elemento della lista dei QR Code generati
 **************************************************************************************/
void MainWindow::on_listWidget_QrCodes_itemClicked(QListWidgetItem *item)
{
    QString itemPath = item->data(Qt::UserRole).toString();
    qDebug()<<"on_listWidget_QrCodes_itemClicked: File path = "<<itemPath;
    showQRcode(itemPath);
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*****************************************************************************
 * Callback richiamata al click su pB_associate
 *****************************************************************************/
void MainWindow::on_pB_associate_clicked()
{
    /***********************************************************************************************
     * Verifica l'item selezionato in listWidget_QrCodes; se non è selezionato nessun item
     * lancia un messaggio di warning
     ***********************************************************************************************/
    QListWidgetItem *selectedQrCodeItem = ui->listWidget_QrCodes->currentItem();
    if(!selectedQrCodeItem){
        QMessageBox::warning(this, "Attenzione","Selezionare un QR Code dalla lista sulla destra."); //QMessageBox::warning(this, "Warning","Select a QR Code from the list on the right.");
        return;
    }
    /***********************************************************************************************/

    /***********************************************************************************************
     * Ricava il percorso al QR Code
     ***********************************************************************************************/
    QString qrCodeFilePath = selectedQrCodeItem->data(Qt::UserRole).toString();
    /***********************************************************************************************/

    /***********************************************************************************************
     * Verifica l'/gli item selezionato/i in listWidget_Readers; se non è selezionato nessun item
     * lancia un messaggio di warning
     ***********************************************************************************************/
    QList<QListWidgetItem*> selectedReaderItems = ui->listWidget_Readers->selectedItems();
    if(selectedReaderItems.isEmpty()){
        QMessageBox::warning(this,"Attenzione","Selezionare almeno un lettore dalla lista sulla sinistra."); //QMessageBox::warning(this,"Warning","Select at least one reader from the list on the left.");
        return;
    }
    /***********************************************************************************************/

    /***********************************************************************************************
     * Copia l'item selezionato in listWidget_QrCodes nella/e cartella/e di destinazione
     ***********************************************************************************************/
    bool success = true;
    for(QListWidgetItem *item : selectedReaderItems){
        if(item->data(Qt::UserRole+1).toString()=="folder"){
            QString readerFolderPath = item->data(Qt::UserRole).toString();
            QFileInfo qrCodeFileInfo(qrCodeFilePath);
            QString destinationFilePath = readerFolderPath+"/"+qrCodeFileInfo.fileName();
            if(QFile::copy(qrCodeFilePath,destinationFilePath)){
                /************************************************************************
                 * Aggiorna il file delle associazioni
                 ************************************************************************/
                updateAssociationsFile(readerFolderPath, destinationFilePath);
                /************************************************************************/
            }else{
                success = false;
            }
        }else{
            success = false;
        }
    }
    /***********************************************************************************************/

    /***************************************************************************************************************
     * Se la copia va a buon fine lancia un messaggio informativo, altimenti lancia un warning
     ***************************************************************************************************************/
    if(success){
        QMessageBox::information(this,"Successo","Associazione avvenuta con successo"); //QMessageBox::information(this,"Success","Association done");


        /***************************************************************************************
         * Aggiorna/crea il file dei log
         ***************************************************************************************/
        //        QDate currentDate=QDate::currentDate();
        //        QTime currentTime=QTime::currentTime();
        //        QString dateString=currentDate.toString("yyyyMMdd");
        //        QString timeString=currentTime.toString("hh:mm");
        //        QString logFileName=logsDirectory+"/"+dateString+".log";
        //        dateString=currentDate.toString("yyyy/MM/dd");
        //        QFile logFile(logFileName);
        //        if(logFile.open(QIODevice::Append | QIODevice::Text)){
        //            QTextStream out(&logFile);
        //            out<<dateString<<" @ "<<timeString
        //                <<" - "<<"New QRCode->Reader Association"<<"\n";
        //            logFile.close();
        //        }
        //        else{
        //            qWarning("on_pB_associate_clicked: Impossible to create/update the log file");
        //            return;
        //        }
        /***************************************************************************************/


    }else{
        QMessageBox::warning(this,"Errore","                              Associazione Fallita.\n"
                                           "Il QR Code che si sta tentando di associare potrebbe essere già associato.\n"
                                           "           Altrimenti assicurarsi di selezionare uno o più lettori.");
        //QMessageBox::warning(this,"Error","                              Association Failed.\n"
        //                                  "The QR Code you are trying to associate could already be associated.\n"
        //                                  "           Otherwise be sure to select one or more reader.");
    }
    /***************************************************************************************************************/
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*********************************************************************************************
 * Funzione che aggiorna il file delle associazioni
 *********************************************************************************************/
void MainWindow::updateAssociationsFile(QString readerFolderPath, QString imagePath)
{

    /*********************************************************************************
     * Legge l'indirizzo MAC e l'ID del reader dal file readerInfo.txt
     *********************************************************************************/
    QString readerMAC, readerID;
    QString readerInfoFileName = readerFolderPath+"/readerInfo.txt";
    qDebug()<<"updateAssociationsFile: readerInfoFileName = "<<readerInfoFileName;
    QFile readerInfoFile(readerInfoFileName);
    if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&readerInfoFile);
        readerMAC = in.readLine();
        if(!in.atEnd()){
            readerID = in.readLine();
            qDebug()<<"updateAssociationsFile: readerID = "<<readerID;
        }
        readerInfoFile.close();
        qDebug()<<"updateAssociationsFile: readerMAC = "<<readerMAC;
    }else{
        qWarning("updateAssociationsFile: Impossible to read readerInfo.txt");
        return;
    }
    /*********************************************************************************/

    /******************************************************************************************
     * Decodifica il QR Code lanciando il programma zbarimg sul Raspberry
     ******************************************************************************************/
    QProcess *process = new QProcess(this);;
    process->start("zbarimg", QStringList() << "--quiet" <<"--raw" << imagePath);
    process->waitForFinished();
    QString decodedQR = process->readAllStandardOutput().trimmed();
    process->close();

    QString name, surname, email, startDate, startTime, expDate, expTime;
    parseDecodedQR(decodedQR, name, surname, email, startDate, startTime, expDate, expTime);

    qDebug()<<"updateAssociationsFile: decodedQR = "<<decodedQR;
    /*******************************************************************************************/

    /******************************************************************************************
     * Crea/aggiorna il file delle associazioni (associationsFile.txt)
     ******************************************************************************************/
    //QString associationsDirectory = "/home/fisitron/BarcodeReaderFiles/Associations";

    QString associationsFileName = associationsDirectory+"/associationsFile.txt";
    QFile associationsFile(associationsFileName);
    if(associationsFile.open(QIODevice::Append | QIODevice::Text)){
        QTextStream out(&associationsFile);
        out<<readerMAC<<"-"<<readerID<<"-"<<decodedQR<<"\n";
        associationsFile.close();
    }else{
        qWarning("updateAssociationsFile: Impossible to update associationsFile.txt");
        return;
    }
    /******************************************************************************************/

    /******************************************************************************************
     * Aggiorna/crea il file dei log
     ******************************************************************************************/
    updateLogFile("Association", logsDirectory, decodedQR, readerMAC, readerID);
    /******************************************************************************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************
 * Callback richiamata al click su pB_disassociate
 ********************************************************************/
void MainWindow::on_pB_disassociate_clicked()
{
    //qDebug()<<"on_pB_disassociate_clicked: selectedReaderItems = "<<selectedReaderItems;

    /***********************************************************************************************
     * Verifica l'/gli item selezionato/i in listWidget_Readers; se non è selezionato nessun item
     * lancia un messaggio di warning
     ***********************************************************************************************/
    QList<QListWidgetItem*> selectedReaderItems = ui->listWidget_Readers->selectedItems();
    if(selectedReaderItems.isEmpty()){
        QMessageBox::warning(this,"Attenzione","Selezionare almeno un QR Code dalla lista sulla sinistra."); //QMessageBox::warning(this,"Warning","Select at least one QR Code from the list on the left.");
        return;
    }
    /***********************************************************************************************/

    /***************************************************************
     * success: flag che indica l'avvenuto dissociamento
     ***************************************************************/
    bool success=true;
    /***************************************************************/

    for(QListWidgetItem *item : selectedReaderItems){

        QString selectedItemPath = item->data(Qt::UserRole).toString();
        QString selectedItemType = item->data(Qt::UserRole+1).toString();

        if(selectedItemType=="file"){
            QFileInfo fileInfo(selectedItemPath);
            if( fileInfo.exists() && fileInfo.isFile() ){
                /************************************************************************
                 * Aggiorna il file delle associazioni eliminando l'associazione
                 ************************************************************************/
                bool assDeleted=deleteAssociationsFileLine(selectedItemPath);
                /************************************************************************/
                if(QFile::remove(fileInfo.absoluteFilePath())){
                    if(assDeleted){
                        delete item;
                        //qDebug()<<"on_pB_disassociate_clicked: Deleted file = "<<fileInfo.absoluteFilePath();
                    }else{
                        success=false;
                    }

                }else{
                    //qDebug()<<"on_pB_disassociate_clicked: Error during deletion of file "<<fileInfo.absoluteFilePath();
                    success=false;
                }
            }else{
                success=false;
            }
        }else{
            success=false;
        } //END OF if(selectedItemType=="file") + else

    } //END OF for(QListWidgetItem *item : selectedReaderItems)


    /***************************************************************************************************************
     * Se la cancellazione è andata a buon fine lancia un messaggio informativo, altimenti lancia un warning
     ***************************************************************************************************************/
    if(success){
        QMessageBox::information(this,"Successo","Disassociazione avvenuta con successo"); //QMessageBox::information(this,"Success","Disassociation done");


        /************************************************************************************
         * Aggiorna/crea il file dei log
         ************************************************************************************/
        //        QDate currentDate=QDate::currentDate();
        //        QTime currentTime=QTime::currentTime();
        //        QString dateString=currentDate.toString("yyyyMMdd");
        //        QString timeString=currentTime.toString("hh:mm");
        //        QString logFileName=logsDirectory+"/"+dateString+".log";
        //        dateString=currentDate.toString("yyyy/MM/dd");
        //        QFile logFile(logFileName);
        //        if(logFile.open(QIODevice::Append | QIODevice::Text)){
        //            QTextStream out(&logFile);
        //            out<<dateString<<" @ "<<timeString
        //                <<" - "<<"QRCode->Reader Disassociation"<<"\n";
        //            logFile.close();
        //        }
        //        else{
        //            qWarning("on_pB_disassociate_clicked: Impossible to create/update the log file");
        //            return;
        //        }
        /************************************************************************************/


    }else{
        QMessageBox::warning(this,"Errore","        Disassociazione Fallita.\n"
                                           "Assicurarsi di selezionare uno o più QR Code.");
        //QMessageBox::warning(this,"Error","        Disassociation Failed.\n"
        //                                  "Be sure to select one or more QR Codes.");
    }
    /***************************************************************************************************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*******************************************************************************************
 * Funzione per la cancellazione dell'associazione all'interno del file delle associazioni
 *******************************************************************************************/
bool MainWindow::deleteAssociationsFileLine(const QString selectedItemPath){

    QFileInfo fileInfo(selectedItemPath);
    QString readerFolderPath=fileInfo.absolutePath();

    /*********************************************************************************
     * Legge l'indirizzo MAC e l'ID del reader dal file readerInfo.txt
     *********************************************************************************/
    QString readerMAC, readerID;
    QString readerInfoFileName = readerFolderPath+"/readerInfo.txt";
    qDebug()<<"deleteAssociationsFileLine: readerInfoFileName = "<<readerInfoFileName;
    QFile readerInfoFile(readerInfoFileName);
    if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&readerInfoFile);
        readerMAC = in.readLine();
        if(!in.atEnd()){
            readerID = in.readLine();
            qDebug()<<"deleteAssociationsFileLine: readerID = "<<readerID;
        }
        readerInfoFile.close();
        qDebug()<<"deleteAssociationsFileLine: readerMAC = "<<readerMAC;
    }else{
        qWarning("deleteAssociationsFileLine: Impossible to read readerInfo.txt");
        return false;
    }
    /*********************************************************************************/

    /******************************************************************************************
     * Decodifica il QR Code lanciando il programma zbarimg sul Raspberry
     ******************************************************************************************/
    QProcess *process = new QProcess(this);
    process->start("zbarimg", QStringList() << "--quiet" <<"--raw" << selectedItemPath);
    process->waitForFinished();
    QString decodedQR = process->readAllStandardOutput().trimmed();
    process->close();

    QString name, surname, email, startDate, startTime, expDate, expTime;
    parseDecodedQR(decodedQR, name, surname, email, startDate, startTime, expDate, expTime);

    qDebug()<<"deleteAssociationsFileLine: decodedQR = "<<decodedQR;
    /*******************************************************************************************/


    /**************************************************************************************************************
     * Legge il file associationsFile.txt e cerca il/i match per l'eliminazione
     **************************************************************************************************************/
    //QString associationsDirectory = "/home/fisitron/BarcodeReaderFiles/Associations";
    QString associationsFileName = associationsDirectory+"/"+"associationsFile.txt";

    QStringList lines; // QStringList di appoggio

    QFile associationsFile(associationsFileName);
    if(associationsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&associationsFile);
        while(!in.atEnd()){
            lines.append(in.readLine());
        }
        associationsFile.close();
    }else{
        qWarning("deleteAssociationsFileLine: Impossible to read associationsFile.txt");
        return false;
    }

    for(int i=0; i<lines.size();){
        QString line = lines.at(i);
        QString storedMacAddr, storedReaderID, storedQrCode;
        parseLine(line, storedMacAddr, storedReaderID, storedQrCode);
        if( (storedMacAddr==readerMAC) && (storedReaderID==readerID) && (storedQrCode==decodedQR) ){
            qDebug()<<"deleteAssociationsFileLine: MATCH FOUND AT LINE "<<i;
            lines.removeAt(i);
            /**************************************************************************************
             * Aggiorna/crea il file dei log
             **************************************************************************************/
            updateLogFile("Disassociation", logsDirectory, decodedQR, readerMAC, readerID);
            /**************************************************************************************/
        }else{
            ++i;
        }
    }
    /**************************************************************************************************************/

    /***********************************************
     * Rimuove il vecchio file delle associazioni
     ***********************************************/
    QFile::remove(associationsFileName);
    /***********************************************/

    /******************************************************************************************
     * Aggiorna il file delle associazioni (associationsFile.txt) se lines.size()!=0
     ******************************************************************************************/
    if(lines.size()!=0){

        //for(const QString &line : lines){
        //    qDebug()<<"deleteAssociationsFileLine: line = "<<line;
        //}

        if(associationsFile.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&associationsFile);
            for(const QString &line : lines){
                out<<line<<"\n";
            }
            associationsFile.close();
        }else{
            qWarning("deleteAssociationsFileLine: Impossible to update associationsFile.txt");
            return false;
        }

    }else{
        qDebug()<<"deleteAssociationsFileLine: line.size())  "<<lines.size();
        qDebug()<<"deleteAssociationsFileLine: NO ASSOCIATIONS TO STORE";
    }
    /******************************************************************************************/

    return true;

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*************************************************************
 * Callback richiamata al click su pB_deleteQR
 *************************************************************/
void MainWindow::on_pB_deleteQR_clicked(){
    deleteQR();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************
 * Funzione per l'eliminazione permanente del QR Code selezionato
 ********************************************************************************/
void MainWindow::deleteQR()
{
    /***********************************************************************************************
     * Verifica l'item selezionato in listWidget_QrCodes; se non è selezionato nessun item
     * lancia un messaggio di warning
     ***********************************************************************************************/
    QListWidgetItem *selectedQrCodeItem = ui->listWidget_QrCodes->currentItem();
    if(!selectedQrCodeItem){
        QMessageBox::warning(this, "Attenzione","   Nessun QR Code selezionato per l'eliminazione permanente.\n"
                                                "Selezionare un QR Code dalla lista sulla destra.");
        //QMessageBox::warning(this, "Warning","   No QR Code selected for permanent deletion.\n"
        //                                     "Please select a QR Code from the list on the right.");
        return;
    }
    /***********************************************************************************************/

    /****************************************************************************************************************
     * Apre una finestra di dialogo per confermare la volontà di cancellare permanentemente il QR Code
     ****************************************************************************************************************/
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Confermare l'eliminazione",
                                  "Si sta tentando di cancellare permanentemente il QR Code.\n"
                                  "                 Premere YES per confermare.", QMessageBox::Yes | QMessageBox::No);
    //reply = QMessageBox::question(nullptr, "Confirm Deletion",
    //                              "You are trying to permanently delete the QR Code.\n"
    //                              "                 Press YES to proceed.", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::No){
        return;
    }
    /****************************************************************************************************************/

    /***********************************************************************************************
     * Ottiene il path del file selezionato ed il nome del file
     ***********************************************************************************************/
    QString selectedItemPath = selectedQrCodeItem->data(Qt::UserRole).toString();
    //qDebug()<<"deleteQR: selectedItemPath = "<<selectedItemPath;

    QFileInfo fileInfo(selectedItemPath);
    QString qrCodeFileName=fileInfo.fileName();
    //qDebug()<<"deleteQR: qrCodeFileName = "<<qrCodeFileName;
    /***********************************************************************************************/

    /******************************************************************************************
     * Decodifica il QR Code lanciando il programma zbarimg sul Raspberry
     ******************************************************************************************/
    QProcess *process = new QProcess(this);
    process->start("zbarimg", QStringList() << "--quiet" <<"--raw" << selectedItemPath);
    process->waitForFinished();
    QString decodedQR = process->readAllStandardOutput().trimmed();
    process->close();

    QString name, surname, email, startDate, startTime, expDate, expTime;
    parseDecodedQR(decodedQR, name, surname, email, startDate, startTime, expDate, expTime);

    //qDebug()<<"deleteQR: decodedQR = "<<decodedQR;
    /*******************************************************************************************/

    /*******************************************************************************************
     * Elimina il QR Code selezionato dalla cartella dei QRCodes
     *******************************************************************************************/
    QFile::remove(selectedItemPath);
    /*******************************************************************************************/

    /*******************************************************************************************
     * Elimina la cartella associata al QR Code selezionato
     *******************************************************************************************/
    QString selectedItemFolderPath = selectedItemPath;
    selectedItemFolderPath.chop(4);
    QDir dir(selectedItemFolderPath);
    if(dir.exists()){
        dir.removeRecursively();
    }
    /*******************************************************************************************/

    /**************************************************************************************************************
     * Legge il file associationsFile.txt e cerca il/i match per l'eventuale
     * eliminazione dalle sottocartelle della cartella Readers
     **************************************************************************************************************/
    //QString associationsDirectory = "/home/fisitron/BarcodeReaderFiles/Associations";
    QString associationsFileName = associationsDirectory+"/"+"associationsFile.txt";

    /*******************************
      * QStringList di appoggio
      *******************************/
    QStringList lines, readerIDs;
    /*******************************/

    /**********************************************************************
     * Lettura del file delle associazioni
     **********************************************************************/
    QFile associationsFile(associationsFileName);
    if(associationsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&associationsFile);
        while(!in.atEnd()){
            lines.append(in.readLine());
        }
        associationsFile.close();
    }
    //    else{
    //        qWarning("deleteQR: Impossible to read associationsFile.txt");
    //    }
    /**********************************************************************/

    /****************************************
     * RIGHE DI DEBUG
     ****************************************/
    qDebug()<<"deleteQR: lines lette da associationsFile.txt:";
    for(int i=0; i<lines.size(); i++){
        qDebug()<<"deleteQR: line = "<<lines.at(i);
    }
    /****************************************/

    /******************************************************************
     * Eventuale rimozione da QStringList lines
     * (iterazione inversa per evitare problemi di indice)
     ******************************************************************/
    for(int i=lines.size()-1; i>=0; --i){
        QString line=lines.at(i);
        QString storedMacAddr, storedReaderID, storedQrCode;
        parseLine(line, storedMacAddr, storedReaderID, storedQrCode);
        if( (storedQrCode==decodedQR) ){
            qDebug()<<"deleteQR: MATCH FOUND AT LINE "<<i;
            readerIDs.append(storedReaderID);
            /********************************************
             * Rimuove l'associazione se trova il match
             ********************************************/
            lines.removeAt(i);
            /********************************************/
        }
    }
    /******************************************************************/


    /***************************************************************
     * RIGHE DI DEBUG
     ***************************************************************/
    if(readerIDs.isEmpty()){
        qDebug()<<"deleteQR: NO MATCH FOUND";
    }

    //qDebug()<<"storedReaderID list: "<<readerIDs;
    //qDebug()<<"storedReaderID list size: "<<readerIDs.size();

    qDebug()<<"deleteQR: Updated lines:";
    for(int i=0; i<lines.size(); i++){
        qDebug()<<"deleteQR: line = "<<lines.at(i);
    }
    /***************************************************************/


    /**************************************************************************
     * Aggiorna il file delle associazioni
     **************************************************************************/
    QFile::remove(associationsFileName);
    if(associationsFile.open(QIODevice::Append | QIODevice::Text)){
        QTextStream out(&associationsFile);
        for(const QString &line : lines){
            out<<line<<"\n";
        }
        associationsFile.close();
    }else{
        qWarning("deleteQR: Impossible to update associationsFile.txt");
        return;
    }
    /**************************************************************************/


    /*******************************************************************************************
     * Eliminazione dalle sottocartelle della cartella Readers
     *******************************************************************************************/
    //QString readersDirectory = "/home/fisitron/BarcodeReaderFiles/Readers";
    for(int i=0; i<readerIDs.size(); i++){
        QString toDeletePath=readersDirectory+"/"+readerIDs.at(i)+"/"+qrCodeFileName;
        qDebug()<<"deleteQR: toDeletePath = "<<toDeletePath;
        QFile::remove(toDeletePath);
    }
    /*******************************************************************************************/

    /*****************************************
     * Aggiorna le liste sull'interfaccia
     *****************************************/
    updateMainWindow();
    /*****************************************/

    /*****************************************
     * Aggiorna l'immagine sull'interfaccia.
     * selectedItemPath non esiste, quindi
     * non mostra nulla
     *****************************************/
    showQRcode(selectedItemPath);
    /*****************************************/


    /************************************************************************************
     * Aggiorna/crea il file dei log
     ************************************************************************************/
    updateLogFile("QRCodeDeletion", logsDirectory,decodedQR, "dummyReaderMAC", "dummyReaderID");
    /************************************************************************************/


    /**************************************************************************************************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/*************************************************************************************************************************************
 * Funzione per l'aggiornamento del file dei log
 *************************************************************************************************************************************/
void MainWindow::updateLogFile(QString EventType, QString logsDirectory, QString decodedQR, QString readerMAC, QString readerID)
{
    //    QString mEventType, mDecodedQR, mReaderMAC, mReaderID;
    //    mEventType=EventType;
    //    mDecodedQR=decodedQR;
    //    mReaderMAC=readerMAC;
    //    mReaderID=readerID;

    QDate currentDate=QDate::currentDate();
    QTime currentTime=QTime::currentTime();
    QString dateString=currentDate.toString("yyyyMMdd");
    QString timeString=currentTime.toString("hh:mm");
    QString logFileName=logsDirectory+"/"+dateString+".log";
    dateString=currentDate.toString("yyyy/MM/dd");

    QString logOutput;

    if(EventType=="ReaderAdd"){
        //Ex: "2024/07/22 @ 16:20 - New Reader Added With MAC Address: 08b61fefa8b4 - ReaderID: Stanza#3"
        logOutput = dateString+" @ "+timeString+" - New Reader Added With MAC Address: "+readerMAC+" - ReaderID: "+readerID+"\n";
    }
    else if(EventType=="QRCodeGenerated"){
        //Ex: "2024/07/22 @ 16:30 - QR Code Generated: !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36"
        logOutput = dateString+" @ "+timeString+" - QR Code Generated: "+decodedQR+"\n";
    }
    else if(EventType=="QRCodeRead"){
        //Ex: "2024/07/22 @ 16:30 - QR Code !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36 Read From Stanza#1 (08b61fefa8b4)"
        logOutput = dateString+" @ "+timeString+" - QR Code "+decodedQR+" Read From "+readerID+"("+readerMAC+")"+"\n";
    }
    else if(EventType=="QRCodeEnabled"){
        //Ex: "2024/07/22 @ 16:30 - QR Code !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36 Read From Stanza#1 (08b61fefa8b4)"
        logOutput = dateString+" @ "+timeString+" - QR Code "+decodedQR+" Enabled - "+readerID+"("+readerMAC+")"+" Opened\n";
    }
    else if(EventType=="QRCodeDisabled"){
        //Ex: "2024/07/22 @ 16:30 - QR Code !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36 Read From Stanza#1 (08b61fefa8b4)"
        logOutput = dateString+" @ "+timeString+" - QR Code "+decodedQR+" Disabled - "+readerID+"("+readerMAC+")"+" Not Opened\n";
    }
    else if(EventType=="Association"){
        //Ex: "2024/07/22 @ 16:30 - QR Code !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36 Associated With Stanza#1 (08b61fefa8b4)"
        logOutput = dateString+" @ "+timeString+" - QR Code "+decodedQR+" Associated With "+readerID+"("+readerMAC+")"+"\n";
    }
    else if(EventType=="Disassociation"){
        //Ex: "2024/07/22 @ 16:30 - QR Code !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36 Disassociated From Stanza#1 (08b61fefa8b4)"
        logOutput = dateString+" @ "+timeString+" - QR Code "+decodedQR+" Disassociated From "+readerID+"("+readerMAC+")"+"\n";
    }
    else if(EventType=="QRCodeDeletion"){
        //Ex: "2024/07/22 @ 16:30 - QR Code Deleted: !N!Gigi!SN!LaTrottola!EM!gg@latrottola.com!StrD!22/07/2024!StrT!09:36!ExpD!22/08/2024!ExpT!10:36"
        logOutput = dateString+" @ "+timeString+" - QR Code Deleted: "+decodedQR+"\n";
    }
    else if(EventType=="ReaderDeletion"){
        //Ex: "2024/07/22 @ 16:30 - Deletion of Reader With ReaderID: Stanza#1"
        logOutput = dateString+" @ "+timeString+" - Deletion of Reader With ReaderID: "+readerID+"\n";
    }
    else if(EventType=="RemoteOpen"){
        //Ex: "2024/07/22 @ 16:30 - Remote Open Booked for Stanza#1 (08b61fefa8b4)"
        logOutput = dateString+" @ "+timeString+" - Remote Open Booked for "+readerID+"("+readerMAC+")"+"\n";
    }
    else {
        qDebug()<<"EventType "<<EventType<<" not matched";
    }



    QFile logFile(logFileName);
    if(logFile.open(QIODevice::Append | QIODevice::Text)){
        QTextStream out(&logFile);
        out<<logOutput;
        logFile.close();
    }
    else{
        qWarning("updateLogFile: Impossible to create/update the log file");
        return;
    }


}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************
 * Callback richiamata al click su pB_deleteReader
 ********************************************************************/
void MainWindow::on_pB_deleteReader_clicked()
{
    deleteReader();
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**************************************************************************
 * Funzione per l'eliminazione definitiva del reader selezionato
 **************************************************************************/
void MainWindow::deleteReader()
{
    /*************************************************************************************************************
     * Verifica gli item selezionati in listWidget_Readers; se non è selezionato nessun Reader
     * lancia un messaggio di warning. Se sono selezionati sia Readers che QR Codes, crea la
     * QList<QListWidgetItem*> dei soli Reader da eliminare (toDeleteReaders)
     *************************************************************************************************************/
    QList<QListWidgetItem*> selectedReaderItems = ui->listWidget_Readers->selectedItems();
    QList<QListWidgetItem*> toDeleteReaders;
    bool checkRightSelection=false;
    for(QListWidgetItem *item : selectedReaderItems){
        QString selectedItemType = item->data(Qt::UserRole+1).toString();
        if(selectedItemType=="folder"){
            checkRightSelection=true;
            toDeleteReaders.append(item);
        }
    }

    /*******************************************************************************
     * DEBUG
     *******************************************************************************/
    for(QListWidgetItem *item : toDeleteReaders){
        qDebug()<<"toDeleteReaders: "<<item->data(Qt::UserRole).toString();
    }
    /*******************************************************************************/

    if(selectedReaderItems.isEmpty() || checkRightSelection==false){
        QMessageBox::warning(this, "Attenzione","       Nessun lettore selezionato per l'eliminazione permanente.\n"
                                                "Selezionare almeno un lettore dalla lista sulla sinistra.");
        //QMessageBox::warning(this, "Warning","       No Readers selected for permanent deletion.\n"
        //                                     "Please select at least one Reader from the list on the left.");
        return;
    }
    /*************************************************************************************************************/

    /****************************************************************************************************************
     * Apre una finestra di dialogo per confermare la volontà di cancellare permanentemente il/i Reader(s)
     ****************************************************************************************************************/
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(nullptr, "Conferma Eliminazione",
                                  "Si sta tentando di eliminare permanentemente il/i lettore/i selezionato/i.\n"
                                  "                 Premere YES per confermare.", QMessageBox::Yes | QMessageBox::No);
    //reply = QMessageBox::question(nullptr, "Confirm Deletion",
    //                              "You are trying to permanently delete the selected Readers.\n"
    //                              "                 Press YES to proceed.", QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::No){
        return;
    }
    /****************************************************************************************************************/

    /*****************************************************************************************************************
     * Apre la Waiting Dialog
     *****************************************************************************************************************/
    //openWaitingDialog();
    /*****************************************************************************************************************/

    /*****************************************************************************************************************
     * Legge il file delle associazioni e mette il contenuto nella QStringList lines
     *****************************************************************************************************************/
    QString associationsFileName = associationsDirectory+"/"+"associationsFile.txt";
    QStringList lines; // QStringList di appoggio
    QFile associationsFile(associationsFileName);
    if(associationsFile.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&associationsFile);
        while(!in.atEnd()){
            lines.append(in.readLine());
        }
        associationsFile.close();
    }else{
        qWarning("deleteReader: Impossible to read associationsFile.txt");
    }
    /*****************************************************************************************************************/


    /*****************************************************************************************************************
     * Rimuove da QStringList lines le righe in cui compaiono gli specifici readerMAC e readerID
     *****************************************************************************************************************/
    if(lines.size()!=0){
        for(QListWidgetItem *item : toDeleteReaders){

            QString selectedItemPath = item->data(Qt::UserRole).toString();

            /*********************************************************************************
             * Legge l'indirizzo MAC e l'ID del reader dal file readerInfo.txt
             *********************************************************************************/
            QString readerMAC, readerID;
            QString readerInfoFileName = selectedItemPath+"/readerInfo.txt";
            qDebug()<<"deleteReader: readerInfoFileName = "<<readerInfoFileName;
            QFile readerInfoFile(readerInfoFileName);
            if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream in(&readerInfoFile);
                readerMAC = in.readLine();
                if(!in.atEnd()){
                    readerID = in.readLine();
                    qDebug()<<"deleteReader: readerID = "<<readerID;
                }
                readerInfoFile.close();
                qDebug()<<"deleteReader: readerMAC = "<<readerMAC;
            }else{
                qWarning("deleteReader: Impossible to read readerInfo.txt");
            }
            /*********************************************************************************/

            /************************************************************************************
             * Legge QStringList lines e cerca il/i match per l'eliminazione
             ************************************************************************************/
            for(int i=0; i<lines.size();){
                QString line = lines.at(i);
                QString storedMacAddr, storedReaderID, storedQrCode;
                parseLine(line, storedMacAddr, storedReaderID, storedQrCode);
                if( (storedMacAddr==readerMAC) && (storedReaderID==readerID) ){
                    qDebug()<<"deleteReader: MATCH FOUND AT LINE "<<i;
                    lines.removeAt(i);
                }else{
                    ++i;
                }
            }
            /**************************************************************************************************************/
        }

    }// END OF if(lines.size()!=0)
    /*****************************************************************************************************************/

    /***********************************************
     * Rimuove il vecchio file delle associazioni
     ***********************************************/
    QFile::remove(associationsFileName);
    /***********************************************/

    /******************************************************************************************
     * Aggiorna il file delle associazioni (associationsFile.txt) se lines.size()!=0
     ******************************************************************************************/
    if(lines.size()!=0){

        //for(const QString &line : lines){
        //    qDebug()<<"deleteReader: line = "<<line;
        //}

        if(associationsFile.open(QIODevice::Append | QIODevice::Text)){
            QTextStream out(&associationsFile);
            for(const QString &line : lines){
                out<<line<<"\n";
            }
            associationsFile.close();
        }else{
            qWarning("deleteReader: Impossible to update associationsFile.txt");
        }

    }else{
        qDebug()<<"deleteReader: line.size())  "<<lines.size();
        qDebug()<<"deleteReader: NO ASSOCIATIONS TO STORE";
    }
    /******************************************************************************************/

    /******************************************************************************************
     * Rimuove le directory dei Reader selezionati
     ******************************************************************************************/
    for(QListWidgetItem *item : toDeleteReaders){

        QString selectedItemPath = item->data(Qt::UserRole).toString();
        QString selectedItemType = item->data(Qt::UserRole+1).toString();

        qDebug()<<"selectedItemPath "<<selectedItemPath;
        qDebug()<<"selectedItemType "<<selectedItemType;

        if(selectedItemType=="folder"){
            QDir directory(selectedItemPath);
            if(directory.exists()){
                /*****************************************************
                 * Ricava il readerID dal path
                 *****************************************************/
                directory.makeAbsolute();
                QString directoryPath=directory.absolutePath();
                QFileInfo fileInfo(directoryPath);
                QString readerID=fileInfo.fileName();
                qDebug()<<"deleteReader: readerID "<<readerID;
                /*****************************************************/

                if(directory.removeRecursively()){
                    qDebug()<<"deleteReader: "<<selectedItemPath<<"deleted";
                    /**************************************************************************************
                     * Aggiorna/crea il file dei log
                     **************************************************************************************/
                    updateLogFile("ReaderDeletion", logsDirectory, "dummyDecodedQR", "readerMAC", readerID);
                    /**************************************************************************************/
                }
                else{
                    qDebug()<<"deleteReader: Failed to delete "<<selectedItemPath;
                }
            }
            else{
                qDebug()<<"deleteReader: "<<selectedItemPath<<"does not exist";
            }
        }

    } //END OF for(QListWidgetItem *item : toDeleteReaders)
    /******************************************************************************************/

    /*********************************
     * Aggiorna la MainWindow
     *********************************/
    updateMainWindow();
    /*********************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/**********************************************************************************
 * Callback che gestisce l'apertura da remoto
 **********************************************************************************/
void MainWindow::on_pB_remoteOpen_clicked()
{
    toOpenMAC="";
    bool checkRightSelection=false;

    QListWidgetItem *selectedReaderItem = ui->listWidget_Readers->currentItem();

    if(!selectedReaderItem){
        QMessageBox::warning(this, "Attenzione","       Nessun lettore selezionato per l'apertura remota.\n"
                                                "Selezionare un lettore dalla lista sulla sinistra.");
        //QMessageBox::warning(this, "Warning","       No Reader selected for remote open.\n"
        //                                     "Please select a Reader from the list on the left.");
        return;
    }

    QString selectedItemType = selectedReaderItem->data(Qt::UserRole+1).toString();

    if(selectedItemType=="folder"){
        checkRightSelection=true;
    }

    if(checkRightSelection==false){
        QMessageBox::warning(this, "Attenzione","       Nessun lettore selezionato per l'apertura remota.\n"
                                                "Selezionare un lettore dalla lista sulla sinistra.");
        //QMessageBox::warning(this, "Warning","       No Readers selected for remote open.\n"
        //                                     "Please select one Reader from the list on the left.");
        return;
    }
    else{

        QString selectedItemPath = selectedReaderItem->data(Qt::UserRole).toString();

        QFileInfo fileInfo(selectedItemPath);
        QString folderName=fileInfo.fileName();

        /****************************************************************************************************************
         * Apre una finestra di dialogo per confermare la volontà di aprire da remoto la stanza associata al Reader
         ****************************************************************************************************************/
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(nullptr, "Conferma Apertura Remota",
                                      "Si sta tentando di aprire "+folderName+" da remoto.\n"
                                                                              "         Premere YES per confermare.", QMessageBox::Yes | QMessageBox::No);
        //reply = QMessageBox::question(nullptr, "Confirm Remote Open",
        //                              "You are about to open "+folderName+" from remote.\n"
        //                                                                  "         Press YES to confirm.", QMessageBox::Yes | QMessageBox::No);
        if(reply==QMessageBox::No){
            ui->listWidget_Readers->setCurrentItem(nullptr);
            ui->listWidget_Readers->clearSelection();
            return;
        }
        /****************************************************************************************************************/


        /*********************************************************************************
         * Legge l'indirizzo MAC e l'ID del reader dal file readerInfo.txt
         *********************************************************************************/
        QString readerID;
        QString readerInfoFileName = selectedItemPath+"/readerInfo.txt";
        qDebug()<<"on_pB_remoteOpen_clicked: readerInfoFileName = "<<readerInfoFileName;
        QFile readerInfoFile(readerInfoFileName);
        if(readerInfoFile.open(QIODevice::ReadOnly | QIODevice::Text)){
            QTextStream in(&readerInfoFile);
            toOpenMAC = in.readLine();
            if(!in.atEnd()){
                readerID = in.readLine();
                qDebug()<<"on_pB_remoteOpen_clicked: readerID = "<<readerID;
            }
            readerInfoFile.close();
            qDebug()<<"on_pB_remoteOpen_clicked: readerMAC = "<<toOpenMAC;
            updateLogFile("RemoteOpen", logsDirectory, "dummyDecodedQR", toOpenMAC, readerID);
        }else{
            qWarning("on_pB_remoteOpen_clicked: Impossible to read readerInfo.txt");
        }
        /*********************************************************************************/

    }

    ui->listWidget_Readers->setCurrentItem(nullptr);
    ui->listWidget_Readers->clearSelection();


}
/*********************************************************************************************************************************************************/


/*********************************************************************************************************************************************************/
/********************************************************************************************
 * Callback richiamata al click su pB_FWD per cambiare pagina visualizzata
 ********************************************************************************************/
void MainWindow::on_pB_FWD_clicked()
{
    /****************************************************************************************
     * Per poter accedere alla pagina di gestione è necessario il login, pertanto quando si
     * tenta di cambiare pagina viene aperta la dialog di login. Se il login ha successo
     * viene aperta la pagina di gestione
     ****************************************************************************************/
    loginDialog = new LoginDialog(this);
    connect(loginDialog, &LoginDialog::LoginValid, this, &MainWindow::onLoginValid);
    connect(loginDialog, &QDialog::finished, loginDialog, &QObject::deleteLater);
    loginDialog->exec(); //loginDialog->show();

    if(loginChecked==true){

        int currentIndex=ui->stackedWidget->currentIndex();
        int nextIndex=(currentIndex+1)%( ui->stackedWidget->count() );
        ui->stackedWidget->setCurrentIndex(nextIndex);

        if(nextIndex==1){
            ui->pB_BWD->setEnabled(true);
            ui->pB_FWD->setEnabled(false);
        }

    }

    /********************************
     * resetta loginChecked
     ********************************/
    loginChecked=false;
    /********************************/

    /****************************************************************************************/


    /********************************************************************************
     * Vecchia versione non protetta da password
     ********************************************************************************/
    //    int currentIndex=ui->stackedWidget->currentIndex();
    //    int nextIndex=(currentIndex+1)%( ui->stackedWidget->count() );
    //    ui->stackedWidget->setCurrentIndex(nextIndex);

    //    if(nextIndex==1){
    //        ui->pB_BWD->setEnabled(true);
    //        ui->pB_FWD->setEnabled(false);
    //    }

    //  //updateReaderList(readersDirectory);
    /********************************************************************************/

}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************************
 * Callback richiamata al click su pB_BWD per cambiare pagina visualizzata
 ********************************************************************************************/
void MainWindow::on_pB_BWD_clicked()
{

    int currentIndex=ui->stackedWidget->currentIndex();
    int prevIndex=(currentIndex - 1 + ui->stackedWidget->count() )%( ui->stackedWidget->count() );
    ui->stackedWidget->setCurrentIndex(prevIndex);

    if(prevIndex==0){
        ui->pB_BWD->setEnabled(false);
        ui->pB_FWD->setEnabled(true);
    }


    //updateReaderList(readersDirectory);
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
/********************************************************************************************
 * Callback richiamata a seguito del login
 ********************************************************************************************/
void MainWindow::onLoginValid(const bool loginFlag){
    qDebug()<<"loginFlag: "<<loginFlag;
    loginChecked=loginFlag;
}
/*********************************************************************************************************************************************************/



/*********************************************************************************************************************************************************/
//void MainWindow::onControlTimerTimeout(){
//    qDebug()<<"onControlTimerTimeout";
//}
/*********************************************************************************************************************************************************/
