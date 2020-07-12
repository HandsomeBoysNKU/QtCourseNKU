#ifndef CARROT_H
#define CARROT_H

#include "MyQGraphicsDigitItem.h"

class Carrot : public MyQGraphicsDigitItem {
    Q_OBJECT
public:
    Carrot(QGraphicsItem *parent = nullptr);
public slots:
    void decrease(int num = 1);
signals:
    void carrotIsDead();
private:
    int& health = value;
};

#endif // CARROT_H
