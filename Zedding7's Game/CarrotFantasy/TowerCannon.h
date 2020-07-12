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
private:
    const static int attackInterval;
    const static int detectInterval;
    const static int scopeRadius;
};

#endif // BROWNTOWER_H
