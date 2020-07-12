#include "TowerSun.h"
#include "Enemy.h"

const int TowerSun::sunCost = 50;

TowerSun::TowerSun(QGraphicsItem *parent) :
    Tower(150, parent)
{
    setPixmap(QPixmap(":/images/cf2_sunflower1_size80_alpha50.png"));
    pixmapFileName = QString(":/images/cf2_sunflower1_size80.png");
    costI = sunCost;
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
