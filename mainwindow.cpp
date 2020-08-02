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
using namespace std;
using namespace cv;
//---------------------------------------------------------------------------------------参数配置
WorkThread *Qtthread =new WorkThread ();
//QtVideoCapture * QtVideo =new QtVideoCapture;
QtVideoCapture *Qtvideo ;
QList <QCameraInfo>Cameralist;
QString Cameraresolution;
bool Do=true; //线程标志位
int count_CloudDataProcess =0;
QTime counttime;
Mat transformmat;
Mat originalMat_gray(640,400,CV_8UC1,Scalar(0));
//Mat originalMat_gray;
QImage originalQIimage;
QMediaPlayer *mediaPlayer = new QMediaPlayer;
//QtVideoSurface = new QtVideoCapture;
//---------------------------------------------------------------------------------------激光测距参数
double PixelSize, f, baseline,step_angle,Laser_angle,RGB,Math_angle;
int Maxindex_n;
//---------------------------------------------------------------------------------------激光测距参数
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
    //Qtthread-> viewfinder =new QCameraViewfinder(this);
     //ui->cameraLayout->addWidget( Qtthread-> viewfinder);
     camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
     QCameraViewfinderSettings set;
     set.setResolution(640,400);
     camera->setCaptureMode(QCamera::CaptureStillImage);
     camera->setViewfinderSettings(set);
     surface_ =new QtVideoCapture();
     camera->setViewfinder(surface_);
     camera->start();
   //Qtthread-> imageCapture =new QCameraImageCapture(Qtthread-> camera);
    //------------------------------------------------Qt摄像参数载入   

    connect(Qtthread,SIGNAL(sendMessage2Main(int)),this,SLOT(receivedFromThread(int)));//进度条信号连接
    connect(Qtthread,SIGNAL(setTabWidgt2Camera(int)),this,SLOT(receivedSetTabWidgt2Camera(int)));//Camera窗体切换信号连接
    connect(surface_, SIGNAL(frameAvailable(QImage)), this, SLOT(receivedCapture2QImage(QImage)));
  //  connect(QtVideoSurface, SIGNAL(onImageOutput(QImage)), this, SLOT(showImage(QImage)));
   //connect(Qtthread->imageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT (receivedCapture2QImage(int,QImage)));//QImage数据传递


}
MainWindow::~MainWindow()
{
    delete ui;
}
WorkThread::WorkThread()
{

};
QtVideoCapture::QtVideoCapture(QObject *parent) : QAbstractVideoSurface(parent)
{

}
void MainWindow::on_PortButton_clicked()//-----------------------------------------------串口开启函数
{
    delete serial;
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
void MainWindow::on_intCamera_clicked()//------------------------------------------------摄像头加载按钮
{
    // viewfinder =new QCameraViewfinder(this);
    // ui->cameraLayout->addWidget( viewfinder);
    // ui->capturelable->setScaledContents(true);
    //  imageCapture =new QCameraImageCapture( camera);
    //  camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
    //  camera->setViewfinder(viewfinder);
    //  camera->start();

    // QList<QCameraViewfinderSettings > ViewSets =  camera->supportedViewfinderSettings();

    //  foreach (QCameraViewfinderSettings ViewSet, ViewSets)
    //  {
    //        Cameraresolution=QString::number(ViewSet.resolution().width())+"x"+QString::number(ViewSet.resolution().height());
    //         ui->cameraResolution->addItem(Cameraresolution);
    //   }

}
void MainWindow::on_closeCamera_clicked()//----------------------------------------------关闭Qt摄像头按钮
{

    Do = false;
    Qtthread->quit();
    Qtthread->wait();
}
void MainWindow::on_captureimage_clicked() //--------------------------------------------捕捉图片按钮
{

    ui->tabWidget->setCurrentIndex(0);
    Qtthread->start();


}
//---------------------------------------------------------------------------------------Mat和QImage转换函数
cv::Mat WorkThread::QImage2cvMat(QImage image)// ----------------------------------------QImage转Mat
{
   cv::Mat mat;
   switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat = Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
        break;
    }
    return mat;
}
QImage WorkThread::cvMat2QImage(cv::Mat& mat)//----------------------------------------- Mat 转 QImage
{
    if (mat.type() == CV_8UC1)                  // 单通道
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        image.setColorCount(256);               // 灰度级数256
        for (int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        uchar *pSrc = mat.data;                 // 复制mat数据
        for (int row = 0; row < mat.rows; row++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }

    else if (mat.type() == CV_8UC3)             // 3通道
    {
        const uchar *pSrc = (const uchar*)mat.data;         // 复制像素
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);    // R, G, B 对应 0,1,2
        return image.rgbSwapped();              // rgbSwapped是为了显示效果色彩好一些。
    }
    else if (mat.type() == CV_8UC4)
    {
        const uchar *pSrc = (const uchar*)mat.data;         // 复制像素
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);        // B,G,R,A 对应 0,1,2,3
        return image.copy();
    }
    else
    {
        return QImage();
    }
}
//---------------------------------------------------------------------------------------Mat和QImage转换函数
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
    if (frame.isValid()) {
        QVideoFrame cloneFrame(frame);
        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
        const QImage image(cloneFrame.bits(),
                           cloneFrame.width(),
                           cloneFrame.height(),
                           QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
       // qDebug() <<  "image" << image;
        emit frameAvailable(image);
        cloneFrame.unmap();
        return true;
    }

    return false;
}
QList<QVideoFrame::PixelFormat> QtVideoCapture::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const//---------------格式设置
{
    if (handleType == QAbstractVideoBuffer::NoHandle) {
        return QList<QVideoFrame::PixelFormat>()<< QVideoFrame::Format_RGB32<< QVideoFrame::Format_ARGB32<< QVideoFrame::Format_ARGB32_Premultiplied<< QVideoFrame::Format_RGB565<< QVideoFrame::Format_RGB555;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }

}
void MainWindow:: opencvreadimage()//----------------------------------------------------读取cv摄像帧函数
{

    // cvVideocapture->read(matframe);

    // QImage Qimage = cvMat2QImage(matframe) ;

    //  ui->capturelable->setPixmap(QPixmap::fromImage(Qimage));



}
void MainWindow::receivedFromThread(int ID)//--------------------------------------------进度条传递函数
{
   ui->progressBar->setValue(ID);
}
void MainWindow:: receivedSetTabWidgt2Camera(int K)//------------------------------------窗体切换传递函数
{
    ui->tabWidget->setCurrentIndex(K);
}
void MainWindow::receivedCapture2QImage(QImage ak47)
 {
         originalQIimage =ak47;

 }
void MainWindow::showImage(QImage image)
{
    QImage tempImage = image.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
    ui->label_2 ->setPixmap(QPixmap::fromImage(tempImage));
}
void WorkThread::Delay_MSec(unsigned int msec)//-----------------------------------------延时函数
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < _Timer )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
int sk=0;
void WorkThread::run()//-----------------------------------------------------------------Qthread单线程摄像帧处理函数
{
    counttime.start();

   // while (count_CloudDataProcess<1)
   // {


       // if(imageCapture->isReadyForCapture())
      //  {
           //imageCapture->capture("C:/Users/NING MEI/Desktop/QT/"+QString::number(count_CloudDataProcess)+".jpg"); enable
           // imageCapture->capture();
           // Delay_MSec(20);//采用
           // originalQIimage.save("C:/Users/NING MEI/Desktop/QT/"+QString::number(count_CloudDataProcess)+".jpg","jpg");
            transformmat = QImage2cvMat(originalQIimage);
            cvtColor(transformmat, originalMat_gray,COLOR_BGR2GRAY);
            uchar* data =originalMat_gray.ptr(0);
          //  for(int i=0;i<640;i++)
           // {

               sk = data[0,0];
           // }
           // cv::imwrite("C:/Users/NING MEI/Desktop/QT/1.jpg",transformmat);
          // transformmat.save("C:/Users/NING MEI/Desktop/QT/"+QString::number(count_CloudDataProcess)+".jpg","jpg");
            count_CloudDataProcess++;
           emit sendMessage2Main(count_CloudDataProcess);
      //  }

   // }

    qDebug()<<counttime.elapsed()<< "++"<<sk;
    qDebug()<<"结束循环";
    count_CloudDataProcess=0;
  // emit setTabWidgt2Camera(1);
}
void MainWindow::on_loadseting_clicked() //----------------------------------------------载入参数按钮
{
    PixelSize = ui->pixelSizeLine->text().toDouble();
    f = ui->focalLine->text().toDouble();
    baseline=ui->baseLineLine->text().toDouble();
    step_angle = ui->stepAngleLine->text().toDouble();
    Laser_angle = ui->laserAngleLine->text().toDouble();
    RGB = ui->rgeLine->text().toDouble();
    Math_angle =0;
}
void WorkThread::cloudDataProcessing()//-------------------------------------------------点云数据处理函数
{

          originalQIimage.save("C:/Users/NING MEI/Desktop/QT/"+QString::number(count_CloudDataProcess)+".jpg");

}
void WorkThread::cloudDataRecord()//-----------------------------------------------------点云数据存储函数
{

}





















