#ifndef CAMERA_H
#define CAMERA_H

#include <QWidget>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QCameraViewfinderSettings>
namespace Ui {
class Camera;
}

class Camera : public QWidget
{
    Q_OBJECT

public:
    explicit Camera(QWidget *parent = nullptr);
    ~Camera();
     void IniCamera();//初始化摄像头
     void IniImageCapture();//初始化图片截取
     QCamera *camera;
     QCameraImageCapture *imagecapture;
private:
    Ui::Camera *ui;
public slots:
    void on_imageCaptured(int,const QImage & );
signals:
    void Image(const QImage &);
};

#endif // CAMERA_H
