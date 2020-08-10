#include<Pcl_progress.h>




void PCL::initialVtkWidget()
{

        cloud.reset(new pcl::PointCloud<pcl::PointXYZ>);
        viewer.reset(new pcl::visualization::PCLVisualizer("viewer", false));
        viewer->addPointCloud(cloud, "cloud");
       // ui.qvtkWidget->SetRenderWindow(viewer->getRenderWindow());
        this->SetRenderWindow(viewer->getRenderWindow());
        viewer->setupInteractor(this->GetInteractor(), this->GetRenderWindow());
        this->update();

}

void PCL::showPCDcloud()
{
    if (pcl::io::loadPCDFile<pcl::PointXYZ>("D:\\rabbit.pcd", *cloud) == -1) //* 读入PCD格式的文件，如果文件不存在，返回-1
    {
        PCL_ERROR("Couldn't read file test_pcd.pcd \n"); //文件不存在时，返回错误，终止程序。
       // return (-1);
    }
            viewer->updatePointCloud(cloud, "cloud");
            viewer->resetCamera();
            this->update();
}
