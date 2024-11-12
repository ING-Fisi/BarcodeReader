#ifndef QRCODEREADER_H
#define QRCODEREADER_H

#include <QObject>
#include <QTimer>
#include "qrcode.h"


typedef enum warning_status_enum
{
    no_error = 0,
    connection_error = 1,
    qrcode_error = 2,

}warning_status;

#define DOOR_OPEN 0
#define DOOR_CLOSE 1


class QRCodeReader : public QObject
{
    Q_OBJECT
public:
    explicit QRCodeReader(QObject *parent = nullptr);

    int door_status = DOOR_OPEN;
    int warning_status = no_error;


    QString reader_id;
    QString reader_mac_address;

    QTimer* ControlTime;


    QList<QRCode> Qrcode_list;

private slots:
    void onControlTimerTimeout();

signals:

};

#endif // QRCODEREADER_H
