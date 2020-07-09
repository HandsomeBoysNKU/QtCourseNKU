#include "mygame.h"
#include "ui_mygame.h"

MyGame::MyGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyGame)
{

    ui->setupUi(this);
    connect(ui->quitGame, &QPushButton::clicked, this,&MyGame::close);


    myPlane.initPos();

    background.initMapPos();


    initSence();
}

MyGame::~MyGame()
{
    delete ui;
}


void MyGame::paintEvent(QPaintEvent *){
    QPainter painter(this);

    painter.drawPixmap(0,background.showPosY(1),background.giveMap(1));
    painter.drawPixmap(0,background.showPosY(2),background.giveMap(2));

    qDebug() << "the x is " << myPlane.showPosX() << "and the Y is " << myPlane.showPosY();
    painter.drawPixmap(myPlane.showPosX(),myPlane.showPosY(), myPlane.givePlane());

    //qDebug()<<"the printer works";


}



void MyGame::initSence()
{
    setFixedSize(GAME_WID, GAME_LEN);

    setWindowTitle(GAME_TITEL);
    setWindowIcon(QIcon(PLANE_ICON));

    myPlane.giveSquare().setWidth(myPlane.givePlane().width());
    myPlane.giveSquare().setWidth(myPlane.givePlane().height());


    timer.setInterval(REFRESH_RATE);
    timer.start();

    connect(&timer, &QTimer::timeout,[=](){
        //qDebug()<<"the connect worked";
        myPlane.updatePos();
        background.mapPos();
        update();
    });

}


void MyGame::keyPressEvent(QKeyEvent *ev)
{
    int num = ev->key();
    myPlane.getKeyPressEvent( (Qt::Key)num);

    QWidget::keyPressEvent(ev);
}

void MyGame::keyReleaseEvent(QKeyEvent *ev)
{   int num = ev->key();
    myPlane.getKeyReleaseEvent( (Qt::Key)num);

    QWidget::keyReleaseEvent(ev);
}

