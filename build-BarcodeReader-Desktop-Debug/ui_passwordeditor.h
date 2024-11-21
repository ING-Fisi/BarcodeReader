/********************************************************************************
** Form generated from reading UI file 'passwordeditor.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PASSWORDEDITOR_H
#define UI_PASSWORDEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PasswordEditor
{
public:
    QPushButton *pB_saveNewPassword;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *l_CurrentPassword;
    QLineEdit *lE_CurrentPassword;
    QHBoxLayout *horizontalLayout_2;
    QLabel *l_NewPassword;
    QLineEdit *lE_NewPassword;

    void setupUi(QDialog *PasswordEditor)
    {
        if (PasswordEditor->objectName().isEmpty())
            PasswordEditor->setObjectName(QString::fromUtf8("PasswordEditor"));
        PasswordEditor->resize(341, 161);
        pB_saveNewPassword = new QPushButton(PasswordEditor);
        pB_saveNewPassword->setObjectName(QString::fromUtf8("pB_saveNewPassword"));
        pB_saveNewPassword->setEnabled(false);
        pB_saveNewPassword->setGeometry(QRect(210, 110, 89, 25));
        layoutWidget = new QWidget(PasswordEditor);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 30, 275, 62));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        l_CurrentPassword = new QLabel(layoutWidget);
        l_CurrentPassword->setObjectName(QString::fromUtf8("l_CurrentPassword"));

        horizontalLayout->addWidget(l_CurrentPassword);

        lE_CurrentPassword = new QLineEdit(layoutWidget);
        lE_CurrentPassword->setObjectName(QString::fromUtf8("lE_CurrentPassword"));

        horizontalLayout->addWidget(lE_CurrentPassword);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        l_NewPassword = new QLabel(layoutWidget);
        l_NewPassword->setObjectName(QString::fromUtf8("l_NewPassword"));

        horizontalLayout_2->addWidget(l_NewPassword);

        lE_NewPassword = new QLineEdit(layoutWidget);
        lE_NewPassword->setObjectName(QString::fromUtf8("lE_NewPassword"));

        horizontalLayout_2->addWidget(lE_NewPassword);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(PasswordEditor);

        QMetaObject::connectSlotsByName(PasswordEditor);
    } // setupUi

    void retranslateUi(QDialog *PasswordEditor)
    {
        PasswordEditor->setWindowTitle(QApplication::translate("PasswordEditor", "Dialog", nullptr));
        pB_saveNewPassword->setText(QApplication::translate("PasswordEditor", "SALVA", nullptr));
        l_CurrentPassword->setText(QApplication::translate("PasswordEditor", "Password Attuale:", nullptr));
        l_NewPassword->setText(QApplication::translate("PasswordEditor", "Nuova Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PasswordEditor: public Ui_PasswordEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PASSWORDEDITOR_H
