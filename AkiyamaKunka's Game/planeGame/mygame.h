#ifndef MYGAME_H
#define MYGAME_H

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

QT_BEGIN_NAMESPACE
namespace Ui { class MyGame; }
QT_END_NAMESPACE



class MyGame : public QMainWindow
{
    Q_OBJECT

public:

    MyGame(QWidget *parent = nullptr);
    ~MyGame();
    void paintEvent(QPaintEvent* );

    void initSence();

    void movePlane();
    void updatePos();
    bool isOutRange(int x ,int y);


protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);


private:
    Map background;
    Plane myPlane;

    QPainter paintRect;

    QTimer timer;



    Ui::MyGame *ui;
};
#endif // MYGAME_H
