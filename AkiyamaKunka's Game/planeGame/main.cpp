#include "mygame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qDebug() << QT_VERSION_STR;
    MyGame object1;
    object1.show();
    return a.exec();
}
