#ifndef TCPSERVIER_H
#define TCPSERVIER_H
#include<QByteArray>
#include<QTcpServer>
#include<QTcpSocket>
//TCP 服务端连接客户端
class Tcpservier :public QTcpServer
{
    Q_OBJECT
public:
    Tcpservier(QString a);
    void SendPhoto(QByteArray str);//发送照片
    void Send(QString str);//发送病人基本信息
    QString Find;//接受病人的医疗保账号
private:
    QTcpServer *server;
    QTcpServer *server1;
    QTcpSocket *socket;
    QTcpSocket *socket1;
public slots:
     void onNewConnect();//接受连接信号
     void onNewConnect1();
     void  onsocketReadyRead();//接受读取信号
     void  onsocketReadyRead1();
signals:
     void Rect_find();//发送病人信息读取信号
     void Rect_photo(QByteArray);//发送照片读取信号
};

#endif // TCPSERVIER_H
