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
#include<math3d.h>
#include <vector>
class OpenGLshow :public QOpenGLWidget,protected QOpenGLFunctions_4_5_Core
{

    Q_OBJECT


public:
    OpenGLshow(QWidget *parent );
    ~OpenGLshow();
     OpenGLshow();
   void  GLclouddataprocess(cv::Mat frame);
   void  show3Dframefrompicturepath(QString picturepath);
   void  doingfreshen(cv::Mat frame);
   void  clearcloud();
   void  draw_area();
   /*** 计算选中的点， 并突出显示 ***/
   void highlight_selected_pts();
   void get_selected_pts_index(std::vector<int> &);
   void set_config(M3DVector3f *pts, int _nr, M3DVector2f _left_bottom, M3DVector2f _right_top, M3DMatrix44f model_view, M3DMatrix44f proj, int viewport[]);

   /*** 还可以添加一些helper函数 ***/
   //-----------------------------------
   void display();
private:
       bool drop_in_area(M3DVector3f x);
       void cal_selected_index();
       M3DVector3f *pts;
       int nr;
       M3DVector2f left_bottom, right_top, left_bottom_2,right_top_2;
       M3DMatrix44f model_view, proj;
       int viewport[4];    
       bool bool_select_area = false;
       std::vector<int> vec_selected_pts_index;

       void countdistance(M3DVector3f,M3DVector3f);
protected:

   void  initializeGL();
   void  resizeGL(int width, int height);
   void  paintGL();
   void  mousePressEvent(QMouseEvent *event);
   void  mouseReleaseEvent(QMouseEvent *event);
   void  mouseMoveEvent(QMouseEvent *event);
   void  wheelEvent(QWheelEvent*event);
   void  readclouddata();
   void  Delay_MSec(unsigned int );


public slots:
   void receivecloudfilename(QString);
   void receiveseting(QList<float>);


};



















#endif // OPENGLSHOW_H
