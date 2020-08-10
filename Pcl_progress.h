#ifndef PCL_PROGRESS_H
#define PCL_PROGRESS_H
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <vtkRenderWindow.h>
#include <QWidget>
#include <QObject>
#include <QVTKWidget.h>
class PCL: public QVTKWidget
{
  Q_OBJECT

public:

    void initialVtkWidget();
    void showPCDcloud();
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;


};











#endif // PCL_PROGRESS_H
