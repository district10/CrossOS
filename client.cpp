#include "client.h"

Client::Client(QObject *parent) :
    QTcpSocket(parent)
{
    mod = new Moderator;
    red = true;

    connect(this, SIGNAL(readyRead()),
            this, SLOT(readServer()));
    connect(this, SIGNAL(disconnected()),
            this, SLOT(connectToServer()));
}

void Client::writeToServer(QByteArray &ba)
{
    if (!this->isWritable()) { // if not writable, just return
        return;
    }

    if (ba.isEmpty()) {        // if data empty, write a random letter
        ba.append((quint8)('A' + QDateTime::currentMSecsSinceEpoch()%26));
    }

    write(ba);
}

void Client::writeRed()
{
    writeToServer(mod->red());
}

void Client::writeGreen()
{
    writeToServer(mod->green());
}

void Client::setIpPort(QString ip, quint16 port)
{
    this->ip = ip;
    this->port = port;
}

void Client::connectToServer()
{
    connectToHost(this->ip, this->port);
}

void Client::readServer()
{
    QByteArray ba = readAll();

    if (ba == mod->red()) {
        emit setRed();
        red = true;
    }

    if (ba == mod->green()) {
        emit setGreen();
        red = false;
    }

    emit readed(ba);
}
