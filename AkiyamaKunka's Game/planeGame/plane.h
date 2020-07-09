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

    void initPos();

    void updatePos();
    bool isOutRange(int x ,int y);

    int showPosX();
    int showPosY();
    QPixmap givePlane();
    QRect giveSquare();
    void getKey(int);
    void getKeyPressEvent(Qt::Key);
    void getKeyReleaseEvent(Qt::Key);



private:
    QRect square;
    QPixmap battlePlane;

    int poX;
    int poY;


    bool isUp;
    bool isDown;
    bool isLeft;
    bool isRight;

};

#endif // PLANE_H
