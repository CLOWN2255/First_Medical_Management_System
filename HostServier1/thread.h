#ifndef THREAD_H
#define THREAD_H
#include<QThread>
#include<tcpservier.h>
class Thread :public QThread
{
    Q_OBJECT
public:
    Thread(QString );
    void run() Q_DECL_OVERRIDE;//运行连接信号函数，使得信息能够传输到mainwindow
   Tcpservier *server;
   QString str;
signals:
   void Rect_find(Thread *);//发送读取信息的信号
   void Rect_Photo(QByteArray);
public slots:
   void onRect_find();//接受读取信息的信号
   void onRect_Photo(QByteArray);
};

#endif // THREAD_H
