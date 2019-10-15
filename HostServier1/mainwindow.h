#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QBuffer>
#include <QMainWindow>
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QTimer>
#include<QMessageBox>
#include<QFile>
#include<QMap>
#include<thread.h>
#include<QImageReader>
#include<QSqlRecord>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow();
    ~MainWindow();
    void onTableSelectChange(int row);//在组件上显示查找的病人信息
    void ShowPhoto(int);//在组件上显示病人照片
    void Map_index();//构造map 使得索引号和病人ID进行连接 用于查找
    QString numbers(int a);//在本mainwindow上显示病人信息
    void Open_Mysql();//打开数据库
    void Update_Table();//更新数据库表
    void Update_View();//更新数据库视图
private slots:
    void on_pushButton_13_clicked();//清除查找的病人ID
    void onRect_find(Thread *);//接收读取的信息，并发送该病人的基本信息
    void on_pushButton_12_clicked();//接收病人ID 并进行查找
    void on_RectPhoto(QByteArray);
    void on_pushButton_8_clicked();//保存照片到数据库
private:
    Ui::MainWindow *ui;
    QSqlTableModel *model;
    QSqlTableModel *model1;//照片和病例信息表
    QMap<QString,int> map;
    Thread *thr;
    Thread *thr1;
    QByteArray arr;
    QSqlDatabase sqldb;
};

#endif // MAINWINDOW_H
