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
    void setPixmap(const QPixmap& pixmap);
    enum Monster { orange, blue };

signals:
    void reachEnd();

public slots:
    void decrease(int num);
    void moveForward();

protected:
    void activate(int msec = 100);
    void setHealth(int v);

    QTimer *timer;
    QList<QPointF> pathCenterPoints;
    QList<QPointF> pathPoints;
    QPointF dest;
    int pathPointIndex;
    int pace;

private:
    int& health = value;
};

#endif // ENEMY_H
