QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cubeshape.cpp \
    elipseshape.cpp \
    lineshape.cpp \
    linewithelipseshape.cpp \
    main.cpp \
    mainwindow.cpp \
    myeditor.cpp \
    myeditorview.cpp \
    mytable.cpp \
    pointshape.cpp \
    rectshape.cpp \
    scenewindow.cpp \
    shape.cpp \
    toolbar.cpp

HEADERS += \
    cubeshape.h \
    drawtype.h \
    elipseshape.h \
    lineshape.h \
    linewithelipseshape.h \
    mainwindow.h \
    myeditor.h \
    myeditorview.h \
    mytable.h \
    pointshape.h \
    rectshape.h \
    scenewindow.h \
    shape.h \
    toolbar.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
