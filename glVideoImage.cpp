#include "glVideoImage.h"
#include "QPainter"

GL_Image::GL_Image(QWidget* parent):
    QOpenGLWidget(parent)
{

}
GL_Image::~GL_Image()
{

}

void GL_Image::paintEvent(QPaintEvent *e)
{
    QPainter painter;
    painter.begin(this);
    QImage img;
    img.load("E:/build-3D_Scanner_UnderWater-Desktop_Qt_5_14_2_MSVC2017_64bit-Debug/debug/1.jpg");
    img = img.scaled(width(), height(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    painter.drawImage(QPoint(0, 0), img);
    painter.end();
}
