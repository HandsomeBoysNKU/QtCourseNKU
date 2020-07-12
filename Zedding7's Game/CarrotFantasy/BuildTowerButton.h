#ifndef BUILDTOWERBUTTON_H
#define BUILDTOWERBUTTON_H

#include <QPushButton>
#include <QPixmap>
#include <QPointF>
#include <QGraphicsTextItem>
#include <QLabel>
#include "Tower.h"
class BuildTowerButton :public QPushButton
{
    Q_OBJECT
public:
    BuildTowerButton(int price = 0, QWidget *parent = nullptr);
    void setPos(int ax, int ay);
signals:
    void testLaunch(int i);
    void setTower(Tower *tower, QPointF pos);
public slots:
    virtual void launch();
protected:
    void setIconFromFile(QString filename);
    QPointF centerPos();

    QLabel *costLabel = nullptr;
    int cost;
    int length;
};

#endif // BUILDTOWERBUTTON_H
