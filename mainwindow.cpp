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
using namespace std;
using namespace cv;
//---------------------------------------------------------------------------------------参数配置
WorkThread *Qtthread =new WorkThread ();
QList <QCameraInfo>Cameralist;
QString Cameraresolution;
bool Do=true; //线程标志位
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
    searchPort();
    searchCamera();
    //------------------------------------------------Qt摄像参数载入
    Qtthread-> viewfinder =new QCameraViewfinder(this);
    ui->cameraLayout->addWidget( Qtthread-> viewfinder);
    Qtthread-> camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
    QCameraViewfinderSettings set;
    set.setResolution(640,400);
   // Qtthread->camera->setViewfinderSettings(set);
    Qtthread-> camera->setViewfinder(Qtthread-> viewfinder);
    Qtthread-> camera->start();
    Qtthread-> imageCapture =new QCameraImageCapture(Qtthread-> camera);
    //------------------------------------------------Qt摄像参数载入
    //connect(Cameraresolution,SIGNAL());
}
MainWindow::~MainWindow()
{
    delete ui;
}
WorkThread::WorkThread()
{

};
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
int i =0;
QTime ssd;
void MainWindow::on_captureimage_clicked() //--------------------------------------------捕捉图片按钮
{

    Qtthread->start();

}
//---------------------------------------------------------------------------------------Mat和QImage转换函数
cv::Mat MainWindow::QImage2cvMat(QImage image)// ----------------------------------------QImage转Mat
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
QImage MainWindow::cvMat2QImage(cv::Mat& mat)//----------------------------------------- Mat 转 QImage
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
void MainWindow:: opencvreadimage()//----------------------------------------------------读取cv摄像帧函数
{

    // cvVideocapture->read(matframe);

    // QImage Qimage = cvMat2QImage(matframe) ;

    //  ui->capturelable->setPixmap(QPixmap::fromImage(Qimage));



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
void WorkThread::run()//-----------------------------------------------------------------Qthread单线程摄像帧处理函数
{
    ssd.start();
    while (i<1000)
    {

        if(imageCapture->isReadyForCapture())
        {
            imageCapture->capture("C:/Users/MIC/Desktop/112/"+QString::number(i)+".jpg");
            i++;
        }

    }
    qDebug()<<ssd.elapsed();
    qDebug()<<"结束循环";
}
void WorkThread::cloudDataProcessing()//-------------------------------------------------点云数据处理函数
{

}
void WorkThread::cloudDataRecord()//-----------------------------------------------------点云数据存储函数
{

}





















