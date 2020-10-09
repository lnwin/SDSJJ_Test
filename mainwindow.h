#ifndef MAINWINDOW_H
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
#include <HDCamera.h>
#include <configuration.h>

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
    void USBCameraint();   
    QtVideoCapture* surface_;   
public slots:
    void showImage(QImage );


private slots:
    void on_PortButton_clicked();
    void on_senddatabutton_clicked();
    void on_pointfilepushButton_clicked();   
    void on_Scanningbutton_clicked();
    void on_openCamera_clicked();
    void on_show3D_clicked();
    void on_MaxGLView_clicked();   
    void receivedFromThread(int);
    void receivedSetTabWidgt2Camera(int);
    void on_OpenHDcamera_clicked();
    void receiveQimageFromHD(QImage);
    void receiveHDcamerastate(int);   
    void on_openconfigurationfor_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    GL_Image *glImage;
    QImage *Picture;
    OpenGLshow *OpenGL;
    HDCamera *HDCamera;   
    Configuration *ConfigForm;
    void  Delay_MSec(unsigned int );
    void  MesStatusBar();
    QLabel *Scanner_Model;
    QLabel *system_time;
    QLabel *system_status;
signals:
    void sendfilepath2Thread(QString);
    //void sendfilepath2opengl(QString);
    void sendfilename2opengl(QString);



};


#endif // MAINWINDOW_H
