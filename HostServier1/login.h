#ifndef LOGIN_H
#define LOGIN_H
#include<QSqlDatabase>
#include<QSqlTableModel>
#include<QSqlQuery>
#include<QTimer>
#include<QMessageBox>
#include<QFile>
#include <QWidget>
#include<mainwindow.h>
#include<QProcess>
//登录界面
namespace Ui {
class Login;
}

class Login : public QWidget
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    static bool CreateMysql(Login *);//打开数据库
    Ui::Login *ui;
private slots:
    void on_pushButton_3_clicked();//登录

    void on_pushButton_4_clicked();//取消登录

private:
    MainWindow *ma;
};

#endif // LOGIN_H
