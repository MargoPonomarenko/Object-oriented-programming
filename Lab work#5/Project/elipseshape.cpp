#include "elipseshape.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

ElipseShape::ElipseShape(DrawType type): Shape(type)
{

}

void ElipseShape::Show(QColor color)
{
    this->color = color;
    this->setPos(std::min(xs1,xs2), std::min(ys1,ys2));
}

void ElipseShape::startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    int x = event->scenePos().x();  //ініціалізація позиції x та y курсора
    int y = event->scenePos().y();
    Set(x, y, x, y);
    scene->addItem(this);
    Show(Qt::blue);
}

void ElipseShape::drawRubberFootprint(QGraphicsSceneMouseEvent *event)
{
    int x1 = getXs1();
    int y1 = getYs1();
    int x2 = event->scenePos().x();
    int y2 = event->scenePos().y();
    Set(x1, y1, x2, y2);
    style = Qt::DashLine;
    Show(Qt::blue);

}

void ElipseShape::endDrawing()
{
    style = Qt::SolidLine;
    Show(Qt::black);
    Shape::endDrawing();
}

QRectF ElipseShape::boundingRect() const
{
    qreal adjust = 0.5;
    QPointF point1(0 - adjust, 0 - adjust);
    QPointF point2(xSize() + adjust, ySize() + adjust);
    qDebug()<<"Bounding rect"<<xSize()<<"; "<<ySize();
    return QRectF(point1, point2);
}

void ElipseShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    qDebug()<<"Paint Elipse"<< xs1<<"; "<<ys1<<"; "<<xs2<<"; "<<ys2;
    int x1,x2,y1,y2;

    x1 = 0;
    y1 = 0;
    x2 = xSize();
    y2 = ySize();

    QPointF point1(x1, y1);
    QPointF point2(x2, y2);

    painter->setPen(QPen(color, 2, style));
    painter->drawEllipse(x1, y1, xSize(), ySize());
}

QPainterPath ElipseShape::shape() const
{
    QPainterPath path;
    QPointF point1(0, 0);
    QPointF point2(xSize(), ySize());
    path.addRect(QRectF(point1, point2));
    return path;
}

int ElipseShape::xSize() const
{
    return abs(xs1 - xs2);
}

int ElipseShape::ySize() const
{
    return abs(ys1 - ys2);
}
