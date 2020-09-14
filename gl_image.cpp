#include "gl_image.h"
#include "QPainter"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include<QTime>
QImage AK;
QPainter GLpainter;
float W_x,W_y,W_z,glscanning=false;
QList<float>listA;
GL_Image::GL_Image(QWidget* parent):
    QOpenGLWidget(parent)
{

}
GL_Image::GL_Image()
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

   GLpainter.setRenderHint(QPainter::Antialiasing);
  // GLpainter.drawImage(QPoint((this->width()-640)/2, (this->height()-480)/2), AK);//这个函数可能有点问题，可能在函数的调用上访问冲突;
   QRect target(0.0, 0.0, 640.0, 480.0); //建立目标矩形，该区域是显示图像的目的地
   QRect source(0.0, 0.0, AK.width(), AK.height());
   GLpainter.drawImage(target,AK, source);
   qDebug()<<"drwa picture ok";
  }
    GLpainter.end();


}


