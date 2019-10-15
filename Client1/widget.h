#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QTcpSocket>
#include<QMessageBox>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
      void onConnected();
       void onConnected1();
       void onReadPhoto();
       void onRead();
       void on_pushButton_clicked();

private:
    Ui::Widget *ui;
     QTcpSocket *socket;
     QTcpSocket *socket1;
};

#endif // WIDGET_H
