QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BuildCannonButton.cpp \
    BuildSunButton.cpp \
    BuildTowerButton.cpp \
    CannonBall.cpp \
    Carrot.cpp \
    Enemy.cpp \
    Game.cpp \
    GameManager.cpp \
    MoneyStorage.cpp \
    MyQGraphicsDigitItem.cpp \
    MyQGraphicsPixmapItem.cpp \
    Road.cpp \
    StartInterface.cpp \
    Tower.cpp \
    TowerCannon.cpp \
    TowerSun.cpp \
    main.cpp

HEADERS += \
    BuildCannonButton.h \
    BuildSunButton.h \
    BuildTowerButton.h \
    CannonBall.h \
    Carrot.h \
    Enemy.h \
    Game.h \
    GameManager.h \
    MoneyStorage.h \
    MyQGraphicsDigitItem.h \
    MyQGraphicsPixmapItem.h \
    Road.h \
    StartInterface.h \
    Tower.h \
    TowerCannon.h \
    TowerSun.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
