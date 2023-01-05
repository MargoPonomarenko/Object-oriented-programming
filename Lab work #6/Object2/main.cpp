#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.move(w.width() * 2 + 50, 10);
    w.show();
    return a.exec();
}
