#include "glVideoImage.h"
#include "QPainter"
#include <QDebug>
QImage AK;
QPainter GLpainter;
QImage img11;
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
    qDebug()<<AK;
   img11.load("C:/Users/Administrator/Desktop/2.jpg");
  //
    img11 =AK;
    //img11 = img11.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation); //访问冲突
   // GLpainter.drawImage(QPoint(0, 0), img11);//这个函数有点问题，可能在函数的调用上访问冲突
   // GLpainter.setRenderHint(QPainter::Antialiasing);
    //Davinci->DavinciBrush(&GLpainter, e, AK);//一样不访问冲突
    GLpainter.end();

    qDebug()<<img11;
   }
}


