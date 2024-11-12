#ifndef NEWQRCODEDIALOG_H
#define NEWQRCODEDIALOG_H

#include <QDialog>

namespace Ui {
class NewQrCodeDialog;
}

class NewQrCodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewQrCodeDialog(QWidget *parent = nullptr);
    ~NewQrCodeDialog();

signals:
    void QRCodeGenerated(const QString &Name, const QString &Surname, const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime);

private slots:
    void on_pB_generateQR_clicked();

    QString checkFormat(const QString &text);

private:
    Ui::NewQrCodeDialog *ui;
};

#endif // NEWQRCODEDIALOG_H
