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
   QStringList objectsRead;
   for (const auto &record: data){
       //StringList objectsRead = record.split("\t");
       objectsRead = record.split("\t");
       qDebug()<< objectsRead;
       if(size < capasity){
           currentShape = createShape(objectsRead.at(0));
           connect(currentShape, &Shape::shapeCreated, this, &MyEditor::onShapeCreated);
           int xp1 = objectsRead.at(1).toInt();
           int yp1 = objectsRead.at(2).toInt();
           int xp2 = objectsRead.at(3).toInt();
           int yp2 = objectsRead.at(4).toInt();

           currentShape->Set(xp1, yp1, xp2, yp2);
           addItem(currentShape);
           currentShape->Show(Qt::black);
           update();
           objects[size] = currentShape;
           size++;
       }
       //connect(currentShape, &Shape::shapeCreated, this, &MyEditor::onShapeCreated);
   }
}

const QVector<MyShapes::Shape *> MyEditor::getObjects()
{
    QVector<MyShapes::Shape *> objects;
    for(int i=0; i<size; i++){
        objects.append(this->objects[i]);
    }
    return objects;
}

MyEditor::MyEditor()
{
    initConverter();
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


Shape *MyEditor::createShape(QString strType)
{
    return Shape::createShape(shapeConvert[strType]);
}

void MyEditor::initConverter()
{
    shapeConvert["Point"] = DrawType::POINT;
    shapeConvert["Line"] = DrawType::LINE;
    shapeConvert["Rect"] = DrawType::RECT;
    shapeConvert["Elipse"] = DrawType::ELIPSE;
    shapeConvert["LineWithElipse"] = DrawType::LINEWITHELIPSE;
    shapeConvert["Cube"] = DrawType::CUBE;
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
