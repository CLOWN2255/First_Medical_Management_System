#include "tcpservier.h"
#include<QMessageBox>

Tcpservier::Tcpservier(QString a)
{
     server=new QTcpServer(this);
     server1=new QTcpServer(this);
     connect(server,SIGNAL(newConnection()),this,
             SLOT(onNewConnect()));
     connect(server1,SIGNAL(newConnection()),this,
             SLOT(onNewConnect1()));
     QHostAddress addr(a);
     server->listen(addr,1200);
     server1->listen(addr,1201);
     if(server->isListening()&&server1->isListening())
     {
       //  QMessageBox::information(0,QObject::tr("监听成功")
         //                      ,"正在监听",QMessageBox::Cancel);
     }
     Find="NULL";
}
void Tcpservier::onNewConnect()
{
    socket=server->nextPendingConnection();
    connect(socket,SIGNAL(readyRead()),this,
            SLOT(onsocketReadyRead()));
}
void Tcpservier::onNewConnect1()
{
    socket1=server1->nextPendingConnection();
    connect(socket1,SIGNAL(readyRead()),this,
            SLOT(onsocketReadyRead1()));
}
void Tcpservier::SendPhoto(QByteArray str)
{
    socket->write(str);
}
void Tcpservier::Send(QString str)
{
    QByteArray arr=str.toUtf8();
    socket1->write(arr);
}

void Tcpservier::onsocketReadyRead()
{
       socket->flush();
       QByteArray arr;
       arr.append((QByteArray)socket->readAll());
       emit Rect_photo(arr);
}
void Tcpservier::onsocketReadyRead1()
{
       Find=socket1->readLine();
       emit  Rect_find();
}
