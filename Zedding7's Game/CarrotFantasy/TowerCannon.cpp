#include "TowerCannon.h"
#include <QTimer>
#include <QGraphicsScene>
#include <qmath.h>
#include "Enemy.h"
#include "CannonBall.h"
#include <QDebug>

const int TowerCannon::cannonCost = 20;
TowerCannon::TowerCannon(QGraphicsItem *parent) :
    Tower(283, parent)
{
    setPixmap(QPixmap(":/images/cf2_cannon1_alpha50.png"));
    pixmapFileName = QString(":/images/cf2_cannon1_cw90.png");
    costI = cannonCost;
}

void TowerCannon::activate()
{
    Tower::activate(150, 800);
    setRotation(-90);
}


void TowerCannon::detectAndAttack()
{
    target = QPointF(0, 0);
    hasTarget = false;
    QList<QGraphicsItem *> colliding_items = attackScope->collidingItems();
    double closestDist = 10000;

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        // make sure it is an enemy
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy != nullptr){
            double thisDist = distanceTo(colliding_items[i]);
            if (thisDist < closestDist){
                closestDist = thisDist;
                target = enemy->pos();
                hasTarget = true;
            }
        }
    }
    if (hasTarget) {
        rotateToPoint(target);
//        QLineF line(selfCenter(), target);
//        int angle = (1) * line.angle();
//        qDebug()<<"c angle"<<angle<<"c rotation"<<rotation();
    }
}

void TowerCannon::attack()
{
    if (hasTarget){
        QPointF origin = centerPos();
        double theta = (-1)*rotation();
        double dy = 10 * qSin(qDegreesToRadians(theta));
        double dx = 10 * qCos(qDegreesToRadians(theta));

        CannonBall * ball = new CannonBall(origin, radius);
        ball->setPos(centerPos() - ball->selfCenter() + QPointF(dx, dy));
        ball->setRotation(rotation());
        scene()->addItem(ball);
    }
}
