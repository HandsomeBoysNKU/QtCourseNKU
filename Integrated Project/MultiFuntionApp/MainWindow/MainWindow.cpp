#include "MainWindow.h"
#include <QGridLayout>
#include <QPushButton>
#include <QIcon>
#include <QSize>
#include <QPixmap>
#include <QLabel>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{

    setFixedSize(600, 600);
    setWindowTitle("Multifunction App");

    QPushButton *bt1 = new QPushButton(this);
    bt1->setFixedSize(200, 200);
    QIcon icon(QPixmap(":/images/buttonIcon1.png"));
    bt1->setIcon(icon);
    bt1->setIconSize(QSize(200, 200));
    QPushButton *bt2 = new QPushButton(this);
    bt2->setFixedSize(200, 200);
    icon = QIcon(QPixmap(":/images/buttonIcon2.png"));
    bt2->setIcon(icon);
    bt2->setIconSize(QSize(200, 200));
    QPushButton *bt3 = new QPushButton("3", this);
    bt3->setFixedSize(200, 200);

    QGridLayout *mainLayout = new QGridLayout(this);
    mainLayout->addWidget(bt1, 0, 0);
    mainLayout->addWidget(bt2, 0, 1);
    mainLayout->addWidget(bt3, 1, 0);

    QLabel *label1 = new QLabel("music player", this);
    label1->setGeometry(120, 280, label1->width(), label1->height());
    QLabel *label2 = new QLabel("carrot fantasy", this);
    label2->setGeometry(380, 280, label2->width() + 20, label2->height());

    connect(bt1, SIGNAL(clicked()), this, SLOT(on_button1_clicked()));
    connect(bt2, SIGNAL(clicked()), this, SLOT(on_button2_clicked()));
}

MainWindow::~MainWindow()
{
    if (player != nullptr) {
        delete player;
    }
    if (si != nullptr) {
        delete si;
    }
}

void MainWindow::on_button1_clicked()
{
    this->hide();
    player = new musicPlayer();
    connect(player, SIGNAL(closed()), this, SLOT(show()));
    player->show();
}

void MainWindow::on_button2_clicked()
{
    this->hide();
    si = new StartInterface();
    connect(si, SIGNAL(closed()), this, SLOT(show()));
    si->show();
}

