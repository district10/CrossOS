#ifndef COSS_H
#define COSS_H

#include <QtCore>
#include <QTcpServer>
#include <QTcpSocket>
#include "client.h"
#include "moderator.h"

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server(QObject *parent = 0);
    void writeToClient(QByteArray ba);

    void writeRed();
    void writeGreen();

signals:
    void readed(QByteArray ba);
    void connected();

    void setRed();
    void setGreen();

public slots:
    void readClient();
    void connectClient();

public:
    bool red;

private:
    QTcpSocket *server;
    Moderator *mod;
};

#endif // COSS_H
