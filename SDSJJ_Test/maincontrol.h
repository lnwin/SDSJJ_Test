#ifndef MAINCONTROL_H
#define MAINCONTROL_H

#include <QObject>
#include <QQuickItem>

class MainControl:public QObject
{
    Q_OBJECT


public:
    MainControl();

   Q_INVOKABLE void chufa();

signals:

  //  void sendmessage();

public slots:

   // void receivedmssage();

};

#endif // MAINCONTROL_H
