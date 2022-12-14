#include "lineshape.h"
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsScene>

LineShape::LineShape(DrawType type): Shape(type)
{

}

void LineShape::Show(QColor color)
{
    this->color = color;
    this->setPos(std::min(xs1,xs2), std::min(ys1,ys2));
}


void LineShape::startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene *scene)
{
    int x = event->scenePos().x();  //ініціалізація позиції x та y курсора
    int y = event->scenePos().y();
    Set(x, y, x, y);
    scene->addItem(this);  //додавання об'єкту лінія
    Show(Qt::blue);
}

void LineShape::drawRubberFootprint(QGraphicsSceneMouseEvent *event)
{
    int x1 = getXs1();
    int y1 = getYs1();
    int x2 = event->scenePos().x();
    int y2 = event->scenePos().y();
    Set(x1, y1, x2, y2);
    style = Qt::DashLine;
    Show(Qt::blue);
}

void LineShape::endDrawing()
{
    style = Qt::SolidLine;
    Show(Qt::black);
    Shape::endDrawing();
}

QRectF LineShape::boundingRect() const
{
    qreal adjust = 10;
    QPointF point1(0 - adjust, 0 - adjust);
    QPointF point2(xSize() + adjust, ySize() + adjust);
    return QRectF(point1, point2);
}

void LineShape::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
    if ((xs2 >xs1 ) && (ys2>ys1)){
        x1 = 0;
        y1 = 0;
        x2 = xSize();
        y2 = ySize();
    }
    if ((xs2 <= xs1 ) && (ys2>ys1)){
        x1 = xSize();
        y1 = 0;
        x2 = 0;
        y2 = ySize();
    }
    if ((xs2 >xs1 ) && (ys2<=ys1)){
        x1 = 0;
        y1 = ySize();
        x2 = xSize();
        y2 = 0;
    }
    if ((xs2 <=xs1 ) && (ys2<=ys1)){
        x1 = xSize();
        y1 = ySize();
        x2 = 0;
        y2 = 0;
    }

    QPointF point1(x1, y1);
    QPointF point2(x2, y2);

    painter->setPen(QPen(color, 2, style));
    painter->drawLine(point2, point1);
}

QPainterPath LineShape::shape() const
{
    QPainterPath path;
    QPointF point1(0, 0);
    QPointF point2(xSize() + 20, ySize() + 20);
    path.addRect(QRectF(point1, point2));
    return path;
}

int LineShape::xSize() const
{
    return abs(xs1 - xs2);
}

int LineShape::ySize() const
{
    return abs(ys1 - ys2);
}
