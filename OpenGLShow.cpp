#include<OpenGLShow.h>
#include<QDebug>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <QMouseEvent>
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
#include <gl/GLU.h>
#include <QFileDialog>
#include<QMessageBox>
#include <QTime>
#include <QCoreApplication>
#include <GL/glut.h>
#include<QPainter>
//---------------------------------------------------------------

//---------------------------------------------------------------着色器配置
using namespace std;
float received_x,received_y,received_z,clickX,clickY,ddx,ddy,fov=-75,translate_x=0,translate_y=0,sumX,sumY,sumZ,meanX,meanY,meanZ;
bool clicKtf=false,mouseposition;
QString cloudfilename;
QList<QString>cloudata;
QList<float>cloud_x;
QList<float>cloud_y;
QList<float>cloud_z;
int mousedond_x,mousedond_y;
float yaw=-75,pitch,roll;//中心位置
float xoffset, yoffset,zoffset;
float viewDistance;
bool mousebutton_left;
bool mousebutton_right;
bool mousebutton_mid;

float Addclouddata_x=0,Addclouddata_y=0,Addclouddata_z=0;
//---------------------------------------------------------------------------------------激光测距参数
float PixelSize =0.004;//0.009
float f = 3.6;
float baseline = 100;//100
float step_angle;
float Laser_angle;
const float pic_wight = 640;//640
const float pic_height = 480;//480
const float rotation_r = 50;//50//420
const float PI = 3.14159265;
float RGB = 50;
float Math_angle=0;
float sumXRGB;
float sumXX;
float Pic_x;
float Pic_y;
float yaw_angle,laser_to_dist_pt,laser_to_current_pt,laser_to_center_pt,center_distance,real_center_distance,real_distance,pitch_angle,pitch_distance,center2target;
int Maxindex_n,MaxRGB;
float real_x=0,real_y=0,real_z=0;
//---------------------------------------------------------------------------------------激光测距参数

cv::Mat copymat =cv::Mat(cv::Size(640,480),CV_8UC3);
OpenGLshow::OpenGLshow()
{

}
OpenGLshow::OpenGLshow(QWidget *parent) : QOpenGLWidget(parent)
{

}
OpenGLshow::~OpenGLshow()
{
    cloud_x.clear();
    cloud_y.clear();
    cloud_z.clear();
    this->destroy();
}


void OpenGLshow::initializeGL()
{




    initializeOpenGLFunctions();
    glClearColor(0.0,0.0,0.0,1.0);
    glShadeModel(GL_SMOOTH);
    glClearDepth(1.0);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);



}
int GLwidth,GLheight;
void OpenGLshow::resizeGL(int width, int height)
{

       GLwidth=width;
       GLheight=height;
        glViewport(0,0,width,height);
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
        glLoadIdentity();
        gluPerspective(60.0,width/height,0.1,100000);//设置观察视窗
        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
        glLoadIdentity();

}
static M3DVector3f corners[1000000];
//= {
//    -25, 25, 25,
//    25, 25, 25,
//    25, -25, 25,
//    -25, -25, 25,
//    -25, 25, -25,
//    25, 25, -25,
//    25, -25, -25,
//    -25, -25, -25
//};
void OpenGLshow:: paintGL()
{

/*
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
//    glTranslatef(translate_x,translate_y,fov); //先平移再旋转
//    glRotatef(yaw,0.0,1.0,0.0);
//    glRotatef(pitch,0.0,0.0,1.0);


//        for (int i = 0; i < cloud_x.count(); i++)
//        {
//           // glLoadName(i);//name the points
//            glBegin(GL_POINTS);
//            viewDistance = sqrt(cloud_x[i]*cloud_x[i]+cloud_z[i]*cloud_z[i])/1000.0f;
//            if(viewDistance < 5)
//           {
//                glColor3f (1.0f, 0.5f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//            else if(viewDistance >= 5 && viewDistance < 6)
//           {
//                glColor3f (1.0f, 0.6f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//            else if(viewDistance >= 6 && viewDistance < 7)
//           {
//                glColor3f (1.0f, 0.7f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//            else if(viewDistance >= 7 && viewDistance < 8)
//           {
//                glColor3f (1.0f, 0.8f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 8 && viewDistance < 9)
//           {
//                glColor3f (1.0F, 0.9f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 9 && viewDistance < 10)
//           {
//                glColor3f (1.0f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 10 && viewDistance < 11)
//           {
//                glColor3f (0.9f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 11 && viewDistance < 12)
//           {
//                glColor3f (0.8f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//          else   if(viewDistance >= 12 && viewDistance < 13)
//           {
//                glColor3f (0.7f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 13 && viewDistance < 14)
//           {
//                glColor3f (0.6f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 14 && viewDistance < 15)
//           {
//                glColor3f (0.5f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 15 && viewDistance <16)
//           {
//                glColor3f (0.4f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 16 && viewDistance < 17)
//           {
//                glColor3f (0.3f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//           else  if(viewDistance >= 17 && viewDistance < 18)
//           {
//                glColor3f (0.2f, 1.0f, 0.0f);
//                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//            else  if(viewDistance >= 18)
//            {
//            glColor3f (0.1f, 1.0f, 0.0f);
//            glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
//           }
//          glEnd();
//        }
*/

    display();

    glFlush();

   // this->update();
}
int mouserightclick_times=0;
void OpenGLshow:: mousePressEvent(QMouseEvent *event)
{

         mousedond_x=event->x();
         mousedond_y=event->y();
        if(event->button()==Qt::LeftButton)
        {

               mousebutton_left = true;
               mousebutton_right=false;
               mouserightclick_times=0;
                //-----------------------------------原版代码



        }
        else if(event->button()==Qt::RightButton)
        {
             mousebutton_right=true;
             mousebutton_left = false;
             int width = GLwidth, height = GLheight;
             mouserightclick_times+=1;
             if(mouserightclick_times>2)
             {
                 mouserightclick_times=0;
             }

            if(mouserightclick_times==1)
            {
                m3dLoadVector2(left_bottom, mousedond_x, height - mousedond_y);
                m3dLoadVector2(right_top, mousedond_x+10, height - mousedond_y-10);
                  qDebug()<< "mouse1";

            }
            if(mouserightclick_times==2)
            {

                m3dLoadVector2(left_bottom_2, mousedond_x, height - mousedond_y);
                m3dLoadVector2(right_top_2, mousedond_x+10, height - mousedond_y-10);
                 qDebug()<< "mouse2";
            }





        }
        else if(event->buttons()==Qt::MiddleButton)
        {
            mousebutton_mid=true;
            mousebutton_left = false;
            mousebutton_right = false;
            Addclouddata_x++;
            Addclouddata_y++;
            Addclouddata_z++;

        }



}
void OpenGLshow:: mouseReleaseEvent(QMouseEvent *event)
{
        bool_select_area = false;

        this->update();
}
void OpenGLshow:: mouseMoveEvent(QMouseEvent *event)
{

    if(mousebutton_left)
    {



       xoffset = (event->x()-mousedond_x)/40;
       yaw+=xoffset;
       yoffset = (event->y()-mousedond_y)/40;
       pitch-=yoffset;

    }
    else if(mousebutton_right)
    {
        //----------------------------------------------框选
//              int width = GLwidth, height = GLheight;

//             if( bool_select_area )
//             {
//                 m3dLoadVector2(right_top, event->x() , height - event->y() );
//             }
        //----------------------------------------------框选     
    }
    else if(mousebutton_mid)
    {

             // xoffset=0;
              xoffset = (event->x()-mousedond_x);
              translate_x+=xoffset;
              yoffset = (event->y()-mousedond_y);
              translate_y-=yoffset;
    }
this->update();
}
void OpenGLshow:: wheelEvent(QWheelEvent*event)
 {



    if(event->delta()>0)
     {
         fov+=event->delta();

     }
     if(event->delta()<0)
     {
         fov+=event->delta();
     }

     this->update();
 }
void OpenGLshow:: receivecloudfilename(QString filename)//----------------接受点云文件名
{

    cloudfilename = filename;
    readclouddata();
    this->update();

};
int cornernumber=10;
void OpenGLshow:: readclouddata()//---------------------------------------读取点云数据文件
{
     QFile file(cloudfilename);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
     QTextStream in(&file);
     QString line = "ready";
     cornernumber=0;
     while (!line.isNull())
     {
         line = in.readLine();
         if(!line.isNull())
         {
            cloudata=line.split(',');
            corners[cornernumber][0]=cloudata[0].toFloat();
            corners[cornernumber][1]=cloudata[1].toFloat();
            corners[cornernumber][2]=cloudata[2].toFloat();
         }
         cornernumber++;
     } 

};
void OpenGLshow:: receiveseting(QList<float> setinglist)
{

    PixelSize = setinglist[0];
    f         = setinglist[1];
    baseline  = setinglist[2];
    step_angle= setinglist[3];
    Laser_angle=setinglist[4];
    RGB        =setinglist[5];

}
float Lx=0,Ly=0,Lz=0;//------------------测试数据
int RGBdata=0;
int dataSum=0;
void OpenGLshow:: GLclouddataprocess(cv::Mat frame)//-------------------------------实时帧处理函数
{
     Math_angle=Math_angle+step_angle;
  // cv::Mat AK =frame.clone();
  // mi++;//https://zhidao.baidu.com/question/225669970.html   进行数字的格式化输出
 //  QString b=QString("%1").arg(mi, 4, 10, QChar('0'));
  // cv::imwrite("C:/Users/MIC/Desktop/imwrite/"+b.toStdString()+ ".jpg",AK);
 //  cv::Mat SK = cv::imread("C:/Users/MIC/Desktop/imwrite/"+b.toStdString()+ ".jpg");//对图片进行再读取后数据正确，如果不imread则不正确，不知为何
   int imagetype = frame.type();
   if(imagetype==0)
   {
       RGBdata = frame.ptr<uchar>(0)[0];//-------------单通道适用。--type=0
       dataSum = frame.ptr<uchar>(0)[0];//--------------
   }
   else
   {
       RGBdata = frame.ptr<cv::Vec3b>(0)[0][0];//-------------
       dataSum = frame.ptr<cv::Vec3b>(0)[0][0];//--------------三通道适用--type=16
   }


    for(int i=0;i<pic_height;i++)
    {
      Maxindex_n = 0 ;
      MaxRGB =RGBdata;
      sumXRGB = 0;
      sumXX = 0;
      for (int j = 0; j < pic_wight; j++)
     {
        if (RGBdata > MaxRGB)
        {
           MaxRGB = RGBdata;
           Maxindex_n = j;
        }
        if(imagetype==0)
        {
           RGBdata = frame.ptr<uchar>(i)[j];//------------------
        }
        else
        {
            RGBdata = frame.ptr<cv::Vec3b>(i)[j][0];
        }
     }

      for(int k = 0; k < pic_wight; k++)
      {

          if (MaxRGB > RGB)
        {
           if (dataSum == MaxRGB)
           {
               sumXRGB += k * (dataSum);
               sumXX += dataSum;
           }
        }
          if(imagetype==0)
          {
                dataSum = frame.ptr<uchar>(i)[k];//-------------------------
          }
          else
          {
                dataSum = frame.ptr<cv::Vec3b>(i)[k][0];
          }

      }
      if(sumXX!=0)
      {
          Maxindex_n = sumXRGB / sumXX;
          Pic_x =((pic_wight/2) - Maxindex_n) * PixelSize;
          Pic_y =(i -(pic_height/2)) * PixelSize;
          center_distance = (f * baseline)/(Pic_x+(f/tan(Laser_angle)));
          pitch_angle =atan(Pic_y / f);
          pitch_distance = center_distance/cos(pitch_angle);
          laser_to_dist_pt = center_distance * tan(Laser_angle);
          laser_to_current_pt =sqrt(pitch_distance * pitch_distance + laser_to_dist_pt * laser_to_dist_pt);
          laser_to_center_pt = sqrt(center_distance * center_distance + laser_to_dist_pt * laser_to_dist_pt);
          real_center_distance = sqrt((laser_to_dist_pt - rotation_r) * (laser_to_dist_pt - rotation_r) + center_distance * center_distance);
          yaw_angle = (PI/2)-acos((rotation_r * rotation_r + real_center_distance * real_center_distance - laser_to_center_pt * laser_to_center_pt)/2.0f/rotation_r/real_center_distance);
          real_distance = sqrt((laser_to_dist_pt - rotation_r) * (laser_to_dist_pt - rotation_r) + pitch_distance * pitch_distance);
          center2target = real_distance * cos(pitch_angle);
         // if(turnleft)
         // {
//              real_x = center2target * sin(yaw_angle + Math_angle);
//              real_z = center2target * cos(yaw_angle + Math_angle);
         // }
         // else
         // {

               real_x = center2target * sin(yaw_angle - Math_angle);
               real_z = center2target * cos(yaw_angle - Math_angle);
         // }
               real_y = real_distance * sin(-pitch_angle);
              // Lx+=0.1;Ly+=0.1;Lz+=0.1;
               cloud_x.append(real_x);
               cloud_y.append(real_y);
               cloud_z.append(real_z);





        }
     }


}

void OpenGLshow::doingfreshen(cv::Mat frame)
{

    GLclouddataprocess(frame);
   // this->update();
    Delay_MSec(1);



};
void OpenGLshow::clearcloud()
{
    cloud_x.clear();
    cloud_y.clear();
    cloud_z.clear();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
}

void OpenGLshow::show3Dframefrompicturepath(QString picturepath)//------------------------------------读取历史照片数据
 {
     cloud_x.clear();
     cloud_y.clear();
     cloud_z.clear();
     QDir dir(picturepath);
     QStringList imagelist;
     std::string imagename;
     imagelist<<"*.jpg"<<"*.bmp"<<"*.png";
     dir.setNameFilters(imagelist);
     int imagecuont =dir.count();
     std::string dirpath =picturepath.toStdString();
    this->showMaximized();
     this->update();
         for(int i=0;i<imagecuont;i++)
         {
             try
             {
                 imagename =dirpath+"/"+dir[i].toStdString();
                 cv::Mat SK = cv::imread(imagename);//灰度图像再度以灰度形式读取，像素值会出错
                 //qDebug()<<dir[i];
                 GLclouddataprocess(SK);
                 this->update();
                 Delay_MSec(1);


             }
             catch (exception& e)
             {
                qDebug()<<"cant read :"+QString::fromStdString(imagename);

             }

         }
 }

void OpenGLshow::Delay_MSec(unsigned int msec)//-----------------------------------------延时函数
 {
     QTime _Timer = QTime::currentTime().addMSecs(msec);

     while( QTime::currentTime() < _Timer )

     QCoreApplication::processEvents(QEventLoop::AllEvents, 1);
 }
//-----------------------------------------------------------------------------------------------------以下为opengl框选函数
void OpenGLshow::draw_area()
{
    int width =GLwidth, height = GLheight;
        glMatrixMode(GL_PROJECTION);
        glPushMatrix();
            glLoadIdentity();
            gluOrtho2D(0, width, 0, height);

            glMatrixMode( GL_MODELVIEW );
            glPushMatrix();
            glLoadIdentity();

                /*** 画矩形 ***/
//                glColor4f(1.0, 1.0, 0, 0.2);
//                glEnable( GL_BLEND );
//                glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//                glRectf( m3dGetVectorX(left_bottom), m3dGetVectorY(left_bottom), m3dGetVectorX(right_top), m3dGetVectorY(right_top));


                /*** 画矩形虚线 ***/
                glEnable( GL_LINE_STIPPLE );
                glColor4f(1, 0, 0, 0.5);
                glLineStipple(3, 0xAAAA);

                glBegin( GL_LINE_LOOP );
//                glVertex2f(m3dGetVectorX(left_bottom), m3dGetVectorY(left_bottom));
//                glVertex2f(m3dGetVectorX(right_top), m3dGetVectorY(left_bottom));
//                glVertex2f(m3dGetVectorX(right_top), m3dGetVectorY(right_top));
//                glVertex2f(m3dGetVectorX(left_bottom), m3dGetVectorY(right_top));
              //   m3dLoadVector2(right_top, mousedond_x , height - mousedond_y );
              //   m3dLoadVector2(left_bottom, mousedond_x+20 , height - mousedond_y-20 );
                glVertex2f(m3dGetVectorX(left_bottom), m3dGetVectorY(left_bottom));
                glVertex2f(m3dGetVectorX(right_top), m3dGetVectorY(left_bottom));
                glVertex2f(m3dGetVectorX(right_top), m3dGetVectorY(right_top));
                glVertex2f(m3dGetVectorX(left_bottom), m3dGetVectorY(right_top));
                glEnd();

                if(mouserightclick_times==2)
                {
                    glColor4f(1, 0, 0, 0.5);
                    glLineStipple(3, 0xAAAA);
                    glBegin( GL_LINE_LOOP );
                    glVertex2f(m3dGetVectorX(left_bottom_2), m3dGetVectorY(left_bottom_2));
                    glVertex2f(m3dGetVectorX(right_top_2), m3dGetVectorY(left_bottom_2));
                    glVertex2f(m3dGetVectorX(right_top_2), m3dGetVectorY(right_top_2));
                    glVertex2f(m3dGetVectorX(left_bottom_2), m3dGetVectorY(right_top_2));
                    glEnd();
                    qDebug()<<left_bottom_2[0] <<left_bottom[0];
                }

        glPopMatrix();
        glPopMatrix();
        glDisable( GL_LINE_STIPPLE );
        glDisable( GL_BLEND );
}
float painter_x,painter_y,painter_z;
void OpenGLshow::highlight_selected_pts()
{
    int i = 0;

    //保存上一个opengl状态
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
        glLoadMatrixf(proj);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
            glLoadMatrixf(model_view);

            glPushAttrib(GL_POINT_BIT);
            glPointSize(3);
            glColor4f(0, 1, 1, 1);

            glBegin(GL_POINTS);

            for(i = 0; i != vec_selected_pts_index.size(); i++)
            {
                glVertex3fv(pts[vec_selected_pts_index[i] ]);
                painter_x = pts[vec_selected_pts_index[i]][0];
                painter_y = pts[vec_selected_pts_index[i]][1] ;
                painter_z = pts[vec_selected_pts_index[i]][2];
                qDebug("the points %d x:%f y:%f z: %f  ",i, painter_x,painter_y,painter_z);
            }

            glEnd();

            QPainter painter;
            painter.begin(this);
            QPen pen;
            QBrush brush(QColor(7,7,77),Qt::SolidPattern);
            pen.setColor(Qt::white);
            painter.setPen(pen);
            painter.setBrush(brush);
            painter.drawRect(GLwidth-120,0,120,70);
            painter.end();
            painter.begin(this);
            QPen coordinate_pen;
            coordinate_pen.setColor(Qt::white);
            painter.setPen(coordinate_pen);

            painter.drawText(GLwidth-110,15,"x:"+QString("%1").arg(painter_x));
            painter.drawText(GLwidth-110,30,"y:"+ QString("%1").arg(painter_y));
            painter.drawText(GLwidth-110,45,"z:"+QString("%1").arg(painter_z));
             painter.drawText(GLwidth-110,60,"cover points:"+ QString("%1").arg(vec_selected_pts_index.size()));
            painter.end();

            glPopAttrib();
        glPopMatrix();
        glPopMatrix();

}
void OpenGLshow::get_selected_pts_index( vector<int> &v )
{
    // assign 赋值最快
    v.assign(vec_selected_pts_index.begin(), vec_selected_pts_index.end());
}
void OpenGLshow::set_config( M3DVector3f *_pts, int _nr, M3DVector2f _left_bottom, M3DVector2f _right_top, M3DMatrix44f _model_view, M3DMatrix44f _proj, int _viewport[] )
{
    pts = _pts;
    nr = _nr;
if(mouserightclick_times==1)
   {
    m3dCopyVector2(left_bottom, _left_bottom);
    m3dCopyVector2(right_top, _right_top);
}
if(mouserightclick_times==2)
 {   m3dCopyVector2(left_bottom_2, _left_bottom);
    m3dCopyVector2(right_top_2, _right_top);
  }
    m3dCopyMatrix44(model_view, _model_view);
    m3dCopyMatrix44(proj, _proj);
    memcpy(viewport, _viewport, sizeof(int) * 4);

    /*** 计算被选中的index ***/

    cal_selected_index();
}
void OpenGLshow::cal_selected_index()
{
    vec_selected_pts_index.clear();

    int i = 0;
    for(i = 0; i != nr; i++){

        if( drop_in_area(pts[i]) ){
            vec_selected_pts_index.push_back(i);
        }

    }
}
bool OpenGLshow::drop_in_area( M3DVector3f x )
{
    M3DVector2f win_coord;

    m3dProjectXY(win_coord, model_view, proj, viewport, x);

    if( (win_coord[0] < left_bottom[0] && win_coord[0] <right_top[0]) || (win_coord[0] > left_bottom[0] && win_coord[0] > right_top[0] ))
        return false;

    if( (win_coord[1] < left_bottom[1] && win_coord[1] <right_top[1]) || (win_coord[1] > left_bottom[1] && win_coord[1] > right_top[1] ))
        return false;

    return true;
}

//-----------------------------------------------------------------------------------------------------实现函数



void OpenGLshow:: display(void)
{
   M3DMatrix44f mat_proj, mat_modelview;

   int width = GLwidth, height = GLheight;


   glViewport (0, 0, (GLsizei) width, (GLsizei) height);

   glGetIntegerv(GL_VIEWPORT, viewport);

   glClear (GL_COLOR_BUFFER_BIT);

   glPushAttrib(GL_POLYGON_BIT);
   glPolygonMode( GL_FRONT_AND_BACK, GL_LINE);

   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) width/(GLfloat) height, 1.0, 30000);

   // 获取投影矩阵
   glGetFloatv(GL_PROJECTION_MATRIX, mat_proj);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
 //  gluLookAt(0, 0, 70, 0, 0, 0, 0, 1, 0);
   glTranslatef(translate_x,translate_y,fov); //先平移再旋转
   glRotatef(yaw,0.0,1.0,0.0);
   glRotatef(pitch,0.0,0.0,1.0);
 //  glColor4f(0.1, 0.4, 0.6, 0.7);
   glPushMatrix();
  // 获取模型视图矩阵
   glGetFloatv(GL_MODELVIEW_MATRIX, mat_modelview);
   for (int i = 0; i < cornernumber-3; i++)
             {
                // glLoadName(i);//name the points
                 glBegin(GL_POINTS);
                 viewDistance = sqrt(corners[i][0]*corners[i][0]+corners[i][2]*corners[i][2])/1000.0f;
                 if(viewDistance < 5)
                {
                     glColor3f (1.0f, 0.5f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                 else if(viewDistance >= 5 && viewDistance < 6)
                {
                     glColor3f (1.0f, 0.6f, 0.0f);
                      glVertex3fv(corners[i]);

                }
                 else if(viewDistance >= 6 && viewDistance < 7)
                {
                     glColor3f (1.0f, 0.7f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                 else if(viewDistance >= 7 && viewDistance < 8)
                {
                     glColor3f (1.0f, 0.8f, 0.0f);
                      glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 8 && viewDistance < 9)
                {
                     glColor3f (1.0F, 0.9f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 9 && viewDistance < 10)
                {
                     glColor3f (1.0f, 1.0f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 10 && viewDistance < 11)
                {
                     glColor3f (0.9f, 1.0f, 0.0f);
                      glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 11 && viewDistance < 12)
                {
                     glColor3f (0.8f, 1.0f, 0.0f);
                     glVertex3fv(corners[i]);

                }
               else   if(viewDistance >= 12 && viewDistance < 13)
                {
                     glColor3f (0.7f, 1.0f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 13 && viewDistance < 14)
                {
                     glColor3f (0.6f, 1.0f, 0.0f);
                      glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 14 && viewDistance < 15)
                {
                     glColor3f (0.5f, 1.0f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 15 && viewDistance <16)
                {
                     glColor3f (0.4f, 1.0f, 0.0f);
                    glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 16 && viewDistance < 17)
                {
                     glColor3f (0.3f, 1.0f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                else  if(viewDistance >= 17 && viewDistance < 18)
                {
                     glColor3f (0.2f, 1.0f, 0.0f);
                     glVertex3fv(corners[i]);

                }
                 else  if(viewDistance >= 18)
                 {
                 glColor3f (0.1f, 1.0f, 0.0f);
                 glVertex3fv(corners[i]);

                }
               glEnd();
}
   glPopMatrix();
   glPopAttrib();
   // 配置  

if(mouserightclick_times==1)
  {set_config(corners, cornernumber-2, left_bottom, right_top, mat_modelview, mat_proj, viewport);}
 if(mouserightclick_times==2)
  { set_config(corners, cornernumber-2, left_bottom_2, right_top_2, mat_modelview, mat_proj, viewport);}
   qDebug()<< "display";
   /************************************************************************/
   /* 构造一个新的环境                                                        */
   /************************************************************************/

   if( mouserightclick_times!=0&&mouserightclick_times<3&& mousebutton_right==true)
   {

      draw_area();
      highlight_selected_pts();

   }

}
void OpenGLshow:: countdistance(M3DVector3f N1,M3DVector3f N2)
{



};



