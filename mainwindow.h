﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <optional>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
#include <QAbstractVideoSurface>
#include <QCameraInfo>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QList>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QThread>
#include <QTime>
#include <QBuffer>
#include <QtVideoCapture.h>
#include <gl_image.h>
#include <WorkThread.h>
#include <OpenGLShow.h>
#include <CameraParameter.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
//----------------------------------------------------------------------

//---------------------------------------------------------------------- Qt视频类

//----------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void searchPort();
    void ReadData();
    void SendData();   
    void searchCamera();
    QtVideoCapture* surface_;




private slots:
    void on_PortButton_clicked();
    void on_senddatabutton_clicked();
    void on_pointfilepushButton_clicked();   
    void on_Scanningbutton_clicked();   
    void on_loadseting_clicked();
    void on_openCamera_clicked();
    void on_show3D_clicked();
    void on_MaxGLView_clicked();
    void on_ProduceMatrix_clicked();
    void on_ParameterContrast_clicked();
    void receivedFromThread(int);
    void receivedSetTabWidgt2Camera(int);   
    void showImage(QImage );

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    GL_Image *glImage;
    QImage *Picture;
    OpenGLshow *OpenGL;
    CameraParameter *Camera_Parameter;
    void  Delay_MSec(unsigned int );
signals:
    void sendfilepath2Thread(QString);
    //void sendfilepath2opengl(QString);
    void sendfilename2opengl(QString);
    void sendseting2opengl(QList<float>);

};


#endif // MAINWINDOW_H
