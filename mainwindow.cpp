/*
******************************************************
**   项目:水下3D扫描                                  **
**   工程创建时间:2020.7.26                           **
**   地点:青岛_即墨_蓝谷创业中心_青岛图海纬度科技有限公司    **
**   作者:lzy                                        **
******************************************************
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <QtVideoCapture.h>
#include <QAbstractVideoSurface>
#include <qvideosurfaceformat.h>
#include <QVideoSurfaceFormat>
#include <OpenGLShow.h>
using namespace std;
using namespace cv;

//---------------------------------------------------------------------------------------参数配置
WorkThread *Qtthread =new WorkThread ();
//QtVideoCapture * QtVideo =new QtVideoCapture;
QtVideoCapture *Qtvideo ;
QList <QCameraInfo>Cameralist;
QString Cameraresolution;
bool Do=true; //线程标志位

Mat transformmat;

QImage originalQIimage;
bool startscan=false;
bool cameraIsStarted=false;

//QtVideoSurface = new QtVideoCapture;

//---------------------------------------------------------------------------------------参数配置
MainWindow::MainWindow(QWidget *parent)// -----------------------------------------------载入函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->progressBar->setRange(0,1000);
    searchPort();
    searchCamera();



   //------------------------------------------------Qt摄像参数载入
     Qtthread-> camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
     QCameraViewfinderSettings set;
     set.setResolution(640,480);
     Qtthread-> camera->setCaptureMode(QCamera::CaptureStillImage);
     Qtthread-> camera->setViewfinderSettings(set);
     surface_ =new QtVideoCapture();
     glImage = new GL_Image();
     OpenGL = new OpenGLshow();
     Qtthread-> camera->setViewfinder(surface_);
    //------------------------------------------------Qt摄像参数载入
    //------------------------------------------------PCL显示创建
    // qvtkWidget->initialVtkWidget();
    // qvtkWidget->showPCDcloud();
    //------------------------------------------------PCL显示创建

    connect(Qtthread,SIGNAL(sendMessage2Main(int)),this,SLOT(receivedFromThread(int)));//进度条信号连接
    connect(Qtthread,SIGNAL(setTabWidgt2Camera(int)),this,SLOT(receivedSetTabWidgt2Camera(int)));//Camera窗体切换信号连接
    connect(surface_, SIGNAL(frameAvailable(QImage)),this, SLOT(showImage(QImage)));//QtVideo显示信号链接
    connect(this, SIGNAL(sendfilepath2Thread(QString)),Qtthread, SLOT(receivefilepath(QString)));//点云文件路径传输
    connect(this, SIGNAL(sendfilename2opengl(QString)),OpenGL, SLOT(receivecloudfilename(QString)));//点云文件名字传输
    connect(this, SIGNAL(sendscanningsignal(bool)),glImage, SLOT(receivescanningsignal(bool)));//开启扫描状态信号传输

}
MainWindow::~MainWindow()
{
    delete ui;
}
QtVideoCapture::QtVideoCapture(QObject *parent) : QAbstractVideoSurface(parent)
{

}
GL_Image::GL_Image()
{

}
void MainWindow::on_PortButton_clicked()//-----------------------------------------------串口开启函数
{

    serial = new QSerialPort;
    serial->setPortName(ui->portcomboBox->currentText());//设置串口名
    serial->open(QIODevice::ReadWrite);//以读写方式打开串口
    serial->setBaudRate(QSerialPort::Baud115200);//波特率
    serial->setDataBits(QSerialPort::Data8);//数据位
    serial->setParity(QSerialPort::NoParity);//校验位
    serial->setStopBits(QSerialPort::OneStop);//停止位
    QObject::connect(serial,&QSerialPort::readyRead,this,&MainWindow::ReadData);
    ui->textEdit->append("串口开启成功！");
}
void MainWindow::on_senddatabutton_clicked()//-------------------------------------------串口发送按钮
{
    SendData();
}
void MainWindow::on_pointfilepushButton_clicked()//--------------------------------------点云路径选择
{

    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "请选择点云存储路径", "/");
    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
        ui->pointfilelineEdit->setText(srcDirPath) ;
        sendfilepath2Thread(srcDirPath);
    }
}
void MainWindow::ReadData()//------------------------------------------------------------串口读取函数
{
    QByteArray buf;
    buf = serial->readAll();
    if(!buf.isEmpty())
    {

        QString str = ui->textEdit->toPlainText();
        str+=tr(buf);
        ui->textEdit->clear();
        ui->textEdit->append(str);
    }
    buf.clear();
}
void MainWindow::SendData()//------------------------------------------------------------串口发送函数
{

    QByteArray senddata;
    senddata.resize(7);
    senddata[0]=0x11;
    senddata[1]=0x11;
    senddata[2]=0x11;
    senddata[3]=0x11;
    senddata[4]=0x11;
    senddata[5]=0x11;
    senddata[6]=0x11;
    serial->write(senddata);
}
void MainWindow::searchPort()//----------------------------------------------------------串口搜索函数
{
    foreach (const QSerialPortInfo &info,QSerialPortInfo::availablePorts())
    {
        QSerialPort serial;
        serial.setPort(info);
        if(serial.open(QIODevice::ReadWrite))
        {
            ui->portcomboBox->addItem(serial.portName());
            serial.close();

        }
    }
}
void MainWindow::searchCamera()//--------------------------------------------------------摄像头搜索函数
{

    Cameralist = QCameraInfo::availableCameras();
    for (int i = 0; i < Cameralist.size(); i++)
    {

        ui->cameralist->addItem( Cameralist.at(i).description());  //获取设备名

    }

}
void MainWindow::on_closeCamera_clicked()//----------------------------------------------关闭Qt摄像头按钮
{

    //processing=true;   
   Qtthread->camera->stop();
   cameraIsStarted=false;
   Qtthread->cloudDataRecord();

}
void MainWindow::on_openCamera_clicked()//-----------------------------------------------打开Qt摄像头按钮
 {


     if(!cameraIsStarted)
    {
         Qtthread->camera->start();
         cameraIsStarted=true;
     }


 }
void MainWindow::on_Scanningbutton_clicked() //------------------------------------------开启扫描按钮
{

    if(!startscan)
    {
          sendscanningsignal(true);
          ui->Scanningbutton->setText("Stop Scan");
          startscan=true;
    }
    else
    {
          sendscanningsignal(false);
          ui->Scanningbutton->setText("Start Scan");
          startscan=false;
          Qtthread->cloudDataRecord();
    }

}
void MainWindow::on_show3D_clicked()
{

    QString  srcDirPath = QFileDialog::getOpenFileName( this, "请选择点云文件", "/");
    if (srcDirPath.isEmpty())
    {
        return;
    }
    else
    {
      sendfilename2opengl(srcDirPath);
    }
};
bool QtVideoCapture::isFormatSupported(const QVideoSurfaceFormat & format) const
{
    return QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat()) != QImage::Format_Invalid && !format.frameSize().isEmpty() && format.handleType() == QAbstractVideoBuffer::NoHandle;
}
bool QtVideoCapture::start(const QVideoSurfaceFormat &videoformat)
{
    //qDebug() << QVideoFrame::imageFormatFromPixelFormat(videoformat.pixelFormat());              //格式是RGB32
    if(QVideoFrame::imageFormatFromPixelFormat(videoformat.pixelFormat()) != QImage::Format_Invalid && !videoformat.frameSize().isEmpty()){
        QAbstractVideoSurface::start(videoformat);
        return true;
    }
    return false;
}
void QtVideoCapture::stop()
{
    QAbstractVideoSurface::stop();
}
bool QtVideoCapture::present(const QVideoFrame &frame)//-----------------------------------自动捕获帧函数
{
    if (frame.isValid())
    {
        QVideoFrame cloneFrame(frame);
        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
        const QImage image(cloneFrame.bits(),
                           cloneFrame.width(),
                           cloneFrame.height(),
                           QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
        emit frameAvailable(image);


        cloneFrame.unmap();
        return true;
    }

    return false;
}
QList<QVideoFrame::PixelFormat> QtVideoCapture::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const//-----格式设置
{
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()<< QVideoFrame::Format_RGB32<< QVideoFrame::Format_ARGB32<< QVideoFrame::Format_ARGB32_Premultiplied<< QVideoFrame::Format_RGB565<< QVideoFrame::Format_RGB555;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }

}
void MainWindow::opencvreadimage()//----------------------------------------------------读取cv摄像帧函数
{

    // cvVideocapture->read(matframe);

    // QImage Qimage = cvMat2QImage(matframe) ;

    //  ui->capturelable->setPixmap(QPixmap::fromImage(Qimage));



}
void MainWindow::receivedFromThread(int ID)//--------------------------------------------进度条传递函数
{
   ui->progressBar->setValue(ID);
}
void MainWindow::receivedSetTabWidgt2Camera(int K)//------------------------------------窗体切换传递函数
{
    ui->tabWidget->setCurrentIndex(K);
}
void MainWindow::showImage(QImage image)//----------------------------------------------图像显示函数
{

      QImage rgba =image.mirrored();
      glImage->pictureFromcamera(rgba);
      ui->openGLWidget_2->update();


}
void MainWindow::on_loadseting_clicked() //----------------------------------------------载入参数按钮
{
//    PixelSize = ui->pixelSizeLine->text().toFloat();
//    f = ui->focalLine->text().toFloat();
//    baseline=ui->baseLineLine->text().toFloat();
//    step_angle = ui->stepAngleLine->text().toFloat()*PI/180;
//    Laser_angle = ui->laserAngleLine->text().toFloat()*PI/180;
//    RGB = ui->rgeLine->text().toInt();
//    Math_angle =0;
     //
}





















