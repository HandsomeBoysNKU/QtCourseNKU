#include "Carrot.h"
#include <QFont>
#include <QColor>

Carrot::Carrot(QGraphicsItem *parent) :
    MyQGraphicsDigitItem(5, parent)
{
    textOffset = QPointF(-55, -20);
    setPixmap(QPixmap(":/images/cf2_carrot1.png"));
    valueText->setFont(QFont("consolas", 20, 120));
    valueText->setDefaultTextColor(QColor(0xff, 0xff, 0xff));
}

void Carrot::decrease(int num)
{
    MyQGraphicsDigitItem::decrease(num);
    if (health <= 0)  {
        carrotIsDead();
        setValue(0);
    }
}
