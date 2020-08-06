#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QCamera>
#include <QCameraViewfinder>
#include <QCameraImageCapture>
class WorkThread:public QThread
{
    Q_OBJECT
  public:
    WorkThread();

    QCameraViewfinder *viewfinder;//取景器
    QCamera *camera;//相机
    QCameraImageCapture *imageCapture;//图片捕捉器
  //  QtVideoCapture *QtVIDEO;
    cv::Mat matframe;//opencv 图片暂存
    cv::VideoCapture *cvVideocapture; //opencv 视频类
    cv::Mat QImage2cvMat(QImage);
    QImage cvMat2QImage(cv::Mat & mat);
    void run();
    void cloudDataProcessing();
    void cloudDataRecord();
    void Delay_MSec(unsigned int );
    signals:
    void sendMessage2Main(int);
    void setTabWidgt2Camera(int);

};
#endif // WORKTHREAD_H
