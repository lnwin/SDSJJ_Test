#include "gl_image.h"
#include "QPainter"
#include <QDebug>
#include <opencv2/opencv.hpp>

QImage AK;
QPainter GLpainter;
cv::Mat img;
cv::Mat gray(640,480,CV_8UC1,cvScalar(0));
float W_x,W_y,W_z;
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
void GL_Image::paintEvent(QPaintEvent *e)
{
     if(GLpainter.begin(this))
  {


   //QImage AKk = AK.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); //占用CPU资源
    GLpainter.setRenderHint(QPainter::Antialiasing);
    GLpainter.drawImage(QPoint(0, 0), AK);//这个函数有点问题，可能在函数的调用上访问冲突;
    img = workThreadGl->QImage2cvMat(AK);

    if(!img.empty())
    {
        cvtColor(img, gray,cv::COLOR_BGR2GRAY);
        workThreadGl->cloudDataProcessing(gray,W_x,W_y,W_z);
        workThreadGl->cloudDataRecord();

    }
    GLpainter.end();

   // qDebug()<<img11;
   }
}


