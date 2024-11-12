/********************************************************************************
** Form generated from reading UI file 'waitingdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGDIALOG_H
#define UI_WAITINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WaitingDialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_gif;

    void setupUi(QDialog *WaitingDialog)
    {
        if (WaitingDialog->objectName().isEmpty())
            WaitingDialog->setObjectName(QString::fromUtf8("WaitingDialog"));
        WaitingDialog->resize(400, 280);
        label = new QLabel(WaitingDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 401, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(WaitingDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 40, 401, 20));
        label_2->setAlignment(Qt::AlignCenter);
        label_gif = new QLabel(WaitingDialog);
        label_gif->setObjectName(QString::fromUtf8("label_gif"));
        label_gif->setGeometry(QRect(100, 70, 200, 200));
        label_gif->setFrameShape(QFrame::Panel);
        label_gif->setAlignment(Qt::AlignCenter);

        retranslateUi(WaitingDialog);

        QMetaObject::connectSlotsByName(WaitingDialog);
    } // setupUi

    void retranslateUi(QDialog *WaitingDialog)
    {
        WaitingDialog->setWindowTitle(QApplication::translate("WaitingDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("WaitingDialog", "STO CONFIGURANDO IL SISTEMA", nullptr));
        label_2->setText(QApplication::translate("WaitingDialog", "ATTENDERE PREGO", nullptr));
        label_gif->setText(QApplication::translate("WaitingDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WaitingDialog: public Ui_WaitingDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGDIALOG_H
