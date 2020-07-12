#include "mygame.h"
#include "ui_mygame.h"

MyGame::MyGame(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MyGame)
{

    ui->setupUi(this);

    bulletRecord = 0;
    enemyRecord = 0;
    cntBullet = 0;
    score = 0;
    life = PLANE_LIFE; // here is to set the HP of a plane
    bulletRecordRate = BULLET_REFRESH_RATE;
    enemyInverval = ENEMY_INTERVAL;

    myPlane.initPos(); // init the plane, the maps and the main sence
    background.initMapPos();
    initSence();
}

MyGame::~MyGame()
{
    delete ui;
}

void MyGame::paintEvent(QPaintEvent *){

    QPainter painter(this); // this is the painter to draw all the element on the board
    painter.drawPixmap(0,background.showPosY(1),background.giveMap(1)); // to draw the tow maps
    painter.drawPixmap(0,background.showPosY(2),background.giveMap(2));
    painter.drawPixmap(myPlane.showPosX(),myPlane.showPosY(), myPlane.givePlane()); // to draw the plane

    for (int i = 0; i < BULLET_NUM; ++i) { // to draw the bullet. We must iterate the whole array to make sure we've checked all states of activation
        if(!myBullet[i].isFree())
            painter.drawPixmap(myBullet[i].givePosX(),myBullet[i].givePosY(),Bullet::giveImage());

    }

    for(int i = 0 ; i< ENEMY_NUM; ++i){ // to draw the enemies. We must iterate the whole array to make sure we've checked all states of activation
        if(!myEnemy[i].isFree())
            painter.drawPixmap(myEnemy[i].showPosX(), myEnemy[i].showPosY(), myEnemy[i].giveImage());
    }

    for(int i = 0 ; i< BOMB_NUM; ++i){ // to draw the bomb effect. More specificlly, we realize an animation by playing a couple of pictures in order
        if(!myBomb[i].isFree()){
            painter.drawPixmap( myBomb[i].showPosX(), myBomb[i].showPosY(), myBomb[i].giveImage(myBomb[i].getIndex() ) ); // remember to get the index by calling the built-in function
        }
    }
}

void MyGame::initSence()
{
    srand((unsigned int)time(NULL)); // to initialize the ramdom number generator by passing the time on user's computer as parameter

    setFixedSize(GAME_WID, GAME_LEN); // set the info for basic widget
    setWindowTitle(GAME_TITEL);
    setWindowIcon(QIcon(PLANE_ICON));

    myPlane.giveSquare().setWidth(myPlane.givePlane().width()); // set the square of plane to detect collapse
    myPlane.giveSquare().setWidth(myPlane.givePlane().height());

    timer.setInterval(REFRESH_RATE); // set the timer to refresh the widget
    timer.start();

    connect(&timer, &QTimer::timeout,[=](){ // the connect fucntion to update the elements

        updateLevel();

        if(life < 0){ // HP = 0, game is over.
            QMessageBox::information(NULL, "Notice", "GameOver", QMessageBox::Retry); // to tell the user the game is over by a message box
            life = PLANE_LIFE; // reset the parameters to restart the game
            score = 0;
        }

        for (int i = 0; i < BOMB_NUM; ++i) { // the update the infomation of bomb
            if(!myBomb[i].isFree())
                myBomb[i].updateInfo();
        }

        QPalette pe;
        pe.setColor(QPalette::WindowText,Qt::white);
        ui->label_2->setPalette(pe);
        ui->label->setPalette(pe);

        QString temp;
        temp += QString("Score:%1").arg(score); // to set the score infomation of the label
        if(life > 0)
            ui->label->setText(temp);

        QString temp2;
        temp2 +=QString("Life:%1").arg(life); // to set the life infomation of the label
        if(life > 0)
            ui->label_2->setText(temp2);


        ifCollapsed(); // to check if objects are collapsed

        setEnemy(); // set the enemy on the screen

        bulletRecord++; // make the record to ensure the bullet can be refresh in a specific rate

        if( bulletRecord % bulletRecordRate == 0){ // I did this division to ensure the bullet can be refreshed in a rate
            myBullet[cntBullet].setFree(); // however, this is not smart enough, another way to realize bomb or enemy are smarter and lighter
            setBullet(cntBullet);
            cntBullet++;
        }

        myPlane.updatePos(); // update the plane and map
        background.mapPos();

        for(int i = 0 ; i< ENEMY_NUM; ++i){ // to update enemy postion
            if(!myEnemy[i].isFree()) // ensure we only change the info of a active enemy
                myEnemy[i].updatePos();
        }

        for (int i = 0; i < BULLET_NUM; ++i) { // to update bullet postion
            if(!myBullet[i].isFree()) // ensure we only change the info of a active bullet
                myBullet[i].updatePos();
        }

        if(life > 0) // if the life is minus, the whole screen would not be update, it seems like the game is stoped, but still running in fact
            update();
    });
}

void MyGame::setBullet(int i){ // set the bullet on the screen
    myBullet[i].setPos(myPlane.showPosX() + myPlane.givePlane().width() / 2
                       - myBullet->giveRect().width() / 2,
                       myPlane.showPosY() - myBullet->giveRect().height() / 2);
}

void MyGame::setEnemy()
{
    enemyRecord++;

    if(enemyRecord < enemyInverval) // it means if you have not reach the interval number, the enemy will not be update a new one
        return;

    enemyRecord = 0; // here you've reach the threshold to generate a new enemy, so the ememyRecord is 0 again for the next loop

    for (int i = 0; i < ENEMY_NUM; ++i) {
        if(myEnemy[i].isFree()){ // check the activation state
            myEnemy[i].setFree(); // make it anti-active
            myEnemy[i].setPos(rand() % (GAME_WID - myEnemy[i].giveRect().width()), 0); // set the postion
            break;
        }
    }
}

void MyGame::ifCollapsed()
{
    for (int i = 0; i < ENEMY_NUM; ++i){

        if(myEnemy[i].isFree()) // not active, so continue
            continue;

        for (int j = 0; j < BULLET_NUM; ++j) {
            if(myBullet[j].isFree()) // not active, so continue
                continue;

            if(myEnemy[i].giveRect().intersects(myBullet[j].giveRect())  ){ //  "intersects" is a function to detect if two QRect object are collapsed
                myEnemy[i].setFree();
                myBullet[j].setFree();

                score += 10; // plus the score of shooting down an enemy
                for (int k  = 0; k < BOMB_NUM; ++k) { // to set the bomb effect
                    if(myBomb[k].isFree()){
                        myBomb[k].setFree();
                        myBomb[k].setPos(myEnemy[i].showPosX(), myEnemy[i].showPosY());
                    }
                }
            }
        }


        if(myPlane.giveSquare().intersects(myEnemy[i].giveRect()) && !myEnemy[i].isFree()) {// "intersects" is a function to detect if two QRect object are collapsed
            for (int k  = 0; k < BOMB_NUM; ++k) { // to set the bomb effect
                if(myBomb[k].isFree()){
                    myBomb[k].setFree();
                    myBomb[k].setPos(myEnemy[i].showPosX(), myEnemy[i].showPosY());
                }
            }
            life -= 2; // collapsed with enemy, so life minus 1

        }
    }
}

void MyGame::updateLevel()
{
    static bool isMapLevel1 = false; // this is the function to update the difficulty
    static bool isMapLevel2 = false;
    static bool isPlaneLevel1 = false;
    static bool isBulletLevel1 = false;
    static bool isBulletLevel2 = false;

    if( score > Level_1_SCORE && !isMapLevel1){ // update map
        background.Level1();
        Enemy::level1();
        enemyInverval = ENEMY_INTERVAL * 0.5;
        isMapLevel1 = true;
    }
    if( score > Level_2_SCORE && isMapLevel1 && !isMapLevel2){ // update map
        background.Level2();
        Enemy::level2();
        enemyInverval = ENEMY_INTERVAL * 0.3;
        isMapLevel2 = true;
    }
    if( score > Level_1_PLANE_SCORE && !isPlaneLevel1){ // update plane iamge
        myPlane.level1();
        isPlaneLevel1 = true;
    }
    if( score > Level_1_BULLET_SCORE && !isBulletLevel1){ // update your bullets
        Bullet::level1();
        bulletRecordRate = BULLET_REFRESH_RATE * 0.5;
        isBulletLevel1 = true;
    }
    if( score > Level_2_BULLET_SCORE && isBulletLevel1 && !isBulletLevel2){ // update your bullets
        Bullet::level2();
        bulletRecordRate = BULLET_REFRESH_RATE * 0.2;
        isBulletLevel2 = true;
    }
}

void MyGame::keyPressEvent(QKeyEvent *ev)  // to detect keyPressed
{
    int num = ev->key();
    myPlane.getKeyPressEvent( (Qt::Key)num); // to pass the Qt::Key type to plane, but we converted it to a int.
    QWidget::keyPressEvent(ev);
}

void MyGame::keyReleaseEvent(QKeyEvent *ev) // to detect keyReleased
{
    int num = ev->key();
    myPlane.getKeyReleaseEvent( (Qt::Key)num); // to pass the Qt::Key type to plane, but we converted it to a int.
    QWidget::keyReleaseEvent(ev);
}

