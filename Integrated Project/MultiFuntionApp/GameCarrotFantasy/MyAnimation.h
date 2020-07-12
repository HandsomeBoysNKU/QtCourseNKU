#ifndef MYANIMATION_H
#define MYANIMATION_H

#include "MyQGraphicsPixmapItem.h"
#include <QObject>
#include <QPixmap>
#include <QList>
#include <QTimer>

class MyAnimation :public QObject, public MyQGraphicsPixmapItem
{
    Q_OBJECT
public:
    MyAnimation(QString filename, int fnum, QGraphicsItem *parent = nullptr);
    void play();
    void setFPS(int fps);
    void setCyclic(bool iscyc);

protected slots:
    void updateFrame();
protected:
    QList<QPixmap> frames;
    QString filename;
    QTimer *playTimer;
    int frameNumber = 0;
    int currentFrameIndex = 0;
    int updateInterval;
    bool isCyclic = false;
};

#endif // MYANIMATION_H
