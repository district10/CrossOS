#include "serveragent.h"
#include "clientagent.h"
#include "server.h"
#include "client.h"

#include <QApplication>
#include <QMessageBox>

/*
 * [ Server <----> moderator <----> Client ]
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Client c;                                       // client
    ClientAgent ca(&c);                             // client UI
    ca.show();

    Server s;                                       // server
    ServerAgent sa(&s);                             // server UI
    sa.show();

    /*
    QMessageBox msg(QMessageBox::Information,       // README
                    "How to USE this Demo?",
                    "* Click 'Serve'\n"
                    "* Click 'Connect'\n"
                    "* Click the two red/green buttons\n",
                    QMessageBox::Yes, NULL);
    msg.exec();
    */

    return a.exec();
}
