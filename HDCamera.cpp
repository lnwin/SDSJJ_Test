#include "HDCamera.h"
#include <string>
#include <QDebug>

HDCamera::HDCamera(QWidget* parent):
    QOpenGLWidget(parent)
{

}
HDCamera::HDCamera()
{

}


void HDCamera:: displayDeviceInfo(GENICAM_Camera *pCameraList, int cameraCnt)
{
        GENICAM_Camera *pDisplayCamera = NULL;
        GENICAM_GigECameraInfo GigECameraInfo;
        GENICAM_GigECamera* pGigECamera = NULL;
        int cameraIndex;
        int keyType;
        const char *vendorName = NULL;
        char vendorNameCat[11];
        const char* deviceUserID = NULL;
        char deviceUserIDCat[16];
        const char* ipAddress = NULL;

        int ret = 0;

        /* 打印Title行 */
        qDebug()<<"\nIdx Type Vendor     Model      S/N             DeviceUserID    IP Address    \n";
        qDebug()<<"------------------------------------------------------------------------------\n";

        for (cameraIndex = 0; cameraIndex < cameraCnt; cameraIndex++)
        {
            pDisplayCamera = &pCameraList[cameraIndex];
            /* Idx 设备列表的相机索引 最大表示字数：3*/
            qDebug()<<cameraIndex + 1;

            /* Type 相机的设备类型（GigE，U3V，CL，PCIe）*/
            keyType = pDisplayCamera->getType(pDisplayCamera);
            switch (keyType)
            {
            case typeGige:
               qDebug()<<" GigE";
                break;
            case typeUsb3:
                 qDebug()<<" U3V ";
                break;
            case typeCL:
                qDebug()<<" CL  ";
                break;
            case typePCIe:
                qDebug()<<" PCIe";
                break;
            default:
                qDebug()<<"     ";
                break;
            }

            /* VendorName 制造商信息  最大表示字数：10 */
            vendorName = pDisplayCamera->getVendorName(pDisplayCamera);
            if (strlen(vendorName) > 10)
            {
                strncpy_s(vendorNameCat, vendorName, 7);
                vendorNameCat[7] = '\0';
                strcat_s(vendorNameCat, "...");
                qDebug()<<vendorNameCat;
            }
            else
            {
                qDebug()<< vendorName;
            }

            /* ModeName 相机的型号信息 最大表示字数：10 */
            qDebug()<< pDisplayCamera->getModelName(pDisplayCamera);

            /* Serial Number 相机的序列号 最大表示字数：15 */
            qDebug()<< pDisplayCamera->getSerialNumber(pDisplayCamera);

            /* deviceUserID 自定义用户ID 最大表示字数：15 */
            deviceUserID = pDisplayCamera->getName(pDisplayCamera);
            if (strlen(deviceUserID) > 15)
            {
                strncpy_s(deviceUserIDCat, deviceUserID, 12);
                deviceUserIDCat[12] = '\0';
                strcat_s(deviceUserIDCat, "...");
                qDebug()<< deviceUserIDCat;
            }
            else
            {
                memcpy(deviceUserIDCat, deviceUserID, sizeof(deviceUserIDCat));
                qDebug()<< deviceUserIDCat;
            }

            /* IPAddress GigE相机时获取IP地址 */
            if (keyType == typeGige)
            {
                GigECameraInfo.pCamera = pDisplayCamera;
                ret = GENICAM_createGigECamera(&GigECameraInfo, &pGigECamera);
                if (ret == 0)
                {
                    ipAddress = pGigECamera->getIpAddress(pGigECamera);
                    if (ipAddress != NULL)
                    {
                        qDebug()<<pGigECamera->getIpAddress(pGigECamera);
                    }

                }
            }

           // printf("\n");
        }
        return;
}
int32_t HDCamera::GENICAM_connect(GENICAM_Camera *pGetCamera)
{
    int32_t isConnectSuccess;

    isConnectSuccess = pGetCamera->connect(pGetCamera, accessPermissionControl);

    if( isConnectSuccess != 0)
    {
        //printf("connect camera failed.\n");
        return -1;
    }

    return 0;
}
int32_t HDCamera::modifyCamralExposureTime(GENICAM_Camera *pGetCamera)
{
   int32_t isExposureTimeSuccess;
   GENICAM_DoubleNode doubleNode;
   double exposureTimeValue;
   GENICAM_AcquisitionControl *pAcquisitionCtrl = NULL;
   GENICAM_AcquisitionControlInfo acquisitionControlInfo = {0};


   acquisitionControlInfo.pCamera = pGetCamera;
   isExposureTimeSuccess = GENICAM_createAcquisitionControl(&acquisitionControlInfo, &pAcquisitionCtrl);
   if( isExposureTimeSuccess != 0)
   {
      qDebug()<<"ExposureTime  fail.\n";
       return -1;
   }

   exposureTimeValue = 0.0;
   doubleNode = pAcquisitionCtrl->exposureTime(pAcquisitionCtrl);
   isExposureTimeSuccess = doubleNode.getValue(&doubleNode, &exposureTimeValue);
   if( isExposureTimeSuccess != 0)
   {
       qDebug()<<"get exposureTime fail.\n";

       //注意：需要释放pAcquisitionCtrl内部对象内存
       pAcquisitionCtrl->release(pAcquisitionCtrl);

       //注意：需要释放doubleNode内部对象内存
       doubleNode.release(&doubleNode);
       return -1;
   }
   else
   {
       //注意：需要释放pAcquisitionCtrl内部对象内存
       pAcquisitionCtrl->release(pAcquisitionCtrl);
       qDebug()<<"before change ,exposureTime is %f\n"<<exposureTimeValue;
   }

   doubleNode.setValue(&doubleNode, (exposureTimeValue + 2));
   if( isExposureTimeSuccess != 0)
   {
      qDebug()<<"set exposureTime fail.\n";
       //注意：需要释放doubleNode内部对象内存
       doubleNode.release(&doubleNode);
       return -1;
   }

   doubleNode.getValue(&doubleNode, &exposureTimeValue);
   if( isExposureTimeSuccess != 0)
   {
      qDebug()<<"get exposureTime fail.\n";
       //注意：需要释放doubleNode内部对象内存
       doubleNode.release(&doubleNode);
       return -1;
   }
   else
   {
      qDebug()<<"after change ,exposureTime is %f\n"<<exposureTimeValue;
       //注意：需要释放doubleNode内部对象内存
       doubleNode.release(&doubleNode);
   }

   return 0;
}
int32_t HDCamera::GENICAM_CreateStreamSource(GENICAM_Camera *pGetCamera, GENICAM_StreamSource **ppStreamSource)
{
    int32_t isCreateStreamSource;
    GENICAM_StreamSourceInfo stStreamSourceInfo;


    stStreamSourceInfo.channelId = 0;
    stStreamSourceInfo.pCamera = pGetCamera;

    isCreateStreamSource = GENICAM_createStreamSource(&stStreamSourceInfo, ppStreamSource);

    if( isCreateStreamSource != 0)
    {
        //printf("create stream obj  fail.\r\n");
        return -1;
    }

    return 0;
}
int32_t HDCamera::GENICAM_startGrabbing(GENICAM_StreamSource *pStreamSource)
{
    int32_t isStartGrabbingSuccess;
    GENICAM_EGrabStrategy eGrabStrategy;

    eGrabStrategy = grabStrartegySequential;
    isStartGrabbingSuccess = pStreamSource->startGrabbing(pStreamSource, 0, eGrabStrategy);

    if( isStartGrabbingSuccess != 0)
    {
        //printf("StartGrabbing  fail.\n");
        return -1;
    }

    return 0;
}
int32_t HDCamera::GENICAM_stopGrabbing(GENICAM_StreamSource *pStreamSource)
{
   int32_t isStopGrabbingSuccess;

   isStopGrabbingSuccess = pStreamSource->stopGrabbing(pStreamSource);
   if( isStopGrabbingSuccess != 0)
   {
      qDebug()<<"StopGrabbing  fail.\n";
       return -1;
   }

   return 0;
}
int32_t HDCamera::GENICAM_disconnect(GENICAM_Camera *pGetCamera)
{
    int32_t isDisconnectSuccess;

    isDisconnectSuccess = pGetCamera->disConnect(pGetCamera);
    if( isDisconnectSuccess != 0)
    {
       qDebug()<<"disconnect fail.\n";
        return -1;
    }

    return 0;
}
