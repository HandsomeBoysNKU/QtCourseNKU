#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "../MusicPlayer/musicplayer.h"
#include "../GameCarrotFantasy/StartInterface.h"

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void on_button1_clicked();
    void on_button2_clicked();
protected:
    musicPlayer *player = nullptr; // Music Player
    StartInterface *si = nullptr; // Game Carrot Fantasy

};
#endif // MAINWINDOW_H
