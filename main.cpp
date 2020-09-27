#include "mainwindow.h"
#include <QApplication>
#include<GL/glut.h>
#include<OpenGLShow.h>
#include<QDebug>





int main(int argc, char *argv[])
{



     QApplication a(argc, argv);
     qDebug()<<"two paraments are"<<&argc<<argv[0]<<argv[1];
      glutInit(&argc, argv);
     MainWindow w;
     w.show();
     return a.exec();

}
