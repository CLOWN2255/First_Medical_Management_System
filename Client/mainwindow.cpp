#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QByteArray>
#include<QStringList>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    socket=new QTcpSocket(this);
    socket->connectToHost("127.0.0.1",1200);
    connect(socket,SIGNAL(readyRead()),this,SLOT(onReadPhoto()));
    connect(socket,SIGNAL(connected()),this,SLOT(onConnected()));
    socket1=new QTcpSocket(this);
    socket1->connectToHost("127.0.0.1",1201);
    connect(socket1,SIGNAL(readyRead()),this,SLOT(onRead()));
    connect(socket1,SIGNAL(connected()),this,SLOT(onConnected1()));
}
void MainWindow::onConnected()
{
    QMessageBox::information(0,QObject::tr("连接成功")
                          ,"1",QMessageBox::Cancel);
}
void MainWindow::onConnected1()
{
    QMessageBox::information(0,QObject::tr("连接成功")
                          ,"正在连接",QMessageBox::Cancel);
}
void MainWindow::onRead()
{

   // QString  str=socket->readLine(); str为空
    ui->textEdit->setText(socket1->readLine());
    QString str=ui->textEdit->toPlainText();
    ui->textEdit->clear();
    QStringList list=str.split(",");
    ui->lineEdit->setText(list.at(1));
    ui->lineEdit_2->setText(list.at(4));
    ui->lineEdit_3->setText(list.at(2));
    ui->lineEdit_4->setText(list.at(5));
    ui->lineEdit_5->setText(list.at(6));
    ui->lineEdit_6->setText(list.at(3));
    ui->lineEdit_7->setText(list.at(0));
    ui->textEdit->setText(list.at(7));

 }
void MainWindow::onReadPhoto()
{
    QPixmap photo;
    QByteArray arr;
    arr.append((QByteArray)socket->readAll());
   // photo.loadFromData(arr,"PNG");
   // ui->label->setPixmap(photo.scaledToHeight(ui->label->size().height()));
    QBuffer buffer(&arr);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"png");
    QImage img=reader.read();
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap::fromImage(img));
    buffer.close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_12_clicked()
{
    QString str=ui->lineEdit_8->text();
    QByteArray arr=str.toUtf8();
    socket1->write(arr);
}

void MainWindow::on_Camera_triggered()
{
    camera=new Camera;
    connect(camera,SIGNAL(Image(const QImage &)),this,SLOT(on_image(const QImage&)));
    camera->show();
    on_picture_triggered();
}

void MainWindow::on_Save_triggered()
{
    Send_photo();
}

void MainWindow::on_noSave_triggered()
{

    camera->camera->stop();
    camera->close();
}
void MainWindow::on_image(const QImage &preview)
{
    QImage image=preview.scaled(ui->label->size(),Qt::KeepAspectRatio,Qt::SmoothTransformation);
    QBuffer buffer;
    QByteArray arr;
    buffer.open(QIODevice::ReadWrite);
    image.save(&buffer,"PNG");
    arr.append(buffer.data());
    buffer.close();
    photo=QPixmap::fromImage(image);
    photo.scaled(ui->label->size(),Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(photo);
    socket->flush();
    this->arr=arr;
}
void MainWindow::Send_photo()
{

    socket->write(arr);
}

void MainWindow::on_picture_triggered()
{
    camera->camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->imagecapture->capture();
}
