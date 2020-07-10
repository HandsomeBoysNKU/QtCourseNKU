#include "plane.h"

Plane::Plane()
{

    battlePlane.load(PLANE_ICON);
    square.setWidth(battlePlane.width());
    square.setHeight(battlePlane.height());
}


QPixmap Plane::givePlane(){
    return battlePlane;
}


int Plane::showPosX(){
    return  poX;
}

int Plane::showPosY(){
    return poY;
}


void Plane::initPos()
{

    poX = GAME_WID  / 2 - battlePlane.width() / 2;
    poY = GAME_LEN / 2 + battlePlane.height();
    square.setWidth(battlePlane.width());
    square.setHeight(battlePlane.height());
    square.moveTo(poX,poY);
}

QRect Plane::giveSquare(){
    return square;
}

void Plane::getKey(int key){
    if(key == 1){
        isUp =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(key == 2){
        isDown =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(key == 3){
        isLeft =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(key == 4){
        isRight =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }


}
void Plane::getKeyPressEvent(Qt::Key ev){
    if(ev == Qt::Key_Up ){
        isUp =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(ev == Qt::Key_Down ){
        isDown =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(ev == Qt::Key_Left ){
        isLeft =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }
    if(ev == Qt::Key_Right ){
        isRight =true;
        //qDebug()<<"W is pressed and the position of X is "<<poY;
    }

}

void Plane::getKeyReleaseEvent(Qt::Key ev){
    if(ev == Qt::Key_Up ){
        isUp = false;
    }
    if(ev == Qt::Key_Down ){
        isDown = false;
    }
    if(ev == Qt::Key_Left ){
        isLeft = false;
    }
    if(ev == Qt::Key_Right ){
        isRight = false;
    }
}

void Plane::updatePos()
{

    if(isUp && !isOutRange(poX, poY- PLANE_MOVE_SPEED) )
        poY -= PLANE_MOVE_SPEED;

    if(isDown && !isOutRange(poX, poY +PLANE_MOVE_SPEED))
        poY += PLANE_MOVE_SPEED;

    if(isLeft && !isOutRange(poX - PLANE_MOVE_SPEED, poY))
        poX -= PLANE_MOVE_SPEED;

    if(isRight && !isOutRange(poX + PLANE_MOVE_SPEED,poY))
        poX += PLANE_MOVE_SPEED;

}


bool Plane::isOutRange(int x, int y){
    if(x  < 0 || y < 0 || x+battlePlane.width() > GAME_WID || y+battlePlane.height() > GAME_LEN)
        return true;
    else
        return false;
}
