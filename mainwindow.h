#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QFileDialog>
#include<optional>
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

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
//----------------------------------------------------------------------
class WorkThread:public QThread
{
    Q_OBJECT
  public:
    WorkThread();

    QCameraViewfinder *viewfinder;//取景器
    QCameraImageCapture *imageCapture;//图片捕捉器
    QtVideoCapture *QtVIDEO;
    cv::Mat matframe;//opencv 图片暂存
    cv::VideoCapture *cvVideocapture; //opencv 视频类
    cv::Mat QImage2cvMat(QImage);
    QImage cvMat2QImage(cv::Mat & mat);
    void run();
    void cloudDataProcessing();
    void cloudDataRecord();
    void Delay_MSec(unsigned int );
    signals:
    void sendMessage2Main(int);
    void setTabWidgt2Camera(int);

};
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
    //void captureImage();
   // void displayImage(int,QImage);
   // void saveImage();
    void searchCamera();

    QtVideoCapture* surface_;
    QCamera *camera;//相机

private slots:
    void on_PortButton_clicked();
    void on_senddatabutton_clicked();
    void on_pointfilepushButton_clicked();
    void on_intCamera_clicked();
    void on_captureimage_clicked();
    void on_closeCamera_clicked();
    void on_loadseting_clicked();
    void receivedFromThread(int);
    void receivedSetTabWidgt2Camera(int);
    void receivedCapture2QImage(QImage);
    void showImage(QImage );

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;


    void opencvreadimage();




static QString getOpenFileName(   //定义点云文件路径属性
         QWidget *parent = Q_NULLPTR,
         const QString &caption = QString(),
         const QString &dir = QString(),
         const QString &filter = QString(),
          QString *selectedFilter = Q_NULLPTR);


};
#endif // MAINWINDOW_H
