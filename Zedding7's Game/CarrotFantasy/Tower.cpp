#include "Tower.h"
#include <QPixmap>
#include <QGraphicsScene>
#include <QPen>
#include <QPointF>
#include <QLineF>
#include <QTimer>
#include <QGraphicsRectItem>
#include "CannonBall.h"
#include "Enemy.h"

Tower::Tower(int aradius, QGraphicsItem *parent) :
    MyQGraphicsPixmapItem(parent),
    radius(aradius)
{
    attackScope = new QGraphicsEllipseItem(0, 0, 2*radius, 2*radius, this);
    setPixmap(QPixmap(":/images/tower1_alpha50.png"));
    pixmapFileName = QString(":/images/tower1.png");
    attackScope->setPen(QPen(Qt::DotLine));
}

void Tower::setPixmap(const QPixmap &pixmap)
{
    MyQGraphicsPixmapItem::setPixmap(pixmap);
    if (attackScope != nullptr) {
        attackScope->setPos(selfCenter() - QPointF(radius, radius));
    }
}

double Tower::distanceTo(QGraphicsItem *item){
    // returns the distance to the item
    QLineF ln(this->centerPos(), item->pos() + item->boundingRect().center());
    return ln.length();
}

void Tower::detectAndAttack(){

}

void Tower::attack()
{

}

int Tower::cost()
{
    return costI;
}

void Tower::activate(int di, int ai)
{
    setPixmap(QPixmap(pixmapFileName));

    detectTimer = new QTimer(this);
    connect(detectTimer, SIGNAL(timeout()), this, SLOT(detectAndAttack()));
    detectTimer->start(di);

    attackTimer = new QTimer(this);
    connect(attackTimer, SIGNAL(timeout()), this, SLOT(attack()));
    attackTimer->start(ai);
    attackScope->hide();
}

void Tower::activate()
{
    activate(1000, 1000);
}
