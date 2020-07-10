#include "bomb.h"

Bomb::Bomb()
{

    free = true;
    posX = 0;
    posY = 0;
    timeRecord = 0;
    indexOfAnime = 0;

    for (int i =0; i < BOMB_MAX; ++i){ // to get all the bombs picture to make the whole playing like a gif
        QString temp = QString(BOMB_PATH).arg(i+1);
        animeArray.push_back(QPixmap(temp));  // we used the vector here
    }
}

void Bomb::updateInfo()
{
    if(free)
        return;

    timeRecord++;

    if(timeRecord < BOMB_INTERVAL)
        return;

    timeRecord = 0;
    indexOfAnime++;

    if(indexOfAnime + 1 > BOMB_MAX){
        indexOfAnime = 0;
        free = true;
    }
}

bool Bomb::isFree()
{
    return free;
}

void Bomb::setPos(int x, int y)
{
    posX = x;
    posY = y;
}

void Bomb::setFree()
{
    free = !free;
}

int Bomb::getIndex()
{
    return indexOfAnime;
}

QPixmap Bomb::giveImage(int i)
{
    return animeArray[i];
}

int Bomb::showPosX()
{
    return posX;
}

int Bomb::showPosY()
{
    return posY;
}

