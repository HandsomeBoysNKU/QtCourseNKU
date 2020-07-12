#include "TowerSun.h"
#include "Enemy.h"

const int TowerSun::sunCost = 50;
const int TowerSun::attackInterval = 1000;
const int TowerSun::detectInterval = 1000;
const int TowerSun::scopeRadius = 150;

TowerSun::TowerSun(QGraphicsItem *parent) :
    Tower(scopeRadius, parent)
{
    setPixmap(QPixmap(":/images/cf2_sunflower1_size80_alpha50.png"));
    pixmapFileName = QString(":/images/cf2_sunflower1_size80.png");
    costI = sunCost;
    animation = new AnimationSunAttack(this);
    animation->setPos(selfCenter() - animation->selfCenter());
}

void TowerSun::activate()
{
    Tower::activate(detectInterval, attackInterval);
    animation->setFPS(4);
    animation->play();
}

void TowerSun::detectAndAttack()
{
    QList<QGraphicsItem *> colliding_items = attackScope->collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        Enemy * enemy = dynamic_cast<Enemy *>(colliding_items[i]);
        if (enemy != nullptr){
            enemy->decrease(1);
        }
    }
}
