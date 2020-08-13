#include<OpenGLShow.h>
#include<QDebug>
//---------------------------------------------------------------着色器配置
unsigned int VBO,VAO,vertexShader,fragmentShader,shaderProgram;
const char *vertexShaderSource = "#version 450 core\n"      //----顶点着色器
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aColor;\n"
    "out vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos, 1.0);\n"
    "   ourColor = aColor;\n"
    "}\0";
const char *fragmentShaderSource = "#version 450 core\n"    //----片着色器
    "out vec4 FragColor;\n"
    "in  vec3 ourColor;\n"
    "void main()\n"
    "{\n"
    " FragColor = vec4 (ourColor, 1.0);\n"
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
    //glDeleteVertexArrays(1, &VAO);
   // glDeleteBuffers(1, &VBO);
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
   {
           -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // left
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // right
            0.0f,  0.5f, 0.0f, 0.0f, 0.0f, 1.0f  // top
   };

  glGenVertexArrays(1,&VAO);
  glGenBuffers(1,&VBO);
  glBindVertexArray(VAO);
  glBindBuffer(GL_ARRAY_BUFFER,VBO);
  glBufferData(GL_ARRAY_BUFFER,sizeof (vertices),vertices,GL_STATIC_DRAW);
  glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)0);//顶点着色器位置信息格式配置
  glEnableVertexAttribArray(0);
  glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,6*sizeof(float),(void*)(3* sizeof(float)));//顶点着色器颜色信息格式配置
  glEnableVertexAttribArray(1);//颜色的location是1
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


   // glUniform4f(vertexColorLocation, 0.0f, RGBvalue, 0.2f, 0.5f);
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES,0,3);
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



















