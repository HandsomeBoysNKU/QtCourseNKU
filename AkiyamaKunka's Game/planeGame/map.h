#ifndef MAP_H
#define MAP_H

#include<QPixmap>
#include "config.h"

class Map
{
public:

    Map();
    void initMapPos();
    void setMapSpeed(int);
    void setMapSpeed();
    void mapPos();
    void resetMapPos1();
    void resetMapPos2();
    QPixmap giveMap(int);
    int showPosY(int);


private:
    QPixmap background1;
    QPixmap background2;
    int bg1PosY;
    int bg2PosY;
    int scrollSpeed;

};

#endif // MAP_H
