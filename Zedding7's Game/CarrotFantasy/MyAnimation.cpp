#include "MyAnimation.h"

MyAnimation::MyAnimation(QString fname, int fnum, QGraphicsItem *parent) :
    MyQGraphicsPixmapItem(parent)
{
    filename = fname;
    frameNumber = fnum;
    for (int i = 0; i < frameNumber; ++i){
        frames<<QPixmap(filename.arg(i));
    }
    setPixmap(frames[0]);
    currentFrameIndex = 0;
    updateInterval = 1000;
    playTimer = new QTimer(this);
    connect(playTimer, SIGNAL(timeout()), this, SLOT(updateFrame()));
}

void MyAnimation::play()
{
    playTimer->start(updateInterval);
}

void MyAnimation::setFPS(int fps)
{
    if (fps > 0) {
        updateInterval = 1000/fps;
    }
}

void MyAnimation::setCyclic(bool iscyc)
{
    isCyclic = iscyc;
}

void MyAnimation::updateFrame()
{
    setPixmap(frames[currentFrameIndex]);
    ++currentFrameIndex;
    if (currentFrameIndex >= frameNumber) {
        currentFrameIndex = 0;
        if (isCyclic == false) {
            playTimer->stop();
        }
    }
}
