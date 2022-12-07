#ifndef SHAPEOBJECTSEDITOR_H
#define SHAPEOBJECTSEDITOR_H

#include <QGraphicsItem>

class ShapeObjectsEditor :public QGraphicsItem
{
public:
    ShapeObjectsEditor();

    virtual void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) = 0;
    virtual void drawOnMove(QGraphicsSceneMouseEvent *event) {}
    virtual void endDrawing() {}
};

#endif // SHAPEOBJECTSEDITOR_H
