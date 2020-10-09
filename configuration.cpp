#include "configuration.h"
#include "ui_configuration.h"

QList<float>setinglist;
const float PI =3.1415926;
QList<float>parametersetinglist;
Configuration::Configuration(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Configuration)
{
    ui->setupUi(this);

    Camera_Parameter =new CameraParameter();//校准对象
}

Configuration::~Configuration()
{
    delete ui;
}

void Configuration::on_buttonBox_accepted()
{
    setinglist.append( ui->pixelSizeLine->text().toFloat());
    setinglist.append( ui->focalLine->text().toFloat());
    setinglist.append( ui->baseLineLine->text().toFloat());
    setinglist.append( ui->stepAngleLine->text().toFloat()*PI/180);
    setinglist.append( ui->laserAngleLine->text().toFloat()*PI/180);
    setinglist.append( ui->rgeLine->text().toInt());
    emit sendseting2opengl(setinglist);
    setinglist.clear();
}

void Configuration::on_CameraBrightness_valueChanged(int value)
{
    double K=value*0.1;
    ui->Brightness_spinBoxdouble->setValue(K);
    emit sendbrightness2HDcamera(K);
}

void Configuration::on_Brightness_spinBoxdouble_valueChanged(double arg1)
{
    int K =arg1*10;
     ui->CameraBrightness->setValue(K);
}

void Configuration::on_CameraGain_valueChanged(int value)
{
    double K=value*0.1;
   ui->Cameragain_spinBoxdouble ->setValue(  K);
    emit sendcameragain2HDcamera( K);
}

void Configuration::on_Cameragain_spinBoxdouble_valueChanged(double arg1)
{
    int K =arg1*10;
       ui->CameraGain->setValue(K);
}

void Configuration::on_CameraGama_valueChanged(int value)
{
    double K=value*0.1;
    ui->Gama_spinBoxdouble->setValue( K);
    emit sendcameragama2HDcamera( K);
}

void Configuration::on_Gama_spinBoxdouble_valueChanged(double arg1)
{
    int K =arg1*10;
       ui->CameraGama->setValue(K);
}

void Configuration::on_ProduceMatrix_clicked()
{
    parametersetinglist.append(ui->Picture_N->text().toFloat());
    parametersetinglist.append(ui->P_CornerNumber_row->text().toFloat());
    parametersetinglist.append(ui->P_CornerNumber_col->text().toFloat());
    parametersetinglist.append(ui->CellSize_width->text().toFloat());
    parametersetinglist.append(ui->CellSize_height->text().toFloat());
    parametersetinglist.append(ui->Iteration_N->text().toFloat());
    parametersetinglist.append(ui->Accuracy->text().toFloat());
    Camera_Parameter->CameraParameter_ProduceMatrix(parametersetinglist);
    parametersetinglist.clear();
}

void Configuration::on_ParameterContrast_clicked()
{
   Camera_Parameter->CameraParameter_Constrast();
}
