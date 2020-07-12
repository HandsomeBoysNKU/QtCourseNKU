#include "AnimationSunAttack.h"

const QString AnimationSunAttack::filename(":/images/cf2_animation_sunTower_attack_%1.png");
const int AnimationSunAttack::count(4);

AnimationSunAttack::AnimationSunAttack(QGraphicsItem *parent) :
    MyAnimation(filename, count, parent)
{
    setCyclic(true);
}
