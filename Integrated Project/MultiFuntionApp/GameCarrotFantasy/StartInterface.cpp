#include "StartInterface.h"
#include <QPixmap>
#include "GameManager.h"

StartInterface::StartInterface()
{
    scene = new QGraphicsScene(this);
    scene->setSceneRect(0, 0, 1200, 900);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage(":/images/cf2_startInterface1_w4h3.png")));
    setFixedSize(1200, 900);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    startButton = new QPushButton(this);
    QPixmap pic(":/images/cf2_startButton1.png");
    QIcon icon(pic);
    int w = pic.width();
    int h = pic.height();
    startButton->setGeometry(450, 358, w, h);
    startButton->setIcon(icon);
    startButton->setIconSize(QSize(w, h));
    startButton->setFlat(true);
    connect(startButton, SIGNAL(clicked()), this, SLOT(startGame()));
}
void StartInterface::startGame()
{
    GameManager *gameManager = new GameManager();
    connect (gameManager, SIGNAL(closed()), this, SLOT(show()));
    this->hide();
}

void StartInterface::closeEvent(QCloseEvent *event)
{
    emit closed();
    QGraphicsView::closeEvent(event);
}
