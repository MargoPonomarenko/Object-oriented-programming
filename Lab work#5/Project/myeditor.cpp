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

void MyEditor::onObjectSelected(int index)
{
    objects[index]->selectShape();
    qDebug()<<"Objects select color: "<<objects[index]->color;
    for(int i = 0; i < size; i++){
        if(i !=index ){
            objects[i]->unselectShape();
            qDebug()<<"Objects unselect color: "<<objects[i]->color;
        }
    }
    update();
}

void MyEditor::onObjectDelete(int row)
{
    deleteObject(row);
}

void MyEditor::drawFromFile(const QVector<QString> &data)
{
   qDebug()<<"Draw from file editor";

   for (const auto &record: data){
       QStringList objects = record.split("\t");
       qDebug()<<objects;
   }
}

void MyEditor::deleteObject(int index)
{
    qDebug()<<"Object deleted";
    this->removeItem(objects[index]);
    delete objects[index];
    for(int i = index; i < size - 1; i++){
        objects[i] = objects[i + 1];
    }
    size--;
    update();
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
