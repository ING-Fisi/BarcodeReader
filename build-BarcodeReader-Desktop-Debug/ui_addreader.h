/********************************************************************************
** Form generated from reading UI file 'addreader.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDREADER_H
#define UI_ADDREADER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_AddReader
{
public:
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *AddReader)
    {
        if (AddReader->objectName().isEmpty())
            AddReader->setObjectName(QString::fromUtf8("AddReader"));
        AddReader->resize(400, 85);
        label = new QLabel(AddReader);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 20, 221, 20));
        label_2 = new QLabel(AddReader);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(110, 50, 181, 17));

        retranslateUi(AddReader);

        QMetaObject::connectSlotsByName(AddReader);
    } // setupUi

    void retranslateUi(QDialog *AddReader)
    {
        AddReader->setWindowTitle(QApplication::translate("AddReader", "Dialog", nullptr));
        label->setText(QApplication::translate("AddReader", "In attesa della configurazione", nullptr));
        label_2->setText(QApplication::translate("AddReader", "Scansionare il QR Code", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddReader: public Ui_AddReader {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDREADER_H
