#ifndef COSSAGENT_H
#define COSSAGENT_H

#include <QDialog>
#include "server.h"

namespace Ui {
class ServerAgent;
}

class ServerAgent : public QDialog
{
    Q_OBJECT

public:
    explicit ServerAgent(Server *s, QWidget *parent = 0);
    ~ServerAgent();
signals:

private slots:
    void on_pushButton_server_clicked();
    void on_pushButton_send_clicked();
    void on_pushButton_switch_green_red_clicked();
    void onConnected();

    void onReaded(QByteArray ba);

    void setRed();
    void setGreen();

private:
    Ui::ServerAgent *ui;
    Server *server;
};

#endif // COSSAGENT_H
