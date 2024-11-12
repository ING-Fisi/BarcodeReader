#include "errormessage.h"
#include "ui_errormessage.h"

ErrorMessage::ErrorMessage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ErrorMessage)
{
    ui->setupUi(this);
    setWindowTitle("ERROR");
}

ErrorMessage::~ErrorMessage()
{
    delete ui;
}
