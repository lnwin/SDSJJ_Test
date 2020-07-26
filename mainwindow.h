#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include<optional>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void searchPort();
    void ReadData();
    void SendData();
private slots:
    void on_PortButton_clicked();
    void on_senddatabutton_clicked();
    void on_pointfilepushButton_clicked();
   // void on_closeButton_clicked();
   // void on_sendSpeedButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort *serial;

static QString getOpenFileName(   //定义点云文件路径属性
QWidget *parent = Q_NULLPTR,
const QString &caption = QString(),
const QString &dir = QString(),
const QString &filter = QString(),
QString *selectedFilter = Q_NULLPTR);


};
#endif // MAINWINDOW_H
