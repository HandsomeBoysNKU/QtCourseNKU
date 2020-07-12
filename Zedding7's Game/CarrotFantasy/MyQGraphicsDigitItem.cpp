#include "MyQGraphicsDigitItem.h"
#include <QPointF>

MyQGraphicsDigitItem::MyQGraphicsDigitItem(int ahealth, QGraphicsItem *parent) :
    MyQGraphicsPixmapItem(parent)
{
    value = ahealth;
    valueText = new QGraphicsTextItem(this);
    textOffset = QPointF(0, 0);
    valueText->setPlainText(QString::number(value));
}

void MyQGraphicsDigitItem::setPixmap(const QPixmap &pixmap)
{
    MyQGraphicsPixmapItem::setPixmap(pixmap);
    valueText->setPos(selfCenter() + textOffset);
}

void MyQGraphicsDigitItem::setTextOffset(QPoint pos)
{
    textOffset = pos;
}

void MyQGraphicsDigitItem::decrease(int num)
{
    value -= num;
    valueText->setPlainText(QString::number(value));
}

void MyQGraphicsDigitItem::increase(int num)
{
    value += num;
    valueText->setPlainText(QString::number(value));
}

void MyQGraphicsDigitItem::setValue(int v)
{
    value = v;
    valueText->setPlainText(QString::number(value));
}

