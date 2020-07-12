#ifndef TOWERSUN_H
#define TOWERSUN_H

#include "Tower.h"
#include "AnimationSunAttack.h"

class TowerSun : public Tower {
public:
    TowerSun(QGraphicsItem *parent = nullptr);
    virtual void activate();

    const static int sunCost;
public slots:
    virtual void detectAndAttack();

private:
    AnimationSunAttack *animation = nullptr;
    const static int attackInterval;
    const static int detectInterval;
    const static int scopeRadius;
};

#endif // TOWERSUN_H
