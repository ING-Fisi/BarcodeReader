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



/********************************************************************/
#include <QObject>

#include "qhttpserverfwd.h"
#include <QCoreApplication>

#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>
/********************************************************************/


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

    void onQRCodeGenerated(const QString &Name, const QString &Surname, const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime);

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
};
#endif // MAINWINDOW_H
