#ifndef BOMB_H
#define BOMB_H
#include "config.h"
#include <QVector>
#include <QPixmap>
#include <QString>
#include <QDebug>
class Bomb
{

public:

    Bomb();

    bool isFree(); //to show if the object is active of not

    void updateInfo();
    void setPos(int, int); // set Position
    void setFree(); // reverse the object state

    int getIndex(); // return the picture index of a gif
    int showPosX(); // to show the x and y coordinate
    int showPosY();

    QPixmap giveImage(int); // return QPixmap

private:

    int posX;
    int posY;
    int timeRecord;
    int indexOfAnime;

    QVector <QPixmap> animeArray;

    bool free;

};

#endif // BOMB_H
