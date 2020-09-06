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
