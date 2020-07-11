#ifndef TOWERSUN_H
#define TOWERSUN_H
#include "Tower.h"

class TowerSun : public Tower {
public:
    TowerSun(QGraphicsItem *parent = nullptr);
    const static int sunCost;
public slots:
    virtual void detectAndAttack();
};

#endif // TOWERSUN_H
