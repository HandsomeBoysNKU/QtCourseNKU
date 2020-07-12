#include "GameManager.h"

GameManager::GameManager()
{
    newGame();
}

void GameManager::closeEvent(QCloseEvent *event)
{
    emit closed();
    QGraphicsWidget::closeEvent(event);
}

void GameManager::newGame()
{
    if (game != nullptr) {
        delete game;
    }
    game = new Game();
    connect(game, SIGNAL(restart()), this, SLOT(newGame()));
    connect(game, SIGNAL(closed()), this, SLOT(close()));
    game->show();
}
