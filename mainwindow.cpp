/*
    项目：水下3D扫描
    工程创建时间：2020.7.26
    地点：青岛_即墨_蓝谷创业中心_青岛图海纬度科技有限公司
    作者：lzy
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)// 载入函数是
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    searchPort();
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_PortButton_clicked()//串口开启函数
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
 void MainWindow::on_senddatabutton_clicked()//串口发送按钮
 {
      SendData();
 }
 void MainWindow::on_pointfilepushButton_clicked()//点云选择
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

