#ifndef GLVIDEOIMAGE_H
#define GLVIDEOIMAGE_H

#include <QWheelEvent>
#include <QOpenGLWidget>
#include <QTimer>
#include <QPainter>
class GL_Image : public QOpenGLWidget
{
    Q_OBJECT

public:

    GL_Image(QWidget* parent );
    ~GL_Image();

 protected:
    void paintEvent(QPaintEvent *e) override;

};


#endif // GLVIDEOIMAGE_H
