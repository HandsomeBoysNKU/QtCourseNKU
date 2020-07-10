#include "bullet.h"

Bullet::Bullet()
{

    image.load(BULLET_LOCAT);
    posX = GAME_WID/2;
    posY = GAME_LEN/2;
    interval = BULLET_INTERVAL;
    speed = BULLET_SPEED;

    square.setWidth(image.width()); // to set the square to detect the collapse
    square.setHeight(image.height());
    square.moveTo(posX, posY);

    free = true;
}


void Bullet::setPos(int x, int y){
    posX = x;
    posY = y;
}
void Bullet::updatePos()
{
    if(free)
        return;

    posY -= speed;
    square.moveTo(posX, posY);

    if(posY <= square.height())
        free = false;
}

int Bullet::givePosX(){
    return posX;
}

int Bullet::givePosY(){
    return posY;
}

QPixmap Bullet::giveImage(){
    return image;
}

QRect Bullet::giveRect()
{
    return square;
}

bool Bullet::isFree()
{
    return free;
}

void Bullet::setFree()
{
    free = !free;
}
