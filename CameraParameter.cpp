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
cv::Mat img_source;
cv::Mat img_target;
cv::Mat cameraMatrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0)); /* 摄像机内参数矩阵 */
cv::Mat distCoeffs = cv::Mat(1, 5, CV_32FC1, cv::Scalar::all(0)); /* 摄像机的5个畸变系数：k1,k2,p1,p2,k3 */
cv::Mat NcameraMatrix = cv::Mat(3, 3, CV_32FC1, cv::Scalar::all(0)); /* 摄像机内参数矩阵 */
cv::Mat NdistCoeffs = cv::Mat(1, 5, CV_32FC1, cv::Scalar::all(0)); /* 摄像机的5个畸变系数：k1,k2,p1,p2,k3 */
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
     int success_n=0;
         for(int i=0;i<imagecuont;i++)
         {
             try
             {
             imagename =dirpath+"/"+dir[i].toStdString();
             img_source = cv::imread(imagename);
             cv::findChessboardCorners(img_source,cv::Size(C_W,C_H),image_points,0);//-----------检测角点
             cv::cvtColor(img_source,img_target,CV_BGR2GRAY);
             cv::cornerSubPix(img_target, image_points, cv::Size(5, 5), cv::Size(-1, -1),
                         cv::TermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS,ITER,accuracy));
             image_points_seq.push_back(image_points);
             success_n++;
//--------------------------------------------------------------将识别的角点画出来
             cv::Mat cb_corner;
             cb_corner = img_source.clone();
             drawChessboardCorners(cb_corner, cv::Size(C_W,C_H), image_points, true);
             cv::imshow("Results",cb_corner);
             waitKey();
//--------------------------------------------------------------
            }
             catch (exception& e)
             {
                qDebug()<<"image quality is not ok :"+QString::fromStdString(imagename);

             }
         }

         cv::Size square_size = cv::Size(cellSize_width, cellSize_height);
         std::vector<std::vector<cv::Point3f>> object_points; /* 保存标定板上角点的三维坐标 */
         std::vector<cv::Mat> tvecsMat;  /* 每幅图像的旋转向量 */
         std::vector<cv::Mat> rvecsMat;  /* 每幅图像的平移向量 */
         std::vector<cv::Point3f> realPoint;

     for(int i=0;i<success_n;i++)
    {
         for (int i = 0; i < C_H; i++)
         {
             for (int j = 0; j < C_W; j++)
             {
                 cv::Point3f tempPoint;
                 /* 假设标定板放在世界坐标系中z=0的平面上 */
                 tempPoint.x = i * square_size.width;
                 tempPoint.y = j * square_size.height;
                 tempPoint.z = 0;
                 realPoint.push_back(tempPoint);
             }

         }

         object_points.push_back(realPoint);
         realPoint.clear();
     }

         cv::calibrateCamera(object_points, image_points_seq, img_source.size(), cameraMatrix, distCoeffs, rvecsMat, tvecsMat,
                               CV_CALIB_FIX_K3, cv::TermCriteria(CV_TERMCRIT_ITER + CV_TERMCRIT_EPS, ITER,accuracy));//---------------------------
         Matrixfilepath= QApplication::applicationDirPath();
         try
         {
            writeMatToFile(cameraMatrix,Matrixfilepath+"/cameraMatrix.txt");
            writeMatToFile(distCoeffs,Matrixfilepath+"/distCoeffs.txt");
            //cameraMatrix.release();
            //distCoeffs.release();
            QMessageBox mesbox;
            mesbox.setText("Calibration done");
            mesbox.exec();
            return;
         }
         catch (exception& e)
         {

         }
    }

};
void CameraParameter::CameraParameter_Constrast()//-------------------------结果对比函数
{
    QString  srcDirPath = QFileDialog::getOpenFileName( this, "select picture", "/");
    if (srcDirPath.isEmpty())
    {
        QMessageBox mesbox;
        mesbox.setText("the file is not exists");
        mesbox.exec();
        return;
    }
    else
    {
        Matrixfilepath= QApplication::applicationDirPath();
        writeFileToMat(NcameraMatrix,Matrixfilepath+"/cameraMatrix.txt","cameraMatrix");
        writeFileToMat(NdistCoeffs,Matrixfilepath+"/distCoeffs.txt","distCoeffs");
        string dirpath =srcDirPath.toStdString();
        imagename =dirpath;
        img_source = cv::imread(imagename);
        cv::undistort(img_source,img_target,NcameraMatrix,NdistCoeffs);
        cv::namedWindow("source",0);
        cv::resizeWindow("source", 640,360);
        cv::imshow("source",img_source);
        cv::moveWindow("source",320,300);
        cv::namedWindow("target",0);
        cv::resizeWindow("target", 640,360);
        cv::imshow("target",img_target);
        cv::moveWindow("target",960,300);

    }

};
void CameraParameter::writeMatToFile(cv::Mat& m,  QString filename)
{
    QString cameraMatrixpath=  filename ;
    QFile cloudfile(cameraMatrixpath);
    QTextStream stream(&cloudfile);
    stringstream streamchange;
    streamchange<<m;
    if(!cloudfile.exists())
      {
          cloudfile.open(QIODevice::WriteOnly | QIODevice::Text );
          stream<<QString::fromStdString(streamchange.str());
          qDebug()<<QString::fromStdString(streamchange.str());
       }
    else
    {
        cloudfile.open(QIODevice::WriteOnly | QIODevice::Text );
        stream<<QString::fromStdString(streamchange.str());
        qDebug()<<QString::fromStdString(streamchange.str());
    }


}
void CameraParameter::writeFileToMat(cv::Mat& m,  QString filename,QString type)
{
    QString cameraMatrixpath= filename;
    QFile cloudfile(cameraMatrixpath);
    QTextStream stream(&cloudfile);
    QString alltxt;
    if(cloudfile.exists())
      {
          cloudfile.open(QIODevice::ReadOnly | QIODevice::Text );
          alltxt = stream.readAll();
          if(type=="cameraMatrix")
          {
           alltxt = alltxt.mid(1,alltxt.count()-2).remove(QRegExp("\n"));
           qDebug()<< "cameraMatrix is follow"<<alltxt;
           QStringList cameraMatrix_Split =alltxt.split(";");
           for(int i=0;i<m.rows;i++)
           {
               QStringList cameraMatrix_Target=cameraMatrix_Split[i].split(",");
               for(int j=0;j<m.cols;j++)
               {
                  m.at<float>(i,j)= cameraMatrix_Target[j].toFloat() ;//有效数字只有6位
               }
           }

          }
          else
          {
              alltxt = alltxt.mid(1,alltxt.count()-2);
              qDebug()<< "distCoeffs is follow"<<alltxt;
              QStringList cameraMatrix_Split =alltxt.split(",");
              for(int i=0;i<m.rows;i++)
              {

                  for(int j=0;j<m.cols;j++)
                  {
                     m.at<float>(i,j)= cameraMatrix_Split[j].toFloat() ;//有效数字只有6位

                  }
              }
          }
          alltxt.clear();

      }
    else
    {
        QMessageBox mesbox;
        mesbox.setText("the Matirxfile is not exists");
        mesbox.exec();
        return;
    }
}

