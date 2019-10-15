#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>
MainWindow::MainWindow() :
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new QSqlTableModel(this);
    model->setTable("Table1");
    model1=new QSqlTableModel(this);
    model1->setTable("Table2");
    model->select();
    model1->select();
    ui->tableView->setModel(model);
    onTableSelectChange(0);
    Map_index();
    //网络
    thr=new Thread("127.0.0.1");
    thr1=new Thread("127.0.0.3");
    thr->start();
    thr1->start();
    connect(thr,SIGNAL(Rect_find(Thread *)),this,SLOT(onRect_find(Thread *)));
    connect(thr1,SIGNAL(Rect_find(Thread *)),this,SLOT(onRect_find(Thread *)));
    connect(thr,SIGNAL(Rect_Photo(QByteArray )),this,SLOT(on_RectPhoto(QByteArray)));
}
void MainWindow::on_RectPhoto(QByteArray arr)
{
    QPixmap photo;
    ui->label->clear();
   // photo.loadFromData(thr->server->arr,"png");
  //  ui->label->setPixmap(photo.scaledToHeight(
                                 //    ui->label->size().height()));
    QBuffer buffer(&arr);
    buffer.open(QIODevice::ReadOnly);
    QImageReader reader(&buffer,"png");
    QImage img=reader.read();
    ui->label->setScaledContents(true);
    ui->label->setPixmap(QPixmap::fromImage(img));
    buffer.close();
    this->arr=arr;
    on_pushButton_8_clicked();//保存照片
}
void MainWindow::onRect_find(Thread *thr)
{

    QMap<QString,int>::iterator it;
    it=map.find(thr->server->Find);
    if(it!=map.end())
    {
       thr->server->SendPhoto(model1->data(
                     model1->index(it.value(),2)).toByteArray());

       thr->server->Send(numbers(it.value()));
    }
}
QString MainWindow::numbers(int a)
{
    QString list;
    list=model->data(model->index(a,0)).toString();
    list.append(",");
    list.append(model->data(model->index(a,1)).toString());
    list.append(",");
    list.append(model->data(model->index(a,2)).toString());
    list.append(",");
    list.append(model->data(model->index(a,3)).toString());
    list.append(",");
    list.append(model->data(model->index(a,4)).toString());
    list.append(",");
    list.append(model->data(model->index(a,5)).toString());
    list.append(",");
    list.append(model->data(model->index(a,6)).toString());
    list.append(",");
    list.append(model1->data(model->index(a,1)).toString());
    return list;
}

void MainWindow::Map_index()
{
   for(int i=0;i<model->rowCount();i++)
    {
       map.insert(model->data(model->index(i,0)).toString(),i);
      // str[i]=model->data(model->index(i,0)).toString();
    }

}
void MainWindow::on_pushButton_12_clicked()
{

    QString snn=ui->lineEdit_8->text();
    QMap<QString,int>::iterator it;
    it=map.find(snn);
    if(it!=map.end())
    {
        onTableSelectChange(it.value());
    }

}

void MainWindow::onTableSelectChange(int row)
{

    QModelIndex index;
    index=model->index(row,1);
    ui->lineEdit->setText(model->data(index).toString());
    index=model->index(row,2);
    ui->lineEdit_2->setText(model->data(index).toString());
    index=model->index(row,5);
    ui->lineEdit_3->setText(model->data(index).toString());
    index=model->index(row,0);
    ui->lineEdit_4->setText(model->data(index).toString());
    index=model->index(row,4);
    ui->lineEdit_5->setText(model->data(index).toString());
    index=model->index(row,3);
    ui->lineEdit_6->setText(model->data(index).toString());
    index=model->index(row,6);
    ui->lineEdit_7->setText(model->data(index).toString());
    index=model1->index(row,1);
   ui->textEdit->setText(model1->data(index).toString());
   ShowPhoto(row);
}
void MainWindow::ShowPhoto(int i)
{
    QPixmap photo;
    QModelIndex index;
    index=model1->index(i,2);
  //  QString name=model1->data(index).toString();
   // photo.loadFromData(model1->data(index).toByteArray(),"PNG");
   // ui->label->setPixmap(photo.scaledToWidth(ui->label->size().width()));
    QByteArray arr=model1->data(index).toByteArray();
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

void MainWindow::on_pushButton_13_clicked()
{
    ui->lineEdit_8->clear();
}
void MainWindow::Open_Mysql()
{
    if(QSqlDatabase::contains("qt_sql_default_connection"))
         sqldb = QSqlDatabase::database("qt_sql_default_connection");
      else
         sqldb = QSqlDatabase::addDatabase("QMYSQL");
      sqldb.setHostName("localhost");
      sqldb.setDatabaseName("patient");
      sqldb.setUserName("root");
      sqldb.setPassword("123");
      sqldb.setPort(3306);
      if(!sqldb.open())
      {
          QMessageBox::critical(0,QObject::tr("后台数据库连接失败!")
                                ,"无法创建连接，请检验排查故障后重启程序",QMessageBox::Cancel);
          return ;
      }
}
void MainWindow::Update_Table()
{
    QSqlQuery query(sqldb);
    QVariant var(arr);
    QMap<QString,int>::iterator it=map.find(thr->server->Find);
    if(it!=map.end())
    {
      QMessageBox::information(0,QObject::tr("提示"),"保存成功");
      QModelIndex index;
      index=model->index(it.value(),1);
      QString name=model->data(index).toString();
      QString sqlstr="update user_profile set picture=? where name=";
      sqlstr.append("'");
      sqlstr.append(name);
      sqlstr.append("'");
      query.prepare(sqlstr);
      query.addBindValue(var);
      if(!query.exec())
        QMessageBox::information(0,QObject::tr("提示"),"照片写入失败");
      Update_View();
      sqldb.close();
    }
}
void MainWindow::Update_View()
{
    QMap<QString,int>::iterator it=map.find(thr->server->Find);
    QSqlRecord cr=model1->record(it.value());
    cr.setValue("picture",arr);
    model1->setRecord(it.value(),cr);
}
void MainWindow::on_pushButton_8_clicked()
{
    Open_Mysql();
    Update_Table();
}
