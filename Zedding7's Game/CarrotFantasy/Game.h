#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsPixmapItem>
#include <QPushButton>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "Tower.h"
#include "MyQGraphicsPixmapItem.h"
#include "Carrot.h"
#include "Road.h"
#include "BuildCannonButton.h"
#include "BuildSunButton.h"
#include "MoneyStorage.h"

class Game: public QGraphicsView
{
    Q_OBJECT
public:
    ~Game();
    Game();
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);

    QGraphicsScene *scene;

signals:
    void restart();

public slots:
    void getTower(Tower *pt, QPointF pos);

protected slots:
    void spawnEnemy();
    void gameover();
    void startSpawn();
    void emitRestart();

protected:
    void tryBuildTower(const QPointF& pos);
    void createCarrot();
    void createBuildButtons();
    void createEnemies();
    void creaetRoad();
    void InitMoney(int v);
    void addRoad(int ax, int ay);
    void createControlButtons();

    Tower *building = nullptr;
    BuildTowerButton *buildCannonButton = nullptr;
    BuildSunButton *buildSunButton = nullptr;
    QTimer *spawnTimer = nullptr;
    QTimer *spawnInterval = nullptr;
    Carrot *carrot = nullptr;
    QPushButton *restartButton = nullptr;
    QPushButton *closeButton = nullptr;
    MoneyStorage *storage = nullptr;
    QList<QPointF> gridRoadPoints;
    QList<QPointF> roadCenterPoints;
    QList<Road *> roads;
    QList<QString> waveList;
    QList<int> enemyNumber;
    int currentWave = 0;
    int maxWave = 0;
    int enemyCounter = 0;
    int maxNumberOfEnemies = 0;
    int availableGrids[12][9] = {};
    int money = 0;
};

#endif // GAME_H
