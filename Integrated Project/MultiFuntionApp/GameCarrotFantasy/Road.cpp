#include "Road.h"

Road::Road(QGraphicsItem *parent) :
    MyQGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/stone3_size100.png"));
}
