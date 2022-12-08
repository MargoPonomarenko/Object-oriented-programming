#include "myeditor.h"
#include "shape.h"

#include <QGraphicsSceneMouseEvent>


MyEditor &MyEditor::getInstance()
{
    static MyEditor instance;
    return instance;
}

void MyEditor::selectShape(DrawType shapeType)
{
    drawType = shapeType;
}

void MyEditor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(size < capasity){
        currentShape = Shape::createShape(drawType);
        connect(currentShape, &Shape::shapeCreated, this, &MyEditor::onShapeCreated);
        currentShape->startDrawing(event, this);
        objects[size] = currentShape;
        size++;
        //this->items()
    }
}

void MyEditor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    currentShape->endDrawing();
    update();
}

void MyEditor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    currentShape->drawRubberFootprint(event);
    update();
}

void MyEditor::onShapeCreated(DrawType type, int x1, int y1, int x2, int y2)
{
    qDebug()<<"MyEditor xs1: "<<x1;
    emit shapeCreated(type, x1, y1, x2, y2);
}
