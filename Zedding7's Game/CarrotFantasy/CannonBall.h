#ifndef BULLET_H
#define BULLET_H

#include "MyQGraphicsPixmapItem.h"
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QObject>
#include <QPointF>

class CannonBall : public QObject, public MyQGraphicsPixmapItem {
    Q_OBJECT
public:
    CannonBall(QPointF originP, int r, QGraphicsItem *parent = nullptr);
public slots:
    void move();
protected:
    QGraphicsEllipseItem *detectionScope;
    int detectionRadius;
    int pace;
    int radius;
    QPointF originPoint;
};

#endif // BULLET_H
