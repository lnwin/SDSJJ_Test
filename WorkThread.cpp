#include<WorkThread.h>
#include <QImage>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QTime>
#include <QCoreApplication>
#include <QFile>
#include <QDateTime>
#include <QList>
#include <QTextStream>
#include<QMutex>
QTime counttime;
int count_CloudDataProcess =0;
cv::Mat originalMat_gray(640,480,CV_8UC1,cvScalar(0));
bool turnleft;//左转向开关
QString filename;
QList <QString> cloudpointlist;
QList <float> cloudpointlist_f;

WorkThread::WorkThread()
{

};
//---------------------------------------------------------------------------------------Mat和QImage转换函数
cv::Mat WorkThread::QImage2cvMat(QImage image)// ----------------------------------------QImage转Mat
{
   cv::Mat mat;
   switch (image.format())
    {
    case QImage::Format_ARGB32:
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32_Premultiplied:
        mat = cv::Mat(image.height(), image.width(), CV_8UC4, (void*)image.constBits(), image.bytesPerLine());
        break;
    case QImage::Format_RGB888:
        mat = cv::Mat(image.height(), image.width(), CV_8UC3, (void*)image.constBits(), image.bytesPerLine());
        cv::cvtColor(mat, mat, CV_BGR2RGB);
        break;
    case QImage::Format_Indexed8:
        mat =cv:: Mat(image.height(), image.width(), CV_8UC1, (void*)image.constBits(), image.bytesPerLine());
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
void WorkThread::receivefilepath(QString DK)//-------------------------------------------接收文件路径函数
{
    filename =DK;

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
    while (count_CloudDataProcess<100)
    {

             //imageCapture->capture("C:/Users/NING MEI/Desktop/QT/"+QString::number(count_CloudDataProcess)+".jpg"); enable
             //Delay_MSec(20);//采用
             //cloudDataProcessing(mat);
             count_CloudDataProcess++;
             emit sendMessage2Main(count_CloudDataProcess);

    }
    qDebug()<<counttime.elapsed();
    qDebug()<<"结束循环";
    count_CloudDataProcess=0;
  //emit setTabWidgt2Camera(1);
}
void WorkThread::cloudDataRecord()//-----------------------------------------------------点云数据存储函数
{


    QDateTime filedate;
    filename=filename+"/"+filedate.currentDateTime().toString("yyyy.MM.dd&hh_mm_ss")+".txt";
    QFile cloudfile(filename);
    QTextStream stream(&cloudfile);
    if(!cloudfile.exists())
             {
                 cloudfile.open(QIODevice::WriteOnly | QIODevice::Text );
                 foreach( QString DKk , cloudpointlist)
                 {
                      stream<<DKk<<"\n";
                 }

             }
    else
    {
        cloudfile.open(QIODevice::WriteOnly | QIODevice::Text|QIODevice::Append);

        foreach( QString DKk , cloudpointlist)
        {
             stream<<DKk<<"\n";

         }

    }

    cloudpointlist.clear();   

}
