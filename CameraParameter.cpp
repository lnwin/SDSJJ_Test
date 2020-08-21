#include<CameraParameter.h>
#include<QApplication>
#include<QDebug>
#include<QMessageBox>
//------------------------------------------------------------------------参数配置
using namespace cv;
using namespace std;
QString Matrixfilepath;
string imagename;
float picture_N,p_CornerNumber_row,p_CornerNumber_col,cellSize_width,cellSize_height,iteration_N,accuracy;

cv::Mat IMG(640, 480, CV_8UC3);
cv::Mat imgaing;
//------------------------------------------------------------------------参数配置
CameraParameter::CameraParameter()
{}
CameraParameter::CameraParameter(QWidget *parent) : QOpenGLWidget(parent)
{}
CameraParameter::~CameraParameter()
{}

void CameraParameter::CameraParameter_LoadMatrix()//------------------------矩阵载入函数
{
    Matrixfilepath = QApplication::applicationDirPath();
    qDebug()<<Matrixfilepath;

};
void CameraParameter::CameraParameter_ProduceMatrix(QList<float> setingliset)//---------------------矩阵生成函数
{

    picture_N         =setingliset[0];
    p_CornerNumber_row=setingliset[1];
    p_CornerNumber_col=setingliset[2];
    cellSize_width    =setingliset[3];
    cellSize_height   =setingliset[4];
    iteration_N       =setingliset[5];
    accuracy          =setingliset[6];
    int C_W =(int)p_CornerNumber_row;
    int C_H =(int)p_CornerNumber_col;
    int ITER =(int)iteration_N;
    QString  srcDirPath = QFileDialog::getExistingDirectory( this, "请选择标定数据图片存储路径", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("the directory is empty");
        mesbox.exec();
        return;
    }
    else
    {
     std::vector<cv::Point2f> image_points;
     std::vector<std::vector<cv::Point2f>> image_points_seq;//-----------------------保存所有角点
     QDir dir(srcDirPath);
     QStringList imagelist;
     imagelist<<"*.jpg"<<"*.bmp"<<"*.png";
     dir.setNameFilters(imagelist);
     int imagecuont =dir.count();
     string dirpath =srcDirPath.toStdString();
     try
     {
         for(int i=0;i<imagecuont;i++)
         {
             imagename =dirpath+"/"+dir[i].toStdString();
             cv::imwrite(imagename,IMG);
             cv::findChessboardCorners(IMG,cv::Size(C_W,C_H),image_points,0);//-----------检测角点
             cv::cvtColor(IMG,imgaing,CV_BGR2GRAY);
             cv::cornerSubPix(imgaing, image_points, cv::Size(11, 11), cv::Size(-1, -1),
                              cv::TermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, ITER, accuracy));
             image_points_seq.push_back(image_points);

         }
     }
     catch (exception& e)
     {
         QMessageBox mesbox1;
         mesbox1.setText("image quality is not ok :"+ QString(QLatin1String(e.what())));
         mesbox1.exec();
     }

         cv::Size square_size = cv::Size(cellSize_width, cellSize_height);
         std::vector<std::vector<cv::Point3f>> object_points; /* 保存标定板上角点的三维坐标 */
         cv::Mat cameraMatrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0)); /* 摄像机内参数矩阵 */
         cv::Mat distCoeffs = cv::Mat(1, 5, CV_32FC1, cv::Scalar::all(0)); /* 摄像机的5个畸变系数：k1,k2,p1,p2,k3 */
         std::vector<cv::Mat> tvecsMat;  /* 每幅图像的旋转向量 */
         std::vector<cv::Mat> rvecsMat;  /* 每幅图像的平移向量 */
         std::vector<cv::Point3f> realPoint;
         for (int i = 0; i < C_H; i++) {
             for (int j = 0; j < C_W; j++) {
                 cv::Point3f tempPoint;
                 /* 假设标定板放在世界坐标系中z=0的平面上 */
                 tempPoint.x = i * square_size.width;
                 tempPoint.y = j * square_size.height;
                 tempPoint.z = 0;
                 realPoint.push_back(tempPoint);
             }
         }
         object_points.push_back(realPoint);
         cv::calibrateCamera(object_points, image_points_seq, imgaing.size(), cameraMatrix, distCoeffs, rvecsMat, tvecsMat,
                                 CV_CALIB_FIX_K3);
         try
         {
             string cameraMatrixpath=  srcDirPath.toStdString()+"/cameraMatrix.txt";
             string distCoeffspath=  srcDirPath.toStdString()+"/distCoeffs.txt";
             writeMatToFile(cameraMatrix,cameraMatrixpath);
             writeMatToFile(distCoeffs,cameraMatrixpath);

         }
         catch (exception& e)
         {

         }
    }

};
void CameraParameter::CameraParameter_Constrast()//-------------------------结果对比函数
{

};
void CameraParameter::writeMatToFile(cv::Mat& m,  std::string filename)
{
     std::ofstream fout(filename);

      if (!fout)
   {
     std::cout << "File Not Opened" << std::endl;
     return;
   }

     for (int i = 0; i<m.rows; i++)
   {
     for (int j = 0; j<m.cols; j++)
   {
     fout << m.at<float>(i, j) << "\t";
   }
     fout << std::endl;
   }
     fout.close();
}

