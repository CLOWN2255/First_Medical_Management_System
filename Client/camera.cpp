#include "camera.h"
#include "ui_camera.h"

Camera::Camera(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Camera)
{
    ui->setupUi(this);
    IniCamera();
    IniImageCapture();
}

void Camera::IniCamera()
{
    QCameraInfo info= QCameraInfo::defaultCamera();
    camera=new QCamera(info,this);
    QCameraViewfinderSettings view;
    view.setResolution(640,480);
    view.setMinimumFrameRate(15.0);
    view.setMaximumFrameRate(30.0);
    camera->setViewfinderSettings(view);
    camera->setViewfinder(ui->widget);
    camera->setCaptureMode(QCamera::CaptureViewfinder);
    camera->start();
}
void Camera::IniImageCapture()
{
    imagecapture=new QCameraImageCapture(camera,this);
    imagecapture->setBufferFormat(QVideoFrame::Format_Jpeg);
    connect(imagecapture,SIGNAL(imageCaptured(int,const QImage &)),this
            ,SLOT(on_imageCaptured(int,const QImage &)));
    //当抓取开始，信号发出，通过 Image(...)函数再一次发出给mainwindow
}
void Camera::on_imageCaptured(int id,const QImage & preview)
{
    Q_UNUSED(id);
    emit Image(preview);
}
Camera::~Camera()
{
    delete ui;
}
