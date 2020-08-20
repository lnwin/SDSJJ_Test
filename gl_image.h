#ifndef GLVIDEOIMAGE_H
#define GLVIDEOIMAGE_H

#include <QWheelEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QPainter>
#include <WorkThread.h>
class GL_Image : public QOpenGLWidget
{
    Q_OBJECT

public:
    GL_Image();
    GL_Image(QWidget* parent );
    ~GL_Image();

    WorkThread *workThreadGl;
signals:
    void sendcloudlist2GLshow(QList <float>);
 protected:
    void paintEvent(QPaintEvent *e);

public slots:

    void pictureFromcamera(QImage);



};


#endif // GLVIDEOIMAGE_H
