#include "rectshape.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

RectShape::RectShape()
{

}

void RectShape::Show(QColor color)
{
    this->color = color;
    this->setPos(std::min(xs1,xs2), std::min(ys1,ys2));
}

void RectShape::startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    int x = event->scenePos().x();
    int y = event->scenePos().y();
    Set(x, y, x, y);
    scene->addItem(this);
    Show(Qt::blue);
}

void RectShape::drawRubberFootprint(QGraphicsSceneMouseEvent *event)
{
    int x1 = getXs1();
    int y1 = getYs1();
    int x2 = event->scenePos().x();
    int y2 = event->scenePos().y();
    Set(x1, y1, x2, y2);
    style = Qt::DashLine;
    Show(Qt::blue);
}

void RectShape::endDrawing()
{
    style = Qt::SolidLine;
    Show(Qt::black);
}

QRectF RectShape::boundingRect() const
{
    qreal adjust = 0.5;
    QPointF point1(0 - adjust - xSize() / 2, 0 - adjust - ySize() / 2);
    QPointF point2(xSize() / 2 + adjust, ySize() / 2 + adjust);
    return QRectF(point1, point2);
}

void RectShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    int x1,x2,y1,y2;

    if ((xs2 >xs1 ) && (ys2>ys1)){
        x1 = -xSize();
        y1 = -ySize();
        x2 = xSize() + xSize() / 2;
        y2 = ySize() + ySize() / 2;
    }
    if ((xs2 <= xs1 ) && (ys2>ys1)){
        x1 = 0;
        y1 = -ySize();
        x2 = xSize();
        y2 = ySize() + ySize() / 2;
    }
    if ((xs2 >xs1 ) && (ys2<=ys1)){
        x1 = -xSize();
        y1 = 0;
        x2 = xSize() + xSize() / 2;
        y2 = ySize();
    }
    if ((xs2 <=xs1 ) && (ys2<=ys1)){
        x1 = 0;
        y1 = 0;
        x2 = xSize();
        y2 = ySize();
    }

    QPointF point1(x1, y1);
    QPointF point2(x2, y2);

    if(color == Qt::blue){
        painter->setPen(QPen(color, 2, style));
    }
    else{
        painter->setPen(QPen(color, 2, style));
        painter->setBrush(Qt::white);
    }
    painter->drawRect(x1, y1, x2, y2);
}

QPainterPath RectShape::shape() const
{
    QPainterPath path;
    QPointF point1(0, 0);
    QPointF point2(xSize(), ySize());
    path.addRect(QRectF(point1, point2));
    return path;
}

int RectShape::xSize() const
{
    return abs(xs1 - xs2) * 2;
}

int RectShape::ySize() const
{
    return abs(ys1 - ys2) * 2;
}
