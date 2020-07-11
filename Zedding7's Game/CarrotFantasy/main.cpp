#include <QApplication>
#include "StartInterface.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StartInterface *si = new StartInterface();
    si->show();
    return a.exec();
}
