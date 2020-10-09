#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>
#include<CameraParameter.h>

namespace Ui {
class Configuration;
}

class Configuration : public QDialog
{
    Q_OBJECT

public:
    explicit Configuration(QWidget *parent = nullptr);
    ~Configuration();
    CameraParameter *Camera_Parameter;

private slots:
    void on_buttonBox_accepted();

    void on_CameraBrightness_valueChanged(int value);

    void on_Brightness_spinBoxdouble_valueChanged(double arg1);

    void on_CameraGain_valueChanged(int value);

    void on_Cameragain_spinBoxdouble_valueChanged(double arg1);

    void on_CameraGama_valueChanged(int value);

    void on_Gama_spinBoxdouble_valueChanged(double arg1);

    void on_ProduceMatrix_clicked();

    void on_ParameterContrast_clicked();

private:
    Ui::Configuration *ui;
signals:
    void sendseting2opengl(QList<float>);
    void sendbrightness2HDcamera(double);
    void sendcameragain2HDcamera(double);
    void sendcameragama2HDcamera(double);
};

#endif // CONFIGURATION_H
