#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <QGraphicsWidget>
#include <QCloseEvent>
#include "Game.h"
class GameManager : public QGraphicsWidget
{
    Q_OBJECT
public:
    GameManager();
    void closeEvent(QCloseEvent *event);
public slots:
    void newGame();
signals:
    void closed();
protected:
    Game *game = nullptr;
};

#endif // GAMEMANAGER_H
