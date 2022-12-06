#ifndef POINTSHAPE_H
#define POINTSHAPE_H
#include "shape.h"

class PointShape: public Shape
{
public:
    PointShape();
    void Show(QColor color) override;
    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;  //малювання фігури
    QPainterPath shape() const override;
};

#endif // POINTSHAPE_H
