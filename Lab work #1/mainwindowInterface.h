#ifndef MAINWINDOWINTERFACE_H
#define MAINWINDOWINTERFACE_H
#include <QMainWindow>

class MainWindowInterface: public QMainWindow
{
public:
    MainWindowInterface(QWidget *parent = nullptr): QMainWindow(parent){}
    virtual void setValue(int value) = 0;
    virtual  ~MainWindowInterface(){};
};

#endif // MAINWINDOWINTERFACE_H
