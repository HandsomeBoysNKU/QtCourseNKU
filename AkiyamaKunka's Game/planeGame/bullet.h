#ifndef BULLET_H
#define BULLET_H
#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include "config.h"
#include "map.h"
#include "plane.h"
#include <QResource>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

class Bullet
{
public:
    Bullet();

    void updatePos();  //functions that relevant to position
    void setFree();
    void setPos(int, int);

    int givePosX();
    int givePosY();

    bool isFree(); //the same logic

    QPixmap giveImage(); //return the QPixmap and QRect to paint and judge the collapse
    QRect giveRect();

private:

    int posX;
    int posY;

    int speed; // the speed of bullet
    bool free;
    int interval; // the interval for timing to emit the bullet

    QPixmap image;
    QRect square;

};

#endif // BULLET_H
