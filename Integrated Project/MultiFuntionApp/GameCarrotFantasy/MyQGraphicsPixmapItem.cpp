#include "MyQGraphicsPixmapItem.h"
#include <QLineF>

MyQGraphicsPixmapItem::MyQGraphicsPixmapItem(QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{

}

MyQGraphicsPixmapItem::MyQGraphicsPixmapItem(const QPixmap &pixmap, QGraphicsItem *parent) :
    QGraphicsPixmapItem(parent)
{
    setPixmap(pixmap);
}

void MyQGraphicsPixmapItem::setPixmap(const QPixmap& pixmap)
{
    QGraphicsPixmapItem::setPixmap(pixmap);
    widthI = pixmap.width();
    heightI = pixmap.height();
    selfCenterI = boundingRect().center();
//    selfCenterI = QPointF(widthI/2, heightI/2);
    setTransformOriginPoint(selfCenter());
}

void MyQGraphicsPixmapItem::rotateToPoint(const QPointF &dest)
{

    QLineF line(centerPos(), dest);
    int angle = (-1) * line.angle();
    setRotation(angle);
}

int MyQGraphicsPixmapItem::width()
{
    return widthI;
}

int MyQGraphicsPixmapItem::height()
{
    return heightI;
}

QPointF MyQGraphicsPixmapItem::selfCenter()
{
    return selfCenterI;
}

QPointF MyQGraphicsPixmapItem::centerPos()
{
    return pos() + selfCenterI;
}
