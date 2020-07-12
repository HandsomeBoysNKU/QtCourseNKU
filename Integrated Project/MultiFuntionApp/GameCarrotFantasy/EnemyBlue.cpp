#include "EnemyBlue.h"

EnemyBlue::EnemyBlue(QList<QPointF> pointsToFollow, QGraphicsItem * parent) :
    Enemy(pointsToFollow, parent)
{
    setPixmap(QPixmap(":/images/cf2_monsterBlue_size60.png"));
    setHealth(10);
}
