#ifndef MYQGRAPHICSHEALTHITEM_H
#define MYQGRAPHICSHEALTHITEM_H

#include <QObject>
#include <QGraphicsTextItem>
#include "MyQGraphicsPixmapItem.h"

class MyQGraphicsDigitItem : public QObject, public MyQGraphicsPixmapItem
{
    Q_OBJECT
public:
    MyQGraphicsDigitItem(int ahealth = 0, QGraphicsItem *parent = nullptr);
    void setPixmap(const QPixmap& pixmap);
    void setValue(int v);
    void setTextOffset(QPoint pos);

    QGraphicsTextItem *valueText;

public slots:
    virtual void decrease(int num = 1);
    virtual void increase(int num = 1);

protected:
    int value;
    QPointF textOffset;
};

#endif // MYQGRAPHICSHEALTHITEM_H
