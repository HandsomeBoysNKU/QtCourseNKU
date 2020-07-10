#include "enemy.h"

Enemy::Enemy()
{

    posX = 0;
    posY = 0;
    free = true;
    image.load(ENEMY_PATH);
    speed = ENEMY_SPEED;

    square.setWidth(image.width());
    square.setHeight(image.height());
    square.moveTo(posX,posY);

}

void Enemy::updatePos()
{
    if(free)
        return;

    posY += speed;
    square.moveTo(posX, posY);

    if(posY > GAME_LEN)
        free = true;
}

void Enemy::setFree()
{
    free = !free;
}

void Enemy::setPos(int x, int y)
{
    posX = x;
    posY = y;
}

int Enemy::showPosX()
{
    return posX;
}

int Enemy::showPosY()
{
    return posY;
}

QPixmap Enemy::giveImage()
{
    return image;
}

QRect Enemy::giveRect()
{
    return square;
}

bool Enemy::isFree()
{
    return free;
}

