#ifndef HDCAMERA_H
#define HDCAMERA_H

#include <QOpenGLWidget>
#include <SDK.h>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QPainter>
class HDCamera:public QOpenGLWidget
{
    Q_OBJECT

public:
    HDCamera();
    HDCamera(QWidget* parent );
   static void HDStatic();
   void  Delay_MSec(unsigned int );
   void displayDeviceInfo(GENICAM_Camera *pCameraList, int cameraCnt);//相机参数显示读取
   void HDCameraParameterInt();
   void HD_Connect();
   void HD_Disconnect();
   int32_t GENICAM_connect(GENICAM_Camera *pGetCamera);//相机连接
   int32_t modifyCamralExposureTime(GENICAM_Camera *pGetCamera);//修改曝光时间
   int32_t GENICAM_CreateStreamSource(GENICAM_Camera *pGetCamera, GENICAM_StreamSource **ppStreamSource);//创建流对象
   int32_t GENICAM_startGrabbing(GENICAM_StreamSource *pStreamSource);//开始拉流
   int32_t GENICAM_stopGrabbing(GENICAM_StreamSource *pStreamSource);//关闭流
   int32_t GENICAM_disconnect(GENICAM_Camera *pGetCamera);
    void test();
   // unsigned __stdcall frameGrabbingProc();
signals:
   void sendQimage2Main(QImage);

protected:
    void paintEvent(QPaintEvent *e);

};

#endif // HDCAMERA_H
