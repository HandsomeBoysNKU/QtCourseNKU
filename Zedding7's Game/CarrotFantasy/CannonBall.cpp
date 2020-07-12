#include <QPixmap>
#include <QTimer>
#include <QList>
#include <QLineF>
#include <qmath.h>
#include <QPen>
#include <QColor>
#include "Game.h"
#include "CannonBall.h"
#include "Enemy.h"

CannonBall::CannonBall(QPointF aoriginPoint, int r, QGraphicsItem *parent) :
    MyQGraphicsPixmapItem(parent)
{
    detectionRadius = 16;
    detectionScope = new QGraphicsEllipseItem(24, 5, 26, 26, this);
    detectionScope->setPen(QPen(QColor(0xff, 0xff, 0xff, 0)));
    setPixmap(QPixmap(":images/cf2_cannonball_cw90.png"));
    pace = 20;
    radius = r;
    originPoint = aoriginPoint;
//    detectionScope->hide();

    QTimer *moveTimer = new QTimer(this);
    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    moveTimer->start(30);
}

void CannonBall::move()
{
    double theta = rotation();
    double dy = pace*qSin(qDegreesToRadians(theta));
    double dx = pace*qCos(qDegreesToRadians(theta));
    setPos(x() + dx, y() + dy);

    QList<QGraphicsItem *> tcollidingItems = detectionScope->collidingItems();
    for (int i = 0, n = tcollidingItems.size(); i < n; ++i){
        Enemy *penemy = dynamic_cast<Enemy *>(tcollidingItems[i]);
        if (penemy != nullptr) {
            penemy->decrease(2);
            // delete them from the heap to save memory
            scene()->removeItem(this);
            delete this;
            return;
        }
    }
    QLineF line = QLineF(pos(), originPoint);
    if (line.length() > radius || x() > scene()->width() || y() > scene()->height()) {
        scene()->removeItem(this);
        delete this;
    }
}

