/********************************************************************************
** Form generated from reading UI file 'editdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITDIALOG_H
#define UI_EDITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditDialog
{
public:
    QPushButton *pB_SaveEdit;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lE_readerID;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *l_macAddress;

    void setupUi(QDialog *EditDialog)
    {
        if (EditDialog->objectName().isEmpty())
            EditDialog->setObjectName(QString::fromUtf8("EditDialog"));
        EditDialog->resize(400, 200);
        pB_SaveEdit = new QPushButton(EditDialog);
        pB_SaveEdit->setObjectName(QString::fromUtf8("pB_SaveEdit"));
        pB_SaveEdit->setGeometry(QRect(20, 130, 89, 25));
        layoutWidget = new QWidget(EditDialog);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 221, 27));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lE_readerID = new QLineEdit(layoutWidget);
        lE_readerID->setObjectName(QString::fromUtf8("lE_readerID"));

        horizontalLayout_2->addWidget(lE_readerID);

        layoutWidget1 = new QWidget(EditDialog);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 50, 281, 19));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        l_macAddress = new QLabel(layoutWidget1);
        l_macAddress->setObjectName(QString::fromUtf8("l_macAddress"));

        horizontalLayout->addWidget(l_macAddress);


        retranslateUi(EditDialog);

        QMetaObject::connectSlotsByName(EditDialog);
    } // setupUi

    void retranslateUi(QDialog *EditDialog)
    {
        EditDialog->setWindowTitle(QApplication::translate("EditDialog", "Dialog", nullptr));
        pB_SaveEdit->setText(QApplication::translate("EditDialog", "SALVA", nullptr));
        label_2->setText(QApplication::translate("EditDialog", "ID Lettore:", nullptr));
        label->setText(QApplication::translate("EditDialog", "Indirizzo MAC Lettore:", nullptr));
        l_macAddress->setText(QApplication::translate("EditDialog", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EditDialog: public Ui_EditDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITDIALOG_H
