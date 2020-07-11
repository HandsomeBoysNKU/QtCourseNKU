#include "BuildCannonButton.h"
#include "TowerCannon.h"
BuildCannonButton::BuildCannonButton(QWidget *parent) :
    BuildTowerButton(TowerCannon::cannonCost, parent)
{
    setIconFromFile(":/images/cf2_cannon1_size60.png");
}

void BuildCannonButton::launch()
{
    setTower(new TowerCannon(), centerPos());
}
