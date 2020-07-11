#ifndef BROWNTOWER_H
#define BROWNTOWER_H

#include "Tower.h"
#include <QPointF>

class TowerCannon: public Tower
{
    Q_OBJECT
public:
    TowerCannon(QGraphicsItem * parent = nullptr);
    virtual void activate();

    const static int cannonCost;
public slots:
    virtual void detectAndAttack();
    virtual void attack();
protected:
    QPointF target;

};

#endif // BROWNTOWER_H
