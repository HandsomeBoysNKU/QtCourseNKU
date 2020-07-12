#include "enemy.h"

int Enemy::speed = ENEMY_SPEED * 0.88;

Enemy::Enemy()
{

    posX = 0;
    posY = 0;
    free = true;

    QPixmap array[3];
    array[0].load(ENEMY_PATH);
    array[1].load(ENEMY_PATH1);
    array[2].load(ENEMY_PATH2);
    image = array[rand() % 3]; // to randomly choose an enemy plane as the image to the single object

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

void Enemy::level1()
{
    speed = speed * 1.5;
}

void Enemy::level2()
{
    speed = speed * 3;
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

