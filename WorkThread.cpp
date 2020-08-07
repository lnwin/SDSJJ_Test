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
#include<QTextStream>

QTime counttime;
int count_CloudDataProcess =0;
cv::Mat originalMat_gray(640,480,CV_8UC1,cvScalar(0));
bool turnleft;//左转向开关
QString filename;
QList <QString> cloudpointlist;
//---------------------------------------------------------------------------------------激光测距参数
const float PixelSize =0.004;
const float f = 3.6;
const float baseline = 640;
const float step_angle = 0.02;
const float Laser_angle = 45;
const float pic_wight = 640;
const float pic_height = 400;
const float rotation_r = 430;
const float PI = 3.14159265;
const int RGB = 170;
float Math_angle;
float sumXRGB;
float sumX;
float Pic_x;
float Pic_y;
float yaw_angle,laser_to_dist_pt,laser_to_current_pt,laser_to_center_pt,center_distance,real_center_distance,real_distance,pitch_angle,pitch_distance,center2target;
int Maxindex_n,MaxRGB;

//---------------------------------------------------------------------------------------激光测距参数
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
void WorkThread::receivefilename(QString DK)//-------------------------------------------接收文件路径函数
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


       //  }

    }

    qDebug()<<counttime.elapsed();
    qDebug()<<"结束循环";
    count_CloudDataProcess=0;
  //emit setTabWidgt2Camera(1);
}
void WorkThread::cloudDataProcessing(cv::Mat & mat,float x,float y,float z)//-------------------------------------------------点云数据处理函数
{

     Math_angle=Math_angle+step_angle;
     uchar* data =mat.ptr(0);
     uchar* dataSum =mat.ptr(0);
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
                 x = center2target * sin(yaw_angle + Math_angle);
                 z = center2target * cos(yaw_angle + Math_angle);
           }
           else
           {
                x = center2target * sin(yaw_angle - Math_angle);
                z = center2target * cos(yaw_angle - Math_angle);
           }
                y = real_distance * sin(-pitch_angle);

            cloudpointlist.append( QString::number(x)+","+QString::number(y)+","+QString::number(z));
       }
     }



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
    qDebug() << "写入成功!";
}
