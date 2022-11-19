QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    datamodel.cpp \
    main.cpp \
    mainwindow.cpp \
    module1.cpp \
    module1dialog.cpp \
    module2.cpp \
    module2dialog.cpp \
    module3.cpp \
    module3dialog.cpp

HEADERS += \
    datamodel.h \
    mainwindow.h \
    mainwindowInterface.h \
    module1.h \
    module1dialog.h \
    module2.h \
    module2dialog.h \
    module3.h \
    module3dialog.h

FORMS += \
    mainwindow.ui \
    module1dialog.ui \
    module2dialog.ui \
    module3dialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
