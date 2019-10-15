#ifndef TCPSERVIER_H
#define TCPSERVIER_H

#include<QTcpServer>
#include<QTcpSocket>
class Tcpservier :public QTcpServer
{
    Q_OBJECT
public:
    Tcpservier(QObject *parent=0)=0;
private:
    QTcpServer *server;
    QTcpSocket *socket;
private slots:
     void onNewConnect();
     QString onsocketReadyRead();
     void Send(QString str);
};

#endif // TCPSERVIER_H
