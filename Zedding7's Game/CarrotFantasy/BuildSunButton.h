#ifndef ICONTOWERSUN_H
#define ICONTOWERSUN_H

#include "BuildTowerButton.h"

class BuildSunButton : public BuildTowerButton {
    Q_OBJECT
public:
    BuildSunButton(QWidget* parent = nullptr);
public slots:
    virtual void launch();
};

#endif // ICONTOWERSUN_H
