#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QList>
#include <QPointF>
#include <QTimer>
#include <QGraphicsTextItem>
#include "MyQGraphicsPixmapItem.h"
#include "MyQGraphicsDigitItem.h"

class Enemy : public MyQGraphicsDigitItem
{
    Q_OBJECT
public:
    ~Enemy();
    Enemy(QList<QPointF> pointsToFollow, QGraphicsItem * parent = nullptr);
signals:
    void reachEnd();
public slots:
    void decrease(int num = 1);
    void moveForward();
protected:
    QTimer *timer;
    QList<QPointF> points;
    QPointF dest;
    int pointIndex;
    int pace;
    void activate(int msec = 100);
private:
    int& health = value;
};

#endif // ENEMY_H
