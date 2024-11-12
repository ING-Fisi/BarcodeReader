#ifndef ERRORMESSAGE2_H
#define ERRORMESSAGE2_H

#include <QDialog>

namespace Ui {
class errormessage2;
}

class errormessage2 : public QDialog
{
    Q_OBJECT

public:
    explicit errormessage2(QWidget *parent = nullptr);
    ~errormessage2();

private:
    Ui::errormessage2 *ui;
};

#endif // ERRORMESSAGE2_H
