#include<OpenGLShow.h>
#include<QDebug>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <QMouseEvent>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<gl/GLU.h>
//---------------------------------------------------------------着色器配置
unsigned int VBO,VAO,EBO,vertexShader,fragmentShader,shaderProgram,texture,texture1,texture2;
float _x=0,_y=0,_z=0,clickX,clickY,ddx,ddy,fov=-100,sumX,sumY,sumZ,meanX,meanY,meanZ;
bool clicKtf=false,mouseposition;
QString cloudfilename;
QList<QString>cloudata;
QList<float>cloud_x;
QList<float>cloud_y;
QList<float>cloud_z;
int mousedond_x,mousedond_y;
float yaw,pitch;//中心位置
float xoffset, yoffset;
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
        gluPerspective(45.0,760/490,0.1,10000);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}

void OpenGLshow::paintGL()
{

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,fov); //先平移再旋转
    glRotatef(yaw,0.0,1.0,0.0);
    glBegin(GL_POINTS);
        for (int i = 0; i < cloud_x.count(); i++)
        {
            glColor3f( 0.0, 1.0, 0.5);
            glVertex3f((cloud_x[i]-meanX)/20,  (cloud_y[i]-meanY)/20, (cloud_z[i]-meanZ)/20);
        }
    glEnd();
    glFlush();


}

void OpenGLshow::mousePressEvent(QMouseEvent *event)
{

         mousedond_x=event->x();
         mousedond_y=event->y();


}
void OpenGLshow:: mouseReleaseEvent(QMouseEvent *event)
{

}
void OpenGLshow:: mouseMoveEvent(QMouseEvent *event)
{

     xoffset = (event->x()-mousedond_x)/40;
     yoffset = (event->y()-mousedond_y)/40;
     yaw+=xoffset;
     this->update();
     qDebug()<<event->x()<<mousedond_x;
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
void OpenGLshow:: receivecloudfilename(QString filename)
{

    cloudfilename = filename;
    readclouddata();
    this->update();

};
void OpenGLshow:: readclouddata()
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
     foreach(auto item,cloud_x)
     {
        sumX+=item;
     }
     foreach(auto item,cloud_y)
     {
        sumY+=item;
     }
     foreach(auto item,cloud_z)
     {
        sumZ+=item;
     }
     meanX = sumX/cloud_x.count();
     meanY = sumY/cloud_x.count();
     meanZ = sumZ/cloud_x.count();


};
















