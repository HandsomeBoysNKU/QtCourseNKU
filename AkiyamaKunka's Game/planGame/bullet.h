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
    static void level1();
    static void level2(); // the function to update difficulty
    int givePosX();
    int givePosY();

    bool isFree(); //the same logic

    static QPixmap giveImage(); //return the QPixmap and QRect to paint and judge the collapse
    QRect giveRect();

private:

    int posX;
    int posY;

    static int speed; // the speed of bullet
    bool free;
    static int interval; // the interval for timing to emit the bullet


    static QPixmap* image;
    QRect square;

};

#endif // BULLET_H
