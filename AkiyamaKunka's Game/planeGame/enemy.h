#ifndef ENEMY_H
#define ENEMY_H

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

class Enemy
{
public:

    Enemy();

    void updatePos(); //the functions to set the coordinate
    void setFree();
    void setPos(int, int);

    int showPosX(); //to provide the coordinate
    int showPosY();

    QPixmap giveImage(); // return the QPixmap and QRect to paint and judge the collapse
    QRect giveRect();

    bool isFree(); //show the state of activation of a object

private:

    QPixmap image;
    QRect square;

    int posX;
    int posY;
    int speed;

    bool free;


};

#endif // ENEMY_H
