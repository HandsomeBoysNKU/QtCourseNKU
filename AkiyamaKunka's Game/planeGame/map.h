#ifndef MAP_H
#define MAP_H

#include<QPixmap>
#include "config.h"

class Map
{
public:

    Map();

    void initMapPos();
    void setMapSpeed(int);// to set the speed of map to scroll
    void setMapSpeed();
    void mapPos(); // set the opsition of the map
    void resetMapPos1(); // to make the maps are able to root
    void resetMapPos2();

    int showPosY(int); // provide only the Y coordinate

    QPixmap giveMap(int); // return the picture for the painter to print the object

private:

    QPixmap background1;
    QPixmap background2;

    int bg1PosY; // the first map Y coordinate
    int bg2PosY; // the second map Y coordinate
    int scrollSpeed; // the scrolling speed

};

#endif // MAP_H
