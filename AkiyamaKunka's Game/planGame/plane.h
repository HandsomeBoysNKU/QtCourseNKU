#ifndef PLANE_H
#define PLANE_H

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include "config.h"
#include "map.h"
#include "bullet.h"
#include <QResource>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

class Plane
{
public:

    Plane();

    void initPos(); // the functions to set the position
    void updatePos();
    void getKey(int); // the get the key number from the user
    void getKeyPressEvent(Qt::Key); // the functions to obtain the key from the user
    void getKeyReleaseEvent(Qt::Key);
    void level1(); // to update the difficulty

    bool isOutRange(int x ,int y); // to detect if the

    int showPosX(); // to provide the coordinate
    int showPosY();

    QPixmap givePlane(); // the provide the picture and square to detect collapse or painting
    QRect giveSquare();

private:

    int poX;
    int poY;

    bool isUp;
    bool isDown;
    bool isLeft;
    bool isRight;

    QRect square;
    QPixmap battlePlane;

};

#endif // PLANE_H
