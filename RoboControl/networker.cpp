#include "networker.h"
#include <QMessageBox>

#include <QDebug>

Networker::Networker():ip("127.0.0.1"), port(3000)
{
    tcpSock = new QTcpSocket(this);

    //connect(tcpSock, SIGNAL(readyRead()), this, SLOT(this->read()));
    connect(tcpSock, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

    qDebug()<< "Connect " <<ip <<":" <<port;
    tcpSock->connectToHost(ip, port);
    if( tcpSock->state() != QAbstractSocket::ConnectedState){
        connected = NOTCONNECTED;
        return;
    }else
        connected = CONNECTED;
}

Networker::Networker(QString ipstr, int porti):ip(ipstr), port(porti)
{
    tcpSock = new QTcpSocket(this);
    qDebug()<< "Connect " <<ip <<":" <<port;

    connect(tcpSock, SIGNAL(readyRead()), this, SLOT(read()));
    connect(tcpSock, SIGNAL(error(QAbstractSocket::SocketError)),
            this, SLOT(displayError(QAbstractSocket::SocketError)));

//    connect(tcpSock, SIGNAL(disconnected()), this, SLOT(disconnected()));
    connect(tcpSock, SIGNAL(connected()), this, SLOT(dispConnected()));

    tcpSock->connectToHost(ip, port);

    qDebug() << tcpSock->state();
    if( tcpSock->state() != QAbstractSocket::ConnectedState){
        connected = NOTCONNECTED;
        return;
    }else
        connected = CONNECTED;
    read();
}

Networker::~Networker()
{
    tcpSock->disconnectFromHost();
    delete tcpSock;
}

void Networker::Reconnect(QString ipstr, int porti)
{
    tcpSock->disconnectFromHost();
    connected = NOTCONNECTED;

    ip = ipstr;
    port = porti;

    qDebug()<< "Reconnect " <<ip <<":" <<port;

    tcpSock->connectToHost(ip, port);
    if( tcpSock->state() != QAbstractSocket::ConnectedState){
        connected = NOTCONNECTED;
        return;
    }else
        connected = CONNECTED;

    read();
}

void Networker::Write(QString msg)
{
//    QByteArray block;
//    QDataStream out(&block, QIODevice::WriteOnly);
//    out.setVersion(QDataStream::Qt_4_0);

//    out << msg;

    qDebug() << msg /*<< ":"<<block.data()*/;
    tcpSock->write(QByteArray(msg.toAscii()));
    read();

}

void Networker::read()
{
//    QMessageBox::information(NULL, tr("!!!"), tr("Read"));
    QTcpSocket* sock = (QTcpSocket*)sender();
    qDebug() << sock->readAll();
    QDataStream in(tcpSock);
    in.setVersion(QDataStream::Qt_4_0);

}

 void Networker::disconnected()
 {
     QMessageBox::information(NULL, tr("Robo"),
                              tr("Disconnected"));
 }

 void Networker::dispConnected()
 {
     QMessageBox::information(NULL, tr("Robo"),
                              tr("Connected"));
 }


void Networker::displayError(QAbstractSocket::SocketError socketError)
{
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        break;
    case QAbstractSocket::HostNotFoundError:
        QMessageBox::information(NULL, tr("Fortune Client"),
                                 tr("The host was not found. Please check the "
                                    "host name and port settings."));
        break;
    case QAbstractSocket::ConnectionRefusedError:
        QMessageBox::information(NULL, tr("Fortune Client"),
                                 tr("The connection was refused by the peer. "
                                    "Make sure the fortune server is running, "
                                    "and check that the host name and port "
                                    "settings are correct."));
        break;
    default:
        QMessageBox::information(NULL, tr("Fortune Client"),
                                 tr("The following error occurred: %1.")
                                 .arg(tcpSock->errorString()));
    }
}
