#include "cubeshape.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

CubeShape::CubeShape()
{

}

void CubeShape::startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    phaze = 0;
    LineShape::startDrawing(event, scene);
    scene->addItem(this);
    Show(Qt::red);
}

void CubeShape::drawRubberFootprint(QGraphicsSceneMouseEvent *event)
{
    LineShape::drawRubberFootprint(event);
    phaze = 1;
}

void CubeShape::endDrawing()
{
    LineShape::endDrawing();
    phaze = 2;
}

void CubeShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if(phaze == 0){
        painter->setPen(QPen(Qt::blue, 2));
        painter->drawRect(0, 0, xSize(), ySize());
    }
    if(phaze == 1){
        painter->setPen(QPen(color, 2, Qt::DashLine));
        painter->drawRect(0, 0, xSize(), ySize());

        x1 = 0;
        y1 = 0;
        x2 = xSize();
        y2 = ySize();
        painter->drawLine(x1, y1,  x1 + 50, y1 - 50);
        painter->drawLine(x1 + 50, y1 - 50, x2 + 50, y1 - 50);
        painter->drawLine(x2, y1, x2 + 50, y1 - 50);
        painter->drawLine(x2, y2, x2 + 50, y2 - 50);
        painter->drawLine(x2 + 50, y1 - 50, x2 + 50, y2 - 50);
        painter->drawLine(x1, y2, x1 + 50, y2 - 50);
        painter->drawLine(x1 + 50, y2 - 50, x2 + 50, y2 - 50);
        painter->drawLine(x1 + 50, y1 - 50, x1 + 50, y2 - 50);
    }

    if(phaze == 2){
        painter->setPen(QPen(color, 2, Qt::SolidLine));
        painter->drawRect(0, 0, xSize(), ySize());
        x1 = 0;
        y1 = 0;
        x2 = xSize();
        y2 = ySize();
        painter->drawLine(x1, y1,  x1 + 50, y1 - 50);
        painter->drawLine(x1 + 50, y1 - 50, x2 + 50, y1 - 50);
        painter->drawLine(x2, y1, x2 + 50, y1 - 50);
        painter->drawLine(x2, y2, x2 + 50, y2 - 50);
        painter->drawLine(x2 + 50, y1 - 50, x2 + 50, y2 - 50);
        painter->drawLine(x1, y2, x1 + 50, y2 - 50);
        painter->drawLine(x1 + 50, y2 - 50, x2 + 50, y2 - 50);
        painter->drawLine(x1 + 50, y1 - 50, x1 + 50, y2 - 50);

    }
}
