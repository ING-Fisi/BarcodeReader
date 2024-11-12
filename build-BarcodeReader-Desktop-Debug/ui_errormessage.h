/********************************************************************************
** Form generated from reading UI file 'errormessage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORMESSAGE_H
#define UI_ERRORMESSAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_ErrorMessage
{
public:
    QLabel *label_2;
    QLabel *label;

    void setupUi(QDialog *ErrorMessage)
    {
        if (ErrorMessage->objectName().isEmpty())
            ErrorMessage->setObjectName(QString::fromUtf8("ErrorMessage"));
        ErrorMessage->resize(400, 85);
        label_2 = new QLabel(ErrorMessage);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 40, 191, 20));
        label = new QLabel(ErrorMessage);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(100, 20, 201, 20));

        retranslateUi(ErrorMessage);

        QMetaObject::connectSlotsByName(ErrorMessage);
    } // setupUi

    void retranslateUi(QDialog *ErrorMessage)
    {
        ErrorMessage->setWindowTitle(QApplication::translate("ErrorMessage", "Dialog", nullptr));
        label_2->setText(QApplication::translate("ErrorMessage", "PER LA CONFIGURAZIONE", nullptr));
        label->setText(QApplication::translate("ErrorMessage", "QR CODE NON VALIDO", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ErrorMessage: public Ui_ErrorMessage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORMESSAGE_H
