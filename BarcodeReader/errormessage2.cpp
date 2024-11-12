#include "errormessage2.h"
#include "ui_errormessage2.h"

errormessage2::errormessage2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::errormessage2)
{
    ui->setupUi(this);
    setWindowTitle("ERROR");
}

errormessage2::~errormessage2()
{
    delete ui;
}
