QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Battlable.cpp \
    BattleHandler.cpp \
    DataHandler.cpp \
    Enemy.cpp \
    GameState.cpp \
    InputHandler.cpp \
    Item.cpp \
    Observer.cpp \
    Player.cpp \
    Potion.cpp \
    Room.cpp \
    Runnable.cpp \
    Stage.cpp \
    Subject.cpp \
    Weapon.cpp \
    box.cpp \
    jsonloadexception.cpp \
    main.cpp \
    mainwindow.cpp \
    uicontroller.cpp \
    utils.cpp

HEADERS += \
    Battlable.h \
    BattleHandler.h \
    DataHandler.h \
    Enemy.h \
    GameState.h \
    InputHandler.h \
    Item.h \
    Observer.h \
    Player.h \
    Potion.h \
    Room.h \
    Runnable.h \
    Stage.h \
    Subject.h \
    Weapon.h \
    box.h \
    json.hpp \
    jsonloadexception.h \
    mainwindow.h \
    showInventoryAbstract.h \
    uicontroller.h \
    utils.h

FORMS += \
    mainwindow.ui

RESOURCES += \
    myresources.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/Zorko2.app/Contents/Info.plist \
    build/Desktop_arm_darwin_generic_mach_o_64bit-Debug/Zorko2.app/Contents/PkgInfo \
    copy_files.sh \
    enemies.json \
    items.json \
    rooms.json
