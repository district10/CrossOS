#ifndef COSCAGENT_H
#define COSCAGENT_H

#include <QDialog>
#include "client.h"

namespace Ui {
class ClientAgent;
}

class ClientAgent : public QDialog
{
    Q_OBJECT

public:
    explicit ClientAgent(Client *c, QWidget *parent = 0);
    ~ClientAgent();

signals:
    void sendAgain();

private slots:
    void on_pushButton_connect_clicked();
    void on_pushButton_tx_clicked();
    void on_pushButton_client_red_green_clicked();

    void onReaded(QByteArray ba);

    void setGreen();
    void setRed();

private:
    Ui::ClientAgent *ui;
    Client *client;
    char *buf;
};

#endif // COSCAGENT_H
