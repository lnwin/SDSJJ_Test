#ifndef HDCAMERA_H
#define HDCAMERA_H

#include <QOpenGLWidget>
#include <SDK.h>

class HDCamera:public QOpenGLWidget
{
    Q_OBJECT
public:
    HDCamera();
    HDCamera(QWidget* parent );


   void displayDeviceInfo(GENICAM_Camera *pCameraList, int cameraCnt);


};

#endif // HDCAMERA_H
