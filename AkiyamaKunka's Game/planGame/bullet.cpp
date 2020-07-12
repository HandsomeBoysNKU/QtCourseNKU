#include "bullet.h"


int Bullet::speed = BULLET_SPEED;
int Bullet::interval = BULLET_INTERVAL * 2;
QPixmap* Bullet::image(NULL);

Bullet::Bullet()
{
    image = new QPixmap(BULLET_LOCAT);
    posX = GAME_WID/2;
    posY = GAME_LEN/2;

    //image->load(BULLET_LOCAT);
    square.setWidth(image->width()); // to set the square to detect the collapse
    square.setHeight(image->height());
    square.moveTo(posX, posY);

    free = true;
}


void Bullet::setPos(int x, int y){
    posX = x;
    posY = y;
}

void Bullet::level1()
{
    image->load(BULLET_LOCAT1);
    speed = BULLET_SPEED * 1.5;
}

void Bullet::level2()
{
    image->load(BULLET_LOCAT2);
    speed = BULLET_SPEED * 4;
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



QRect Bullet::giveRect()
{
    return square;
}

bool Bullet::isFree()
{
    return free;
}

QPixmap Bullet::giveImage()
{
    return *image;
}

void Bullet::setFree()
{
    free = !free;
}
