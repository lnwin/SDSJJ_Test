/********************************************************************************
** Form generated from reading UI file 'configuration.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGURATION_H
#define UI_CONFIGURATION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_Configuration
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QPushButton *ProduceMatrix;
    QPushButton *ParameterContrast;
    QLineEdit *Picture_N;
    QLabel *label;
    QLabel *label_6;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *P_CornerNumber_col;
    QLineEdit *Accuracy;
    QLabel *label_5;
    QLineEdit *Iteration_N;
    QLineEdit *CellSize_height;
    QLineEdit *P_CornerNumber_row;
    QLabel *label_3;
    QLabel *label_7;
    QLineEdit *CellSize_width;
    QGroupBox *groupBox_2;
    QLabel *label_10;
    QDoubleSpinBox *Brightness_spinBoxdouble;
    QSlider *CameraGama;
    QLabel *label_11;
    QSlider *CameraGain;
    QLabel *label_9;
    QDoubleSpinBox *Cameragain_spinBoxdouble;
    QDoubleSpinBox *Gama_spinBoxdouble;
    QSlider *CameraBrightness;
    QGroupBox *groupBox_3;
    QLabel *Focallabel;
    QLineEdit *pixelSizeLine;
    QLabel *RGBlabel;
    QLineEdit *baseLineLine;
    QLabel *baselinelabel;
    QLineEdit *laserAngleLine;
    QLineEdit *focalLine;
    QLineEdit *rgeLine;
    QLabel *laserAnglelabel;
    QLabel *stepangleplable;
    QLineEdit *stepAngleLine;
    QLabel *PixelSizelable;

    void setupUi(QDialog *Configuration)
    {
        if (Configuration->objectName().isEmpty())
            Configuration->setObjectName(QString::fromUtf8("Configuration"));
        Configuration->resize(548, 326);
        buttonBox = new QDialogButtonBox(Configuration);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(340, 290, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::SaveAll);
        groupBox = new QGroupBox(Configuration);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(180, 10, 361, 181));
        ProduceMatrix = new QPushButton(groupBox);
        ProduceMatrix->setObjectName(QString::fromUtf8("ProduceMatrix"));
        ProduceMatrix->setGeometry(QRect(200, 25, 150, 75));
        ProduceMatrix->setMinimumSize(QSize(0, 75));
        ParameterContrast = new QPushButton(groupBox);
        ParameterContrast->setObjectName(QString::fromUtf8("ParameterContrast"));
        ParameterContrast->setGeometry(QRect(200, 100, 150, 75));
        ParameterContrast->setMinimumSize(QSize(0, 75));
        Picture_N = new QLineEdit(groupBox);
        Picture_N->setObjectName(QString::fromUtf8("Picture_N"));
        Picture_N->setGeometry(QRect(140, 24, 39, 20));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 65, 108, 21));
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 151, 108, 21));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 43, 108, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 108, 108, 21));
        P_CornerNumber_col = new QLineEdit(groupBox);
        P_CornerNumber_col->setObjectName(QString::fromUtf8("P_CornerNumber_col"));
        P_CornerNumber_col->setGeometry(QRect(140, 66, 39, 20));
        Accuracy = new QLineEdit(groupBox);
        Accuracy->setObjectName(QString::fromUtf8("Accuracy"));
        Accuracy->setGeometry(QRect(140, 150, 39, 20));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 129, 108, 22));
        Iteration_N = new QLineEdit(groupBox);
        Iteration_N->setObjectName(QString::fromUtf8("Iteration_N"));
        Iteration_N->setGeometry(QRect(140, 129, 39, 20));
        CellSize_height = new QLineEdit(groupBox);
        CellSize_height->setObjectName(QString::fromUtf8("CellSize_height"));
        CellSize_height->setGeometry(QRect(140, 108, 39, 20));
        P_CornerNumber_row = new QLineEdit(groupBox);
        P_CornerNumber_row->setObjectName(QString::fromUtf8("P_CornerNumber_row"));
        P_CornerNumber_row->setGeometry(QRect(140, 45, 39, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 86, 108, 22));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 22, 108, 21));
        CellSize_width = new QLineEdit(groupBox);
        CellSize_width->setObjectName(QString::fromUtf8("CellSize_width"));
        CellSize_width->setGeometry(QRect(140, 87, 39, 20));
        groupBox_2 = new QGroupBox(Configuration);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 200, 271, 121));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(20, 50, 66, 24));
        Brightness_spinBoxdouble = new QDoubleSpinBox(groupBox_2);
        Brightness_spinBoxdouble->setObjectName(QString::fromUtf8("Brightness_spinBoxdouble"));
        Brightness_spinBoxdouble->setEnabled(true);
        Brightness_spinBoxdouble->setGeometry(QRect(210, 20, 54, 20));
        Brightness_spinBoxdouble->setDecimals(0);
        Brightness_spinBoxdouble->setValue(50.000000000000000);
        CameraGama = new QSlider(groupBox_2);
        CameraGama->setObjectName(QString::fromUtf8("CameraGama"));
        CameraGama->setEnabled(true);
        CameraGama->setGeometry(QRect(90, 80, 101, 22));
        CameraGama->setMaximum(40);
        CameraGama->setPageStep(5);
        CameraGama->setValue(1);
        CameraGama->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 80, 66, 24));
        CameraGain = new QSlider(groupBox_2);
        CameraGain->setObjectName(QString::fromUtf8("CameraGain"));
        CameraGain->setEnabled(true);
        CameraGain->setGeometry(QRect(90, 50, 101, 22));
        CameraGain->setMaximum(300);
        CameraGain->setValue(10);
        CameraGain->setOrientation(Qt::Horizontal);
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 20, 66, 24));
        Cameragain_spinBoxdouble = new QDoubleSpinBox(groupBox_2);
        Cameragain_spinBoxdouble->setObjectName(QString::fromUtf8("Cameragain_spinBoxdouble"));
        Cameragain_spinBoxdouble->setEnabled(true);
        Cameragain_spinBoxdouble->setGeometry(QRect(210, 50, 54, 20));
        Cameragain_spinBoxdouble->setDecimals(1);
        Cameragain_spinBoxdouble->setMaximum(30.000000000000000);
        Cameragain_spinBoxdouble->setSingleStep(0.100000000000000);
        Cameragain_spinBoxdouble->setValue(1.000000000000000);
        Gama_spinBoxdouble = new QDoubleSpinBox(groupBox_2);
        Gama_spinBoxdouble->setObjectName(QString::fromUtf8("Gama_spinBoxdouble"));
        Gama_spinBoxdouble->setEnabled(true);
        Gama_spinBoxdouble->setGeometry(QRect(210, 80, 54, 20));
        Gama_spinBoxdouble->setDecimals(1);
        Gama_spinBoxdouble->setMaximum(4.000000000000000);
        Gama_spinBoxdouble->setSingleStep(0.100000000000000);
        Gama_spinBoxdouble->setStepType(QAbstractSpinBox::AdaptiveDecimalStepType);
        Gama_spinBoxdouble->setValue(0.500000000000000);
        CameraBrightness = new QSlider(groupBox_2);
        CameraBrightness->setObjectName(QString::fromUtf8("CameraBrightness"));
        CameraBrightness->setEnabled(true);
        CameraBrightness->setGeometry(QRect(90, 20, 101, 22));
        CameraBrightness->setMinimumSize(QSize(101, 22));
        CameraBrightness->setMaximum(1000);
        CameraBrightness->setSingleStep(1);
        CameraBrightness->setValue(500);
        CameraBrightness->setOrientation(Qt::Horizontal);
        groupBox_3 = new QGroupBox(Configuration);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 141, 181));
        Focallabel = new QLabel(groupBox_3);
        Focallabel->setObjectName(QString::fromUtf8("Focallabel"));
        Focallabel->setGeometry(QRect(20, 50, 60, 20));
        pixelSizeLine = new QLineEdit(groupBox_3);
        pixelSizeLine->setObjectName(QString::fromUtf8("pixelSizeLine"));
        pixelSizeLine->setGeometry(QRect(90, 50, 39, 20));
        pixelSizeLine->setEchoMode(QLineEdit::Normal);
        pixelSizeLine->setDragEnabled(false);
        pixelSizeLine->setReadOnly(false);
        RGBlabel = new QLabel(groupBox_3);
        RGBlabel->setObjectName(QString::fromUtf8("RGBlabel"));
        RGBlabel->setGeometry(QRect(20, 154, 60, 20));
        baseLineLine = new QLineEdit(groupBox_3);
        baseLineLine->setObjectName(QString::fromUtf8("baseLineLine"));
        baseLineLine->setGeometry(QRect(90, 76, 39, 20));
        baselinelabel = new QLabel(groupBox_3);
        baselinelabel->setObjectName(QString::fromUtf8("baselinelabel"));
        baselinelabel->setGeometry(QRect(20, 76, 60, 20));
        laserAngleLine = new QLineEdit(groupBox_3);
        laserAngleLine->setObjectName(QString::fromUtf8("laserAngleLine"));
        laserAngleLine->setGeometry(QRect(90, 128, 39, 20));
        focalLine = new QLineEdit(groupBox_3);
        focalLine->setObjectName(QString::fromUtf8("focalLine"));
        focalLine->setGeometry(QRect(90, 24, 39, 20));
        rgeLine = new QLineEdit(groupBox_3);
        rgeLine->setObjectName(QString::fromUtf8("rgeLine"));
        rgeLine->setGeometry(QRect(90, 154, 39, 20));
        laserAnglelabel = new QLabel(groupBox_3);
        laserAnglelabel->setObjectName(QString::fromUtf8("laserAnglelabel"));
        laserAnglelabel->setGeometry(QRect(20, 128, 60, 20));
        stepangleplable = new QLabel(groupBox_3);
        stepangleplable->setObjectName(QString::fromUtf8("stepangleplable"));
        stepangleplable->setGeometry(QRect(20, 102, 60, 20));
        stepAngleLine = new QLineEdit(groupBox_3);
        stepAngleLine->setObjectName(QString::fromUtf8("stepAngleLine"));
        stepAngleLine->setGeometry(QRect(90, 102, 39, 20));
        PixelSizelable = new QLabel(groupBox_3);
        PixelSizelable->setObjectName(QString::fromUtf8("PixelSizelable"));
        PixelSizelable->setGeometry(QRect(20, 24, 60, 20));

        retranslateUi(Configuration);
        QObject::connect(buttonBox, SIGNAL(accepted()), Configuration, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Configuration, SLOT(reject()));

        QMetaObject::connectSlotsByName(Configuration);
    } // setupUi

    void retranslateUi(QDialog *Configuration)
    {
        Configuration->setWindowTitle(QCoreApplication::translate("Configuration", "Dialog", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Configuration", "CameraCalibrate", nullptr));
#if QT_CONFIG(tooltip)
        ProduceMatrix->setToolTip(QCoreApplication::translate("Configuration", "<html><head/><body><p>\347\224\237\346\210\220\347\225\270\345\217\230\346\240\241\345\207\206\347\237\251\351\230\265</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ProduceMatrix->setText(QCoreApplication::translate("Configuration", "Produce Matrix", nullptr));
#if QT_CONFIG(tooltip)
        ParameterContrast->setToolTip(QCoreApplication::translate("Configuration", "<html><head/><body><p>\347\225\270\345\217\230\346\240\241\345\207\206\346\265\213\350\257\225</p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        ParameterContrast->setText(QCoreApplication::translate("Configuration", "Calibrate Contrast", nullptr));
        Picture_N->setText(QCoreApplication::translate("Configuration", "62", nullptr));
        label->setText(QCoreApplication::translate("Configuration", "P_CornerNumber_col", nullptr));
        label_6->setText(QCoreApplication::translate("Configuration", "Accuracy", nullptr));
        label_2->setText(QCoreApplication::translate("Configuration", "P_CornerNumber_row", nullptr));
        label_4->setText(QCoreApplication::translate("Configuration", "CellSize_height", nullptr));
        P_CornerNumber_col->setText(QCoreApplication::translate("Configuration", "6", nullptr));
        Accuracy->setText(QCoreApplication::translate("Configuration", "0.01", nullptr));
        label_5->setText(QCoreApplication::translate("Configuration", "Iteration_N", nullptr));
        Iteration_N->setText(QCoreApplication::translate("Configuration", "50", nullptr));
        CellSize_height->setText(QCoreApplication::translate("Configuration", "20", nullptr));
        P_CornerNumber_row->setText(QCoreApplication::translate("Configuration", "9", nullptr));
        label_3->setText(QCoreApplication::translate("Configuration", "CellSize_width", nullptr));
        label_7->setText(QCoreApplication::translate("Configuration", "Picture_N", nullptr));
        CellSize_width->setText(QCoreApplication::translate("Configuration", "22", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Configuration", "CameraSetting", nullptr));
        label_10->setText(QCoreApplication::translate("Configuration", "Camera gain", nullptr));
        label_11->setText(QCoreApplication::translate("Configuration", "Gama", nullptr));
        label_9->setText(QCoreApplication::translate("Configuration", "brightness ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("Configuration", "ScannerSetting", nullptr));
        Focallabel->setText(QCoreApplication::translate("Configuration", "focal", nullptr));
        pixelSizeLine->setText(QCoreApplication::translate("Configuration", "0.009", nullptr));
        RGBlabel->setText(QCoreApplication::translate("Configuration", "rgb", nullptr));
        baseLineLine->setText(QCoreApplication::translate("Configuration", "100", nullptr));
        baselinelabel->setText(QCoreApplication::translate("Configuration", "baseLine", nullptr));
        laserAngleLine->setText(QCoreApplication::translate("Configuration", "70", nullptr));
        focalLine->setText(QCoreApplication::translate("Configuration", "2.7", nullptr));
        rgeLine->setText(QCoreApplication::translate("Configuration", "100", nullptr));
        laserAnglelabel->setText(QCoreApplication::translate("Configuration", "laserAngle", nullptr));
        stepangleplable->setText(QCoreApplication::translate("Configuration", "stepAngle", nullptr));
        stepAngleLine->setText(QCoreApplication::translate("Configuration", "0.7", nullptr));
        PixelSizelable->setText(QCoreApplication::translate("Configuration", "pixelSize", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Configuration: public Ui_Configuration {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGURATION_H
