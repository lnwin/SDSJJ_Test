#ifndef CAMERAPARAMETER_H
#define CAMERAPARAMETER_H
#include <QOpenGLWidget>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <QFileDialog>


class CameraParameter:public QOpenGLWidget
{
  Q_OBJECT
public:
      CameraParameter(QWidget *parent );
      ~CameraParameter();
      CameraParameter();
      void CameraParameter_LoadMatrix();
      void CameraParameter_ProduceMatrix(QList<float>);
      void CameraParameter_Constrast();
      void writeMatToFile(cv::Mat& m, QString filename);
      void writeFileToMat(cv::Mat& m, QString filename,QString type);
      //void CameraParameter_Run();
public slots:



};














#endif // CAMERAPARAMETER_H
