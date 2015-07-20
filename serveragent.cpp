#include "serveragent.h"
#include "ui_serveragent.h"

ServerAgent::ServerAgent(Server *s, QWidget *parent) :
    server(s),
    QDialog(parent),
    ui(new Ui::ServerAgent)
{
    ui->setupUi(this);
    setWindowTitle(tr("Server"));

    if (server->red) {
        setRed();
    } else {
        setGreen();
    }

    // no need to configure ip/port
    ui->lineEdit_ip->setEnabled(false);
    ui->lineEdit_port->setEnabled(false);
    ui->pushButton_server->setEnabled(false);

    // not work before connection established
    ui->pushButton_send->setEnabled(false);
    ui->pushButton_switch_green_red->setEnabled(false);
    ui->lineEdit_tx->setEnabled(false);

    // inbox, not editable
    ui->plainTextEdit_rx->setEnabled(false);
    ui->plainTextEdit_rx->setStyleSheet("background-color: white;"
                                        "font: 24px;");

    // serve
    if (!server->listen(QHostAddress::Any, 8000)) {
        qDebug() << "Failed to bind to port.";
    } else {
        qDebug() << "Listening...";
    }

    connect(server, SIGNAL(readed(QByteArray)),
            this, SLOT(onReaded(QByteArray)));
    connect(server, SIGNAL(setRed()),
            this, SLOT(setRed()));
    connect(server, SIGNAL(setGreen()),
            this, SLOT(setGreen()));
    connect(server, SIGNAL(connected()),
            this ,SLOT(onConnected()));
}

ServerAgent::~ServerAgent()
{
    delete ui;
}

void ServerAgent::on_pushButton_server_clicked()
{
    // configure ip/port, then serve
}

void ServerAgent::on_pushButton_send_clicked()
{
    QByteArray ba;
    ba.append( ui->lineEdit_tx->text().simplified() );
    server->writeToClient(ba);
    ui->lineEdit_tx->clear();
}

void ServerAgent::onReaded(QByteArray ba)
{
    ui->plainTextEdit_rx->setPlainText(QString(ba));
}

void ServerAgent::on_pushButton_switch_green_red_clicked()
{
    server->red = !server->red;

    if (server->red) {
        setRed();
        server->writeRed();
    } else {
        setGreen();
        server->writeGreen();
    }
}

void ServerAgent::onConnected()
{
    ui->lineEdit_tx->setEnabled(true);
    ui->pushButton_send->setEnabled(true);
    ui->pushButton_switch_green_red->setEnabled(true);
}

void ServerAgent::setRed()
{
    ui->pushButton_switch_green_red->setStyleSheet("background-color: red");
}

void ServerAgent::setGreen()
{
    ui->pushButton_switch_green_red->setStyleSheet("background-color: green");
}
