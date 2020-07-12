#include "EnemyOrange.h"

EnemyOrange::EnemyOrange(QList<QPointF> pointsToFollow, QGraphicsItem * parent) :
    Enemy(pointsToFollow, parent)
{
    setPixmap(QPixmap(":/images/cf2_monsterOrange_size60.png"));
    setHealth(6);
}
