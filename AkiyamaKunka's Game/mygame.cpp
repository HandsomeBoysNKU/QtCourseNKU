#include "mygame.h"
#include "ui_mygame.h"

MyGame::MyGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyGame)
{

    ui->setupUi(this);
    connect(ui->quitGame, &QPushButton::clicked, this,&MyGame::close);

    //this->grabKeyboard();
    initPos();
    initSence();

}

MyGame::~MyGame()
{
    delete ui;
}


void MyGame::paintEvent(QPaintEvent *){
    QPainter painter(this);
    //painter.setBrush(QBrush(Qt::gray,Qt::SolidPattern));
    //painter.drawRect(5,5,100,100);
    //connect(ui->startGame,&QPushButton::clicked,painter, &changePoX );
    battlePlane.load(PLANE_ICON);
    painter.drawPixmap(5,5,QPixmap(PLANE_ICON));
    painter.drawPixmap(poX,poY,PLANE_WID,PLANE_LEN, battlePlane);
    //qDebug()<<"the printer works";


}

void MyGame::changePoX()
{

}

void MyGame::initSence()
{
    setFixedSize(GAME_WID, GAME_LEN);
    setWindowTitle(GAME_TITEL);
    setWindowIcon(QIcon(PLANE_ICON));
    timer.setInterval(REFRESH_RATE);
    timer.start();
    connect(&timer, &QTimer::timeout,[=](){
        //qDebug()<<"the connect worked";
        updatePos();
        update();

    });

}

void MyGame::initPos()
{
    poX = (GAME_WID + PLANE_WID)/2;
    poY = (GAME_LEN + PLANE_LEN)/2;
}

void MyGame::movePlane()
{

}

void MyGame::keyPressEvent(QKeyEvent *ev)
{
    if(ev->key() == Qt::Key_Up ){
       isUp =true;
       //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(ev->key() == Qt::Key_Down ){
       isDown =true;
       //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(ev->key() == Qt::Key_Left ){
       isLeft =true;
       //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(ev->key() == Qt::Key_Right ){
       isRight =true;
       //qDebug()<<"W is pressed and the position of X is "<<poY;
    }

    QWidget::keyPressEvent(ev);
}

void MyGame::keyReleaseEvent(QKeyEvent *ev)
{   //qDebug()<< " isUp false";
    if(ev->key() == Qt::Key_Up ){
           isUp = false;
        }
    if(ev->key() == Qt::Key_Down ){
           isDown = false;
        }
    if(ev->key() == Qt::Key_Left ){
           isLeft = false;
        }
    if(ev->key() == Qt::Key_Right ){
           isRight = false;
        }
        QWidget::keyReleaseEvent(ev);
}

void MyGame::updatePos()
{

    if(isUp && !isOutRange())
        poY -= PLANE_MOVE_SPEED;
    else{
        if(isUp && poY < 0)
        poY += PLANE_MOVE_SPEED*4;
    }
    if(isDown && !isOutRange())
        poY += PLANE_MOVE_SPEED;
    else{
        if(isDown && poY > GAME_LEN)
        poY -= PLANE_MOVE_SPEED*4;
    }
    if(isLeft && !isOutRange())
        poX -= PLANE_MOVE_SPEED;
    else{
        if(isLeft&& poX < 0)
        poX += PLANE_MOVE_SPEED*4;
    }
    if(isRight && !isOutRange())
        poX += PLANE_MOVE_SPEED;
    else{
        if(isRight && poX >GAME_WID )
        poX -= PLANE_MOVE_SPEED*4;
    }

}
bool MyGame::isOutRange(){
    if(poX < 0 || poY < 0 || poX > GAME_WID || poY > GAME_LEN)
        return true;
    else
        return false;
}
