#include "myeditor.h"
#include "shape.h"

#include <QGraphicsSceneMouseEvent>

MyEditor::MyEditor()
{

}

void MyEditor::selectShape(DrawType shapeType)
{
    drawType = shapeType;
}

void MyEditor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(size < capasity){
        currentShape = Shape::createShape(drawType);
        currentShape->startDrawing(event, this);
        objects[size] = currentShape;
        size++;
        //this->items() as an additional option
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
