#ifndef ADDREADER_H
#define ADDREADER_H

#include <QDialog>
#include "barcodereaderserver.h"

namespace Ui {
class AddReader;
}

class AddReader : public QDialog
{
    Q_OBJECT

public:
    explicit AddReader(QWidget *parent = nullptr);
    ~AddReader();

    //BarcodeReaderServer* BarcodeReaderServer_Instance_2;

private:
    Ui::AddReader *ui;
};

#endif // ADDREADER_H
