#include "editdialog.h"
#include "ui_editdialog.h"

EditDialog::EditDialog(const QString &strMAC, const QString &strQR, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditDialog),
    m_strMAC(strMAC),
    m_strQR(strQR)
{
    ui->setupUi(this);

    ui->l_macAddress->setText(strMAC);
    connect(ui->pB_SaveEdit, &QPushButton::clicked, this, &EditDialog::onSaveClicked);
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::onSaveClicked()
{
    QString editedStr = ui->lE_readerID->text();
    if(editedStr.contains(' ')){
        editedStr.remove(' ');
    }
    emit saveClicked(m_strMAC, m_strQR, editedStr);
    accept();
}
