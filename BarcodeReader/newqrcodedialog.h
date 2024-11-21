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
    //void QRCodeGenerated(const QString &Name, const QString &Surname, const QString &PhoneNumber, const QString &Email, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime);
    void QRCodeGenerated(const QString &Name, const QString &Surname, const QString &PhoneNumber, const QString &Email, const QString &QrType, const QString &StartingDate, const QString &StartingTime, const QString &ExpiringDate, const QString &ExpiringTime,
                             const QString &monday, const QString &StartingTimeMonday, const QString &ExpiringTimeMonday,
                             const QString &tuesday, const QString &StartingTimeTuesday, const QString &ExpiringTimeTuesday,
                             const QString &wednsday, const QString &StartingTimeWednsday, const QString &ExpiringTimeWednsday,
                             const QString &thursday, const QString &StartingTimeThursday, const QString &ExpiringTimeThursday,
                             const QString &friday, const QString &StartingTimeFriday, const QString &ExpiringTimeFriday,
                             const QString &saturday, const QString &StartingTimeSaturday, const QString &ExpiringTimeSaturday,
                             const QString &sunday, const QString &StartingTimeSunday, const QString &ExpiringTimeSunday);

private slots:
    void on_pB_generateQR_clicked();

    QString checkFormat(const QString &text);

    //void on_calendarWidget_clicked(const QDate &date);

    void on_rB_days_clicked();

    void on_rB_range_clicked();

    void enableDays();
    void enableRange();

private:
    Ui::NewQrCodeDialog *ui;
};

#endif // NEWQRCODEDIALOG_H
