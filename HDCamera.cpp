﻿#include "HDCamera.h"
#include "GenICam/System.h"
#include "GenICam/Camera.h"
#include "GenICam/StreamSource.h"
#include <QDebug>

#define DEFAULT_SHOW_RATE (30) // 默认显示帧率
#define DEFAULT_ERROR_STRING ("N/A")
#define MAX_FRAME_STAT_NUM (50)
#define MIN_LEFT_LIST_NUM (2)
#define MAX_STATISTIC_INTERVAL (5000000000) // List的更新时与最新一帧的时间最大间隔

HDCamera::HDCamera(QWidget *parent) :
    QWidget(parent)
  , m_thdDisplayThread(CThreadLite::ThreadProc(&HDCamera::DisplayThreadProc, this), "Display")
  , m_nDisplayInterval(0)
  , m_nFirstFrameTime(0)
  , m_nLastFrameTime(0)
  , m_bNeedUpdate(true)
  , m_nTotalFrameCount(0)
{

}
HDCamera::HDCamera():
    m_thdDisplayThread(CThreadLite::ThreadProc(&HDCamera::DisplayThreadProc, this), "Display")
  , m_nDisplayInterval(0)
  , m_nFirstFrameTime(0)
  , m_nLastFrameTime(0)
  , m_bNeedUpdate(true)
  , m_nTotalFrameCount(0)
{

};
HDCamera::~HDCamera()
{
    //关闭显示线程
    if (!m_thdDisplayThread.isThreadOver())
    {
        m_thdDisplayThread.destroyThread();
    }

}
// 取流回调函数
void HDCamera::FrameCallback(const CFrame& frame)
{
    CFrameInfo frameInfo;
    frameInfo.m_nWidth = frame.getImageWidth();
    frameInfo.m_nHeight = frame.getImageHeight();
    frameInfo.m_nBufferSize = frame.getImageSize();
    frameInfo.m_nPaddingX = frame.getImagePadddingX();
    frameInfo.m_nPaddingY = frame.getImagePadddingY();
    frameInfo.m_ePixelType = frame.getImagePixelFormat();
    frameInfo.m_pImageBuf = (BYTE *)malloc(sizeof(BYTE)* frameInfo.m_nBufferSize);
    frameInfo.m_nTimeStamp = frame.getImageTimeStamp();

    /* 内存申请失败，直接返回 */
    if (frameInfo.m_pImageBuf != NULL)
    {
        memcpy(frameInfo.m_pImageBuf, frame.getImage(), frame.getImageSize());

        if (m_qDisplayFrameQueue.size() > 16)
        {
            CFrameInfo frameOld;
            m_qDisplayFrameQueue.get(frameOld);
            free(frameOld.m_pImageBuf);
        }

        m_qDisplayFrameQueue.push_back(frameInfo);
    }

    recvNewFrame(frame);
}

// 设置曝光
bool HDCamera::SetExposeTime(double dExposureTime)
{
    if (NULL == m_pCamera)
    {
        printf("Set ExposureTime fail. No camera or camera is not connected.\n");
        return false;
    }

    CDoubleNode nodeExposureTime(m_pCamera, "ExposureTime");

    if (false == nodeExposureTime.isValid())
    {
        printf("get ExposureTime node fail.\n");
        return false;
    }

    if (false == nodeExposureTime.isAvailable())
    {
        printf("ExposureTime is not available.\n");
        return false;
    }

    if (false == nodeExposureTime.setValue(dExposureTime))
    {
        printf("set ExposureTime value = %f fail.\n", dExposureTime);
        return false;
    }

    return true;
}

// 设置增益
bool HDCamera::SetAdjustPlus(double dGainRaw)
{
    if (NULL == m_pCamera)
    {
        printf("Set GainRaw fail. No camera or camera is not connected.\n");
        return false;
    }

    CDoubleNode nodeGainRaw(m_pCamera, "GainRaw");

    if (false == nodeGainRaw.isValid())
    {
        printf("get GainRaw node fail.\n");
        return false;
    }

    if (false == nodeGainRaw.isAvailable())
    {
        printf("GainRaw is not available.\n");
        return false;
    }

    if (false == nodeGainRaw.setValue(dGainRaw))
    {
        printf("set GainRaw value = %f fail.\n", dGainRaw);
        return false;
    }

    return true;
}

// 打开相机
bool HDCamera::CameraOpen(void)
{
    if (NULL == m_pCamera)
    {
        printf("connect camera fail. No camera.\n");
        return false;
    }

    if (true == m_pCamera->isConnected())
    {
        printf("camera is already connected.\n");
        return true;
    }

    if (false == m_pCamera->connect())
    {
        printf("connect camera fail.\n");
        return false;
    }

    return true;
}

// 关闭相机
bool HDCamera::CameraClose(void)
{
    if (NULL == m_pCamera)
    {
        printf("disconnect camera fail. No camera.\n");
        return false;
    }

    if (false == m_pCamera->isConnected())
    {
        printf("camera is already disconnected.\n");
        return true;
    }

    if (false == m_pCamera->disConnect())
    {
        printf("disconnect camera fail.\n");
        return false;
    }

    return true;
}

// 开始采集
bool HDCamera::CameraStart()
{
    if (NULL == m_pStreamSource)
    {
        m_pStreamSource = CSystem::getInstance().createStreamSource(m_pCamera);
    }

    if (NULL == m_pStreamSource)
    {
        return false;
    }

    if (m_pStreamSource->isGrabbing())
    {
        return true;
    }

    bool bRet = m_pStreamSource->attachGrabbing(IStreamSource::Proc(&HDCamera::FrameCallback, this));
    if (!bRet)
    {
        return false;
    }

    if (!m_pStreamSource->startGrabbing())
    {
        return false;
    }

    return true;
}

// 停止采集
bool HDCamera::CameraStop()
{
    if (m_pStreamSource != NULL)
    {
        m_pStreamSource->detachGrabbing(IStreamSource::Proc(&HDCamera::FrameCallback, this));

        m_pStreamSource->stopGrabbing();
        m_pStreamSource.reset();
    }

    /* 清空显示队列 */
    m_qDisplayFrameQueue.clear();

    return true;
}

// 切换采集方式、触发方式 （连续采集、外部触发、软件触发）
bool HDCamera::CameraChangeTrig(ETrigType trigType)
{
    if (NULL == m_pCamera)
    {
        printf("Change Trig fail. No camera or camera is not connected.\n");
        return false;
    }

    if (trigContinous == trigType)
    {
        //设置触发模式
        CEnumNode nodeTriggerMode(m_pCamera, "TriggerMode");
        if (false == nodeTriggerMode.isValid())
        {
            printf("get TriggerMode node fail.\n");
            return false;
        }
        if (false == nodeTriggerMode.setValueBySymbol("Off"))
        {
            printf("set TriggerMode value = Off fail.\n");
            return false;
        }
    }
    else if (trigSoftware == trigType)
    {
        //设置触发器
        CEnumNode nodeTriggerSelector(m_pCamera, "TriggerSelector");
        if (false == nodeTriggerSelector.isValid())
        {
            printf("get TriggerSelector node fail.\n");
            return false;
        }
        if (false == nodeTriggerSelector.setValueBySymbol("FrameStart"))
        {
            printf("set TriggerSelector value = FrameStart fail.\n");
            return false;
        }

        //设置触发模式
        CEnumNode nodeTriggerMode(m_pCamera, "TriggerMode");
        if (false == nodeTriggerMode.isValid())
        {
            printf("get TriggerMode node fail.\n");
            return false;
        }
        if (false == nodeTriggerMode.setValueBySymbol("On"))
        {
            printf("set TriggerMode value = On fail.\n");
            return false;
        }

        //设置触发源为软触发
        CEnumNode nodeTriggerSource(m_pCamera, "TriggerSource");
        if (false == nodeTriggerSource.isValid())
        {
            printf("get TriggerSource node fail.\n");
            return false;
        }
        if (false == nodeTriggerSource.setValueBySymbol("Software"))
        {
            printf("set TriggerSource value = Software fail.\n");
            return false;
        }
    }
    else if (trigLine == trigType)
    {
        //设置触发器
        CEnumNode nodeTriggerSelector(m_pCamera, "TriggerSelector");
        if (false == nodeTriggerSelector.isValid())
        {
            printf("get TriggerSelector node fail.\n");
            return false;
        }
        if (false == nodeTriggerSelector.setValueBySymbol("FrameStart"))
        {
            printf("set TriggerSelector value = FrameStart fail.\n");
            return false;
        }

        //设置触发模式
        CEnumNode nodeTriggerMode(m_pCamera, "TriggerMode");
        if (false == nodeTriggerMode.isValid())
        {
            printf("get TriggerMode node fail.\n");
            return false;
        }
        if (false == nodeTriggerMode.setValueBySymbol("On"))
        {
            printf("set TriggerMode value = On fail.\n");
            return false;
        }

        //设置触发源为Line1触发
        CEnumNode nodeTriggerSource(m_pCamera, "TriggerSource");
        if (false == nodeTriggerSource.isValid())
        {
            printf("get TriggerSource node fail.\n");
            return false;
        }
        if (false == nodeTriggerSource.setValueBySymbol("Line1"))
        {
            printf("set TriggerSource value = Line1 fail.\n");
            return false;
        }
    }

    return true;
}

// 执行一次软触发
bool HDCamera::ExecuteSoftTrig(void)
{
    if (NULL == m_pCamera)
    {
        printf("Set GainRaw fail. No camera or camera is not connected.\n");
        return false;
    }

    CCmdNode nodeTriggerSoftware(m_pCamera, "TriggerSoftware");
    if (false == nodeTriggerSoftware.isValid())
    {
        printf("get TriggerSoftware node fail.\n");
        return false;
    }
    if (false == nodeTriggerSoftware.execute())
    {
        printf("set TriggerSoftware fail.\n");
        return false;
    }

    printf("ExecuteSoftTrig success.\n");
    return true;
}

// 设置当前相机
void HDCamera::SetCemera(const QString& strKey)
{
    CSystem &systemObj = CSystem::getInstance();
    qDebug()<<strKey.toStdString().c_str();
    m_pCamera = systemObj.getCameraPtr(strKey.toStdString().c_str());

}

// 显示
bool HDCamera::ShowImage(uint8_t* pRgbFrameBuf, int nWidth, int nHeight, uint64_t nPixelFormat)
{
    QImage image;
    if (NULL == pRgbFrameBuf ||
        nWidth == 0 ||
        nHeight == 0)
    {
        printf("%s image is invalid.\n", __FUNCTION__);
        return false;
    }
    if (Dahua::GenICam::gvspPixelMono8 == nPixelFormat)
    {
        image = QImage(pRgbFrameBuf, nWidth, nHeight, QImage::Format_Grayscale8);
    }
    else
    {
        image = QImage(pRgbFrameBuf,nWidth, nHeight, QImage::Format_RGB888);
    }
    //将QImage的大小收缩或拉伸，与label的大小保持一致。这样label中能显示完整的图片
   // QImage imageScale = image.scaled(QSize(ui->label_Pixmap->width(), ui->label_Pixmap->height()));
   // QPixmap pixmap = QPixmap::fromImage(imageScale);
   // ui->label_Pixmap->setPixmap(pixmap);
    free(pRgbFrameBuf);

    return true;
}

// 显示线程
void HDCamera::DisplayThreadProc(Dahua::Infra::CThreadLite& lite)
{
    while (lite.looping())
    {
        CFrameInfo frameInfo;

        if (false == m_qDisplayFrameQueue.get(frameInfo, 500))
        {
            continue;
        }

        // 判断是否要显示。超过显示上限（30帧），就不做转码、显示处理
        if (!isTimeToDisplay())
        {
            /* 释放内存 */
            free(frameInfo.m_pImageBuf);
            continue;
        }

        /* mono8格式可不做转码，直接显示，其他格式需要经过转码才能显示 */
        if (Dahua::GenICam::gvspPixelMono8 == frameInfo.m_ePixelType)
        {
            //显示线程中发送显示信号，在主线程中显示图像
            emit signalShowImage(frameInfo.m_pImageBuf, frameInfo.m_nWidth, frameInfo.m_nHeight, frameInfo.m_ePixelType);

        }
        else
        {
            /* 转码 */
            uint8_t *pRGBbuffer = NULL;
            int nRgbBufferSize = 0;
            nRgbBufferSize = frameInfo.m_nWidth * frameInfo.m_nHeight * 3;
            pRGBbuffer = (uint8_t *)malloc(nRgbBufferSize);
            if (pRGBbuffer == NULL)
            {
                /* 释放内存 */
                free(frameInfo.m_pImageBuf);
                printf("RGBbuffer malloc failed.\n");
                continue;
            }

            IMGCNV_SOpenParam openParam;
            openParam.width = frameInfo.m_nWidth;
            openParam.height = frameInfo.m_nHeight;
            openParam.paddingX = frameInfo.m_nPaddingX;
            openParam.paddingY = frameInfo.m_nPaddingY;
            openParam.dataSize = frameInfo.m_nBufferSize;
            openParam.pixelForamt = frameInfo.m_ePixelType;

            IMGCNV_EErr status = IMGCNV_ConvertToRGB24(frameInfo.m_pImageBuf, &openParam, pRGBbuffer, &nRgbBufferSize);
            if (IMGCNV_SUCCESS != status)
            {
                /* 释放内存 */
                printf("IMGCNV_ConvertToRGB24 failed.\n");
                free(frameInfo.m_pImageBuf);
                free(pRGBbuffer);
                return;
            }

            /* 释放内存 */
            free(frameInfo.m_pImageBuf);

            //显示线程中发送显示信号，在主线程中显示图像
            emit signalShowImage(pRGBbuffer, openParam.width, openParam.height, openParam.pixelForamt);

        }
    }
}

bool HDCamera::isTimeToDisplay()
{
    CGuard guard(m_mxTime);

    // 不显示
    if (m_nDisplayInterval <= 0)
    {
        return false;
    }

    // 第一帧必须显示
    if (m_nFirstFrameTime == 0 || m_nLastFrameTime == 0)
    {
        m_nFirstFrameTime = m_elapsedTimer.nsecsElapsed();
        m_nLastFrameTime = m_nFirstFrameTime;

        return true;
    }

    // 当前帧和上一帧的间隔如果大于显示间隔就显示
    uint64_t nCurTimeTmp = m_elapsedTimer.nsecsElapsed();
    uint64_t nAcquisitionInterval = nCurTimeTmp - m_nLastFrameTime;
    if (nAcquisitionInterval > m_nDisplayInterval)
    {
        m_nLastFrameTime = nCurTimeTmp;
        return true;
    }

    // 当前帧相对于第一帧的时间间隔
    uint64_t nPre = (m_nLastFrameTime - m_nFirstFrameTime) % m_nDisplayInterval;
    if (nPre + nAcquisitionInterval > m_nDisplayInterval)
    {
        m_nLastFrameTime = nCurTimeTmp;
        return true;
    }

    return false;
}

// 设置显示频率
void HDCamera::setDisplayFPS(int nFPS)
{
    if (nFPS > 0)
    {
        CGuard guard(m_mxTime);

        m_nDisplayInterval = 1000 * 1000 * 1000.0 / nFPS;
    }
    else
    {
        CGuard guard(m_mxTime);
        m_nDisplayInterval = 0;
    }
}

// 窗口关闭响应函数
void HDCamera::closeEvent(QCloseEvent * event)
{
    if (NULL != m_pStreamSource && m_pStreamSource->isGrabbing())
        m_pStreamSource->stopGrabbing();
    if (NULL != m_pCamera && m_pCamera->isConnected())
        m_pCamera->disConnect();
}

/* 状态栏统计信息 start */
void HDCamera::resetStatistic()
{
    QMutexLocker locker(&m_mxStatistic);
    m_nTotalFrameCount = 0;
    m_listFrameStatInfo.clear();
    m_bNeedUpdate = true;
}
QString HDCamera::getStatistic()
{
    if (m_mxStatistic.tryLock(30))
    {
        if (m_bNeedUpdate)
        {
            updateStatistic();
        }

        m_mxStatistic.unlock();
        return m_strStatistic;
    }
    return "";
}
void HDCamera::updateStatistic()
{
    size_t nFrameCount = m_listFrameStatInfo.size();
    QString strFPS = DEFAULT_ERROR_STRING;
    QString strSpeed = DEFAULT_ERROR_STRING;

    if (nFrameCount > 1)
    {
        quint64 nTotalSize = 0;
        FrameList::const_iterator it = m_listFrameStatInfo.begin();

        if (m_listFrameStatInfo.size() == 2)
        {
            nTotalSize = m_listFrameStatInfo.back().m_nFrameSize;
        }
        else
        {
            for (++it; it != m_listFrameStatInfo.end(); ++it)
            {
                nTotalSize += it->m_nFrameSize;
            }
        }

        const FrameStatInfo& first = m_listFrameStatInfo.front();
        const FrameStatInfo& last = m_listFrameStatInfo.back();

        qint64 nsecs = last.m_nPassTime - first.m_nPassTime;

        if (nsecs > 0)
        {
            double dFPS = (nFrameCount - 1) * ((double)1000000000.0 / nsecs);
            double dSpeed = nTotalSize * ((double)1000000000.0 / nsecs) / (1000.0) / (1000.0) * (8.0);
            strFPS = QString::number(dFPS, 'f', 2);
            strSpeed = QString::number(dSpeed, 'f', 2);
        }
    }

    m_strStatistic = QString("Stream: %1 images   %2 FPS   %3 Mbps")
        .arg(m_nTotalFrameCount)
        .arg(strFPS)
        .arg(strSpeed);
    m_bNeedUpdate = false;
}
void HDCamera::recvNewFrame(const CFrame& pBuf)
{
    QMutexLocker locker(&m_mxStatistic);
    if (m_listFrameStatInfo.size() >= MAX_FRAME_STAT_NUM)
    {
        m_listFrameStatInfo.pop_front();
    }
    m_listFrameStatInfo.push_back(FrameStatInfo(pBuf.getImageSize(), m_elapsedTimer.nsecsElapsed()));
    ++m_nTotalFrameCount;

    if (m_listFrameStatInfo.size() > MIN_LEFT_LIST_NUM)
    {
        FrameStatInfo infoFirst = m_listFrameStatInfo.front();
        FrameStatInfo infoLast = m_listFrameStatInfo.back();
        while (m_listFrameStatInfo.size() > MIN_LEFT_LIST_NUM && infoLast.m_nPassTime - infoFirst.m_nPassTime > MAX_STATISTIC_INTERVAL)
        {
            m_listFrameStatInfo.pop_front();
            infoFirst = m_listFrameStatInfo.front();
        }
    }

    m_bNeedUpdate = true;
}
/* 状态栏统计信息 end */
