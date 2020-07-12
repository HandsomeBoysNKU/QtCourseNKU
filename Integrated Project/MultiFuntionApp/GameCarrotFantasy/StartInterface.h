#ifndef STARTINTERFACE_H
#define STARTINTERFACE_H

#include <QGraphicsView>
#include <QPushButton>
#include <QCloseEvent>
class StartInterface : public QGraphicsView {
    Q_OBJECT
public:
    StartInterface();

public slots:
    void startGame();
    void closeEvent(QCloseEvent *event);
signals:
    void closed();
protected:
    QGraphicsScene *scene;
    QPushButton *startButton;
};

#endif // STARTINTERFACE_H
