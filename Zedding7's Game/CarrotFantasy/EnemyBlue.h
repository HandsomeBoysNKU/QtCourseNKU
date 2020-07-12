#ifndef ENEMYBLUE_H
#define ENEMYBLUE_H

#include "Enemy.h"

class EnemyBlue : public Enemy
{
public:
    EnemyBlue(QList<QPointF> pointsToFollow, QGraphicsItem * parent = nullptr);
};

#endif // ENEMYBLUE_H
