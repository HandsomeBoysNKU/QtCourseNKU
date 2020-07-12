#ifndef ICONTOWERCANNON_H
#define ICONTOWERCANNON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include "MyQGraphicsPixmapItem.h"
#include "TowerCannon.h"
#include "BuildTowerButton.h"

class BuildCannonButton: public BuildTowerButton
{
    Q_OBJECT
public:
    BuildCannonButton(QWidget* parent = nullptr);
public slots:
    virtual void launch();
};

#endif // ICONTOWERCANNON_H
