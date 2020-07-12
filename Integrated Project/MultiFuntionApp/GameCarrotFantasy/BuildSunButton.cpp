#include "BuildSunButton.h"
#include "TowerSun.h"
BuildSunButton::BuildSunButton(QWidget *parent) :
    BuildTowerButton(TowerSun::sunCost, parent)
{
    setIconFromFile(":/images/cf2_sunflower1_size60.png");
}

void BuildSunButton::launch()
{
    setTower(new TowerSun(), centerPos());
}
