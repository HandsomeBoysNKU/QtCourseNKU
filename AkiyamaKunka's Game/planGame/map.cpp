#include "map.h"


Map::Map()
{
    initMapPos();
    setMapSpeed();

    background1.load(MAP_LOCAT);
    background2.load(MAP_LOCAT); // to set the background image

}
QPixmap Map::giveMap(int num)
{
    if(num == 1)
        return background1;
    else
        return background2;
}


int Map::showPosY(int num)
{
    if(num == 1)
        return bg1PosY;
    else
        return bg2PosY;
}
void Map::initMapPos()
{
    resetMapPos1();
    resetMapPos2();
}

void Map::setMapSpeed()
{
    scrollSpeed = MAP_SPEED;
}
void Map::setMapSpeed(int num)
{
    scrollSpeed = num;
}

void Map::mapPos()
{
    bg1PosY += scrollSpeed;
    bg2PosY += scrollSpeed;

    if( bg1PosY > GAME_LEN){
        resetMapPos1();
    }
    if(bg2PosY > 0)
    {
        resetMapPos2();
    }
}

void Map::resetMapPos1()
{
    bg1PosY = 0;
}

void Map::resetMapPos2()
{
    bg2PosY =-GAME_LEN;
}

void Map::Level1()
{
    background1.load(MAP_LOCAT1);
    background2.load(MAP_LOCAT1);
}

void Map::Level2()
{
    background1.load(MAP_LOCAT2);
    background2.load(MAP_LOCAT2);
}
