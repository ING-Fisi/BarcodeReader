#include "barcodereaderserver.h"

BarcodeReaderServer::BarcodeReaderServer(QObject *parent) : QObject(parent)
{
    QHttpServer *server = new QHttpServer(this);
    connect(server, SIGNAL(newRequest(QHttpRequest*, QHttpResponse*)),
            this, SLOT(handleRequest(QHttpRequest*, QHttpResponse*)));

    server->listen(QHostAddress::Any, 8080);
}


void BarcodeReaderServer::handleRequest(QHttpRequest *req, QHttpResponse *resp)
{
    Q_UNUSED(req);

    //qDebug()<< req->url();

    QUrl url = req->url();
    //qDebug()<< url;

    QString request =url.toString();
    qDebug()<< request;


    QByteArray body = "Hello Pippo";
    resp->setHeader("Content-Length", QString::number(body.size()));
    resp->writeHead(200);
    resp->end(body);

}
