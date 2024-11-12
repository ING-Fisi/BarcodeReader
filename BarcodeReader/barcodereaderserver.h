#ifndef BARCODEREADERSERVER_H
#define BARCODEREADERSERVER_H

#include <QObject>

#include "qhttpserverfwd.h"
#include <QCoreApplication>

#include <qhttpserver.h>
#include <qhttprequest.h>
#include <qhttpresponse.h>


class BarcodeReaderServer : public QObject
{
    Q_OBJECT
public:
    explicit BarcodeReaderServer(QObject *parent = nullptr);

signals:

private slots:
    void handleRequest(QHttpRequest *req, QHttpResponse *resp);

};



#endif // BARCODEREADERSERVER_H
