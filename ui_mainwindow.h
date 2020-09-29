/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <gl_image.h>
#include "OpenGLShow.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_5;
    QFrame *MianWD;
    QVBoxLayout *verticalLayout_16;
    QWidget *openglWindows;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    GL_Image *openGLWidget_2;
    OpenGLshow *openGLWidget;
    QFrame *toolFrame;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QLabel *PixelSizelable;
    QLabel *Focallabel;
    QLabel *baselinelabel;
    QLabel *stepangleplable;
    QLabel *laserAnglelabel;
    QLabel *RGBlabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *focalLine;
    QLineEdit *pixelSizeLine;
    QLineEdit *baseLineLine;
    QLineEdit *stepAngleLine;
    QLineEdit *laserAngleLine;
    QLineEdit *rgeLine;
    QVBoxLayout *verticalLayout_3;
    QPushButton *loadseting;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QVBoxLayout *verticalLayout_4;
    QComboBox *portcomboBox;
    QPushButton *PortButton;
    QPushButton *senddatabutton;
    QVBoxLayout *verticalLayout_5;
    QTextEdit *textEdit;
    QGridLayout *gridLayout;
    QLabel *scan_light;
    QLabel *camera_light;
    QLabel *label_8;
    QLabel *Camera_icon;
    QVBoxLayout *verticalLayout_6;
    QComboBox *cameralist;
    QPushButton *openCamera;
    QPushButton *Scanningbutton;
    QPushButton *pointfilepushButton;
    QLineEdit *pointfilelineEdit;
    QVBoxLayout *verticalLayout_7;
    QPushButton *show3D;
    QPushButton *MaxGLView;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_7;
    QLabel *label_2;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QVBoxLayout *verticalLayout_9;
    QLineEdit *Picture_N;
    QLineEdit *P_CornerNumber_row;
    QLineEdit *P_CornerNumber_col;
    QLineEdit *CellSize_width;
    QLineEdit *CellSize_height;
    QLineEdit *Iteration_N;
    QLineEdit *Accuracy;
    QVBoxLayout *verticalLayout_10;
    QPushButton *ProduceMatrix;
    QPushButton *ParameterContrast;
    QWidget *HDcameraWindow;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_11;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QVBoxLayout *verticalLayout_12;
    QSlider *CameraBrightness;
    QSlider *CameraGain;
    QSlider *CameraGama;
    QVBoxLayout *verticalLayout_13;
    QDoubleSpinBox *Brightness_spinBoxdouble;
    QDoubleSpinBox *Cameragain_spinBoxdouble;
    QDoubleSpinBox *Gama_spinBoxdouble;
    QVBoxLayout *verticalLayout_14;
    QPushButton *OpenHDcamera;
    QVBoxLayout *verticalLayout_15;
    QProgressBar *progressBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1319, 673);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/picture/camera.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        MianWD = new QFrame(centralwidget);
        MianWD->setObjectName(QString::fromUtf8("MianWD"));
        verticalLayout_16 = new QVBoxLayout(MianWD);
        verticalLayout_16->setSpacing(2);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        openglWindows = new QWidget(MianWD);
        openglWindows->setObjectName(QString::fromUtf8("openglWindows"));
        horizontalLayout_2 = new QHBoxLayout(openglWindows);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget_2 = new GL_Image(openglWindows);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));
        openGLWidget_2->setFocusPolicy(Qt::ClickFocus);
        openGLWidget_2->setAutoFillBackground(true);

        horizontalLayout->addWidget(openGLWidget_2);

        openGLWidget = new OpenGLshow(openglWindows);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        horizontalLayout->addWidget(openGLWidget);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_16->addWidget(openglWindows);

        toolFrame = new QFrame(MianWD);
        toolFrame->setObjectName(QString::fromUtf8("toolFrame"));
        toolFrame->setFocusPolicy(Qt::StrongFocus);
        toolFrame->setFrameShape(QFrame::StyledPanel);
        toolFrame->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(toolFrame);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(7, -1, 7, -1);
        PixelSizelable = new QLabel(toolFrame);
        PixelSizelable->setObjectName(QString::fromUtf8("PixelSizelable"));

        verticalLayout->addWidget(PixelSizelable);

        Focallabel = new QLabel(toolFrame);
        Focallabel->setObjectName(QString::fromUtf8("Focallabel"));

        verticalLayout->addWidget(Focallabel);

        baselinelabel = new QLabel(toolFrame);
        baselinelabel->setObjectName(QString::fromUtf8("baselinelabel"));

        verticalLayout->addWidget(baselinelabel);

        stepangleplable = new QLabel(toolFrame);
        stepangleplable->setObjectName(QString::fromUtf8("stepangleplable"));

        verticalLayout->addWidget(stepangleplable);

        laserAnglelabel = new QLabel(toolFrame);
        laserAnglelabel->setObjectName(QString::fromUtf8("laserAnglelabel"));

        verticalLayout->addWidget(laserAnglelabel);

        RGBlabel = new QLabel(toolFrame);
        RGBlabel->setObjectName(QString::fromUtf8("RGBlabel"));

        verticalLayout->addWidget(RGBlabel);


        horizontalLayout_3->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(7, -1, 7, -1);
        focalLine = new QLineEdit(toolFrame);
        focalLine->setObjectName(QString::fromUtf8("focalLine"));

        verticalLayout_2->addWidget(focalLine);

        pixelSizeLine = new QLineEdit(toolFrame);
        pixelSizeLine->setObjectName(QString::fromUtf8("pixelSizeLine"));
        pixelSizeLine->setEchoMode(QLineEdit::Normal);
        pixelSizeLine->setDragEnabled(false);
        pixelSizeLine->setReadOnly(false);

        verticalLayout_2->addWidget(pixelSizeLine);

        baseLineLine = new QLineEdit(toolFrame);
        baseLineLine->setObjectName(QString::fromUtf8("baseLineLine"));

        verticalLayout_2->addWidget(baseLineLine);

        stepAngleLine = new QLineEdit(toolFrame);
        stepAngleLine->setObjectName(QString::fromUtf8("stepAngleLine"));

        verticalLayout_2->addWidget(stepAngleLine);

        laserAngleLine = new QLineEdit(toolFrame);
        laserAngleLine->setObjectName(QString::fromUtf8("laserAngleLine"));

        verticalLayout_2->addWidget(laserAngleLine);

        rgeLine = new QLineEdit(toolFrame);
        rgeLine->setObjectName(QString::fromUtf8("rgeLine"));

        verticalLayout_2->addWidget(rgeLine);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(7, 0, 7, 45);
        loadseting = new QPushButton(toolFrame);
        loadseting->setObjectName(QString::fromUtf8("loadseting"));
        loadseting->setMinimumSize(QSize(0, 50));

        verticalLayout_3->addWidget(loadseting);

        checkBox = new QCheckBox(toolFrame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setAcceptDrops(true);
        checkBox->setToolTipDuration(-1);
        checkBox->setChecked(true);

        verticalLayout_3->addWidget(checkBox);

        checkBox_2 = new QCheckBox(toolFrame);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);

        horizontalLayout_3->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(7);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(7, -1, 7, 25);
        portcomboBox = new QComboBox(toolFrame);
        portcomboBox->setObjectName(QString::fromUtf8("portcomboBox"));
        portcomboBox->setEnabled(true);
        portcomboBox->setMinimumSize(QSize(0, 30));
        portcomboBox->setContextMenuPolicy(Qt::NoContextMenu);
        portcomboBox->setToolTipDuration(1);

        verticalLayout_4->addWidget(portcomboBox);

        PortButton = new QPushButton(toolFrame);
        PortButton->setObjectName(QString::fromUtf8("PortButton"));
        PortButton->setMinimumSize(QSize(0, 30));

        verticalLayout_4->addWidget(PortButton);

        senddatabutton = new QPushButton(toolFrame);
        senddatabutton->setObjectName(QString::fromUtf8("senddatabutton"));
        senddatabutton->setMinimumSize(QSize(0, 30));

        verticalLayout_4->addWidget(senddatabutton);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(7, 0, 7, 0);
        textEdit = new QTextEdit(toolFrame);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout_5->addWidget(textEdit);


        horizontalLayout_3->addLayout(verticalLayout_5);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(20);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(7, 20, 7, 20);
        scan_light = new QLabel(toolFrame);
        scan_light->setObjectName(QString::fromUtf8("scan_light"));
        scan_light->setMinimumSize(QSize(40, 30));
        scan_light->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/gray.png);"));
        scan_light->setPixmap(QPixmap(QString::fromUtf8("picture/gray.png")));

        gridLayout->addWidget(scan_light, 1, 1, 1, 1);

        camera_light = new QLabel(toolFrame);
        camera_light->setObjectName(QString::fromUtf8("camera_light"));
        camera_light->setMinimumSize(QSize(40, 30));
        camera_light->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/gray.png);"));
        camera_light->setPixmap(QPixmap(QString::fromUtf8("picture/gray.png")));

        gridLayout->addWidget(camera_light, 0, 1, 1, 1);

        label_8 = new QLabel(toolFrame);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setMinimumSize(QSize(40, 40));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/Scaneye.jpg);"));

        gridLayout->addWidget(label_8, 1, 0, 1, 1);

        Camera_icon = new QLabel(toolFrame);
        Camera_icon->setObjectName(QString::fromUtf8("Camera_icon"));
        Camera_icon->setMinimumSize(QSize(30, 30));
        Camera_icon->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/camera_01.jpg);"));
        Camera_icon->setTextFormat(Qt::AutoText);
        Camera_icon->setScaledContents(true);
        Camera_icon->setWordWrap(true);

        gridLayout->addWidget(Camera_icon, 0, 0, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 2);

        horizontalLayout_3->addLayout(gridLayout);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(7, 0, 7, 0);
        cameralist = new QComboBox(toolFrame);
        cameralist->setObjectName(QString::fromUtf8("cameralist"));
        cameralist->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(cameralist);

        openCamera = new QPushButton(toolFrame);
        openCamera->setObjectName(QString::fromUtf8("openCamera"));
        openCamera->setMinimumSize(QSize(0, 25));
        openCamera->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_6->addWidget(openCamera);

        Scanningbutton = new QPushButton(toolFrame);
        Scanningbutton->setObjectName(QString::fromUtf8("Scanningbutton"));
        Scanningbutton->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(Scanningbutton);

        pointfilepushButton = new QPushButton(toolFrame);
        pointfilepushButton->setObjectName(QString::fromUtf8("pointfilepushButton"));
        pointfilepushButton->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(pointfilepushButton);

        pointfilelineEdit = new QLineEdit(toolFrame);
        pointfilelineEdit->setObjectName(QString::fromUtf8("pointfilelineEdit"));
        pointfilelineEdit->setEnabled(true);
        pointfilelineEdit->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(pointfilelineEdit);


        horizontalLayout_3->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(7, -1, 7, -1);
        show3D = new QPushButton(toolFrame);
        show3D->setObjectName(QString::fromUtf8("show3D"));
        show3D->setMinimumSize(QSize(40, 75));

        verticalLayout_7->addWidget(show3D);

        MaxGLView = new QPushButton(toolFrame);
        MaxGLView->setObjectName(QString::fromUtf8("MaxGLView"));
        MaxGLView->setMinimumSize(QSize(40, 75));

        verticalLayout_7->addWidget(MaxGLView);


        horizontalLayout_3->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(7, -1, 7, -1);
        label_7 = new QLabel(toolFrame);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_8->addWidget(label_7);

        label_2 = new QLabel(toolFrame);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_8->addWidget(label_2);

        label = new QLabel(toolFrame);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_8->addWidget(label);

        label_3 = new QLabel(toolFrame);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_8->addWidget(label_3);

        label_4 = new QLabel(toolFrame);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_8->addWidget(label_4);

        label_5 = new QLabel(toolFrame);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_8->addWidget(label_5);

        label_6 = new QLabel(toolFrame);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_8->addWidget(label_6);


        horizontalLayout_3->addLayout(verticalLayout_8);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(1);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(7, 2, 7, -1);
        Picture_N = new QLineEdit(toolFrame);
        Picture_N->setObjectName(QString::fromUtf8("Picture_N"));

        verticalLayout_9->addWidget(Picture_N);

        P_CornerNumber_row = new QLineEdit(toolFrame);
        P_CornerNumber_row->setObjectName(QString::fromUtf8("P_CornerNumber_row"));

        verticalLayout_9->addWidget(P_CornerNumber_row);

        P_CornerNumber_col = new QLineEdit(toolFrame);
        P_CornerNumber_col->setObjectName(QString::fromUtf8("P_CornerNumber_col"));

        verticalLayout_9->addWidget(P_CornerNumber_col);

        CellSize_width = new QLineEdit(toolFrame);
        CellSize_width->setObjectName(QString::fromUtf8("CellSize_width"));

        verticalLayout_9->addWidget(CellSize_width);

        CellSize_height = new QLineEdit(toolFrame);
        CellSize_height->setObjectName(QString::fromUtf8("CellSize_height"));

        verticalLayout_9->addWidget(CellSize_height);

        Iteration_N = new QLineEdit(toolFrame);
        Iteration_N->setObjectName(QString::fromUtf8("Iteration_N"));

        verticalLayout_9->addWidget(Iteration_N);

        Accuracy = new QLineEdit(toolFrame);
        Accuracy->setObjectName(QString::fromUtf8("Accuracy"));

        verticalLayout_9->addWidget(Accuracy);


        horizontalLayout_3->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        ProduceMatrix = new QPushButton(toolFrame);
        ProduceMatrix->setObjectName(QString::fromUtf8("ProduceMatrix"));
        ProduceMatrix->setMinimumSize(QSize(0, 75));

        verticalLayout_10->addWidget(ProduceMatrix);

        ParameterContrast = new QPushButton(toolFrame);
        ParameterContrast->setObjectName(QString::fromUtf8("ParameterContrast"));
        ParameterContrast->setMinimumSize(QSize(0, 75));

        verticalLayout_10->addWidget(ParameterContrast);


        horizontalLayout_3->addLayout(verticalLayout_10);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 2);
        horizontalLayout_3->setStretch(3, 2);
        horizontalLayout_3->setStretch(4, 4);
        horizontalLayout_3->setStretch(5, 3);
        horizontalLayout_3->setStretch(6, 3);
        horizontalLayout_3->setStretch(7, 3);
        horizontalLayout_3->setStretch(8, 2);
        horizontalLayout_3->setStretch(9, 1);
        horizontalLayout_3->setStretch(10, 3);

        verticalLayout_16->addWidget(toolFrame);

        HDcameraWindow = new QWidget(MianWD);
        HDcameraWindow->setObjectName(QString::fromUtf8("HDcameraWindow"));
        horizontalLayout_4 = new QHBoxLayout(HDcameraWindow);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(7, -1, 7, -1);
        label_9 = new QLabel(HDcameraWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_11->addWidget(label_9);

        label_10 = new QLabel(HDcameraWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_11->addWidget(label_10);

        label_11 = new QLabel(HDcameraWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        verticalLayout_11->addWidget(label_11);


        horizontalLayout_4->addLayout(verticalLayout_11);

        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_12->setContentsMargins(7, -1, 7, -1);
        CameraBrightness = new QSlider(HDcameraWindow);
        CameraBrightness->setObjectName(QString::fromUtf8("CameraBrightness"));
        CameraBrightness->setEnabled(false);
        CameraBrightness->setMinimumSize(QSize(101, 22));
        CameraBrightness->setMaximum(1000);
        CameraBrightness->setSingleStep(1);
        CameraBrightness->setValue(500);
        CameraBrightness->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(CameraBrightness);

        CameraGain = new QSlider(HDcameraWindow);
        CameraGain->setObjectName(QString::fromUtf8("CameraGain"));
        CameraGain->setEnabled(false);
        CameraGain->setMaximum(300);
        CameraGain->setValue(10);
        CameraGain->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(CameraGain);

        CameraGama = new QSlider(HDcameraWindow);
        CameraGama->setObjectName(QString::fromUtf8("CameraGama"));
        CameraGama->setEnabled(false);
        CameraGama->setMaximum(40);
        CameraGama->setPageStep(5);
        CameraGama->setValue(1);
        CameraGama->setOrientation(Qt::Horizontal);

        verticalLayout_12->addWidget(CameraGama);


        horizontalLayout_4->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(7, -1, 7, -1);
        Brightness_spinBoxdouble = new QDoubleSpinBox(HDcameraWindow);
        Brightness_spinBoxdouble->setObjectName(QString::fromUtf8("Brightness_spinBoxdouble"));
        Brightness_spinBoxdouble->setEnabled(false);
        Brightness_spinBoxdouble->setDecimals(0);
        Brightness_spinBoxdouble->setValue(50.000000000000000);

        verticalLayout_13->addWidget(Brightness_spinBoxdouble);

        Cameragain_spinBoxdouble = new QDoubleSpinBox(HDcameraWindow);
        Cameragain_spinBoxdouble->setObjectName(QString::fromUtf8("Cameragain_spinBoxdouble"));
        Cameragain_spinBoxdouble->setEnabled(false);
        Cameragain_spinBoxdouble->setDecimals(1);
        Cameragain_spinBoxdouble->setMaximum(30.000000000000000);
        Cameragain_spinBoxdouble->setSingleStep(0.100000000000000);
        Cameragain_spinBoxdouble->setValue(1.000000000000000);

        verticalLayout_13->addWidget(Cameragain_spinBoxdouble);

        Gama_spinBoxdouble = new QDoubleSpinBox(HDcameraWindow);
        Gama_spinBoxdouble->setObjectName(QString::fromUtf8("Gama_spinBoxdouble"));
        Gama_spinBoxdouble->setEnabled(false);
        Gama_spinBoxdouble->setDecimals(1);
        Gama_spinBoxdouble->setMaximum(4.000000000000000);
        Gama_spinBoxdouble->setSingleStep(0.100000000000000);
        Gama_spinBoxdouble->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        Gama_spinBoxdouble->setValue(0.500000000000000);

        verticalLayout_13->addWidget(Gama_spinBoxdouble);


        horizontalLayout_4->addLayout(verticalLayout_13);

        verticalLayout_14 = new QVBoxLayout();
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(7, -1, 7, -1);
        OpenHDcamera = new QPushButton(HDcameraWindow);
        OpenHDcamera->setObjectName(QString::fromUtf8("OpenHDcamera"));
        OpenHDcamera->setMinimumSize(QSize(97, 70));

        verticalLayout_14->addWidget(OpenHDcamera);


        horizontalLayout_4->addLayout(verticalLayout_14);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        verticalLayout_15->setContentsMargins(-1, 50, -1, -1);
        progressBar = new QProgressBar(HDcameraWindow);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout_15->addWidget(progressBar);


        horizontalLayout_4->addLayout(verticalLayout_15);

        horizontalLayout_4->setStretch(0, 1);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 2);
        horizontalLayout_4->setStretch(4, 20);

        verticalLayout_16->addWidget(HDcameraWindow);

        verticalLayout_16->setStretch(0, 5);
        verticalLayout_16->setStretch(1, 1);
        verticalLayout_16->setStretch(2, 1);

        horizontalLayout_5->addWidget(MianWD);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Laser Scanner", nullptr));
        PixelSizelable->setText(QCoreApplication::translate("MainWindow", "pixelSize", nullptr));
        Focallabel->setText(QCoreApplication::translate("MainWindow", "focal", nullptr));
        baselinelabel->setText(QCoreApplication::translate("MainWindow", "baseLine", nullptr));
        stepangleplable->setText(QCoreApplication::translate("MainWindow", "stepAngle", nullptr));
        laserAnglelabel->setText(QCoreApplication::translate("MainWindow", "laserAngle", nullptr));
        RGBlabel->setText(QCoreApplication::translate("MainWindow", "rgb", nullptr));
        focalLine->setText(QCoreApplication::translate("MainWindow", "2.7", nullptr));
        pixelSizeLine->setText(QCoreApplication::translate("MainWindow", "0.009", nullptr));
        baseLineLine->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
        stepAngleLine->setText(QCoreApplication::translate("MainWindow", "0.7", nullptr));
        laserAngleLine->setText(QCoreApplication::translate("MainWindow", "70", nullptr));
        rgeLine->setText(QCoreApplication::translate("MainWindow", "100", nullptr));
#if QT_CONFIG(tooltip)
        loadseting->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\350\275\275\345\205\245\346\211\253\346\217\217\345\217\202\346\225\260</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        loadseting->setText(QCoreApplication::translate("MainWindow", "Load Seting", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Turn Left", nullptr));
        checkBox_2->setText(QCoreApplication::translate("MainWindow", "Turn Right", nullptr));
#if QT_CONFIG(tooltip)
        PortButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\344\270\262\345\217\243</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PortButton->setText(QCoreApplication::translate("MainWindow", "Open Port", nullptr));
#if QT_CONFIG(tooltip)
        senddatabutton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\217\221\351\200\201\346\225\260\346\215\256\345\210\260\344\270\262\345\217\243</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        senddatabutton->setText(QCoreApplication::translate("MainWindow", "Send Message", nullptr));
        scan_light->setText(QString());
        camera_light->setText(QString());
        label_8->setText(QString());
        Camera_icon->setText(QString());
#if QT_CONFIG(tooltip)
        openCamera->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\347\233\270\346\234\272</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        openCamera->setText(QCoreApplication::translate("MainWindow", "Open Camera", nullptr));
#if QT_CONFIG(tooltip)
        Scanningbutton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\274\200\345\220\257\346\211\253\346\217\217</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        Scanningbutton->setText(QCoreApplication::translate("MainWindow", "Start Scan", nullptr));
#if QT_CONFIG(tooltip)
        pointfilepushButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\344\272\221\346\226\207\344\273\266\350\267\257\345\276\204</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        pointfilepushButton->setText(QCoreApplication::translate("MainWindow", "Cloud Path", nullptr));
#if QT_CONFIG(tooltip)
        show3D->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\344\272\221\346\225\260\346\215\256\346\230\276\347\244\272(\344\273\216\346\226\207\344\273\266)</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        show3D->setText(QCoreApplication::translate("MainWindow", "Show 3D Model", nullptr));
#if QT_CONFIG(tooltip)
        MaxGLView->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\202\271\344\272\221\347\252\227\345\217\243\346\234\200\345\244\247\345\214\226</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        MaxGLView->setText(QCoreApplication::translate("MainWindow", "Max GLView", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Picture_N", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "P_CornerNumber_row", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "P_CornerNumber_col", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "CellSize_width", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "CellSize_height", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Iteration_N", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Accuracy", nullptr));
        Picture_N->setText(QCoreApplication::translate("MainWindow", "62", nullptr));
        P_CornerNumber_row->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        P_CornerNumber_col->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        CellSize_width->setText(QCoreApplication::translate("MainWindow", "22", nullptr));
        CellSize_height->setText(QCoreApplication::translate("MainWindow", "20", nullptr));
        Iteration_N->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        Accuracy->setText(QCoreApplication::translate("MainWindow", "0.01", nullptr));
#if QT_CONFIG(tooltip)
        ProduceMatrix->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\224\237\346\210\220\347\225\270\345\217\230\346\240\241\345\207\206\347\237\251\351\230\265</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ProduceMatrix->setText(QCoreApplication::translate("MainWindow", "Produce Matrix", nullptr));
#if QT_CONFIG(tooltip)
        ParameterContrast->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\347\225\270\345\217\230\346\240\241\345\207\206\346\265\213\350\257\225</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ParameterContrast->setText(QCoreApplication::translate("MainWindow", "Calibrate Contrast", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "brightness ", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Camera gain", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Gama", nullptr));
#if QT_CONFIG(tooltip)
        OpenHDcamera->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\345\267\245\344\270\232\347\233\270\346\234\272</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        OpenHDcamera->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        OpenHDcamera->setText(QCoreApplication::translate("MainWindow", "OpenHDCamera", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
