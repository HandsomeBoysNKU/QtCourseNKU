#ifndef MYGAME_H
#define MYGAME_H

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include "config.h"
#include "map.h"
#include "plane.h"
#include "enemy.h"
#include "bomb.h"
#include <QResource>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QMessageBox>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class MyGame; }
QT_END_NAMESPACE



class MyGame : public QMainWindow
{
    Q_OBJECT

public:

    MyGame(QWidget *parent = nullptr);
    ~MyGame();

    void paintEvent(QPaintEvent* ); // the function to paint all the elements
    void initSence();
    void movePlane();
    void updatePos();
    void setBullet(int i);
    void setEnemy();
    void ifCollapsed(); // to detect if some objects are collapsed
    void updateLevel();
    bool isOutRange(int x ,int y);

protected:

    virtual void keyPressEvent(QKeyEvent *event); // rewrite the game to make sure that the keyEvent can be detect correctly
    virtual void keyReleaseEvent(QKeyEvent *event);

private:

    int enemyRecord; // a parameter for timer to refresh the enemies
    int bulletRecord; // to set the time of the bullet to emit
    int bulletRecordRate;
    int cntBullet; // to relize the bullet functions
    int score; // the score of the player
    int life; // the HP of our plane
    int enemyInverval; // to generate enemy every a few second

    Map background; // the background

    Plane myPlane; // our plane

    Bullet myBullet[BULLET_NUM]; // an array of bullets in the plane

    Bomb myBomb[ENEMY_NUM]; // an array of bombs

    Enemy myEnemy[ENEMY_NUM]; // an array of enemies

    QPainter paintRect; // the painter

    QTimer timer; // record the time to make sure the game is refreshed

    Ui::MyGame *ui;
};
#endif // MYGAME_H
