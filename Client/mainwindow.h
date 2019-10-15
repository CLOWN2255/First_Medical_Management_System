#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTcpServer>
#include<QTcpSocket>
#include<camera.h>
#include<QBuffer>
#include<QImageReader>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Send_find(QString );//发送病人基本信息
    void Send_photo();//发送图片
private slots:
    void onConnected();//接受socket连接信号
    void onConnected1();
    void onRead();//接受信息读取信号
    void onReadPhoto();
    void on_Camera_triggered();//打开摄像头
    void on_Save_triggered();//保存照片
    void on_noSave_triggered();//关闭摄像头
    void on_image(const QImage &);//接受照片显示信号，在组件上显示
    void on_picture_triggered();//开始拍照
    void on_pushButton_12_clicked();//发送查找病人的医疗保账号到服务器
private:
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QTcpSocket *socket1;
    Camera *camera;
    QPixmap photo;
    QByteArray arr;
};

#endif // MAINWINDOW_H
