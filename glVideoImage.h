#ifndef GLVIDEOIMAGE_H
#define GLVIDEOIMAGE_H

#include <QWheelEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QPainter>
#include <DaVinci.h>

class GL_Image : public QOpenGLWidget
{
    Q_OBJECT

public:
    GL_Image();
    GL_Image(QWidget* parent );
    ~GL_Image();

 protected:
    void paintEvent(QPaintEvent *e);
 private:
    Davinci *Davinci;
public slots:

    void pictureFromcamera(QImage);


};


#endif // GLVIDEOIMAGE_H
