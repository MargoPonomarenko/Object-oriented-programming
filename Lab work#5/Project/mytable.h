#ifndef MYTABLE_H
#define MYTABLE_H

#include <QTableWidget>
#include <QWidget>
#include "drawtype.h"

class MyTable:public QObject
{
    Q_OBJECT
public:
     MyTable(QWidget *parent);
    ~MyTable();
    void onShapeCreated(DrawType type, int x1, int y1, int x2, int y2);

    QTableWidget *getTable() const;
    void clearFile();

private:
     QStringList columnLabels = {"Назва", "x1", "y1", "x2", "y2"};
     QTableWidget *table;
     void saveRow(QString shapeType, int x1, int y1, int x2, int y2);
    QMenu *contextMenu;

signals:
     void objectSelected(int index);

private slots:
    void onCellClicked(int row, int col);
    void onContextMenu(const QPoint &position);


};

#endif // MYTABLE_H
