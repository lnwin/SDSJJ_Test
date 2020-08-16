#include<OpenGLShow.h>
#include<QDebug>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <QMouseEvent>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
//---------------------------------------------------------------着色器配置
unsigned int VBO,VAO,EBO,vertexShader,fragmentShader,shaderProgram,texture,texture1,texture2;
float _x=0,_y=0,_z=0,clickX,clickY,ddx,ddy;
bool clicKtf=false,mouseposition;
const char *vertexShaderSource = "#version 450 core\n"      //----顶点着色器主要传递数据的位置
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 TexCoord;\n"
    "uniform mat4 transform;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = transform * vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";
const char *fragmentShaderSource = "#version 450 core\n"    //----片段着色器输出具体数据
    "out vec4 FragColor;\n"
    "in  vec3 ourColor;\n"
    "in  vec2 TexCoord;\n"
    "uniform sampler2D texture1;\n"
    "uniform sampler2D texture2;\n"
    "void main()\n"
    "{\n"
    " FragColor =  mix(texture(texture1, TexCoord),texture(texture2, TexCoord),0.5);\n"
    "}\n\0";
//---------------------------------------------------------------着色器配置



OpenGLshow::OpenGLshow()
{

}
OpenGLshow::OpenGLshow(QWidget *parent) : QOpenGLWidget(parent)
{

}
OpenGLshow::~OpenGLshow()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

}


void OpenGLshow::initializeGL()
{

    initializeOpenGLFunctions();
//--------------------------------------------------------------简单绘制点云操作
//    glClearColor(0,0,0,1);
//    glEnable(GL_DEPTH_TEST);
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);
//    glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
//    glEnable(GL_COLOR_MATERIAL);
//--------------------------------------------------------------简单绘制点云操作
//--------------------------------------------------------------opengl教程
    vertexShader =glCreateShader(GL_VERTEX_SHADER);
   glShaderSource(vertexShader,1,&vertexShaderSource,NULL);
   glCompileShader(vertexShader);
   int success;
   char infoLog[512];
      glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
      if (!success)
      {
          glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
          qDebug()<< "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog ;
      }
   fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
   glShaderSource(fragmentShader,1,&fragmentShaderSource,NULL);
   glCompileShader(fragmentShader);
     glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
     if(!success)
     {
         glGetShaderInfoLog(fragmentShader,512,NULL,infoLog);
         qDebug()<< "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog;

     }
   shaderProgram=glCreateProgram();
   glAttachShader(shaderProgram,vertexShader);
   glAttachShader(shaderProgram,fragmentShader);
   glLinkProgram(shaderProgram);
      glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
      if (!success)
      {
          glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
          qDebug() << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog ;
      }
   glDeleteShader(vertexShader);
   glDeleteShader(fragmentShader);


   float vertices[] =
   {       //位置                 颜色              纹理位置
           0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
           0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
          -0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
          -0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上
   };
   unsigned int indices[] = {
          0, 1, 3, // first triangle
          1, 2, 3  // second triangle    得好好看看这部分
      };

  glGenVertexArrays(1,&VAO);
  glGenBuffers(1,&VBO);
  glGenBuffers(1, &EBO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)0);//顶点着色器位置信息格式配置
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(3* sizeof(float)));//顶点着色器颜色信息格式配置
  glEnableVertexAttribArray(1);//颜色的location是1
  glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6* sizeof(float)));//顶点着色器纹理信息格式配置
  glEnableVertexAttribArray(2);//颜色的location是1

  //-------------------------------------------------------纹理配置
  glGenTextures(1,&texture1);
  glBindTexture(GL_TEXTURE_2D,texture1);
  //
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT); //画面扩展方式
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//放大缩小的细节
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //加载纹理
  int width,height,nrChannels;
  stbi_set_flip_vertically_on_load(true);
  unsigned char *data = stbi_load("C:/Users/Administrator/Desktop/timg.jpg",&width,&height,&nrChannels,0);
  if(data)
  {
      glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
      glGenerateMipmap(GL_TEXTURE_2D);
  }
  else
  {
      qDebug() << "Failed to load texture" ;
  }
    stbi_image_free(data);
  //-------------------------------------------------------纹理配置
    glGenTextures(1,&texture2);
    glBindTexture(GL_TEXTURE_2D,texture2);
    //
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT); //画面扩展方式
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//放大缩小的细节
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    //加载纹理
    stbi_set_flip_vertically_on_load(true);
    data = stbi_load("C:/Users/Administrator/Desktop/spacex.jpg",&width,&height,&nrChannels,0);
    if(data)
    {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        qDebug() << "Failed to load texture" ;
    }
      stbi_image_free(data);

  glUseProgram(shaderProgram);
//--------------------------------------------------------------opengl教程

}

void OpenGLshow::resizeGL(int width, int height)
{

    glViewport(0,0,width,height);
//--------------------------------------------------------------简单绘制点云操作
   // glMatrixMode(GL_PROJECTION);//切换至投影矩阵
   // glLoadIdentity();//设置矩阵
   // glOrtho(-width/20,width/20,-height/20,height/20,-1,1);
   // glMatrixMode(GL_MODELVIEW);//设置完成后开始画图,需要切换到 模型视图矩阵 才能正确画图
 //--------------------------------------------------------------简单绘制点云操作
}

void OpenGLshow::paintGL()
{
//--------------------------------------------------------------opengl教程
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
   // float RGBvalue = 0.4;
   // int vertexColorLocation = glGetUniformLocation(shaderProgram, "FragColor");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glUniform1i(glGetUniformLocation(shaderProgram, "texture1"),0);
    glUniform1i(glGetUniformLocation(shaderProgram, "texture2"),1);

    //------------------------------------矩阵变换
    glm::vec4 vec(1.0f,0.0f,0.0f,1.0f);
    glm::mat4 trans;
    trans=glm::translate(trans,glm::vec3(0.5f,0.0f,0.0f));
    vec =trans*vec;
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"transform"), 1, GL_FALSE, glm::value_ptr(trans));//传递位置值
    //------------------------------------
    glBindVertexArray(VAO);
   // glDrawArrays(GL_TRIANGLES,0,3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//--------------------------------------------------------------opengl教程


}

void OpenGLshow::mousePressEvent(QMouseEvent *event)
{

             QPoint p_ab = event->pos();
             clicKtf = true;

               clickX = p_ab.x();
               clickY = p_ab.y();
               if (event->button() == Qt::LeftButton)
               {
                   mouseposition = false;
               }
               else
               {
                   mouseposition = true;
               }


}
 void OpenGLshow:: mouseReleaseEvent(QMouseEvent *event)
{
                clicKtf = false;
                ddx = _y;
                ddy = _x;
}

 void OpenGLshow:: mouseMoveEvent(QMouseEvent *event)
{
     QPoint p_ab = event->pos();
     if (clicKtf)
                {
                    if (!mouseposition)
                    {
                        _x = p_ab.y() - clickY;
                        _y = p_ab.x() - clickX;
                    }
                    else
                    {
                        //_ZByT += e.Y - clickY;
                        //_ZBzT += e.X - clickX;
                    }


                }
     this->update();
}

















