#include "addreader.h"
#include "ui_addreader.h"
#include "barcodereaderserver.h"

AddReader::AddReader(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddReader)
{
    ui->setupUi(this);
    setWindowTitle(" ");

    //BarcodeReaderServer_Instance_2 = new BarcodeReaderServer();

}

AddReader::~AddReader()
{
    delete ui;
}
