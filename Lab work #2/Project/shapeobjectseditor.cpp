#include "shapeobjectseditor.h"
#include "pointshape.h"
#include "lineshape.h"
#include "rectshape.h"
#include "elipseshape.h"

#include <QGraphicsSceneMouseEvent>


ShapeObjectsEditor::ShapeObjectsEditor()
{
}

void ShapeObjectsEditor::selectPoint()
{
    drawType = DrawType::POINT;
}

void ShapeObjectsEditor::selectLine()
{
    drawType = DrawType::LINE;
}

void ShapeObjectsEditor::selectRect()
{
    drawType = DrawType::RECT;
}

void ShapeObjectsEditor::selectElipse()
{
    drawType = DrawType::ELIPSE;
}


void ShapeObjectsEditor::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(size < capasity){
        currentShape = Shape::createShape(drawType);
        currentShape->startDrawing(event, this);
        objects[size] = currentShape;
        size++;
        //this->items()
    }
}

void ShapeObjectsEditor::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    currentShape->endDrawing();
    update();
}

void ShapeObjectsEditor::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    currentShape->drawOnMove(event);
    update();
}
