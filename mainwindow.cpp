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
QImage originalQIimage;
bool watching=false;
bool processing=false;
bool cameraIsStarted=false;
bool turnleft;
//QtVideoSurface = new QtVideoCapture;
//---------------------------------------------------------------------------------------激光测距参数
float PixelSize, f, baseline,step_angle,Laser_angle,Math_angle,sumXRGB,sumX,Pic_x,Pic_y;
float yaw_angle,laser_to_dist_pt,laser_to_current_pt,laser_to_center_pt,center_distance,real_center_distance,real_distance,pitch_angle,pitch_distance,center2target,World_x,World_y,World_z;
const float pic_wight = 640;
const float pic_height = 400;
const float rotation_r = 430;
const float PI = 3.14159265;
int Maxindex_n,MaxRGB,RGB;
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
     Qtthread-> camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
     QCameraViewfinderSettings set;
     set.setResolution(1280,720);
     Qtthread-> camera->setCaptureMode(QCamera::CaptureStillImage);
     Qtthread-> camera->setViewfinderSettings(set);
     surface_ =new QtVideoCapture();
     Qtthread->  camera->setViewfinder(surface_);   
    //------------------------------------------------Qt摄像参数载入   

    connect(Qtthread,SIGNAL(sendMessage2Main(int)),this,SLOT(receivedFromThread(int)));//进度条信号连接
    connect(Qtthread,SIGNAL(setTabWidgt2Camera(int)),this,SLOT(receivedSetTabWidgt2Camera(int)));//Camera窗体切换信号连接
    connect(surface_, SIGNAL(frameAvailable(QImage)), this, SLOT(showImage(QImage)));//QtVideo显示信号链接


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
void MainWindow::on_closeCamera_clicked()//----------------------------------------------关闭Qt摄像头按钮
{
    watching=false;
    processing=true;
    //Qtthread->camera->stop();

}
void MainWindow::on_openCamera_clicked()//-----------------------------------------------打开Qt摄像头按钮
 {
     watching=true;
     processing=false;
     if(!cameraIsStarted)
     {
         Qtthread->camera->start();
         cameraIsStarted=true;
     }


 }
void MainWindow::on_Scanningbutton_clicked() //------------------------------------------开启扫描按钮
{

    ui->tabWidget->setCurrentIndex(0);
    watching=false;
    processing=true;
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
        if(processing)
       {
        originalQIimage =image;
        transformmat = Qtthread->QImage2cvMat(originalQIimage);
        cvtColor(transformmat, originalMat_gray,COLOR_BGR2GRAY);
       }
        if(watching)
       {
        emit frameAvailable(image);
       }// qDebug()<<originalQIimage;
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
     // QImage tempImage = image.scaled(ui->label_2->size(), Qt::KeepAspectRatio);
     // ui->label_2 ->setPixmap(QPixmap::fromImage(tempImage));
     // QImage rgba = image.rgbSwapped(); //qimage加载的颜色通道顺序和opengl显示的颜色通道顺序不一致,调换R通道和B通道
     //glImage->setImageData(rgba.bits(), rgba.width(), rgba.height());
     // glImage->repaint();



}
void MainWindow::on_loadseting_clicked() //----------------------------------------------载入参数按钮
{
    PixelSize = ui->pixelSizeLine->text().toFloat();
    f = ui->focalLine->text().toFloat();
    baseline=ui->baseLineLine->text().toFloat();
    step_angle = ui->stepAngleLine->text().toFloat()*PI/180;
    Laser_angle = ui->laserAngleLine->text().toFloat()*PI/180;
    RGB = ui->rgeLine->text().toInt();
    Math_angle =0;
}
void WorkThread::Delay_MSec(unsigned int msec)//-----------------------------------------延时函数
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < _Timer )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void WorkThread::run()//-----------------------------------------------------------------Qthread单线程摄像帧处理函数
{

    counttime.start();
    while (count_CloudDataProcess<1)
    {


           //imageCapture->capture("C:/Users/NING MEI/Desktop/QT/"+QString::number(count_CloudDataProcess)+".jpg"); enable
           // Delay_MSec(20);//采用
             cloudDataProcessing();
             count_CloudDataProcess++;
             emit sendMessage2Main(count_CloudDataProcess);


       //  }

    }

    qDebug()<<counttime.elapsed();
    qDebug()<<"结束循环";
    count_CloudDataProcess=0;
  //emit setTabWidgt2Camera(1);
}
void WorkThread::cloudDataProcessing()//-------------------------------------------------点云数据处理函数
{

     Math_angle=Math_angle+step_angle;
     uchar* data =originalMat_gray.ptr(0);
     uchar* dataSum =originalMat_gray.ptr(0);
      for(int i=0;i<pic_height;i++)
     {
       Maxindex_n = 0 ;
       MaxRGB =*data;
       sumXRGB = 0;
       sumX = 0;
       for (int j = 0; j < pic_wight; j++)
      {
         if (*data > MaxRGB)
         {
            MaxRGB = *data;
            Maxindex_n = j;
         }
            data++;
      }
       for(int k = 0; k < 640; k++)
       {
         if (MaxRGB > RGB)
         {
            if (*dataSum == MaxRGB)
            {
                sumXRGB += k * (*dataSum);
                sumX += *dataSum;
            }
         }
         dataSum++;

       }
       if(sumX!=0)
       {
           Maxindex_n = sumXRGB / sumX;
           Pic_x =((pic_wight/2) - Maxindex_n) * PixelSize;
           Pic_y =(i -(pic_height/2)) * PixelSize;
           center_distance = (f * baseline)/(Pic_x+(f/tan(Laser_angle)));
           pitch_angle =atan(Pic_y / f);
           pitch_distance = center_distance/cos(pitch_angle);
           laser_to_dist_pt = center_distance * tan(Laser_angle);
           laser_to_current_pt =sqrt(pitch_distance * pitch_distance + laser_to_dist_pt * laser_to_dist_pt);
           laser_to_center_pt = sqrt(center_distance * center_distance + laser_to_dist_pt * laser_to_dist_pt);
           real_center_distance = sqrt((laser_to_dist_pt - rotation_r) * (laser_to_dist_pt - rotation_r) + center_distance * center_distance);
           yaw_angle = (PI/2)-acos((rotation_r * rotation_r + real_center_distance * real_center_distance - laser_to_center_pt * laser_to_center_pt)/2.0f/rotation_r/real_center_distance);
           real_distance = sqrt((laser_to_dist_pt - rotation_r) * (laser_to_dist_pt - rotation_r) + pitch_distance * pitch_distance);
           center2target = real_distance * cos(pitch_angle);
           if(turnleft)
           {
                 World_x = center2target * sin(yaw_angle + Math_angle);
                 World_z = center2target * cos(yaw_angle + Math_angle);
           }
           else
           {
                World_x = center2target * sin(yaw_angle - Math_angle);
                World_z = center2target * cos(yaw_angle - Math_angle);
           }
                World_y = real_distance *sin(-pitch_angle);

       }
     }



}
void WorkThread::cloudDataRecord()//-----------------------------------------------------点云数据存储函数
{

}





















