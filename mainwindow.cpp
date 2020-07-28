/*
    项目：水下3D扫描
    工程创建时间：2020.7.26
    地点：青岛_即墨_蓝谷创业中心_青岛图海纬度科技有限公司
    作者：lzy
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;

MainWindow::MainWindow(QWidget *parent)// 载入函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    searchPort();
    searchCamera();


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_PortButton_clicked()//串口开启函数
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
 void MainWindow::on_senddatabutton_clicked()//串口发送按钮
 {
      SendData();
 }
 void MainWindow::on_pointfilepushButton_clicked()//点云路径选择
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
void MainWindow::ReadData()//串口读取函数
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
void MainWindow::SendData()//串口发送函数
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
void MainWindow::searchPort()//串口搜索函数
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
 QList <QCameraInfo>Cameralist;
void MainWindow::searchCamera()//摄像头搜索函数
{

    Cameralist = QCameraInfo::availableCameras();
    for (int i = 0; i < Cameralist.size(); i++)
    {

        ui->cameralist->addItem( Cameralist.at(i).description());  //获取设备名

    }

}
  QString Cameraresolution;
  void MainWindow::on_intCamera_clicked()//摄像头加载按钮
  {
      viewfinder =new QCameraViewfinder(this);
      ui->cameraLayout->addWidget(viewfinder);
      ui->capturelable->setScaledContents(true);
      delete camera;
      camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
      camera->setViewfinder(viewfinder);
      camera->start();
      imageCapture = new QCameraImageCapture(camera);
      connect(imageCapture,SIGNAL(imageCaptured(int,QImage)),this,SLOT(cameraImageCaptured(int,QImage)));
      QList<QCameraViewfinderSettings > ViewSets = camera->supportedViewfinderSettings();

       foreach (QCameraViewfinderSettings ViewSet, ViewSets)
       {
             Cameraresolution=QString::number(ViewSet.resolution().width())+"x"+QString::number(ViewSet.resolution().height());
             ui->cameraResolution->addItem(Cameraresolution);
       }

  }

void MainWindow::cameraImageCaptured(int ,QImage image )
{
   ui->capturelable->setPixmap(QPixmap::fromImage(image));
}
void MainWindow::on_captureimage_clicked()
{

   imageCapture->capture();
}
























