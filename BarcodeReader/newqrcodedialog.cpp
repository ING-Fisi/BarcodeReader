#include "newqrcodedialog.h"
#include "ui_newqrcodedialog.h"
#include <QProcess>
#include <QDebug>
#include <QDate>
#include <QTime>
#include "mainwindow.h"


/****************************************************
 * Indice che tiene conto di quante selezioni
 * sono state effettuate sul calendar
 ****************************************************/
int selectionNumber=0;
/****************************************************/

/****************************************************
 * Date di inizio e fine validità
 ****************************************************/
QDate Date_1=QDate::currentDate();
QDate Date_2=Date_1;
/****************************************************/



NewQrCodeDialog::NewQrCodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewQrCodeDialog)
{
    ui->setupUi(this);
    setWindowTitle("NEW QR CODE DIALOG");


    //qDebug()<<fileshomedirectory;

    /**************************************************
     * imposta come invisibile cB_noDeadline
     **************************************************/
    ui->cB_noDeadline->setVisible(false);
    /**************************************************/


    /*******************************************************
     * abilita o disabilita opportunamente giorni o range
     *******************************************************/
    if(ui->rB_days->isChecked()){
        enableDays();
    }else{
        enableRange();
    }
    /*******************************************************/


    /******************************************************************************************
     * Definisce il validatore per lE_phone (es. +39 0123456789)
     ******************************************************************************************/
    QRegularExpression regex("^\\+?[0-9]{1,3}?[0-9]{4,14}$");
    QRegularExpressionValidator *validator = new QRegularExpressionValidator(regex, this);
    ui->lE_phone->setValidator(validator);
    /******************************************************************************************/


    /********************************************************************
     * Imposta la data e l'ora corrente per le QDateEdit e QTimeEdit.
     * In particolare expiringTimeEdit viene settato con un'ora in più
     * rispetto all'ora attuale
     ********************************************************************/
    ui->startingDateEdit->setDate(QDate::currentDate());
    ui->startingTimeEdit->setTime(QTime::currentTime());
    ui->expiringDateEdit->setDate(QDate::currentDate());
    //ui->expiringTimeEdit->setTime(QTime::currentTime());

    QTime currentTime=QTime::currentTime();
    QTime futureTime=currentTime.addSecs(3600);
    ui->expiringTimeEdit->setTime(futureTime);
    /********************************************************************/

}

NewQrCodeDialog::~NewQrCodeDialog()
{
    delete ui;
}

void NewQrCodeDialog::on_pB_generateQR_clicked()
{

    QString Name = ui->lE_Name->text();
    Name=checkFormat(Name);

    QString Surname = ui->lE_Surname->text();
    Surname=checkFormat(Surname);

    QString PhoneNumber = ui->lE_phone->text();

    QString Email = ui->lE_email->text();
    if(Email.contains(' ')){
        Email.remove(' ');
    }

    QString StartingDate = ui->startingDateEdit->text();
    QString StartingTime = ui->startingTimeEdit->text();
    QString ExpiringDate = ui->expiringDateEdit->text();
    QString ExpiringTime = ui->expiringTimeEdit->text();


    /*******************************************************
     * stabilisce la tipologia di QR Code
     *******************************************************/
    QString QrType;
    if(ui->rB_days->isChecked()){
        QrType = "NoDeadline";
    }else{
        QrType = "WithDeadline";
    }
    /*******************************************************/

    QString monday;
    if(ui->cB_mon->isChecked()){
        monday="YES";
    }else{
        monday="NO";
    }
    QString StartingTimeMonday=ui->startingTimeEdit_mon->text();
    QString ExpiringTimeMonday=ui->expiringTimeEdit_mon->text();

    QString tuesday;
    if(ui->cB_tue->isChecked()){
        tuesday="YES";
    }else{
        tuesday="NO";
    }
    QString StartingTimeTuesday=ui->startingTimeEdit_tue->text();
    QString ExpiringTimeTuesday=ui->expiringTimeEdit_tue->text();

    QString wednsday;
    if(ui->cB_wen->isChecked()){
        wednsday="YES";
    }else{
        wednsday="NO";
    }
    QString StartingTimeWednsday=ui->startingTimeEdit_wen->text();
    QString ExpiringTimeWednsday=ui->expiringTimeEdit_wen->text();

    QString thursday;
    if(ui->cB_thu->isChecked()){
        thursday="YES";
    }else{
        thursday="NO";
    }
    QString StartingTimeThursday=ui->startingTimeEdit_thu->text();
    QString ExpiringTimeThursday=ui->expiringTimeEdit_thu->text();

    QString friday;
    if(ui->cB_fri->isChecked()){
        friday="YES";
    }else{
        friday="NO";
    }
    QString StartingTimeFriday=ui->startingTimeEdit_fri->text();
    QString ExpiringTimeFriday=ui->expiringTimeEdit_fri->text();

    QString saturday;
    if(ui->cB_sat->isChecked()){
        saturday="YES";
    }else{
        saturday="NO";
    }
    QString StartingTimeSaturday=ui->startingTimeEdit_sat->text();
    QString ExpiringTimeSaturday=ui->expiringTimeEdit_sat->text();

    QString sunday;
    if(ui->cB_sun->isChecked()){
        sunday="YES";
    }else{
        sunday="NO";
    }
    QString StartingTimeSunday=ui->startingTimeEdit_sun->text();
    QString ExpiringTimeSunday=ui->expiringTimeEdit_sun->text();




    qDebug()<<"QrCodeDialog Name "<<Name;
    qDebug()<<"QrCodeDialog Surname "<<Surname;
    qDebug()<<"QrCodeDialog PhoneNumber "<<PhoneNumber;
    qDebug()<<"QrCodeDialog Email "<<Email;

    qDebug()<<"QrCodeDialog QR Type "<<QrType;
    qDebug()<<"QrCodeDialog StartingDate "<<StartingDate;
    qDebug()<<"QrCodeDialog StartingTime "<<StartingTime;
    qDebug()<<"QrCodeDialog ExpiringDate "<<ExpiringDate;
    qDebug()<<"QrCodeDialog ExpiringTime "<<ExpiringTime;

    qDebug()<<"QrCodeDialog monday "<<monday;
    qDebug()<<"QrCodeDialog StartingTimeMonday "<<StartingTimeMonday;
    qDebug()<<"QrCodeDialog ExpiringTimeMonday "<<ExpiringTimeMonday;
    qDebug()<<"QrCodeDialog tuesday "<<tuesday;
    qDebug()<<"QrCodeDialog StartingTimeTuesday "<<StartingTimeTuesday;
    qDebug()<<"QrCodeDialog ExpiringTimeTuesday "<<ExpiringTimeTuesday;
    qDebug()<<"QrCodeDialog wednsday "<<wednsday;
    qDebug()<<"QrCodeDialog StartingTimeWednsday "<<StartingTimeWednsday;
    qDebug()<<"QrCodeDialog ExpiringTimeWednsday "<<ExpiringTimeWednsday;
    qDebug()<<"QrCodeDialog thursday "<<thursday;
    qDebug()<<"QrCodeDialog StartingTimeThursday "<<StartingTimeThursday;
    qDebug()<<"QrCodeDialog ExpiringTimeThursday "<<ExpiringTimeThursday;
    qDebug()<<"QrCodeDialog friday "<<friday;
    qDebug()<<"QrCodeDialog StartingTimeFriday "<<StartingTimeFriday;
    qDebug()<<"QrCodeDialog ExpiringTimeFriday "<<ExpiringTimeFriday;
    qDebug()<<"QrCodeDialog saturday "<<saturday;
    qDebug()<<"QrCodeDialog StartingTimeSaturday "<<StartingTimeSaturday;
    qDebug()<<"QrCodeDialog ExpiringTimeSaturday "<<ExpiringTimeSaturday;
    qDebug()<<"QrCodeDialog sunday "<<sunday;
    qDebug()<<"QrCodeDialog StartingTimeSunday "<<StartingTimeSunday;
    qDebug()<<"QrCodeDialog ExpiringTimeSunday "<<ExpiringTimeSunday;


    //emit QRCodeGenerated(Name, Surname, PhoneNumber, Email, StartingDate, StartingTime, ExpiringDate, ExpiringTime);
    emit QRCodeGenerated(Name, Surname, PhoneNumber, Email, QrType, StartingDate, StartingTime, ExpiringDate, ExpiringTime,
                         monday, StartingTimeMonday, ExpiringTimeMonday,
                         tuesday, StartingTimeTuesday, ExpiringTimeTuesday,
                         wednsday, StartingTimeWednsday, ExpiringTimeWednsday,
                         thursday, StartingTimeThursday, ExpiringTimeThursday,
                         friday, StartingTimeFriday, ExpiringTimeFriday,
                         saturday, StartingTimeSaturday, ExpiringTimeSaturday,
                         sunday, StartingTimeSunday, ExpiringTimeSunday);
    accept();


    //***********************************************//
//    QString program = "qrencode";
//    QStringList arguments;
//    arguments << "!N!" + Name
//                 + "!SN!" + Surname
//                 + "!EM!" + Email
//                 + "!StrD!" + StartingDate
//                 + "!StrT!" + StartingTime
//                 + "!ExpD!" + ExpiringDate
//                 + "!ExpT!" + ExpiringTime
//                 << "-o output.png";

//    QProcess *myProcess = new QProcess(this);
//    myProcess->start(program, arguments);
    //*******************************************************//

}


QString NewQrCodeDialog::checkFormat(const QString &text)
{
    if(text.isEmpty()){
        return text;
    }

    /*********************************************************
     * Se la prima lettera è minuscola, la rende maiuscola
     *********************************************************/
    QString modifiedText=text;
    if(modifiedText[0].isLower()){
        modifiedText[0]=modifiedText[0].toUpper();
    }
    /*********************************************************/

    /*********************************************************
     * Se sono presenti spazi vuoti, li elimina
     *********************************************************/
    if(modifiedText.contains(' ')){
        modifiedText.remove(' ');
    }
    /*********************************************************/

    return modifiedText;

}



void NewQrCodeDialog::on_rB_days_clicked()
{
    enableDays();
}

void NewQrCodeDialog::enableDays(){
    /***************************************************************
     * abilita i giorni e disabilita il range
     ***************************************************************/
    ui->cB_mon->setEnabled(true);
    ui->startingTimeEdit_mon->setEnabled(true);
    ui->expiringTimeEdit_mon->setEnabled(true);
    ui->cB_tue->setEnabled(true);
    ui->startingTimeEdit_tue->setEnabled(true);
    ui->expiringTimeEdit_tue->setEnabled(true);
    ui->cB_wen->setEnabled(true);
    ui->startingTimeEdit_wen->setEnabled(true);
    ui->expiringTimeEdit_wen->setEnabled(true);
    ui->cB_thu->setEnabled(true);
    ui->startingTimeEdit_thu->setEnabled(true);
    ui->expiringTimeEdit_thu->setEnabled(true);
    ui->cB_fri->setEnabled(true);
    ui->startingTimeEdit_fri->setEnabled(true);
    ui->expiringTimeEdit_fri->setEnabled(true);
    ui->cB_sat->setEnabled(true);
    ui->startingTimeEdit_sat->setEnabled(true);
    ui->expiringTimeEdit_sat->setEnabled(true);
    ui->cB_sun->setEnabled(true);
    ui->startingTimeEdit_sun->setEnabled(true);
    ui->expiringTimeEdit_sun->setEnabled(true);

    ui->label_4->setEnabled(false);
    ui->startingDateEdit->setEnabled(false);
    ui->startingTimeEdit->setEnabled(false);
    ui->label_5->setEnabled(false);
    ui->expiringDateEdit->setEnabled(false);
    ui->expiringTimeEdit->setEnabled(false);
    /***************************************************************/

}



void NewQrCodeDialog::on_rB_range_clicked()
{
    enableRange();
}

void NewQrCodeDialog::enableRange(){
    /***************************************************************
     * disabilita i giorni e abilita il range
     ***************************************************************/
    ui->cB_mon->setEnabled(false);
    ui->startingTimeEdit_mon->setEnabled(false);
    ui->expiringTimeEdit_mon->setEnabled(false);
    ui->cB_tue->setEnabled(false);
    ui->startingTimeEdit_tue->setEnabled(false);
    ui->expiringTimeEdit_tue->setEnabled(false);
    ui->cB_wen->setEnabled(false);
    ui->startingTimeEdit_wen->setEnabled(false);
    ui->expiringTimeEdit_wen->setEnabled(false);
    ui->cB_thu->setEnabled(false);
    ui->startingTimeEdit_thu->setEnabled(false);
    ui->expiringTimeEdit_thu->setEnabled(false);
    ui->cB_fri->setEnabled(false);
    ui->startingTimeEdit_fri->setEnabled(false);
    ui->expiringTimeEdit_fri->setEnabled(false);
    ui->cB_sat->setEnabled(false);
    ui->startingTimeEdit_sat->setEnabled(false);
    ui->expiringTimeEdit_sat->setEnabled(false);
    ui->cB_sun->setEnabled(false);
    ui->startingTimeEdit_sun->setEnabled(false);
    ui->expiringTimeEdit_sun->setEnabled(false);

    ui->label_4->setEnabled(true);
    ui->startingDateEdit->setEnabled(true);
    ui->startingTimeEdit->setEnabled(true);
    ui->label_5->setEnabled(true);
    ui->expiringDateEdit->setEnabled(true);
    ui->expiringTimeEdit->setEnabled(true);
    /***************************************************************/
}



//void NewQrCodeDialog::on_calendarWidget_clicked(const QDate &date)
//{

//    /***********************************************
//     * incrementa il contatore selectionNumber
//     ***********************************************/
//    selectionNumber++;
//    /***********************************************/

//    if(selectionNumber==1){

//        /******************************************************************************
//         * Cambia il colore di background del calendario se necessario
//         ******************************************************************************/
//        if(Date_1!=QDate::currentDate() || Date_2!=QDate::currentDate() ){
//            QTextCharFormat format;
//            format.setBackground(Qt::white);
//            QDate movingDate=Date_1;
//            while(movingDate<=Date_2){
//                ui->calendarWidget->setDateTextFormat(movingDate, format);
//                movingDate=movingDate.addDays(1);
//            }
//        }
//        /******************************************************************************/

//        /*************************************************
//         * se la data selezionata è antecedente alla
//         * data corrente, imposta Date_1 alla data
//         * corrente
//         *************************************************/
//        if(date<=QDate::currentDate()){
//            Date_1=QDate::currentDate();
//        }else{
//            Date_1=date;
//        }
//        /*************************************************/

//    }
//    if(selectionNumber==2){
//        /**********************************************************************
//         * calcola il range di date selezionate
//         **********************************************************************/
//        if(date<=QDate::currentDate()){
//            Date_2=QDate::currentDate();
//        }else{
//            Date_2=date;
//        }
//        if(Date_2<=Date_1){
//            QDate tmpDate=Date_2;
//            Date_2=Date_1;
//            Date_1=tmpDate;
//        }

//        /*******************************************************
//         * Controlla se cB_noDeadline è attivo
//         *******************************************************/
//        if(ui->cB_noDeadline->isChecked()){
//            QDate noDeadline(9999,12,31);
//            Date_2 = noDeadline;
//            //ui->expiringDateEdit->setDate(noDeadline);
//        }
//        /*******************************************************/


//        ui->startingDateEdit->setDate(Date_1);
//        ui->expiringDateEdit->setDate(Date_2);
//        /**********************************************************************/

//        /*************************************
//         * riazzera il contatore
//         *************************************/
//        selectionNumber=0;
//        /*************************************/

//        /**********************************************************************
//         * imposta lo sfondo blu per il range di date selezionate
//         **********************************************************************/
//        QTextCharFormat format;
//        format.setBackground(Qt::blue);
//        QDate movingDate=Date_1;
//        while(movingDate<=Date_2){
//            ui->calendarWidget->setDateTextFormat(movingDate, format);
//            movingDate=movingDate.addDays(1);
//        }
//        /**********************************************************************/

//    }

//}
