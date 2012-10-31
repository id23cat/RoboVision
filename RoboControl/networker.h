#ifndef NETWORKER_H
#define NETWORKER_H

#include <QTcpSocket>
#include <QString>

class Networker: public QObject
{
    Q_OBJECT
    QTcpSocket *tcpSock;
    QString ip;
    int port;
public:
    Networker();
    Networker(QString ipstr, int porti);
    ~Networker();
    void Reconnect(QString ipstr, int porti);
    void Write(QString msg);
public slots:
    void displayError(QAbstractSocket::SocketError socketError);
    void read();
    void disconnected();
};

#endif // NETWORKER_H
