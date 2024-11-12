/********************************************************************************
** Form generated from reading UI file 'newqrcodedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWQRCODEDIALOG_H
#define UI_NEWQRCODEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewQrCodeDialog
{
public:
    QPushButton *pB_generateQR;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lE_Name;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lE_Surname;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lE_email;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QDateEdit *startingDateEdit;
    QTimeEdit *startingTimeEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QDateEdit *expiringDateEdit;
    QTimeEdit *expiringTimeEdit;

    void setupUi(QDialog *NewQrCodeDialog)
    {
        if (NewQrCodeDialog->objectName().isEmpty())
            NewQrCodeDialog->setObjectName(QString::fromUtf8("NewQrCodeDialog"));
        NewQrCodeDialog->resize(400, 242);
        pB_generateQR = new QPushButton(NewQrCodeDialog);
        pB_generateQR->setObjectName(QString::fromUtf8("pB_generateQR"));
        pB_generateQR->setGeometry(QRect(30, 190, 89, 25));
        layoutWidget = new QWidget(NewQrCodeDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 312, 163));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lE_Name = new QLineEdit(layoutWidget);
        lE_Name->setObjectName(QString::fromUtf8("lE_Name"));

        horizontalLayout->addWidget(lE_Name);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lE_Surname = new QLineEdit(layoutWidget);
        lE_Surname->setObjectName(QString::fromUtf8("lE_Surname"));

        horizontalLayout_2->addWidget(lE_Surname);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lE_email = new QLineEdit(layoutWidget);
        lE_email->setObjectName(QString::fromUtf8("lE_email"));

        horizontalLayout_3->addWidget(lE_email);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        startingDateEdit = new QDateEdit(layoutWidget);
        startingDateEdit->setObjectName(QString::fromUtf8("startingDateEdit"));

        horizontalLayout_5->addWidget(startingDateEdit);

        startingTimeEdit = new QTimeEdit(layoutWidget);
        startingTimeEdit->setObjectName(QString::fromUtf8("startingTimeEdit"));

        horizontalLayout_5->addWidget(startingTimeEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_4->addWidget(label_5);

        expiringDateEdit = new QDateEdit(layoutWidget);
        expiringDateEdit->setObjectName(QString::fromUtf8("expiringDateEdit"));

        horizontalLayout_4->addWidget(expiringDateEdit);

        expiringTimeEdit = new QTimeEdit(layoutWidget);
        expiringTimeEdit->setObjectName(QString::fromUtf8("expiringTimeEdit"));

        horizontalLayout_4->addWidget(expiringTimeEdit);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(NewQrCodeDialog);

        QMetaObject::connectSlotsByName(NewQrCodeDialog);
    } // setupUi

    void retranslateUi(QDialog *NewQrCodeDialog)
    {
        NewQrCodeDialog->setWindowTitle(QApplication::translate("NewQrCodeDialog", "Dialog", nullptr));
        pB_generateQR->setText(QApplication::translate("NewQrCodeDialog", "GENERA", nullptr));
        label->setText(QApplication::translate("NewQrCodeDialog", "NOME:", nullptr));
        label_2->setText(QApplication::translate("NewQrCodeDialog", "COGNOME:", nullptr));
        label_3->setText(QApplication::translate("NewQrCodeDialog", "EMAIL:", nullptr));
        label_4->setText(QApplication::translate("NewQrCodeDialog", "INIZIO VALIDITA':", nullptr));
        startingDateEdit->setDisplayFormat(QApplication::translate("NewQrCodeDialog", "dd/MM/yyyy", nullptr));
        label_5->setText(QApplication::translate("NewQrCodeDialog", "FINE VALIDITA':", nullptr));
        expiringDateEdit->setDisplayFormat(QApplication::translate("NewQrCodeDialog", "dd/MM/yyyy", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewQrCodeDialog: public Ui_NewQrCodeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWQRCODEDIALOG_H
