#include<OpenGLShow.h>
#include<QDebug>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <QMouseEvent>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <gl/GLU.h>
#include <QFileDialog>
#include<QMessageBox>
#include <QTime>
#include <QCoreApplication>
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
float Addclouddata_x=0,Addclouddata_y=0,Addclouddata_z=0;
//---------------------------------------------------------------------------------------激光测距参数
float PixelSize =0.004;
float f = 3.6;
float baseline = 640;
float step_angle;
float Laser_angle;
const float pic_wight = 1280;
const float pic_height = 720;
const float rotation_r = 430;
const float PI = 3.14159265;
float RGB = 170;
float Math_angle;
float sumXRGB;
float sumXX;
float Pic_x;
float Pic_y;
float yaw_angle,laser_to_dist_pt,laser_to_current_pt,laser_to_center_pt,center_distance,real_center_distance,real_distance,pitch_angle,pitch_distance,center2target;
int Maxindex_n,MaxRGB;
float real_x=0,real_y=0,real_z=0;
//---------------------------------------------------------------------------------------激光测距参数
cv::Mat mat;
OpenGLshow::OpenGLshow()
{

}
OpenGLshow::OpenGLshow(QWidget *parent) : QOpenGLWidget(parent)
{

}
OpenGLshow::~OpenGLshow()
{

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

void OpenGLshow::resizeGL(int width, int height)
{

        glViewport(0,0,width,height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(60.0,760/490,0.1,100000);//设置观察视窗
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}

void OpenGLshow::paintGL()
{

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(translate_x,translate_y,fov); //先平移再旋转
    glRotatef(yaw,0.0,1.0,0.0);
    glRotatef(pitch,0.0,0.0,1.0);
    glBegin(GL_POINTS);
        for (int i = 0; i < cloud_x.count(); i++)
        {

            viewDistance = sqrt(cloud_x[i]*cloud_x[i]+cloud_z[i]*cloud_z[i])/1000.0f;
            if(viewDistance >= 4 && viewDistance < 5)
           {
                glColor3f (1.0f, 0.5f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
            else if(viewDistance >= 5 && viewDistance < 6)
           {
                glColor3f (1.0f, 0.6f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
            else if(viewDistance >= 6 && viewDistance < 7)
           {
                glColor3f (1.0f, 0.7f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
            else if(viewDistance >= 7 && viewDistance < 8)
           {
                glColor3f (1.0f, 0.8f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 8 && viewDistance < 9)
           {
                glColor3f (1.0F, 0.9f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 9 && viewDistance < 10)
           {
                glColor3f (1.0f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 10 && viewDistance < 11)
           {
                glColor3f (0.9f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 11 && viewDistance < 12)
           {
                glColor3f (0.8f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
          else   if(viewDistance >= 12 && viewDistance < 13)
           {
                glColor3f (0.7f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 13 && viewDistance < 14)
           {
                glColor3f (0.6f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 14 && viewDistance < 15)
           {
                glColor3f (0.5f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 15 && viewDistance <16)
           {
                glColor3f (0.4f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 16 && viewDistance < 17)
           {
                glColor3f (0.3f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
           else  if(viewDistance >= 17 && viewDistance < 18)
           {
                glColor3f (0.2f, 1.0f, 0.0f);
                glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
           }
            else  if(viewDistance >= 18)
            {
            glColor3f (0.1f, 1.0f, 0.0f);
            glVertex3f(cloud_x[i]/20,  cloud_y[i]/20, cloud_z[i]/20);
            }

        }

    glEnd();
//    glBegin(GL_LINES);    //--------------------------------------------------实时扫描线的绘制
//    glColor3f (0.1f, 1.0f, 1.0f);
//    glVertex3f(cloud_x[777]/20,  cloud_y[777]/20, cloud_z[777]/20);
//    glVertex3f(0,  0, 0);
//    glEnd();
    glFlush();


}
void OpenGLshow:: mousePressEvent(QMouseEvent *event)
{

         mousedond_x=event->x();
         mousedond_y=event->y();
        if(event->button()==Qt::LeftButton)
        {
             mousebutton_left = true;
        }
        else
        {
             mousebutton_left = false;
             Addclouddata_x++;
             Addclouddata_y++;
             Addclouddata_z++;
        }


}
void OpenGLshow:: mouseReleaseEvent(QMouseEvent *event)
{

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
    else
    {
       // xoffset=0;
        xoffset = (event->x()-mousedond_x)/40;
        translate_x+=xoffset;
        yoffset = (event->y()-mousedond_y)/40;
        translate_y-=yoffset;
    }
     this->update();    
}
void OpenGLshow:: wheelEvent(QWheelEvent*event)
 {
     if(event->delta()>0)
     {
         fov+=event->delta()/10;
     }
     if(event->delta()<0)
     {
         fov+=event->delta()/10;
     }

     this->update();
 }
void OpenGLshow:: receivecloudfilename(QString filename)//----------------接受点云文件名
{

    cloudfilename = filename;
    readclouddata();
    this->update();

};
void OpenGLshow:: readclouddata()//---------------------------------------读取点云数据文件
{
     QFile file(cloudfilename);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
         return;
     QTextStream in(&file);
     QString line = "ready";
     while (!line.isNull())
     {
         line = in.readLine();
         if(!line.isNull())
         {
            cloudata=line.split(',');
            cloud_x.append(cloudata[0].toFloat());
            cloud_y.append(cloudata[1].toFloat());
            cloud_z.append(cloudata[2].toFloat());

         }
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
void OpenGLshow:: GLclouddataprocess(cv::Mat frame)//-------------------------------实时帧处理函数
{

    Math_angle=Math_angle+step_angle;  
    int data = frame.ptr<cv::Vec3b>(0)[0][0];
    int dataSum = frame.ptr<cv::Vec3b>(0)[0][0];
    for(int i=0;i<pic_height;i++)
    {
      Maxindex_n = 0 ;
      MaxRGB =data;
      sumXRGB = 0;
      sumXX = 0;
      for (int j = 0; j < pic_wight; j++)
     {
        if (data > MaxRGB)
        {
           MaxRGB = data;
           Maxindex_n = j;
        }
           data = frame.ptr<cv::Vec3b>(i)[j][0];
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

        dataSum = frame.ptr<cv::Vec3b>(i)[k][0];

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
               // real_x = center2target * sin(yaw_angle + Math_angle);
               // real_z = center2target * cos(yaw_angle + Math_angle);
         // }
         // else
         // {
               real_x = center2target * sin(yaw_angle - Math_angle);
               real_z = center2target * cos(yaw_angle - Math_angle);
         // }
               real_y = real_distance * sin(-pitch_angle);
               Lx+=0.1;Ly+=0.1;Lz+=0.1;
               cloud_x.append(Lx);
               cloud_y.append(Ly);
               cloud_z.append(Lz);




        }
     }

}

void OpenGLshow:: doingfreshen(cv::Mat frame)
{

   GLclouddataprocess(frame);
   this->update();
   Delay_MSec(1);


};

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
   //  this->showMaximized();
     this->update();
         for(int i=0;i<imagecuont;i++)
         {
             try
             {
                 imagename =dirpath+"/"+dir[i].toStdString();
                 cv::Mat SK = cv::imread(imagename,CV_BGR2GRAY);
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














