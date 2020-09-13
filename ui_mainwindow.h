/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <OpenGLShow.h>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>
#include <gl_image.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QProgressBar *progressBar;
    GL_Image *openGLWidget_2;
    OpenGLshow *openGLWidget;
    QFrame *frame;
    QLabel *laserAnglelabel;
    QLineEdit *rgeLine;
    QLabel *stepangleplable;
    QLineEdit *stepAngleLine;
    QLabel *Focallabel;
    QLineEdit *pixelSizeLine;
    QLineEdit *baseLineLine;
    QLabel *PixelSizelable;
    QLineEdit *focalLine;
    QLabel *RGBlabel;
    QLabel *baselinelabel;
    QLineEdit *laserAngleLine;
    QPushButton *show3D;
    QPushButton *pointfilepushButton;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QPushButton *senddatabutton;
    QPushButton *openCamera;
    QPushButton *PortButton;
    QComboBox *portcomboBox;
    QTextEdit *textEdit;
    QComboBox *cameralist;
    QPushButton *loadseting;
    QPushButton *Scanningbutton;
    QLineEdit *pointfilelineEdit;
    QPushButton *MaxGLView;
    QPushButton *ProduceMatrix;
    QLineEdit *Picture_N;
    QLineEdit *P_CornerNumber_row;
    QLineEdit *P_CornerNumber_col;
    QLineEdit *Accuracy;
    QLineEdit *CellSize_width;
    QLineEdit *CellSize_height;
    QLineEdit *Iteration_N;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QPushButton *ParameterContrast;
    QLabel *Camera_icon;
    QLabel *camera_light;
    QLabel *scan_light;
    QLabel *label_8;
    QComboBox *Cameraresolution;
    QComboBox *Cameraframerate;
    QWidget *widget;
    QPushButton *OpenHDcamera;
    QSlider *CameraBrightness;
    QSlider *CameraGain;
    QLabel *label_9;
    QLabel *label_10;
    QSpinBox *Brightness_spinBox;
    QSpinBox *Cameragain_spinBox;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1290, 769);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/picture/camera.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(590, 740, 691, 21));
        progressBar->setValue(0);
        openGLWidget_2 = new GL_Image(centralwidget);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));
        openGLWidget_2->setGeometry(QRect(0, 0, 651, 480));
        openGLWidget_2->setFocusPolicy(Qt::ClickFocus);
        openGLWidget_2->setAutoFillBackground(true);
        openGLWidget = new OpenGLshow(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(649, 0, 641, 480));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(10, 490, 1271, 161));
        frame->setFocusPolicy(Qt::StrongFocus);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        laserAnglelabel = new QLabel(frame);
        laserAnglelabel->setObjectName(QString::fromUtf8("laserAnglelabel"));
        laserAnglelabel->setGeometry(QRect(10, 110, 60, 16));
        rgeLine = new QLineEdit(frame);
        rgeLine->setObjectName(QString::fromUtf8("rgeLine"));
        rgeLine->setGeometry(QRect(81, 139, 61, 20));
        stepangleplable = new QLabel(frame);
        stepangleplable->setObjectName(QString::fromUtf8("stepangleplable"));
        stepangleplable->setGeometry(QRect(8, 84, 54, 16));
        stepAngleLine = new QLineEdit(frame);
        stepAngleLine->setObjectName(QString::fromUtf8("stepAngleLine"));
        stepAngleLine->setGeometry(QRect(81, 87, 61, 20));
        Focallabel = new QLabel(frame);
        Focallabel->setObjectName(QString::fromUtf8("Focallabel"));
        Focallabel->setGeometry(QRect(10, 34, 30, 16));
        pixelSizeLine = new QLineEdit(frame);
        pixelSizeLine->setObjectName(QString::fromUtf8("pixelSizeLine"));
        pixelSizeLine->setGeometry(QRect(81, 9, 61, 20));
        pixelSizeLine->setEchoMode(QLineEdit::Normal);
        pixelSizeLine->setDragEnabled(false);
        pixelSizeLine->setReadOnly(false);
        baseLineLine = new QLineEdit(frame);
        baseLineLine->setObjectName(QString::fromUtf8("baseLineLine"));
        baseLineLine->setGeometry(QRect(81, 61, 61, 20));
        PixelSizelable = new QLabel(frame);
        PixelSizelable->setObjectName(QString::fromUtf8("PixelSizelable"));
        PixelSizelable->setGeometry(QRect(11, 7, 54, 16));
        focalLine = new QLineEdit(frame);
        focalLine->setObjectName(QString::fromUtf8("focalLine"));
        focalLine->setGeometry(QRect(81, 35, 61, 20));
        RGBlabel = new QLabel(frame);
        RGBlabel->setObjectName(QString::fromUtf8("RGBlabel"));
        RGBlabel->setGeometry(QRect(10, 134, 18, 16));
        baselinelabel = new QLabel(frame);
        baselinelabel->setObjectName(QString::fromUtf8("baselinelabel"));
        baselinelabel->setGeometry(QRect(9, 59, 48, 16));
        laserAngleLine = new QLineEdit(frame);
        laserAngleLine->setObjectName(QString::fromUtf8("laserAngleLine"));
        laserAngleLine->setGeometry(QRect(81, 113, 61, 20));
        show3D = new QPushButton(frame);
        show3D->setObjectName(QString::fromUtf8("show3D"));
        show3D->setGeometry(QRect(710, 10, 91, 71));
        pointfilepushButton = new QPushButton(frame);
        pointfilepushButton->setObjectName(QString::fromUtf8("pointfilepushButton"));
        pointfilepushButton->setGeometry(QRect(580, 130, 111, 23));
        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(160, 100, 81, 16));
        checkBox->setAcceptDrops(true);
        checkBox->setToolTipDuration(-1);
        checkBox->setChecked(true);
        checkBox_2 = new QCheckBox(frame);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(160, 130, 81, 16));
        senddatabutton = new QPushButton(frame);
        senddatabutton->setObjectName(QString::fromUtf8("senddatabutton"));
        senddatabutton->setGeometry(QRect(350, 10, 91, 31));
        openCamera = new QPushButton(frame);
        openCamera->setObjectName(QString::fromUtf8("openCamera"));
        openCamera->setGeometry(QRect(580, 50, 111, 31));
        openCamera->setFocusPolicy(Qt::StrongFocus);
        PortButton = new QPushButton(frame);
        PortButton->setObjectName(QString::fromUtf8("PortButton"));
        PortButton->setGeometry(QRect(250, 10, 91, 31));
        portcomboBox = new QComboBox(frame);
        portcomboBox->setObjectName(QString::fromUtf8("portcomboBox"));
        portcomboBox->setEnabled(true);
        portcomboBox->setGeometry(QRect(150, 10, 91, 31));
        portcomboBox->setContextMenuPolicy(Qt::NoContextMenu);
        portcomboBox->setToolTipDuration(1);
        textEdit = new QTextEdit(frame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(250, 50, 191, 101));
        cameralist = new QComboBox(frame);
        cameralist->setObjectName(QString::fromUtf8("cameralist"));
        cameralist->setGeometry(QRect(460, 11, 81, 31));
        loadseting = new QPushButton(frame);
        loadseting->setObjectName(QString::fromUtf8("loadseting"));
        loadseting->setGeometry(QRect(150, 50, 91, 31));
        Scanningbutton = new QPushButton(frame);
        Scanningbutton->setObjectName(QString::fromUtf8("Scanningbutton"));
        Scanningbutton->setGeometry(QRect(580, 90, 111, 31));
        pointfilelineEdit = new QLineEdit(frame);
        pointfilelineEdit->setObjectName(QString::fromUtf8("pointfilelineEdit"));
        pointfilelineEdit->setEnabled(true);
        pointfilelineEdit->setGeometry(QRect(460, 130, 111, 21));
        MaxGLView = new QPushButton(frame);
        MaxGLView->setObjectName(QString::fromUtf8("MaxGLView"));
        MaxGLView->setGeometry(QRect(710, 90, 91, 61));
        ProduceMatrix = new QPushButton(frame);
        ProduceMatrix->setObjectName(QString::fromUtf8("ProduceMatrix"));
        ProduceMatrix->setGeometry(QRect(1000, 100, 131, 51));
        Picture_N = new QLineEdit(frame);
        Picture_N->setObjectName(QString::fromUtf8("Picture_N"));
        Picture_N->setGeometry(QRect(930, 10, 61, 20));
        P_CornerNumber_row = new QLineEdit(frame);
        P_CornerNumber_row->setObjectName(QString::fromUtf8("P_CornerNumber_row"));
        P_CornerNumber_row->setGeometry(QRect(930, 40, 61, 20));
        P_CornerNumber_col = new QLineEdit(frame);
        P_CornerNumber_col->setObjectName(QString::fromUtf8("P_CornerNumber_col"));
        P_CornerNumber_col->setGeometry(QRect(930, 70, 61, 20));
        Accuracy = new QLineEdit(frame);
        Accuracy->setObjectName(QString::fromUtf8("Accuracy"));
        Accuracy->setGeometry(QRect(1080, 40, 61, 20));
        CellSize_width = new QLineEdit(frame);
        CellSize_width->setObjectName(QString::fromUtf8("CellSize_width"));
        CellSize_width->setGeometry(QRect(930, 100, 61, 20));
        CellSize_height = new QLineEdit(frame);
        CellSize_height->setObjectName(QString::fromUtf8("CellSize_height"));
        CellSize_height->setGeometry(QRect(930, 130, 61, 20));
        Iteration_N = new QLineEdit(frame);
        Iteration_N->setObjectName(QString::fromUtf8("Iteration_N"));
        Iteration_N->setGeometry(QRect(1080, 10, 61, 20));
        label_7 = new QLabel(frame);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(810, 10, 54, 12));
        label_2 = new QLabel(frame);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(810, 40, 111, 16));
        label = new QLabel(frame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(810, 70, 121, 16));
        label_3 = new QLabel(frame);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(810, 100, 111, 16));
        label_4 = new QLabel(frame);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(810, 130, 91, 16));
        label_5 = new QLabel(frame);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(1000, 10, 71, 16));
        label_6 = new QLabel(frame);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(1000, 40, 54, 12));
        ParameterContrast = new QPushButton(frame);
        ParameterContrast->setObjectName(QString::fromUtf8("ParameterContrast"));
        ParameterContrast->setGeometry(QRect(1140, 100, 121, 51));
        Camera_icon = new QLabel(frame);
        Camera_icon->setObjectName(QString::fromUtf8("Camera_icon"));
        Camera_icon->setGeometry(QRect(460, 47, 35, 35));
        Camera_icon->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/camera_01.jpg);"));
        Camera_icon->setTextFormat(Qt::AutoText);
        Camera_icon->setScaledContents(true);
        Camera_icon->setWordWrap(true);
        camera_light = new QLabel(frame);
        camera_light->setObjectName(QString::fromUtf8("camera_light"));
        camera_light->setGeometry(QRect(503, 50, 68, 31));
        camera_light->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/gray.png);"));
        camera_light->setPixmap(QPixmap(QString::fromUtf8("picture/gray.png")));
        scan_light = new QLabel(frame);
        scan_light->setObjectName(QString::fromUtf8("scan_light"));
        scan_light->setGeometry(QRect(503, 90, 68, 31));
        scan_light->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/gray.png);"));
        scan_light->setPixmap(QPixmap(QString::fromUtf8("picture/gray.png")));
        label_8 = new QLabel(frame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(460, 87, 35, 35));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/Scaneye.jpg);"));
        Cameraresolution = new QComboBox(frame);
        Cameraresolution->setObjectName(QString::fromUtf8("Cameraresolution"));
        Cameraresolution->setGeometry(QRect(550, 11, 91, 31));
        Cameraframerate = new QComboBox(frame);
        Cameraframerate->setObjectName(QString::fromUtf8("Cameraframerate"));
        Cameraframerate->setGeometry(QRect(650, 11, 41, 31));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 660, 571, 101));
        OpenHDcamera = new QPushButton(widget);
        OpenHDcamera->setObjectName(QString::fromUtf8("OpenHDcamera"));
        OpenHDcamera->setGeometry(QRect(250, 10, 101, 51));
        CameraBrightness = new QSlider(widget);
        CameraBrightness->setObjectName(QString::fromUtf8("CameraBrightness"));
        CameraBrightness->setGeometry(QRect(90, 10, 101, 22));
        CameraBrightness->setMinimumSize(QSize(101, 22));
        CameraBrightness->setMaximum(100);
        CameraBrightness->setSingleStep(1);
        CameraBrightness->setValue(70);
        CameraBrightness->setOrientation(Qt::Horizontal);
        CameraGain = new QSlider(widget);
        CameraGain->setObjectName(QString::fromUtf8("CameraGain"));
        CameraGain->setGeometry(QRect(90, 40, 101, 22));
        CameraGain->setMaximum(30);
        CameraGain->setValue(7);
        CameraGain->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 10, 71, 16));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 40, 71, 16));
        Brightness_spinBox = new QSpinBox(widget);
        Brightness_spinBox->setObjectName(QString::fromUtf8("Brightness_spinBox"));
        Brightness_spinBox->setGeometry(QRect(200, 10, 42, 22));
        Brightness_spinBox->setValue(70);
        Cameragain_spinBox = new QSpinBox(widget);
        Cameragain_spinBox->setObjectName(QString::fromUtf8("Cameragain_spinBox"));
        Cameragain_spinBox->setGeometry(QRect(200, 40, 42, 22));
        Cameragain_spinBox->setValue(7);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Laser Scanner", nullptr));
        laserAnglelabel->setText(QCoreApplication::translate("MainWindow", "laserAngle", nullptr));
        rgeLine->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        stepangleplable->setText(QCoreApplication::translate("MainWindow", "stepAngle", nullptr));
        stepAngleLine->setText(QCoreApplication::translate("MainWindow", "0.7", nullptr));
        Focallabel->setText(QCoreApplication::translate("MainWindow", "focal", nullptr));
        pixelSizeLine->setText(QCoreApplication::translate("MainWindow", "0.009", nullptr));
        baseLineLine->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        PixelSizelable->setText(QCoreApplication::translate("MainWindow", "pixelSize", nullptr));
        focalLine->setText(QCoreApplication::translate("MainWindow", "2.7", nullptr));
        RGBlabel->setText(QCoreApplication::translate("MainWindow", "rgb", nullptr));
        baselinelabel->setText(QCoreApplication::translate("MainWindow", "baseLine", nullptr));
        laserAngleLine->setText(QCoreApplication::translate("MainWindow", "70", nullptr));
#if QT_CONFIG(tooltip)
        show3D->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\344\272\221\346\225\260\346\215\256\346\230\276\347\244\272</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        show3D->setText(QCoreApplication::translate("MainWindow", "Show 3D Model", nullptr));
#if QT_CONFIG(tooltip)
        pointfilepushButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\344\272\221\346\226\207\344\273\266\350\267\257\345\276\204</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pointfilepushButton->setText(QCoreApplication::translate("MainWindow", "Cloud Path", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Turn Left", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Turn Right", nullptr));
#if QT_CONFIG(tooltip)
        senddatabutton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\217\221\351\200\201\346\225\260\346\215\256\345\210\260\344\270\262\345\217\243</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        senddatabutton->setText(QCoreApplication::translate("MainWindow", "Send Message", nullptr));
#if QT_CONFIG(tooltip)
        openCamera->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\347\233\270\346\234\272</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        openCamera->setText(QCoreApplication::translate("MainWindow", "Open Camera", nullptr));
#if QT_CONFIG(tooltip)
        PortButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\344\270\262\345\217\243</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PortButton->setText(QCoreApplication::translate("MainWindow", "Open Port", nullptr));
#if QT_CONFIG(tooltip)
        loadseting->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\350\275\275\345\205\245\346\211\253\346\217\217\345\217\202\346\225\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        loadseting->setText(QCoreApplication::translate("MainWindow", "Load Seting", nullptr));
#if QT_CONFIG(tooltip)
        Scanningbutton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\274\200\345\220\257\346\211\253\346\217\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Scanningbutton->setText(QCoreApplication::translate("MainWindow", "Start Scan", nullptr));
#if QT_CONFIG(tooltip)
        MaxGLView->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\344\272\221\347\252\227\345\217\243\346\234\200\345\244\247\345\214\226</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        MaxGLView->setText(QCoreApplication::translate("MainWindow", "Max GLView", nullptr));
#if QT_CONFIG(tooltip)
        ProduceMatrix->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\224\237\346\210\220\347\225\270\345\217\230\346\240\241\345\207\206\347\237\251\351\230\265</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ProduceMatrix->setText(QCoreApplication::translate("MainWindow", "Produce Matrix", nullptr));
        Picture_N->setText(QCoreApplication::translate("MainWindow", "62", nullptr));
        P_CornerNumber_row->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        P_CornerNumber_col->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        Accuracy->setText(QCoreApplication::translate("MainWindow", "0.01", nullptr));
        CellSize_width->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        CellSize_height->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        Iteration_N->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Picture_N", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "P_CornerNumber_row", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "P_CornerNumber_col", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CellSize_width", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "CellSize_height", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Iteration_N", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Accuracy", nullptr));
#if QT_CONFIG(tooltip)
        ParameterContrast->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\225\270\345\217\230\346\240\241\345\207\206\346\265\213\350\257\225</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ParameterContrast->setText(QCoreApplication::translate("MainWindow", "Calibrate Contrast", nullptr));
        Camera_icon->setText(QString());
        camera_light->setText(QString());
        scan_light->setText(QString());
        label_8->setText(QString());
        OpenHDcamera->setText(QCoreApplication::translate("MainWindow", "OpenHDCamera", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "brightness ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Camera gain", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
