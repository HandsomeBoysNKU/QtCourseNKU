#ifndef TOWER_H
#define TOWER_H

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QPointF>
#include <QTimer>
#include <QObject>
#include "MyQGraphicsPixmapItem.h"

class Tower:public QObject, public MyQGraphicsPixmapItem
{
    Q_OBJECT
public:
    Tower(int aradius = 200, QGraphicsItem * parent = nullptr);
    void setPixmap(const QPixmap &pixmap);
    double distanceTo(QGraphicsItem * item);
    virtual void activate();
    int cost();

public slots:
    virtual void detectAndAttack();
    virtual void attack();

protected:
    void activate(int detectInterval, int attackInterval);

    QTimer *detectTimer = nullptr;
    QTimer *attackTimer = nullptr;
    QGraphicsEllipseItem * attackScope = nullptr;
    int radius = 0;
    int costI = 0;
    bool hasTarget;
};

#endif // TOWER_H
