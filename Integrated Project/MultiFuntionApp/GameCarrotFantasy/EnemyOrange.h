#ifndef ENEMYORANGE_H
#define ENEMYORANGE_H
#include "Enemy.h"

class EnemyOrange : public Enemy
{
    Q_OBJECT
public:
    EnemyOrange(QList<QPointF> pointsToFollow, QGraphicsItem * parent = nullptr);
};

#endif // ENEMYORANGE_H
