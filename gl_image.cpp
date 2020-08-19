#include "gl_image.h"
#include "QPainter"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include<QTime>
QImage AK;
QPainter GLpainter;
cv::Mat img;
cv::Mat gray(640,480,CV_8UC1,cvScalar(0));
float W_x,W_y,W_z,glscanning=false;
GL_Image::GL_Image(QWidget* parent):
    QOpenGLWidget(parent)
{

}
GL_Image::~GL_Image()
{

}
void GL_Image::pictureFromcamera(QImage ss)
{
    AK = ss;
}
void  GL_Image::receivescanningsignal(bool signal)
{
    glscanning = signal;

}
;
void GL_Image::paintEvent(QPaintEvent *e)
{
     if(GLpainter.begin(this))
  {

   GLpainter.setRenderHint(QPainter::Antialiasing);
   GLpainter.drawImage(QPoint((this->width()-640)/2, (this->height()-480)/2), AK);//这个函数有点问题，可能在函数的调用上访问冲突;
   if(glscanning)//整个if内过程耗时1ms
   {
     img = workThreadGl->QImage2cvMat(AK);
     if(!img.empty())
     {

       cvtColor(img, gray,cv::COLOR_BGR2GRAY);
       workThreadGl->cloudDataProcessing(gray);

    }

   }
    GLpainter.end();

   // qDebug()<<img11;
   }
}


