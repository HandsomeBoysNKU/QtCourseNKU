#ifndef ANIMATIONSUNATTACK_H
#define ANIMATIONSUNATTACK_H

#include "MyAnimation.h"

class AnimationSunAttack : public MyAnimation
{
    Q_OBJECT
public:
    AnimationSunAttack(QGraphicsItem *parent = nullptr);
private:
    static const QString filename;
    static const int count;
};

#endif // ANIMATIONSUNATTACK_H
