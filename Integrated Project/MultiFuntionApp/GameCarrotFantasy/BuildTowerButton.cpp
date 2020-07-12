#include "BuildTowerButton.h"
#include "TowerCannon.h"
#include <QFont>

BuildTowerButton::BuildTowerButton(int price, QWidget *parent) :
    QPushButton(parent),
    length(60)
{
    cost = price;
    costLabel = new QLabel(parent);
    costLabel->setText(QString::number(cost));
    costLabel->setFont(QFont("consolas", 12, 100));
    costLabel->setStyleSheet("color: #bbbbbb;");
    connect(this, SIGNAL(clicked()), this, SLOT(launch()));
}

void BuildTowerButton::setPos(int ax, int ay)
{
    setGeometry(ax, ay, length, length);
    costLabel->setGeometry(ax + 70, ay + 10, costLabel->width(), costLabel->height());
}

void BuildTowerButton::launch()
{
    setTower(new TowerCannon(), centerPos());
}

void BuildTowerButton::setIconFromFile(QString filename)
{
    QPixmap pic(filename);
    QIcon icon(pic);
    int w = pic.width();
    int h = pic.height();
    setGeometry(0, 0, length, length);
    setIcon(icon);
    setIconSize(QSize(w, h));
}

QPointF BuildTowerButton::centerPos()
{
    return pos() + QPointF(length/2, length/2);
}
