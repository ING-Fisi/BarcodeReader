#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QWidget>
#include <QListWidget>
#include <QListWidgetItem>
#include "barcodereaderserver.h"
#include "addreader.h"
#include "errormessage.h"
#include "errormessage2.h"
#include "editdialog.h"
#include "newqrcodedialog.h"
#include "qrcodereader.h"
#include "waitingdialog.h"
#include "logindialog.h"

#include <datepicker.h>
#include <datepickerhumanreadableformater.h>



/********************************************************************/
#include <QObject>

#include "qhttpserverfwd.h"
#include <QCoreApplication>

#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>
/********************************************************************/

/***************************************************************************************************************************
 * Files directories
 ***************************************************************************************************************************/
//const QString fileshomedirectory = "/home/tinylap/";
//const QString filesDirectory = fileshomedirectory + "BarcodeReaderFiles";
//const QString associationsDirectory = filesDirectory+"/Associations"; //"/home/fisitron/BarcodeReaderFiles/Associations";
//const QString logsDirectory = filesDirectory+"/Logs";                 //"/home/fisitron/BarcodeReaderFiles/Logs";
//const QString qrCodesDirectory = filesDirectory+"/QRCodes";           //"/home/fisitron/BarcodeReaderFiles/QRCodes";
//const QString readersDirectory = filesDirectory+"/Readers";           //"/home/fisitron/BarcodeReaderFiles/Readers";
//const QString downloadFolderPath = fileshomedirectory + "Downloads";
//const QString settingsDirectory = filesDirectory+"/Settings";

const QString fileshomedirectory = "";
const QString filesDirectory = fileshomedirectory + "BarcodeReaderFiles";
const QString associationsDirectory = filesDirectory+"/Associations"; //"/home/fisitron/BarcodeReaderFiles/Associations";
const QString logsDirectory = filesDirectory+"/Logs";                 //"/home/fisitron/BarcodeReaderFiles/Logs";
const QString qrCodesDirectory = filesDirectory+"/QRCodes";           //"/home/fisitron/BarcodeReaderFiles/QRCodes";
const QString readersDirectory = filesDirectory+"/Readers";           //"/home/fisitron/BarcodeReaderFiles/Readers";
const QString downloadFolderPath = fileshomedirectory + "Downloads";
const QString settingsDirectory = filesDirectory+"/Settings";
/***************************************************************************************************************************/


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    BarcodeReaderServer* BarcodeReaderServer_Instance;


    QList<QRCodeReader*> QrcodeReader_list;

    QList<QRCode*> QRCodeListTotal;



    bool receive_sync_packet(QString receivedMacAddr);


    QTimer* RefreshTimer;






private slots:
    void checkDirectories();
    void checkDirectory(QString directoryPath);

    void openAddReaderDialog();
    void updateMainWindow();

    void on_pB_addReader_clicked();
    bool checkMAC(QString receivedMacAddr);

    QString getReaderID(QString receivedMacAddr);

    void onTimerTimeout();

    void onDialogSaveClicked(const QString &strMAC, const QString &strQR, const QString &editedStr);
    bool checkReaderID(const QString editedStr);

    //void onQRCodeGenerated(const QString &Name, const QString &Surname, const QString &PhoneNumber, const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime);
    void onQRCodeGenerated(const QString &Name, const QString &Surname, const QString &PhoneNumber, const QString &Email, const QString &QrType, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime,
                             const QString &monday, const QString &StartingTimeMonday, const QString &ExpiringTimeMonday,
                             const QString &tuesday, const QString &StartingTimeTuesday, const QString &ExpiringTimeTuesday,
                             const QString &wednsday, const QString &StartingTimeWednsday, const QString &ExpiringTimeWednsday,
                             const QString &thursday, const QString &StartingTimeThursday, const QString &ExpiringTimeThursday,
                             const QString &friday, const QString &StartingTimeFriday, const QString &ExpiringTimeFriday,
                             const QString &saturday, const QString &StartingTimeSaturday, const QString &ExpiringTimeSaturday,
                             const QString &sunday, const QString &StartingTimeSunday, const QString &ExpiringTimeSunday);

    void showQRcode(QString imagePath);

    void updateQrCodeList(const QString &qrCodesDirectory);

    bool parseDecodedQR(const QString &decodedQR, QString &name, QString &surname, QString &email, QString &startDate, QString &startTime, QString &expDate, QString &expTime);

    void onRefreshTimerTimeout();

    /*************************************************************/
    void handleRequest(QHttpRequest *req, QHttpResponse *resp);
    /*************************************************************/

    void on_pushB_NewQrCode_clicked();

    void on_pB_downloadQR_clicked();

    void createReaderFile(const QString &strMAC, const QString &editedStr);

    void updateReaderList(const QString &readersDirectory);

    void on_listWidget_Readers_itemClicked(QListWidgetItem *item);

    void expandReaderFolder(QListWidgetItem *folderItem);
    void collapseReaderFolder(QListWidgetItem *folderItem);

    void on_listWidget_QrCodes_itemClicked(QListWidgetItem *item);

    void on_pB_associate_clicked();

    void updateAssociationsFile(QString readerFolderPath, QString imagePath);

    bool parseLine(const QString &line, QString &macAddr, QString &readerID, QString &qrCode);

    void on_pB_disassociate_clicked();

    bool deleteAssociationsFileLine(const QString selectedItemPath);

    void on_pB_deleteQR_clicked();
    void deleteQR();

    void updateLogFile(QString EventType, QString logsDirectory, QString decodedQR, QString readerMAC, QString readerID);

    void on_pB_deleteReader_clicked();
    void deleteReader();

    void on_pB_remoteOpen_clicked();

    void on_pB_FWD_clicked();

    void on_pB_BWD_clicked();

    void openWaitingDialog();
    void onWaitingFinished();

    void onLoginValid(const bool loginFlag);

    //void createQRInfoFile(const QString &Name, const QString &mSurname, const QString &PhoneNumber,const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime);
    void createQRInfoFile(const QString &Name, const QString &mSurname, const QString &PhoneNumber, const QString &Email, const QString &QrType, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime,
                             const QString &monday, const QString &StartingTimeMonday, const QString &ExpiringTimeMonday,
                             const QString &tuesday, const QString &StartingTimeTuesday, const QString &ExpiringTimeTuesday,
                             const QString &wednsday, const QString &StartingTimeWednsday, const QString &ExpiringTimeWednsday,
                             const QString &thursday, const QString &StartingTimeThursday, const QString &ExpiringTimeThursday,
                             const QString &friday, const QString &StartingTimeFriday, const QString &ExpiringTimeFriday,
                             const QString &saturday, const QString &StartingTimeSaturday, const QString &ExpiringTimeSaturday,
                             const QString &sunday, const QString &StartingTimeSunday, const QString &ExpiringTimeSunday);

    QString generateRandomString(int length);
    //void onControlTimerTimeout();

private:
    Ui::MainWindow *ui;
    AddReader *addReaderDialog;
    WaitingDialog *waitDialog;
    QTimer *addReaderTimer;
    QTimer *waitingTimer;
    ErrorMessage *errorMessageDialog;
    errormessage2 *errorMessage2Dialog;
    NewQrCodeDialog *newQrCodeDialog;
    LoginDialog *loginDialog;
};
#endif // MAINWINDOW_H
