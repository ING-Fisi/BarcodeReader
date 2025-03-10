#ifndef QRCODE_H
#define QRCODE_H

#include <QObject>
#include <QDate>
#include <QTime>
#include <datepicker.h>


//typedef struct qrcode_param
//{
//    QString name;
//    QString surname;
//    QString email;
//    QDate starting_date;
//    QTime starting_time;
//    QDate expiring_date;
//    QTime expiring_time;

//    QString qrcode_string;

//}qrcode_param;

class QRCode : public QObject
{
    Q_OBJECT
public:
    explicit QRCode(QObject *parent = nullptr);

    ~QRCode();


    QString QRcodePartNumber;

    QString name;
    QString surname;
    QString phonenumber;
    QString email;

    //qrcode_param qrcode_param_instance;

    //DatePicker qrcode_param_instance;
    DatePicker* qrcode_datepicker_instance;


signals:

};

#endif // QRCODE_H
