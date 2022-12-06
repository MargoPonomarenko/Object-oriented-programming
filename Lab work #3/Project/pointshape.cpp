#include "pointshape.h"

#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

PointShape::PointShape()
{

}

void PointShape::Show(QColor color)
{
    this->color = color;
    this->setPos(xs1, ys1);
}

void PointShape::startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene)
{
    this->scene = scene;
    int x = event->scenePos().x();  //initializing the x and y position of the cursor
    int y = event->scenePos().y();
    Set(x, y, x, y);
    scene->addItem(this);  //adding an object to the scene
    Show(Qt::blue);
}

void PointShape::drawRubberFootprint(QGraphicsSceneMouseEvent *event)
{
}

void PointShape::endDrawing()
{
}

QRectF PointShape::boundingRect() const  //виділенян на сцені прямокутної області для відображення фігури
{
    return QRectF(0,0,2,2);
}

void PointShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)  //метод малювання крапки
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    painter->setBrush(Qt::black);
    painter->setPen(Qt::NoPen);
    painter->drawEllipse(0,0,2,2);
}

QPainterPath PointShape::shape() const
{
    QPainterPath path;
    path.addRect(0,0,2,2);
    return path;
}
