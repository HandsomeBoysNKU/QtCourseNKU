#ifndef MYQGRAPHICSPIXMAPITEM_H
#define MYQGRAPHICSPIXMAPITEM_H

#include <QGraphicsPixmapItem>
#include <QPointF>


class MyQGraphicsPixmapItem : public QGraphicsPixmapItem
{
public:
    MyQGraphicsPixmapItem(QGraphicsItem *parent = nullptr);
    void setPixmap(const QPixmap &pixmap);
    void rotateToPoint(const QPointF& dest);
    int width();
    int height();
    QPointF selfCenter();
    QPointF centerPos();
protected:
    QString pixmapFileName;
    int widthI;
    int heightI;
    QPointF selfCenterI;

};

#endif // MYQGRAPHICSPIXMAPITEM_H
