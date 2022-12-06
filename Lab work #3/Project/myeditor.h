#ifndef MYEDITOR_H
#define MYEDITOR_H
#include <QGraphicsScene>
#include "shape.h"

const int capasity = 129;

class MyEditor: public QGraphicsScene
{
public:
    MyEditor();

    void selectShape(DrawType shapeType);

private:
    DrawType drawType = DrawType::POINT;
    bool drawStatus = false;
    Shape *currentShape;

    int size = 0;
    Shape *objects [capasity];  //an array of pointers to Shape objects

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

};

#endif // MYEDITOR_H
