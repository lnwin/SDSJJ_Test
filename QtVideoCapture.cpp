#include <QtVideoCapture.h>
#include <QVideoSurfaceFormat>


QtVideoCapture::QtVideoCapture(QObject *parent) : QAbstractVideoSurface(parent)
{

}
QtVideoCapture::~QtVideoCapture()
{

}
//QtVideoCapture::QtVideoCapture()
//{

//}
bool QtVideoCapture::isFormatSupported(const QVideoSurfaceFormat & format) const
{
    return QVideoFrame::imageFormatFromPixelFormat(format.pixelFormat()) != QImage::Format_Invalid && !format.frameSize().isEmpty() && format.handleType() == QAbstractVideoBuffer::NoHandle;
}
bool QtVideoCapture::start(const QVideoSurfaceFormat &videoformat)
{
    //qDebug() << QVideoFrame::imageFormatFromPixelFormat(videoformat.pixelFormat());              //格式是RGB32
    if(QVideoFrame::imageFormatFromPixelFormat(videoformat.pixelFormat()) != QImage::Format_Invalid && !videoformat.frameSize().isEmpty()){
        QAbstractVideoSurface::start(videoformat);
        return true;
    }
    return false;
}
void QtVideoCapture::stop()
{
    QAbstractVideoSurface::stop();
}
bool QtVideoCapture::present(const QVideoFrame &frame)//-----------------------------------自动捕获帧函数
{
    if (frame.isValid())
    {
        QVideoFrame cloneFrame(frame);
        cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
        const QImage image(cloneFrame.bits(),
                           cloneFrame.width(),
                           cloneFrame.height(),
                           QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
        emit frameAvailable(image);        
        cloneFrame.unmap();
        return true;

    }

    return false;
}
QList<QVideoFrame::PixelFormat> QtVideoCapture::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const//-----格式设置
{
    if (handleType == QAbstractVideoBuffer::NoHandle)
    {
        return QList<QVideoFrame::PixelFormat>()<< QVideoFrame::Format_RGB32<< QVideoFrame::Format_ARGB32<< QVideoFrame::Format_ARGB32_Premultiplied<< QVideoFrame::Format_RGB565<< QVideoFrame::Format_RGB555;
    } else {
        return QList<QVideoFrame::PixelFormat>();
    }

}
