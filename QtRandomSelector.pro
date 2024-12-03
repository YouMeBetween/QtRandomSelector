QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    src/interfaceBase.cpp \
    src/items.cpp \
    src/jsonTool.cpp \
    src/mainMenu.cpp \
    src/resultShow.cpp \
    src/setting.cpp \
    src/switchButton.cpp

HEADERS += \
    inc/filePath.h \
    inc/interfaceBase.h \
    inc/items.h \
    inc/jsonTool.h \
    inc/mainMenu.h \
    inc/resultShow.h \
    inc/setting.h \
    inc/switchButton.h \
    mainwindow.h

FORMS += \
    mainwindow.ui \
    ui/mainMenu.ui \
    ui/resultShow.ui \
    ui/setting.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res/mainwindow.qrc

DISTFILES += \
    cfg/cfg.csv \
    cfg/setting.json

TRANSLATIONS += \
    res/trans/english.ts \
    res/trans/chinese.ts
