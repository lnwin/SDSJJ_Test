#include<OpenGLShow.h>
#include<QDebug>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
//---------------------------------------------------------------着色器配置
unsigned int VBO,VAO,EBO,vertexShader,fragmentShader,shaderProgram,texture;
const char *vertexShaderSource = "#version 450 core\n"      //----顶点着色器
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "layout (location=2) in vec2 aTexCoord;\n"
    "out vec3 ourColor;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "   TexCoord = aTexCoord;\n"
    "}\0";
const char *fragmentShaderSource = "#version 450 core\n"    //----片段着色器
    "out vec4 FragColor;\n"
    "in  vec3 ourColor;\n"
    "in vec2 TexCoord;\n"
    "uniform sampler2D ourTexture;\n"

    "void main()\n"
    "{\n"
    " FragColor =  texture(ourTexture, TexCoord);\n"
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
  glGenTextures(1,&texture);
  glBindTexture(GL_TEXTURE_2D,texture);
  //
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT); //画面扩展方式
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//放大缩小的细节
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  //加载纹理
  int width,height,nrChannels;
  unsigned char *data = stbi_load("C:/Users/Administrator/Desktop/spacex.jpg",&width,&height,&nrChannels,0);
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

  glUseProgram(shaderProgram);

}

void OpenGLshow::resizeGL(int width, int height)
{

     glViewport(0,0,width,height);
    //--------------------------------------------------------------简单绘制点云操作
    glMatrixMode(GL_PROJECTION);//切换至投影矩阵
    glLoadIdentity();//设置矩阵
    glOrtho(-width/10,width/10,-height/10,height/10,-1,1);
    glMatrixMode(GL_MODELVIEW);//设置完成后开始画图,需要切换到 模型视图矩阵 才能正确画图
    //--------------------------------------------------------------简单绘制点云操作
}

void OpenGLshow::paintGL()
{

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
   // float RGBvalue = 0.4;
   // int vertexColorLocation = glGetUniformLocation(shaderProgram, "FragColor");
     glBindTexture(GL_TEXTURE_2D, texture);

   // glUniform4f(vertexColorLocation, 0.0f, RGBvalue, 0.2f, 0.5f);
    glBindVertexArray(VAO);
   // glDrawArrays(GL_TRIANGLES,0,3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    //--------------------------------------------------------------简单绘制点云操作
//            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//            glBegin(GL_TRIANGLES);//按三角形绘制
//            glColor3f(1.0, 0.0, 0.0);
//            glVertex3f(-5, -5, 0);
//            glColor3f(0.0, 1.0, 0.0);
//            glVertex3f( 5, -5, 0);
//            glColor3f(0.0, 0.0, 1.0);
//            glVertex3f( 0.0,  5, 0);
//            glEnd();
    //--------------------------------------------------------------简单绘制点云操作

}



















