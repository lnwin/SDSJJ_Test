#include<OpenGLShow.h>
#include<QDebug>

unsigned int VBO,VAO,vertexShader,fragmentShader,shaderProgram;
const char *vertexShaderSource = "#version 450 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 450 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
OpenGLshow::~OpenGLshow()
{
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
}


void OpenGLshow::initializeGL()
{

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


}

void OpenGLshow::resizeGL(int width, int height)
{

}

void OpenGLshow::paintGL()
{

}



















