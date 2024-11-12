#include "qrcodereader.h"
#include <QDebug>

QRCodeReader::QRCodeReader(QObject *parent) : QObject(parent)
{

    ControlTime=new QTimer(this);
    connect(ControlTime,&QTimer::timeout,this,&QRCodeReader::onControlTimerTimeout);
    if(ControlTime->isActive()){
        ControlTime->stop();
    }
    ControlTime->start(60*1000);


}

void QRCodeReader::onControlTimerTimeout(){
    qDebug()<<"--------------------------------------- onControlTimerTimeout -----------------------------------------------";
    warning_status = connection_error;
    //ControlTime->stop();
}
