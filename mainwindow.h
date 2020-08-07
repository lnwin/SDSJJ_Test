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
#include <glVideoImage.h>
#include <WorkThread.h>

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
    void on_closeCamera_clicked();
    void on_loadseting_clicked();
    void on_openCamera_clicked();
    void receivedFromThread(int);
    void receivedSetTabWidgt2Camera(int);   
    void showImage(QImage );

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;
    GL_Image *glImage;

    void opencvreadimage();

    QImage *Picture;


static QString getOpenFileName(   //定义点云文件路径属性
         QWidget *parent = Q_NULLPTR,
         const QString &caption = QString(),
         const QString &dir = QString(),
         const QString &filter = QString(),
          QString *selectedFilter = Q_NULLPTR);

signals:
    void sendfilename2Thread(QString);
};
#endif // MAINWINDOW_H
