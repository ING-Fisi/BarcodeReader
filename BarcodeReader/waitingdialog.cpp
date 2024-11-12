#include "waitingdialog.h"
#include "ui_waitingdialog.h"

#include <QMovie>

WaitingDialog::WaitingDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingDialog)
{
    ui->setupUi(this);
    setWindowTitle(" ");
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint); // Per impostare la finestra sempre in primo piano

    QMovie *GifAnimation = new QMovie("/home/fisitron/BarcodeReaderFiles/Background/hold-on.gif");
    ui->label_gif->setMovie(GifAnimation);
    ui->label_gif->raise();
    GifAnimation->start();
}

WaitingDialog::~WaitingDialog()
{
    delete ui;
}
