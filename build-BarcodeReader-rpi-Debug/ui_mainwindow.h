/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QListWidget *listWidget_Readers_2;
    QLabel *label_8;
    QWidget *page_2;
    QPushButton *pB_addReader;
    QPushButton *pB_associate;
    QLabel *label_6;
    QPushButton *pB_remoteOpen;
    QLabel *label_3;
    QListWidget *listWidget_QrCodes;
    QPushButton *pB_downloadQR;
    QLabel *l_QrCodeImage;
    QLabel *label_5;
    QPushButton *pB_deleteReader;
    QLabel *l_StartTime;
    QLabel *l_Surname;
    QPushButton *pushB_NewQrCode;
    QPushButton *pB_disassociate;
    QLabel *label;
    QListWidget *listWidget_Readers;
    QLabel *l_ExpTime;
    QLabel *label_4;
    QLabel *l_ExpDate;
    QLabel *label_2;
    QLabel *l_StartDate;
    QLabel *label_7;
    QLabel *l_Name;
    QLabel *l_Email;
    QPushButton *pB_deleteQR;
    QPushButton *pB_FWD;
    QPushButton *pB_BWD;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(900, 677);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(10, 10, 1250, 730));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        listWidget_Readers_2 = new QListWidget(page);
        listWidget_Readers_2->setObjectName(QString::fromUtf8("listWidget_Readers_2"));
        listWidget_Readers_2->setEnabled(true);
        listWidget_Readers_2->setGeometry(QRect(20, 100, 240, 300));
        QFont font;
        font.setPointSize(14);
        listWidget_Readers_2->setFont(font);
        listWidget_Readers_2->setSelectionMode(QAbstractItemView::NoSelection);
        listWidget_Readers_2->setViewMode(QListView::ListMode);
        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 70, 241, 31));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_8->setFont(font1);
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        pB_addReader = new QPushButton(page_2);
        pB_addReader->setObjectName(QString::fromUtf8("pB_addReader"));
        pB_addReader->setGeometry(QRect(20, 50, 131, 41));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        pB_addReader->setFont(font2);
        pB_associate = new QPushButton(page_2);
        pB_associate->setObjectName(QString::fromUtf8("pB_associate"));
        pB_associate->setGeometry(QRect(218, 50, 101, 41));
        pB_associate->setFont(font2);
        label_6 = new QLabel(page_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(541, 340, 159, 21));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setWeight(75);
        label_6->setFont(font3);
        label_6->setAutoFillBackground(true);
        pB_remoteOpen = new QPushButton(page_2);
        pB_remoteOpen->setObjectName(QString::fromUtf8("pB_remoteOpen"));
        pB_remoteOpen->setGeometry(QRect(20, 460, 151, 41));
        pB_remoteOpen->setFont(font2);
        label_3 = new QLabel(page_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(541, 310, 69, 21));
        label_3->setFont(font3);
        label_3->setAutoFillBackground(true);
        listWidget_QrCodes = new QListWidget(page_2);
        listWidget_QrCodes->setObjectName(QString::fromUtf8("listWidget_QrCodes"));
        listWidget_QrCodes->setGeometry(QRect(280, 100, 240, 300));
        listWidget_QrCodes->setFont(font);
        pB_downloadQR = new QPushButton(page_2);
        pB_downloadQR->setObjectName(QString::fromUtf8("pB_downloadQR"));
        pB_downloadQR->setEnabled(true);
        pB_downloadQR->setGeometry(QRect(540, 400, 101, 41));
        pB_downloadQR->setFont(font2);
        l_QrCodeImage = new QLabel(page_2);
        l_QrCodeImage->setObjectName(QString::fromUtf8("l_QrCodeImage"));
        l_QrCodeImage->setGeometry(QRect(570, 30, 250, 250));
        l_QrCodeImage->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(830, 370, 41, 21));
        label_5->setFont(font3);
        label_5->setAutoFillBackground(true);
        pB_deleteReader = new QPushButton(page_2);
        pB_deleteReader->setObjectName(QString::fromUtf8("pB_deleteReader"));
        pB_deleteReader->setGeometry(QRect(130, 410, 131, 41));
        pB_deleteReader->setFont(font2);
        l_StartTime = new QLabel(page_2);
        l_StartTime->setObjectName(QString::fromUtf8("l_StartTime"));
        l_StartTime->setGeometry(QRect(870, 340, 151, 21));
        l_StartTime->setFont(font3);
        l_StartTime->setAutoFillBackground(true);
        l_Surname = new QLabel(page_2);
        l_Surname->setObjectName(QString::fromUtf8("l_Surname"));
        l_Surname->setGeometry(QRect(650, 280, 241, 21));
        l_Surname->setFont(font3);
        l_Surname->setAutoFillBackground(true);
        pushB_NewQrCode = new QPushButton(page_2);
        pushB_NewQrCode->setObjectName(QString::fromUtf8("pushB_NewQrCode"));
        pushB_NewQrCode->setGeometry(QRect(330, 50, 191, 41));
        pushB_NewQrCode->setFont(font2);
        pB_disassociate = new QPushButton(page_2);
        pB_disassociate->setObjectName(QString::fromUtf8("pB_disassociate"));
        pB_disassociate->setGeometry(QRect(20, 410, 101, 41));
        pB_disassociate->setFont(font2);
        label = new QLabel(page_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(541, 251, 72, 21));
        QFont font4;
        font4.setPointSize(14);
        font4.setBold(true);
        font4.setItalic(false);
        font4.setUnderline(false);
        font4.setWeight(75);
        font4.setStrikeOut(false);
        font4.setKerning(true);
        label->setFont(font4);
        label->setAutoFillBackground(true);
        label->setFrameShape(QFrame::NoFrame);
        listWidget_Readers = new QListWidget(page_2);
        listWidget_Readers->setObjectName(QString::fromUtf8("listWidget_Readers"));
        listWidget_Readers->setGeometry(QRect(20, 100, 240, 300));
        listWidget_Readers->setFont(font);
        listWidget_Readers->setSelectionMode(QAbstractItemView::ExtendedSelection);
        listWidget_Readers->setViewMode(QListView::ListMode);
        l_ExpTime = new QLabel(page_2);
        l_ExpTime->setObjectName(QString::fromUtf8("l_ExpTime"));
        l_ExpTime->setGeometry(QRect(870, 370, 151, 21));
        l_ExpTime->setFont(font3);
        l_ExpTime->setAutoFillBackground(true);
        label_4 = new QLabel(page_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(541, 370, 149, 21));
        label_4->setFont(font3);
        label_4->setAutoFillBackground(true);
        l_ExpDate = new QLabel(page_2);
        l_ExpDate->setObjectName(QString::fromUtf8("l_ExpDate"));
        l_ExpDate->setGeometry(QRect(690, 370, 141, 21));
        l_ExpDate->setFont(font3);
        l_ExpDate->setAutoFillBackground(true);
        label_2 = new QLabel(page_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(541, 280, 109, 21));
        label_2->setFont(font3);
        label_2->setAutoFillBackground(true);
        l_StartDate = new QLabel(page_2);
        l_StartDate->setObjectName(QString::fromUtf8("l_StartDate"));
        l_StartDate->setGeometry(QRect(700, 340, 131, 21));
        l_StartDate->setFont(font3);
        l_StartDate->setAutoFillBackground(true);
        label_7 = new QLabel(page_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(830, 340, 42, 21));
        label_7->setFont(font3);
        label_7->setAutoFillBackground(true);
        l_Name = new QLabel(page_2);
        l_Name->setObjectName(QString::fromUtf8("l_Name"));
        l_Name->setGeometry(QRect(613, 251, 277, 21));
        l_Name->setFont(font3);
        l_Name->setAutoFillBackground(true);
        l_Email = new QLabel(page_2);
        l_Email->setObjectName(QString::fromUtf8("l_Email"));
        l_Email->setGeometry(QRect(610, 310, 281, 21));
        l_Email->setFont(font3);
        l_Email->setAutoFillBackground(true);
        pB_deleteQR = new QPushButton(page_2);
        pB_deleteQR->setObjectName(QString::fromUtf8("pB_deleteQR"));
        pB_deleteQR->setGeometry(QRect(380, 410, 141, 41));
        pB_deleteQR->setFont(font2);
        stackedWidget->addWidget(page_2);
        pB_FWD = new QPushButton(centralwidget);
        pB_FWD->setObjectName(QString::fromUtf8("pB_FWD"));
        pB_FWD->setGeometry(QRect(90, 14, 41, 41));
        QFont font5;
        font5.setPointSize(14);
        font5.setBold(false);
        font5.setWeight(50);
        pB_FWD->setFont(font5);
        pB_BWD = new QPushButton(centralwidget);
        pB_BWD->setObjectName(QString::fromUtf8("pB_BWD"));
        pB_BWD->setGeometry(QRect(30, 14, 41, 41));
        pB_BWD->setFont(font5);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Lista dei Lettori", nullptr));
        pB_addReader->setText(QCoreApplication::translate("MainWindow", "Nuovo Lettore", nullptr));
        pB_associate->setText(QCoreApplication::translate("MainWindow", "Associa\n"
"<-------------", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Inizio Validit\303\240:", nullptr));
        pB_remoteOpen->setText(QCoreApplication::translate("MainWindow", "Apertura Remota", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Email:", nullptr));
        pB_downloadQR->setText(QCoreApplication::translate("MainWindow", "Download", nullptr));
        l_QrCodeImage->setText(QCoreApplication::translate("MainWindow", "QR Code Not Available", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "alle", nullptr));
        pB_deleteReader->setText(QCoreApplication::translate("MainWindow", "Elimina Lettore", nullptr));
        l_StartTime->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        l_Surname->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        pushB_NewQrCode->setText(QCoreApplication::translate("MainWindow", "Genera Nuovo QR Code", nullptr));
        pB_disassociate->setText(QCoreApplication::translate("MainWindow", "Disassocia", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Nome:", nullptr));
        l_ExpTime->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Fine Validit\303\240:", nullptr));
        l_ExpDate->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cognome:", nullptr));
        l_StartDate->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "alle", nullptr));
        l_Name->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        l_Email->setText(QCoreApplication::translate("MainWindow", "Not Available", nullptr));
        pB_deleteQR->setText(QCoreApplication::translate("MainWindow", "Elimina QR Code", nullptr));
        pB_FWD->setText(QCoreApplication::translate("MainWindow", ">>", nullptr));
        pB_BWD->setText(QCoreApplication::translate("MainWindow", "<<", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
