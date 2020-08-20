#ifndef OPENGLSHOW_H
#define OPENGLSHOW_H

#include <QOpenGLExtraFunctions>
#include <QOpenGLFunctions_4_5_Core>
#include <QOpenGLWidget>
#include <QOpenGLShader>
#include <QOpenGLShaderProgram>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>




class OpenGLshow :public QOpenGLWidget,protected QOpenGLFunctions_4_5_Core
{

    Q_OBJECT


public:
    OpenGLshow(QWidget *parent );
    ~OpenGLshow();
     OpenGLshow();
   void  GLclouddataprocess(cv::Mat frame);
protected:

    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();
   void  mousePressEvent(QMouseEvent *event);
   void  mouseReleaseEvent(QMouseEvent *event);
   void  mouseMoveEvent(QMouseEvent *event);
   void  wheelEvent(QWheelEvent*event);
   void  readclouddata();



public slots:
   void receivecloudfilename(QString);
   //void receivedframe(cv::Mat);


};



















#endif // OPENGLSHOW_H
