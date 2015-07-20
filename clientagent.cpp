#include "clientagent.h"
#include "ui_clientagent.h"

ClientAgent::ClientAgent(Client *c, QWidget *parent) :
    client(c),
    QDialog(parent),
    ui(new Ui::ClientAgent)
{
    ui->setupUi(this);
    setWindowTitle(tr("Client"));

    if (client->red) {
        setRed();
    } else {
        setGreen();
    }

    // no need to configure
    ui->lineEdit_ip->setEnabled(false);
    ui->lineEdit_port->setEnabled(false);

    // not work before connection established
    ui->pushButton_tx->setEnabled(false);
    ui->pushButton_client_red_green->setEnabled(false);
    ui->lineEdit_tx->setEnabled(false);

    // inbox, not editable
    ui->plainTextEdit_rx->setEnabled(false);
    ui->plainTextEdit_rx->setStyleSheet("background-color: white;"
                                        "font: 24px;");

    connect(client, SIGNAL(readed(QByteArray)),
            this, SLOT(onReaded(QByteArray)));
    connect(client, SIGNAL(setRed()),
            this, SLOT(setRed()));
    connect(client, SIGNAL(setGreen()),
            this, SLOT(setGreen()));
}

ClientAgent::~ClientAgent()
{
    delete ui;
}

void ClientAgent::on_pushButton_connect_clicked()
{
    client->setIpPort(ui->lineEdit_ip->text().simplified(), ui->lineEdit_port->text().toInt());
    client->connectToServer();

    ui->lineEdit_tx->setEnabled(true);
    ui->pushButton_tx->setEnabled(true);
    ui->pushButton_connect->setEnabled(false);
    ui->pushButton_client_red_green->setEnabled(true);
}

void ClientAgent::on_pushButton_tx_clicked()
{
    QString tx = ui->lineEdit_tx->text().simplified();
    if (tx.isEmpty()) {
        return;
    }

    QByteArray ba;
    ba.append(tx);
    client->writeToServer(ba);
    ui->lineEdit_tx->clear();
}

void ClientAgent::onReaded(QByteArray ba)
{
    QString msg(ba);
    ui->plainTextEdit_rx->setPlainText(msg);
}

void ClientAgent::on_pushButton_client_red_green_clicked()
{
    client->red = !client->red;

    if (client->red) {
        emit setRed();
        client->writeRed();
    } else {
        emit setGreen();
        client->writeGreen();
    }

}

void ClientAgent::setGreen()
{
    ui->pushButton_client_red_green->setStyleSheet("background-color: green;");
}

void ClientAgent::setRed()
{
    ui->pushButton_client_red_green->setStyleSheet("background-color: red;");
}
