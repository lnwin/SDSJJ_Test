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
float _x=0,_y=0,_z=0,clickX,clickY,ddx,ddy,fov=45;
bool clicKtf=false,mouseposition;
const char *vertexShaderSource = "#version 450 core\n"      //----顶点着色器主要传递数据的位置
    "layout (location = 0) in vec3 aPos;\n"   
    "layout (location = 1) in vec2 aTexCoord;\n"
    "out vec2 TexCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = projection * view * model * vec4(aPos, 1.0);\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";
const char *fragmentShaderSource = "#version 450 core\n"    //----片段着色器输出具体数据
    "out vec4 FragColor;\n"   
    "in  vec2 TexCoord;\n"
    "uniform sampler2D texture1;\n"
    "uniform sampler2D texture2;\n"
    "void main()\n"
    "{\n"
    " FragColor =  mix(texture(texture1, TexCoord),texture(texture2, TexCoord),0.5);\n"
    "}\n\0";
//---------------------------------------------------------------着色器配置
glm::vec3 camraPos      = glm::vec3(0.0,0.0,3.0);
glm::vec3 cameraFront   = glm::vec3(0.0,0.0,-1.0);
glm::vec3 cameraUp      = glm::vec3(0.0,1.0,0.0);


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
   {           //位置                 纹理位置
               -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
                0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
               -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
               -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

               -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
               -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
               -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

               -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
               -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
               -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
               -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
               -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
               -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

               -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
                0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
                0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
               -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
               -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

               -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
                0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
                0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
               -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
               -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
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

  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)0);//顶点着色器位置信息格式配置
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,5*sizeof(float),(void*)(3* sizeof(float)));//顶点着色器颜色信息格式配置
  glEnableVertexAttribArray(1);//颜色的location是1
 // glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,8*sizeof(float),(void*)(6* sizeof(float)));//顶点着色器纹理信息格式配置
 // glEnableVertexAttribArray(2);//颜色的location是2

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
  unsigned char *data = stbi_load("C:/Users/MIC/Desktop/2.jpg",&width,&height,&nrChannels,0);
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
    data = stbi_load("C:/Users/MIC/Desktop/1.jpg",&width,&height,&nrChannels,0);
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
   // glOrtho(-width/20,width/20,-height/20,height/20,-1,1);//证摄影投射矩阵
   // glMatrixMode(GL_MODELVIEW);//设置完成后开始画图,需要切换到 模型视图矩阵 才能正确画图
 //--------------------------------------------------------------简单绘制点云操作
}

void OpenGLshow::paintGL()
{
//--------------------------------------------------------------opengl教程
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   // float RGBvalue = 0.4;
   // int vertexColorLocation = glGetUniformLocation(shaderProgram, "FragColor");
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture1);
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, texture2);

    glUniform1i(glGetUniformLocation(shaderProgram, "texture1"),0);
    glUniform1i(glGetUniformLocation(shaderProgram, "texture2"),1);
    glBindVertexArray(VAO);
    //------------------------------------矩阵变换

    glm::mat4 view          = glm::mat4(1.0f);
    glm::mat4 projection    = glm::mat4(1.0f);
    view  = glm::lookAt(camraPos,camraPos+cameraFront,cameraUp);

    projection = glm::perspective(glm::radians(fov), (float)760 / (float)490, 0.1f, 100.0f);
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"view"), 1, GL_FALSE, glm::value_ptr(view));//传递位置值
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"projection"), 1, GL_FALSE, glm::value_ptr(projection));//传递位置值

    glm::vec3 cubePositions[] = {
      glm::vec3( 0.0f,  0.0f,  0.0f),
      glm::vec3( 2.0f,  5.0f, -15.0f),
      glm::vec3(-1.5f, -2.2f, -2.5f),
      glm::vec3(-3.8f, -2.0f, -12.3f),
      glm::vec3( 2.4f, -0.4f, -3.5f),
      glm::vec3(-1.7f,  3.0f, -7.5f),
      glm::vec3( 1.3f, -2.0f, -2.5f),
      glm::vec3( 1.5f,  2.0f, -2.5f),
      glm::vec3( 1.5f,  0.2f, -1.5f),
      glm::vec3(-1.3f,  1.0f, -1.5f)
    };
    for(unsigned int i =0;i<10;i++)
    {
      glm::mat4 model;
      model =glm::translate(model,cubePositions[i]);
      float angle = 20.0f * i;
      model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
      glUniformMatrix4fv(glGetUniformLocation(shaderProgram,"model"), 1, GL_FALSE, glm::value_ptr(model));//传递位置值
      glDrawArrays(GL_TRIANGLES,0,36);
    }


    //------------------------------------


   // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//--------------------------------------------------------------opengl教程


}
int mousedond_x,mousedond_y;
float yaw,pitch;//中心位置
float xoffset, yoffset;

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

     xoffset = (event->x() - mousedond_x)/20;
     yoffset = (event->y() - mousedond_y)/20;
     yaw    -= xoffset;
     pitch  += yoffset;
     if(pitch > 89.0f)
        pitch = 89.0f;
     if(pitch < -89.0f)
        pitch = -89.0f;
     glm::vec3 front;
     front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
     front.y = sin(glm::radians(pitch));
     front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
     cameraFront = glm::normalize(front);
     this->update();



}
 void OpenGLshow::wheelEvent(QWheelEvent*event)
 {
     //if(fov >= 1.0f && fov <= 45.0f)
         fov -= event->delta()/20;
     //  if(fov <= 1.0f)
     // fov = 1.0f;
     //   if(fov >= 45.0f)
     //  fov = 45.0f;
        this->update();

 }

















