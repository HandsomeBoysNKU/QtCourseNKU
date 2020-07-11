#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

#include <QGraphicsView>
#include <QPushButton>
class StartInterface : public QGraphicsView {
    Q_OBJECT
public:
    StartInterface();
public slots:
    void startGame();
protected:
    QGraphicsScene *scene;
    QPushButton *startButton;
};

#endif // STARTINTERFACE_H
