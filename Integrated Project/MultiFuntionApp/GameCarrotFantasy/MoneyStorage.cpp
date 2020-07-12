#include "MoneyStorage.h"
#include <QFont>
#include <QColor>

MoneyStorage::MoneyStorage(int v, QGraphicsItem *parent) :
    MyQGraphicsDigitItem(v, parent)
{
    if (money < 0) setValue(0);
    textOffset = QPointF(35, -15);
    setPixmap(QPixmap(":/images/cf2_moneyIcon_size50.png"));
    valueText->setFont(QFont("consolas", 12, 75));
    valueText->setDefaultTextColor(QColor(0xff, 0xcc, 0x22));
}

bool MoneyStorage::tryPay(int cost)
{
    if (cost <= money) {
        decrease(cost);
        return true;
    }
    return false;
}
