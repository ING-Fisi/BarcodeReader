#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_pB_login_clicked();

    void on_pB_editPassword_clicked();

signals:
    bool LoginValid(bool loginFlag);



private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
