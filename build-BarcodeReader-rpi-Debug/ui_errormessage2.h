/********************************************************************************
** Form generated from reading UI file 'errormessage2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ERRORMESSAGE2_H
#define UI_ERRORMESSAGE2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_errormessage2
{
public:
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *errormessage2)
    {
        if (errormessage2->objectName().isEmpty())
            errormessage2->setObjectName(QString::fromUtf8("errormessage2"));
        errormessage2->resize(400, 85);
        label_3 = new QLabel(errormessage2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 20, 361, 20));
        label_4 = new QLabel(errormessage2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(140, 40, 131, 17));

        retranslateUi(errormessage2);

        QMetaObject::connectSlotsByName(errormessage2);
    } // setupUi

    void retranslateUi(QDialog *errormessage2)
    {
        errormessage2->setWindowTitle(QCoreApplication::translate("errormessage2", "Dialog", nullptr));
        label_3->setText(QCoreApplication::translate("errormessage2", "IL LETTORE CHE SI STA TENTANDO DI AGGIUNGERE", nullptr));
        label_4->setText(QCoreApplication::translate("errormessage2", "GIA' ESISTE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class errormessage2: public Ui_errormessage2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ERRORMESSAGE2_H
