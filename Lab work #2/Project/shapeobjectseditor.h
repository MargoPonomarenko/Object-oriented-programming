#ifndef SHAPEOBJECTSEDITOR_H
#define SHAPEOBJECTSEDITOR_H
#include <QGraphicsScene>
#include "shape.h"

const int capasity = 129;

class ShapeObjectsEditor: public QGraphicsScene
{
public:
    ShapeObjectsEditor();

    void selectPoint();
    void selectLine();
    void selectRect();
    void selectElipse();

private:
    DrawType drawType = DrawType::POINT;
    bool drawStatus = false;
    Shape *currentShape;


    int size = 0;
    Shape *objects [capasity];  //масив вказівників на об'єкти типу Shape


    // QGraphicsScene interface
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif // SHAPEOBJECTSEDITOR_H
