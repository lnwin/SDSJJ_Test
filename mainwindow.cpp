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
#include <QVariant>
#include <OpenGLShow.h>
#include <QTime>
#include "GenICam/System.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <process.h>
using namespace std;
using namespace cv;

//---------------------------------------------------------------------------------------参数配置
WorkThread *Qtthread =new WorkThread ();
QtVideoCapture *Qtvideo ;
QList <QCameraInfo>Cameralist;
QList<float>setinglist;
QList<float>parametersetinglist;
QString Cameraresolution;
bool Do=true; //线程标志位
Mat transformmat;
QImage originalQIimage;
bool startscan=false;
bool cameraIsStarted=false;
bool HDCamerastarted=false;
const float PI =3.1415926;

GENICAM_StreamSource *pStreamSource = NULL;
GENICAM_Camera *Camerainformation;
int32_t ret;
GENICAM_System *pSystem = NULL;
GENICAM_Camera *pCamera = NULL;
GENICAM_Camera *pCameraList = NULL;
GENICAM_AcquisitionControl *pAcquisitionCtrl = NULL;
uint32_t cameraCnt = 0;
HANDLE threadHandle;
unsigned threadID;
int cameraIndex = -1;
//---------------------------------------------------------------------------------------参数配置
MainWindow::MainWindow(QWidget *parent)// -----------------------------------------------载入函数
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->progressBar->setRange(0,1000);  
    searchPort();
    searchCamera();
    USBCameraint();//载入USB相机   
    serial = new QSerialPort;
    glImage = new GL_Image();
    OpenGL  = new OpenGLshow();
    //----------------------------------------------------------------------------------工业相机载入
    HDCamera = new class HDCamera();//实例化对象
    HDCameraParameterInt();//相机信息获取

    //----------------------------------------------------------------------------------工业相机载入

    connect(Qtthread,SIGNAL(sendMessage2Main(int)),this,SLOT(receivedFromThread(int)));//进度条信号连接
    //connect(Qtthread,SIGNAL(setTabWidgt2Camera(int)),this,SLOT(receivedSetTabWidgt2Camera(int)));//Camera窗体切换信号连接
    connect(surface_, SIGNAL(frameAvailable(QImage)),this, SLOT(showImage(QImage)));//QtVideo显示信号链接
    connect(this, SIGNAL(sendfilepath2Thread(QString)),Qtthread, SLOT(receivefilepath(QString)));//点云文件路径传输
    connect(this, SIGNAL(sendfilename2opengl(QString)),OpenGL, SLOT(receivecloudfilename(QString)));//点云文件名字传输   
    connect(this, SIGNAL(sendseting2opengl(QList<float>)),OpenGL, SLOT(receiveseting(QList<float>)));//配置信息传输   
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_PortButton_clicked()//-----------------------------------------------串口开启函数
{

    if(!serial->isOpen())
    {
    serial->setPortName(ui->portcomboBox->currentText());//设置串口名
    serial->open(QIODevice::ReadWrite);//以读写方式打开串口
    serial->setBaudRate(QSerialPort::Baud115200);//波特率
    serial->setDataBits(QSerialPort::Data8);//数据位
    serial->setParity(QSerialPort::NoParity);//校验位
    serial->setStopBits(QSerialPort::OneStop);//停止位
    QObject::connect(serial,&QSerialPort::readyRead,this,&MainWindow::ReadData);
    ui->textEdit->append("SerialPort Opened");
    ui->PortButton->setText("Close Port");
    }
    else
    {
       serial->close();
       ui->PortButton->setText("Open Port");
       ui->textEdit->append("SerialPort Closed");
    }


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
       // sendfilepath2opengl(srcDirPath);
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
void MainWindow::readcamerainformation()
{
    QList<QSize>Cameresollution =Qtthread->camera->supportedViewfinderResolutions();

    for (const QSize &resolution : Cameresollution)
    {
        ui->Cameraresolution->addItem(QString("%1x%2").arg(resolution.width()).arg(resolution.height()));
    }

    QList<QCamera::FrameRateRange>Cameframrate =Qtthread->camera->supportedViewfinderFrameRateRanges();

    for (const QCamera::FrameRateRange & camerarate : Cameframrate)
    {
        ui->Cameraframerate->addItem(QString::number( camerarate.maximumFrameRate) );
    }
}
void MainWindow::on_openCamera_clicked()//-----------------------------------------------打开关闭Qt摄像头按钮
 {


     if(!cameraIsStarted)
    {
         Qtthread->camera->start();
         cameraIsStarted=true;
         ui->openCamera->setText("Close Camera");
         // ui->openCamera->setStyleSheet("QPushButton{background-color:lightgreen;border-style: inherit ;}");
         ui->camera_light->setStyleSheet("border-image: url(:/new/icon/picture/green.png);");
         readcamerainformation();
    }
    else
     {
         Qtthread->camera->stop();
         cameraIsStarted=false;
         ui->openCamera->setText("Open Camera");        
         //ui->openCamera->setStyleSheet("QPushButton{background-color:red;border-style: double ;}");
         ui->camera_light->setStyleSheet("border-image: url(:/new/icon/picture/gray.png);");

     }



 }
void MainWindow::on_Scanningbutton_clicked() //------------------------------------------开启扫描按钮
{

    if(!startscan)
    {

        if(cameraIsStarted)
        {
          ui->Scanningbutton->setText("Stop Scan");
          startscan=true;
          ui->scan_light->setStyleSheet("border-image: url(:/new/icon/picture/green.png);");
        // OpenGL->show();  //添加这句后数据处理只执行一次就卡死

        }
        else
        {
            QMessageBox mesbox;
            mesbox.setText("please open the camera");
            mesbox.exec();
            return;
        }
    }
    else
    {

          ui->Scanningbutton->setText("Start Scan");
          startscan=false;
          ui->scan_light->setStyleSheet("border-image: url(:/new/icon/picture/gray.png);");
         // Qtthread->cloudDataRecord();
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
void MainWindow::on_MaxGLView_clicked()//------------------------------------------------OpenGL窗口最大化
{

       OpenGL->showMaximized();


};
void MainWindow::on_ProduceMatrix_clicked()//--------------------------------------------生成校准矩阵按钮
{
     parametersetinglist.append(ui->Picture_N->text().toFloat());
     parametersetinglist.append(ui->P_CornerNumber_row->text().toFloat());
     parametersetinglist.append(ui->P_CornerNumber_col->text().toFloat());
     parametersetinglist.append(ui->CellSize_width->text().toFloat());
     parametersetinglist.append(ui->CellSize_height->text().toFloat());
     parametersetinglist.append(ui->Iteration_N->text().toFloat());
     parametersetinglist.append(ui->Accuracy->text().toFloat());
     Camera_Parameter->CameraParameter_ProduceMatrix(parametersetinglist);
     parametersetinglist.clear();
}
void MainWindow::on_ParameterContrast_clicked()//----------------------------------------校准对比测试按钮
{
     Camera_Parameter->CameraParameter_Constrast();
};
void MainWindow::on_OpenHDcamera_clicked()//---------------------------------------------打开工业相机
{
     HDCamera_connect();
}
void MainWindow::receivedFromThread(int ID)//--------------------------------------------进度条传递函数
{
   ui->progressBar->setValue(ID);
}
void MainWindow::receivedSetTabWidgt2Camera(int K)//------------------------------------窗体切换传递函数
{
    //ui->tabWidget->setCurrentIndex(K);
}
cv::Mat XXIMAGE;
cv::Mat XXgray;
int ddd=0;
void MainWindow::showImage(QImage image)//----------------------------------------------图像显示与扫描开启函数
{
     // QTime counttime_1;
     // counttime_1.start();
      QImage rgba =image.mirrored();
      glImage->pictureFromcamera(rgba);   
      ui->openGLWidget_2->update();
     // glImage->show();
     // glImage->update();

    if(startscan)
    {

      XXIMAGE = Qtthread->QImage2cvMat(rgba);
      if(!XXIMAGE.empty())
     {

          //OpenGL->show();
          cvtColor(XXIMAGE, XXgray,cv::COLOR_BGR2GRAY);
          OpenGL->doingfreshen(XXgray);
          ui->openGLWidget->update();
         // Delay_MSec(1);


      }
    }


}
void MainWindow::on_loadseting_clicked() //----------------------------------------------载入参数按钮
{
    setinglist.append( ui->pixelSizeLine->text().toFloat());
    setinglist.append(ui->focalLine->text().toFloat());
    setinglist.append(ui->baseLineLine->text().toFloat());
    setinglist.append(ui->stepAngleLine->text().toFloat()*PI/180);
    setinglist.append( ui->laserAngleLine->text().toFloat()*PI/180);
    setinglist.append( ui->rgeLine->text().toInt());
    emit sendseting2opengl(setinglist);
    setinglist.clear();
    ui->textEdit->append("setting successful");
    //-------------------------------------------------------------------
   // OpenGL->show();
   // OpenGL->show3Dframefrompicturepath(ui->pointfilelineEdit->text());
    //OpenGL->doingfreshen(XXgray);
   //OpenGL->doingfreshen();
   // Qtthread->run();


}
void MainWindow::Delay_MSec(unsigned int msec)//-----------------------------------------延时函数
{
    QTime _Timer = QTime::currentTime().addMSecs(msec);

    while( QTime::currentTime() < _Timer )

    QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
}
void MainWindow::USBCameraint()//USB相机载入
{
    Qtthread-> camera =new QCamera(Cameralist.at(ui->cameralist->currentIndex()));
    QCameraViewfinderSettings set;
    set.setResolution(640,480);
    set.setMinimumFrameRate(30);
    Qtthread-> camera->setCaptureMode(QCamera::CaptureStillImage);
    Qtthread-> camera->setViewfinderSettings(set);
    surface_= new QtVideoCapture();
    Camera_Parameter =new CameraParameter();
   // OpenGL->setGeometry(300,300,1080,720);
    Qtthread-> camera->setViewfinder(surface_);

}
unsigned __stdcall frameGrabbingProc(MainWindow AK)//@@@@@@@@@线程函数需要是静态成员函数@@@@@@@@@@   弄清楚这一点！
{
    int i;
    int32_t ret = -1;
    uint64_t blockId = 0;
    GENICAM_Frame* pFrame;

    for (i = 0; i < 1000; i++)
    {
        if(NULL == pStreamSource)
        {
            return 0;
        }


        ret = pStreamSource->getFrame(pStreamSource, &pFrame, 100);
        if (ret < 0)
        {
            qDebug()<<"getFrame  fail.\n";
            continue;
        }

        ret = pFrame->valid(pFrame);
        if (ret < 0)
        {
            qDebug()<<"frame is invalid!\n";

            //Caution：release the frame after using it
            //注意：使用该帧后需要显示释放
            pFrame->release(pFrame);

            continue;
        }

        qDebug()<<"get frame id = [%u] successfully!\n"<<pFrame->getBlockId(pFrame);

//         cv::Mat image = cv::Mat(pFrame->getImageHeight(pFrame),
//         pFrame->getImageWidth(pFrame),
//         CV_8U,
//         (uint8_t*)((pFrame->getImage(pFrame))));

        // waitKey();
        //Caution：release the frame after using it
        //注意：使用该帧后需要显示释放
        pFrame->release(pFrame);
    }

    return 1;
}
void MainWindow::HDCameraParameterInt()//------------------------------------------------工业相机载入
{

        // discover camera
            //发现设备
            ret = GENICAM_getSystemInstance(&pSystem);
            if (-1 == ret)
            {

                qDebug()<<"pSystem is null.\r\n";
                getchar();
                return ;
            }

            ret = pSystem->discovery(pSystem, &pCameraList, &cameraCnt, typeAll);
            if (-1 == ret)
            {
                 qDebug()<<"discovery device fail.\r\n";
                getchar();
                return ;
            }

            if(cameraCnt < 1)
            {
                qDebug()<<"no camera\r\n";
                getchar();
                return;
            }
             Camerainformation =&pCameraList[0];
             ui->HDcameraList->addItem(Camerainformation->getModelName(Camerainformation));
             ui->textEdit->append("HDCamera init success! ");

}

void MainWindow::HDCamera_connect()//----------------------------------------------------连接工业相机
{

   if(!HDCamerastarted)
   {
    pCamera = &pCameraList[0];
    if(HDCamera->GENICAM_connect(pCamera)==0)
    {
        ui->textEdit->append("**HDCamera open success! **");
    }
    else
    {
         ui->textEdit->append("**HDCamera open failed!**");
    }
    //---------------------------修改曝光
    if(HDCamera->modifyCamralExposureTime(pCamera)==0)
    {
        ui->textEdit->append("**HDCamera modifiy exposure time success!**");
    }
    else
    {
         ui->textEdit->append("**HDCamera modifiy exposure time failed!**");
    }
    //--------------------------创建流对象
    if(HDCamera->GENICAM_CreateStreamSource(pCamera, &pStreamSource)==0)
    {
        ui->textEdit->append("**HDCamera create streamsource success!**");
    }
    else
    {
         ui->textEdit->append("**HDCamera create streamsource failed!**");
         pStreamSource->release(pStreamSource);
    }

    threadHandle = (HANDLE)_beginthreadex(NULL,
                                           0,
                                           (unsigned(__stdcall *)(void *))frameGrabbingProc,
                                           NULL,
                                           CREATE_SUSPENDED,
                                           &threadID);
    if ( threadHandle == 0 )
        {
            qDebug()<<"Failed to create getFrame thread!\n";
            //注意：需要释放pStreamSource内部对象内存
            pStreamSource->release(pStreamSource);
            return;
        }
    //-------------------------------------拉流
    if(HDCamera->GENICAM_startGrabbing(pStreamSource)==0)
    {
        ui->textEdit->append("**HDCamera StartGrabbing success!**");
    }
    else
    {
         ui->textEdit->append("**HDCamera StartGrabbing failed!**");
         pStreamSource->release(pStreamSource);
    }
    //--------------------------------------开启线程
         ResumeThread(threadHandle);

         ui->OpenHDcamera->setText("CloseHDcamera");
         HDCamerastarted=true;
    }

   else
   {
        ui->OpenHDcamera->setText("OpenHDcamera");
        HDCamerastarted=false;
        WaitForSingleObject(threadHandle, INFINITE);
        CloseHandle(threadHandle);
        // stop grabbing from camera
        HDCamera->GENICAM_stopGrabbing(pStreamSource);
       //注意：需要释放pStreamSource内部对象内存
        pStreamSource->release(pStreamSource);
        HDCamera->GENICAM_disconnect(pCamera);
   }

}




















