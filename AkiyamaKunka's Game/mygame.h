#ifndef MYGAME_H
#define MYGAME_H

#include <QMainWindow>
#include <QApplication>
#include <QPainter>
#include <QPushButton>
#include "config.h"
#include <QResource>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QTimer>

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
    void changePoX();
    void initSence();
    void initPos();
    void movePlane();
    void updatePos();
    bool isOutRange();

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    virtual void keyReleaseEvent(QKeyEvent *event);




private:

    QPainter paintRect;
    QRect square;
    QPixmap battlePlane;
    QTimer timer;

    int poX;
    int poY;

    bool isUp;
    bool isDown;
    bool isLeft;
    bool isRight;

    Ui::MyGame *ui;
};
#endif // MYGAME_H
