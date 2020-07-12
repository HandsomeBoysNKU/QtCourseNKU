#include "GameManager.h"

GameManager::GameManager()
{
    newGame();
}

void GameManager::newGame()
{
    if (game != nullptr) {
        delete game;
    }
    game = new Game();
    connect(game, SIGNAL(restart()), this, SLOT(newGame()));
    game->show();
}
