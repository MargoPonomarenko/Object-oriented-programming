#include "mainwindow.h"

#include <QApplication>
#include <QList>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QList<QString> list;
    for(int i=1; i<argc; i++){
        list.append(argv[i]);
    }
    MainWindow w(list);
    if(list.size() == 5){
        w.move(list.at(3).toInt() + list.at(4).toInt() + 10, 10);
    }
    w.show();
    return a.exec();
}
