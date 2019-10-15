#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}
bool Login::CreateMysql(Login *login)
{

       QSqlDatabase sqldb;
      if(QSqlDatabase::contains("qt_sql_default_connection"))
           sqldb = QSqlDatabase::database("qt_sql_default_connection");
        else
           sqldb = QSqlDatabase::addDatabase("QMYSQL");
        QString dataname,password;
        dataname=login->ui->lineEdit->text();
        password=login->ui->lineEdit_2->text();
        sqldb.setHostName("localhost");
        sqldb.setDatabaseName("patient");
        sqldb.setUserName("root");
        sqldb.setPassword("123");
        sqldb.setPort(3306);
        if(!sqldb.open())
        {
            QMessageBox::critical(0,QObject::tr("后台数据库连接失败!")
                                  ,"无法创建连接，请检验排查故障后重启程序",QMessageBox::Cancel);
            return false;
        }
        sqldb.close();
        return true;
}


Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_3_clicked()
{
    if(!CreateMysql(this))
    {
            return ;
    }
    ma=new MainWindow;
    ma->setWindowTitle("后台界面");
    ma->show();
    this->close();
}

void Login::on_pushButton_4_clicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
}
