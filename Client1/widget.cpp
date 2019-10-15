#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);
    socket1=new QTcpSocket(this);
    socket->connectToHost("127.0.0.3",1200);
    socket1->connectToHost("127.0.0.3",1201);
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadPhoto()));
    connect(socket1,SIGNAL(readyRead()),this,SLOT(onRead()));
    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    connect(socket1,SIGNAL(connected()),this,SLOT(onConnected()));

}
void Widget::onConnected()
{
    QMessageBox::information(0,QObject::tr("连接成功")
                          ,"3,1200",QMessageBox::Cancel);
}
void Widget::onConnected1()
{
    QMessageBox::information(0,QObject::tr("连接成功")
                          ,"3,1201",QMessageBox::Cancel);
}
void Widget::onReadPhoto()
{
    QPixmap photo;
    QByteArray arr;
    arr.append((QByteArray)socket->readAll());
    photo.loadFromData(arr,"JPG");
    ui->label->setPixmap(photo.scaledToHeight(
                             ui->label->size().height()));

}
void Widget::onRead()
{
    ui->textEdit->setText(socket1->readLine());

}
Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    QString str=ui->lineEdit->text();
    QByteArray arr=str.toUtf8();
    socket->write(arr);
}
