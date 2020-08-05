#include "DaVinci.h"
#include <QPainter>
#include <QPaintEvent>
#include <QWidget>



//Davinci::Davinci()
//{

//}

void Davinci::DavinciBrush(QPainter *painter, QPaintEvent *event,QImage sk)
{
      painter->fillRect(event->rect(),QColor(64, 32, 64));
      painter->save();
      painter->restore();
      painter->drawImage(QPoint(0, 0),sk);

}
