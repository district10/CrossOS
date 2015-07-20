#include "server.h"

Server::Server(QObject *parent):
     QTcpServer(parent)
{
    mod = new Moderator;
    red = true;
    server = NULL;

    connect(this, SIGNAL(newConnection()),
            this, SLOT(connectClient()));
}

void Server::writeToClient(QByteArray ba)
{
    if (server && server->isWritable()) {
        server->write(ba);
    }
}

void Server::writeRed()
{
    writeToClient(mod->red());
}

void Server::writeGreen()
{
    writeToClient(mod->green());
}

void Server::readClient()
{
    // MAX FRAME SIZE: 2^13 = 8192 bytes.
    QByteArray ba;
    ba = server->readAll();

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

void Server::connectClient()
{
    // connect server & client
    server = this->nextPendingConnection();
    connect(server, SIGNAL(readyRead()),
            this, SLOT(readClient()));

    // notify UI
    emit connected();

    // send a hello message
    QByteArray ba;
    ba.append("Hello. \n-- from server.");
    server->write(ba);

    // no more connection available
    this->disconnect(SIGNAL(newConnection()));
}
