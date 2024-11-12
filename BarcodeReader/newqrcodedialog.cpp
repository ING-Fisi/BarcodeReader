#include "newqrcodedialog.h"
#include "ui_newqrcodedialog.h"
#include <QProcess>
#include <QDebug>
#include <QDate>
#include <QTime>

NewQrCodeDialog::NewQrCodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewQrCodeDialog)
{
    ui->setupUi(this);
    setWindowTitle("NEW QR CODE DIALOG");

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

    QString Email = ui->lE_email->text();
    if(Email.contains(' ')){
        Email.remove(' ');
    }

    QString StartingDate = ui->startingDateEdit->text();
    QString StartingTime = ui->startingTimeEdit->text();
    QString ExpiringDate = ui->expiringDateEdit->text();
    QString ExpiringTime = ui->expiringTimeEdit->text();

    qDebug()<<"QrCodeDialog Name "<<Name;
    qDebug()<<"QrCodeDialog Surname "<<Surname;
    qDebug()<<"QrCodeDialog Email "<<Email;
    qDebug()<<"QrCodeDialog StartingDate "<<StartingDate;
    qDebug()<<"QrCodeDialog StartingTime "<<StartingTime;
    qDebug()<<"QrCodeDialog ExpiringDate "<<ExpiringDate;
    qDebug()<<"QrCodeDialog ExpiringTime "<<ExpiringTime;


    emit QRCodeGenerated(Name, Surname, Email, StartingDate, StartingTime, ExpiringDate, ExpiringTime);
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
//                 << "-o output.jpg";

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
     * Se sono presenti spazi vuoli, li elimina
     *********************************************************/
    if(modifiedText.contains(' ')){
        modifiedText.remove(' ');
    }
    /*********************************************************/

    return modifiedText;

}
