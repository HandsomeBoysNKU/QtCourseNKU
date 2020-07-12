#include "Enemy.h"
#include <QPixmap>
#include <QTimer>
#include <qmath.h>
#include <QFont>
#include <QColor>
#include <QDebug> ///
#include "Game.h"
#include "Carrot.h"

Enemy::~Enemy()
{
    delete timer;
}

Enemy::Enemy(QList<QPointF> pointsToFollow, QGraphicsItem *parent) :
    MyQGraphicsDigitItem(5, parent)
{
    textOffset = QPointF(20, -40);
    pace = 10;

    if (pointsToFollow.size() <= 0) return;

    for (int i = 0, n = pointsToFollow.size(); i < n; ++i) {
        pathCenterPoints << pointsToFollow[i];
        pathPoints << pathCenterPoints[i];
    }
    pathPointIndex = 0;
    dest = pathPoints[0];
    setTransformOriginPoint(20, 20);

    valueText->setFont(QFont("consolas", 12, 100));
    valueText->setDefaultTextColor(QColor(0xaa, 0xaa, 0xaa));

    activate(100);
}

void Enemy::setPixmap(const QPixmap &pixmap)
{
    MyQGraphicsDigitItem::setPixmap(pixmap);
    for (int i = 0, n = pathCenterPoints.size(); i < n; ++i) {
        pathPoints[i] = pathCenterPoints[i] - selfCenter();
    }
    setPos(pathPoints[pathPointIndex]);
    if (pathPointIndex == 0) {
        dest = pathPoints[0];
        setPos(pathPoints[0]);
    }
}

void Enemy::decrease(int num)
{
    MyQGraphicsDigitItem::decrease(num);
    if (health <= 0) {
        timer->stop();
        scene()->removeItem(this);
        delete this;
    }
}

void Enemy::moveForward()
{
    QLineF line(pos(), dest);
    if (line.length() < 5) {
        ++pathPointIndex;
        if (pathPointIndex >= pathPoints.size()) {
            timer->stop();
            reachEnd();
            scene()->removeItem(this);
            delete this;
            return;
        }
        dest = pathPoints[pathPointIndex];
    }
    double theta = (-1)*line.angle();
    double dy = pace * qSin(qDegreesToRadians(theta));
    double dx = pace * qCos(qDegreesToRadians(theta));
    setPos(x() + dx, y() + dy);
}

void Enemy::activate(int msec)
{
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(moveForward()));
    timer->start(msec);
}

void Enemy::setHealth(int v)
{
    setValue(v);
}
