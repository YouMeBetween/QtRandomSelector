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
    src/mainMenu.cpp

HEADERS += \
    inc/interfaceBase.h \
    inc/items.h \
    inc/mainMenu.h \
    mainwindow.h

FORMS += \
    mainwindow.ui \
    ui/mainMenu.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=

DISTFILES += \
    cfg/cfg.csv
