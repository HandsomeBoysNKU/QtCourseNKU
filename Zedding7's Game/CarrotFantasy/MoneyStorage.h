#ifndef MONEYICON_H
#define MONEYICON_H


#include "MyQGraphicsDigitItem.h"

class MoneyStorage : public MyQGraphicsDigitItem {
    Q_OBJECT
public:
    MoneyStorage(int v = 0, QGraphicsItem *parent = nullptr);
    bool tryPay(int cost);
private:
    int& money = value;
};

#endif // MONEYICON_H
