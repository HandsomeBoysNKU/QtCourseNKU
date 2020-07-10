#include "mygame.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyGame object1;
    object1.show();
    return a.exec(); // to prevent the widget to quit in a instance
}
