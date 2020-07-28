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
#include <QCameraInfo>
#include <QDebug>
#include <QList>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class QCamera;
class QCameraViewfinder;
class QCameraImageCapture;
class WorkThread:public QThread
{
  public:
    WorkThread();
  private:
    void dataprocessing();

};
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




private slots:
    void on_PortButton_clicked();
    void on_senddatabutton_clicked();
    void on_pointfilepushButton_clicked();
    void on_intCamera_clicked();
    void on_captureimage_clicked();
    void on_closeCamera_clicked();
    void on_loadseting_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    QCamera *camera;//相机
    QCameraViewfinder *viewfinder;//取景器
    QCameraImageCapture *imageCapture;//图片捕捉器
    cv::Mat matframe;//opencv 图片暂存
    cv::VideoCapture *cvVideocapture; //opencv 视频类
    void opencvreadimage();
    cv::Mat QImage2cvMat(QImage);
    QImage cvMat2QImage(cv::Mat & mat);



static QString getOpenFileName(   //定义点云文件路径属性
         QWidget *parent = Q_NULLPTR,
         const QString &caption = QString(),
         const QString &dir = QString(),
         const QString &filter = QString(),
          QString *selectedFilter = Q_NULLPTR);


};
#endif // MAINWINDOW_H
