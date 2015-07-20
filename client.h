#ifndef COSC_H
#define COSC_H

#include <QtCore>
#include <QTcpSocket>
#include "moderator.h"

class Client : public QTcpSocket
{
    Q_OBJECT

public:
    Client(QObject *parent = 0);

    void setIpPort(QString ip, quint16 port);
    void writeToServer(QByteArray &ba);

    void writeRed();
    void writeGreen();

signals:
   void readed(QByteArray ba);
   void setGreen();
   void setRed();

public slots:
    void readServer();
    void connectToServer();

public:
    bool red;

private:
    QString ip;
    quint16 port;
    Moderator *mod;
};

#endif // COSC_H
