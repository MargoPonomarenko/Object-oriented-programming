#include "linewithelipseshape.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

LineWithElipseShape::LineWithElipseShape(DrawType type): LineShape(type)
{

}

void LineWithElipseShape::startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    phaze = 0;
    LineShape::startDrawing(event, scene);
    scene->addItem(this);
    Show(Qt::red);

}

void LineWithElipseShape::drawRubberFootprint(QGraphicsSceneMouseEvent *event)
{
    LineShape::drawRubberFootprint(event);
    phaze = 1;
}

void LineWithElipseShape::endDrawing()
{
    LineShape::endDrawing();
    phaze = 2;
}

void LineWithElipseShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if(phaze == 0){
        painter->setPen(QPen(Qt::blue, 2));
        painter->drawEllipse(-5, -5,  10, 10);
    }
    if(phaze == 1){
        LineShape::paint(painter, option, widget);
        painter->setPen(QPen(color, 2, Qt::DashLine));
        painter->setBrush(Qt::white);
        painter->drawEllipse(x1 - 5, y1 - 5,  10,  10);
        painter->drawEllipse(x2 - 5, y2 - 5,  10,  10);
    }
    if(phaze == 2){
        LineShape::paint(painter, option, widget);
        painter->setPen(QPen(color, 2));
        painter->setBrush(Qt::white);
        painter->drawEllipse(x1 - 5, y1 - 5,  10,  10);
        painter->drawEllipse(x2 - 5, y2 - 5,  10,  10);
    }
}



