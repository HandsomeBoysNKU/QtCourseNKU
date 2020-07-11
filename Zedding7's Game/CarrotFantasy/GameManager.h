#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsWidget>
#include "Game.h"
class GameManager : public QGraphicsWidget
{
    Q_OBJECT
public:
    GameManager();
public slots:
    void newGame();
protected:
    Game *game = nullptr;
};

#endif // GAMEMANAGER_H
