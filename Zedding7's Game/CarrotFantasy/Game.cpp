#include "Game.h"
#include <QGraphicsScene>
#include <QTimer>
#include <QGraphicsLineItem>
#include <QPen>
#include <QBrush>
#include <QBitmap>
#include <QDebug>
#include "TowerCannon.h"
#include "CannonBall.h"
#include "Enemy.h"
#include "EnemyOrange.h"
#include "EnemyBlue.h"
#include "TowerSun.h"
#include "Carrot.h"


Game::~Game()
{
    if (building != nullptr) delete building;
    delete spawnTimer;
    delete carrot;
    delete storage;
}

Game::Game():
    QGraphicsView()
{
    // create a scene
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1200, 900);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage(":/images/greenscreen1.png")));
    // set curosr
    building = nullptr;
    setMouseTracking(true);
    // alter window
    setFixedSize(1200, 900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    spawnTimer = new QTimer(this);

    creaetRoad();
    createBuildButtons();
    createCarrot();
    createEnemies();
    createControlButtons();
    InitMoney(1000);
}

void Game::mouseMoveEvent(QMouseEvent *event) {
    if (building != nullptr){
        building->setPos(event->pos() - building->selfCenter());
    }
}

void Game::mousePressEvent(QMouseEvent *event) {
    if (building != nullptr){
        tryBuildTower(event->pos());
    }
    else {
        QGraphicsView::mousePressEvent(event);
    }

}

void Game::createEnemies() {
    spawnTimer = new QTimer(this);
    spawnInterval = new QTimer(this);
    waveList << Enemy::orange << Enemy::blue << Enemy::orange << Enemy::blue;
    enemyNumber << 5 << 5 << 8 << 8;
    maxWave = waveList.size();
    currentWave = 0;
    enemyCounter = enemyNumber.at(currentWave);
    connect(spawnInterval, SIGNAL(timeout()), this, SLOT(startSpawn()));
    connect(spawnTimer, SIGNAL(timeout()), this, SLOT(spawnEnemy()));
    spawnInterval->start(5000);
}

void Game::spawnEnemy() {
    // spawn an enemy
    Enemy * enemy = nullptr;
    switch(waveList[currentWave]) {
    case Enemy::orange:
        enemy = new EnemyOrange(roadCenterPoints);
        break;
    case Enemy::blue:
        enemy = new EnemyBlue(roadCenterPoints);
        break;
    default:
        break;
    }

    connect(enemy, SIGNAL(reachEnd()), carrot, SLOT(decrease()));
    scene->addItem(enemy);
    --enemyCounter;

    if (enemyCounter <= 0) {
        spawnTimer->stop();
        ++currentWave;
        if (currentWave < maxWave) {
            enemyCounter = enemyNumber.at(currentWave);
            spawnInterval->start(10000);
        }
    }
}

void Game::gameover()
{
    restartButton->show();
    closeButton->show();
}

void Game::startSpawn()
{
    spawnInterval->stop();
    spawnTimer->start(300);
}

void Game::getTower(Tower *pt, QPointF pos)
{
    if (building != nullptr && building != pt) {
        delete building;
        building = nullptr;
    }
    building = pt;
    scene->addItem(building);
    building->setPos(pos - building->selfCenter());
}

void Game::emitRestart()
{
    restart();
}

void Game::tryBuildTower(const QPointF &pos)
{
    int gx = pos.x()/100;
    int gy = pos.y()/100;
    int ax = gx*100;
    int ay = gy*100;
    if (availableGrids[gx][gy] == 0 && building != nullptr && storage->tryPay(building->cost())) {
        building->activate();
        building->setPos(QPointF(ax + 50, ay + 50) - building->selfCenter());
        availableGrids[gx][gy] = 1;
        building = nullptr;
    }
    else {
        scene->removeItem(building);
        delete building;
        building = nullptr;
    }
}

void Game::createCarrot()
{
    carrot = new Carrot();
    carrot->setPos(1000, 800);
    scene->addItem(carrot);
    connect(carrot, SIGNAL(carrotIsDead()), this, SLOT(gameover()));
}

void Game::createBuildButtons()
{
    buildCannonButton = new BuildCannonButton(this);
    buildCannonButton->setPos(20, 40);
    connect(buildCannonButton, SIGNAL(setTower(Tower *, QPointF)), this, SLOT(getTower(Tower *, QPointF)));

    buildSunButton = new BuildSunButton(this);
    buildSunButton->setPos(20, 110);
    connect(buildSunButton, SIGNAL(setTower(Tower *, QPointF)), this, SLOT(getTower(Tower *, QPointF)));
}

void Game::creaetRoad(){
    gridRoadPoints << QPointF(0, 7) << QPointF(1, 7) << QPointF(1, 2) <<QPointF(4, 2)
                   << QPointF(4, 7) << QPointF(7, 7) << QPointF(7, 2) << QPointF(10, 2) << QPointF(10, 7);
    int n = gridRoadPoints.size();
    for (int i = 0; i < n - 1; i++) {
        QLineF cline(gridRoadPoints[i], gridRoadPoints[i+1]);
        if (cline.dy() == 0) {
            int ay = cline.y1();
            if (cline.dx() > 0) {
                for (int ax = cline.x1(); ax <= cline.x2(); ++ax) {
                    addRoad(ax, ay);
                }
            }
            else {
                for (int ax = cline.x1(); ax >= cline.x2(); --ax) {
                    addRoad(ax, ay);
                }
            }
        }
        else if (cline.dx() == 0){
            int ax = cline.x1();
            if (cline.dy() > 0) {
                for (int ay = cline.y1(); ay <= cline.y2(); ++ay) {
                    addRoad(ax, ay);
                }
            }
            else {
                for (int ay = cline.y1(); ay >= cline.y2(); --ay) {
                    addRoad(ax, ay);
                }
            }
        }

    }
    for (int i = 0; i < n; i++) {
        roadCenterPoints << gridRoadPoints[i]*100 + QPointF(50, 50);
    }
}

void Game::InitMoney(int v)
{
    storage = new MoneyStorage(v);
    storage->setPos(200, 20);
    scene->addItem(storage);
}

void Game::addRoad(int ax, int ay)
{
    if (availableGrids[ax][ay] != 0) return;
    Road *pRoad = new Road();
    pRoad->setPos(ax*100, ay*100);
    scene->addItem(pRoad);
    roads << pRoad;
    pRoad = nullptr;
    availableGrids[ax][ay] = 1;
}

void Game::createControlButtons()
{

    QPixmap pic(":/images/buttonIcon_restart.png");
    QIcon icon(pic);
    int w = pic.width();
    int h = pic.height();
    restartButton = new QPushButton(this);
    restartButton->setGeometry(200, 400, w, h);
    restartButton->setIcon(icon);
    restartButton->setIconSize(QSize(w, h));
    restartButton->setMask(QBitmap(pic.mask()));
    restartButton->setStyleSheet("QPushButton{border-image: url(:/images/buttonIcon_restart.png);}");
    connect(restartButton, SIGNAL(clicked()), this, SLOT(emitRestart()));
    restartButton->hide();

    pic = QPixmap(":/images/buttonIcon_close.png");
    icon = QIcon(pic);
    w = pic.width();
    h = pic.height();
    closeButton = new QPushButton(this);
    closeButton->setGeometry(700, 400, w, h);
    closeButton->setIcon(icon);
    closeButton->setIconSize(QSize(w, h));
    restartButton->setMask(QBitmap(pic.mask()));
    closeButton->setStyleSheet("QPushButton{border-image: url(:/images/buttonIcon_close.png);}");
    connect(closeButton, SIGNAL(clicked()), this, SLOT(close()));
    closeButton->hide();
}
