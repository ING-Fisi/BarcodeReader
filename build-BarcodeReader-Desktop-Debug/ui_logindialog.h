/********************************************************************************
** Form generated from reading UI file 'logindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDIALOG_H
#define UI_LOGINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginDialog
{
public:
    QPushButton *pB_editPassword;
    QLabel *l_wrongPsw;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lE_password;
    QPushButton *pB_login;

    void setupUi(QDialog *LoginDialog)
    {
        if (LoginDialog->objectName().isEmpty())
            LoginDialog->setObjectName(QString::fromUtf8("LoginDialog"));
        LoginDialog->resize(350, 142);
        pB_editPassword = new QPushButton(LoginDialog);
        pB_editPassword->setObjectName(QString::fromUtf8("pB_editPassword"));
        pB_editPassword->setGeometry(QRect(190, 60, 131, 25));
        pB_editPassword->setAutoDefault(false);
        l_wrongPsw = new QLabel(LoginDialog);
        l_wrongPsw->setObjectName(QString::fromUtf8("l_wrongPsw"));
        l_wrongPsw->setGeometry(QRect(80, 90, 201, 41));
        QFont font;
        font.setPointSize(16);
        l_wrongPsw->setFont(font);
        layoutWidget = new QWidget(LoginDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 20, 305, 27));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lE_password = new QLineEdit(layoutWidget);
        lE_password->setObjectName(QString::fromUtf8("lE_password"));

        horizontalLayout->addWidget(lE_password);

        pB_login = new QPushButton(layoutWidget);
        pB_login->setObjectName(QString::fromUtf8("pB_login"));

        horizontalLayout->addWidget(pB_login);


        retranslateUi(LoginDialog);

        QMetaObject::connectSlotsByName(LoginDialog);
    } // setupUi

    void retranslateUi(QDialog *LoginDialog)
    {
        LoginDialog->setWindowTitle(QApplication::translate("LoginDialog", "Dialog", nullptr));
        pB_editPassword->setText(QApplication::translate("LoginDialog", "Cambia Password", nullptr));
        l_wrongPsw->setText(QApplication::translate("LoginDialog", "PASSWORD ERRATA", nullptr));
        label->setText(QApplication::translate("LoginDialog", "Password:", nullptr));
        pB_login->setText(QApplication::translate("LoginDialog", "LOGIN", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginDialog: public Ui_LoginDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDIALOG_H
