#include "thread.h"

Thread::Thread(QString s)
{
    str=s;
    server=new Tcpservier(str);
  //  connect(server,&Tcpservier::Rect_find,this,&Thread::onRect_find);
}
void Thread::onRect_find()
{
    emit Rect_find(this);
}
void Thread::onRect_Photo(QByteArray arr)
{
    emit Rect_Photo(arr);
}
void Thread::run()
{
    connect(server,&Tcpservier::Rect_find,this,&Thread::onRect_find);
    connect(server,&Tcpservier::Rect_photo,this,&Thread::onRect_Photo);
}
