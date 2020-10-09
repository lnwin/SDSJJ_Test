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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
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
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout;
    GL_Image *openGLWidget_2;
    OpenGLshow *openGLWidget;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_2;
    QComboBox *portcomboBox;
    QPushButton *PortButton;
    QPushButton *senddatabutton;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QComboBox *cameralist;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Camera_icon;
    QLabel *camera_light;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_8;
    QLabel *scan_light;
    QVBoxLayout *verticalLayout_5;
    QPushButton *openCamera;
    QPushButton *OpenHDcamera;
    QVBoxLayout *verticalLayout_6;
    QPushButton *Scanningbutton;
    QPushButton *pointfilepushButton;
    QLineEdit *pointfilelineEdit;
    QVBoxLayout *verticalLayout_7;
    QPushButton *show3D;
    QPushButton *MaxGLView;
    QVBoxLayout *verticalLayout_8;
    QPushButton *openconfigurationfor;
    QProgressBar *progressBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1349, 667);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/icon/picture/camera.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_9 = new QVBoxLayout(centralwidget);
        verticalLayout_9->setSpacing(1);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(1, 1, 1, 1);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        openGLWidget_2 = new GL_Image(centralwidget);
        openGLWidget_2->setObjectName(QString::fromUtf8("openGLWidget_2"));
        openGLWidget_2->setFocusPolicy(Qt::ClickFocus);
        openGLWidget_2->setAutoFillBackground(true);

        horizontalLayout->addWidget(openGLWidget_2);

        openGLWidget = new OpenGLshow(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));

        horizontalLayout->addWidget(openGLWidget);


        verticalLayout_9->addLayout(horizontalLayout);

        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(frame_2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(frame_2);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        verticalLayout->addWidget(textEdit);


        horizontalLayout_4->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        portcomboBox = new QComboBox(frame_2);
        portcomboBox->setObjectName(QString::fromUtf8("portcomboBox"));
        portcomboBox->setEnabled(true);
        portcomboBox->setMinimumSize(QSize(0, 30));
        portcomboBox->setContextMenuPolicy(Qt::NoContextMenu);
        portcomboBox->setToolTipDuration(1);

        verticalLayout_2->addWidget(portcomboBox);

        PortButton = new QPushButton(frame_2);
        PortButton->setObjectName(QString::fromUtf8("PortButton"));
        PortButton->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(PortButton);

        senddatabutton = new QPushButton(frame_2);
        senddatabutton->setObjectName(QString::fromUtf8("senddatabutton"));
        senddatabutton->setMinimumSize(QSize(0, 30));

        verticalLayout_2->addWidget(senddatabutton);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        horizontalLayout_4->addLayout(verticalLayout_2);

        frame_3 = new QFrame(frame_2);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        cameralist = new QComboBox(frame_3);
        cameralist->setObjectName(QString::fromUtf8("cameralist"));
        cameralist->setMinimumSize(QSize(0, 30));

        verticalLayout_3->addWidget(cameralist);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Camera_icon = new QLabel(frame_3);
        Camera_icon->setObjectName(QString::fromUtf8("Camera_icon"));
        Camera_icon->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/camera_01.jpg);"));
        Camera_icon->setTextFormat(Qt::AutoText);
        Camera_icon->setScaledContents(true);
        Camera_icon->setWordWrap(true);

        horizontalLayout_2->addWidget(Camera_icon);

        camera_light = new QLabel(frame_3);
        camera_light->setObjectName(QString::fromUtf8("camera_light"));
        camera_light->setMinimumSize(QSize(40, 30));
        camera_light->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/gray.png);"));
        camera_light->setPixmap(QPixmap(QString::fromUtf8("picture/gray.png")));

        horizontalLayout_2->addWidget(camera_light);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_8 = new QLabel(frame_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/Scaneye.jpg);"));

        horizontalLayout_3->addWidget(label_8);

        scan_light = new QLabel(frame_3);
        scan_light->setObjectName(QString::fromUtf8("scan_light"));
        scan_light->setMinimumSize(QSize(40, 30));
        scan_light->setStyleSheet(QString::fromUtf8("border-image: url(:/new/icon/picture/gray.png);"));
        scan_light->setPixmap(QPixmap(QString::fromUtf8("picture/gray.png")));

        horizontalLayout_3->addWidget(scan_light);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 3);

        verticalLayout_4->addLayout(horizontalLayout_3);

        verticalLayout_4->setStretch(1, 1);
        verticalLayout_4->setStretch(2, 1);

        horizontalLayout_4->addWidget(frame_3);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        openCamera = new QPushButton(frame_2);
        openCamera->setObjectName(QString::fromUtf8("openCamera"));
        openCamera->setEnabled(false);
        openCamera->setMinimumSize(QSize(0, 50));
        openCamera->setFocusPolicy(Qt::StrongFocus);

        verticalLayout_5->addWidget(openCamera);

        OpenHDcamera = new QPushButton(frame_2);
        OpenHDcamera->setObjectName(QString::fromUtf8("OpenHDcamera"));
        OpenHDcamera->setEnabled(true);
        OpenHDcamera->setMinimumSize(QSize(0, 50));

        verticalLayout_5->addWidget(OpenHDcamera);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(-1, 3, -1, 3);
        Scanningbutton = new QPushButton(frame_2);
        Scanningbutton->setObjectName(QString::fromUtf8("Scanningbutton"));
        Scanningbutton->setEnabled(false);
        Scanningbutton->setMinimumSize(QSize(0, 50));

        verticalLayout_6->addWidget(Scanningbutton);

        pointfilepushButton = new QPushButton(frame_2);
        pointfilepushButton->setObjectName(QString::fromUtf8("pointfilepushButton"));
        pointfilepushButton->setMinimumSize(QSize(0, 25));

        verticalLayout_6->addWidget(pointfilepushButton);

        pointfilelineEdit = new QLineEdit(frame_2);
        pointfilelineEdit->setObjectName(QString::fromUtf8("pointfilelineEdit"));
        pointfilelineEdit->setEnabled(true);

        verticalLayout_6->addWidget(pointfilelineEdit);

        verticalLayout_6->setStretch(0, 2);
        verticalLayout_6->setStretch(1, 1);
        verticalLayout_6->setStretch(2, 1);

        horizontalLayout_4->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        show3D = new QPushButton(frame_2);
        show3D->setObjectName(QString::fromUtf8("show3D"));
        show3D->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(show3D);

        MaxGLView = new QPushButton(frame_2);
        MaxGLView->setObjectName(QString::fromUtf8("MaxGLView"));
        MaxGLView->setMinimumSize(QSize(0, 50));

        verticalLayout_7->addWidget(MaxGLView);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 1);

        horizontalLayout_4->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        openconfigurationfor = new QPushButton(frame_2);
        openconfigurationfor->setObjectName(QString::fromUtf8("openconfigurationfor"));
        openconfigurationfor->setMinimumSize(QSize(0, 105));

        verticalLayout_8->addWidget(openconfigurationfor);


        horizontalLayout_4->addLayout(verticalLayout_8);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 1);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 1);
        horizontalLayout_4->setStretch(6, 1);

        verticalLayout_9->addWidget(frame_2);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        verticalLayout_9->addWidget(progressBar);

        verticalLayout_9->setStretch(0, 5);
        verticalLayout_9->setStretch(1, 1);
        verticalLayout_9->setStretch(2, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setSizeGripEnabled(false);
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Laser Scanner", nullptr));
#if QT_CONFIG(tooltip)
        PortButton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\344\270\262\345\217\243</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        PortButton->setText(QCoreApplication::translate("MainWindow", "Open Port", nullptr));
#if QT_CONFIG(tooltip)
        senddatabutton->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\345\217\221\351\200\201\346\225\260\346\215\256\345\210\260\344\270\262\345\217\243</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        senddatabutton->setText(QCoreApplication::translate("MainWindow", "Send Message", nullptr));
        Camera_icon->setText(QString());
        camera_light->setText(QString());
        label_8->setText(QString());
        scan_light->setText(QString());
#if QT_CONFIG(tooltip)
        openCamera->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\347\233\270\346\234\272</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        openCamera->setText(QCoreApplication::translate("MainWindow", "Open USB Camera", nullptr));
#if QT_CONFIG(tooltip)
        OpenHDcamera->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p>\346\211\223\345\274\200/\345\205\263\351\227\255\345\267\245\344\270\232\347\233\270\346\234\272</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(whatsthis)
        OpenHDcamera->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        OpenHDcamera->setText(QCoreApplication::translate("MainWindow", "Open HD Camera", nullptr));
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
        openconfigurationfor->setText(QCoreApplication::translate("MainWindow", "Configuration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
