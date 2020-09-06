#include "HDCamera.h"
#include <string>
#include <QDebug>
#include <process.h>

//------------------------------------------------------
GENICAM_StreamSource *pStreamSource = NULL;
GENICAM_Camera *Camerainformation;
int32_t ret;
GENICAM_System *pSystem = NULL;
GENICAM_Camera *pCamera = NULL;
GENICAM_Camera *pCameraList = NULL;
GENICAM_AcquisitionControl *pAcquisitionCtrl = NULL;
uint32_t cameraCnt = 0;
HANDLE threadHandle;
unsigned threadID;
int cameraIndex = -1;
//--------------------------------------------------------

HDCamera::HDCamera(QWidget* parent):
    QOpenGLWidget(parent)
{

}
HDCamera::HDCamera()
{

}

unsigned __stdcall frameGrabbingProc()//@@@@@@@@@线程函数需要是静态成员函数@@@@@@@@@@   弄清楚这一点！
{
    int i;
    int32_t ret = -1;
    uint64_t blockId = 0;
    GENICAM_Frame* pFrame;

    for (i = 0; i < 1; i++)
    {
        if(NULL == pStreamSource)
        {
            return 0;
        }


        ret = pStreamSource->getFrame(pStreamSource, &pFrame, 100);
        if (ret < 0)
        {
            qDebug()<<"getFrame  fail.\n";
            continue;
        }

        ret = pFrame->valid(pFrame);
        if (ret < 0)
        {
            qDebug()<<"frame is invalid!\n";

            //Caution：release the frame after using it
            //注意：使用该帧后需要显示释放
            pFrame->release(pFrame);

            continue;
        }

        qDebug()<<"get frame id = [%u] successfully!\n"<<pFrame->getBlockId(pFrame);


        //Caution：release the frame after using it
        //注意：使用该帧后需要显示释放
        pFrame->release(pFrame);
    }

    return 1;
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
void HDCamera::HDCameraParameterInt()
{
    // discover camera
        //发现设备
        ret = GENICAM_getSystemInstance(&pSystem);
        if (-1 == ret)
        {

            qDebug()<<"pSystem is null.\r\n";
            getchar();
            return ;
        }

        ret = pSystem->discovery(pSystem, &pCameraList, &cameraCnt, typeAll);
        if (-1 == ret)
        {
             qDebug()<<"discovery device fail.\r\n";
            getchar();
            return ;
        }

        if(cameraCnt < 1)
        {
            qDebug()<<"no camera\r\n";
            getchar();
            return;
        }
         Camerainformation =&pCameraList[0];
        // ui->HDcameraList->addItem(Camerainformation->getModelName(Camerainformation));
         qDebug()<<"HDCamera init success! ";


};
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
void HDCamera::HD_Connect()
{


     pCamera = &pCameraList[0];
     if(GENICAM_connect(pCamera)==0)
     {
        qDebug()<<"**HDCamera open success! **";
     }
     else
     {
           qDebug()<<"**HDCamera open failed!**";
     }
     //---------------------------修改曝光
     if(modifyCamralExposureTime(pCamera)==0)
     {
         qDebug()<<"**HDCamera modifiy exposure time success!**";
     }
     else
     {
          qDebug()<<"**HDCamera modifiy exposure time failed!**";
     }
     //--------------------------创建流对象
     if(GENICAM_CreateStreamSource(pCamera, &pStreamSource)==0)
     {
         qDebug()<<"**HDCamera create streamsource success!**";
     }
     else
     {
         qDebug()<<"**HDCamera create streamsource failed!**";
          pStreamSource->release(pStreamSource);
     }



     threadHandle = (HANDLE)_beginthreadex(NULL,
                                            0,
                                            (unsigned(__stdcall *)(void *)) frameGrabbingProc,
                                            NULL,
                                            CREATE_SUSPENDED,
                                            &threadID);
     if ( threadHandle == 0 )
         {
             qDebug()<<"Failed to create getFrame thread!\n";
             //注意：需要释放pStreamSource内部对象内存
             pStreamSource->release(pStreamSource);
             return;
         }

     //-------------------------------------拉流
     if(GENICAM_startGrabbing(pStreamSource)==0)
     {
         qDebug()<<"**HDCamera StartGrabbing success!**";
     }
     else
     {
         qDebug()<<"**HDCamera StartGrabbing failed!**";
          pStreamSource->release(pStreamSource);
     }
     //--------------------------------------开启线程
          ResumeThread(threadHandle);

}




