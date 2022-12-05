#ifndef POINTSHAPE_H
#define POINTSHAPE_H
#include "shape.h"


class PointShape: public Shape
{
public:
    PointShape();
    void Show(QColor color) override;  //метод відображення фігури на сцені
    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawOnMove(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;

    // QGraphicsItem interface
    QRectF boundingRect() const override;  //виділення "фізичної" області на сцені для малювання
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;  //малювання фігури
    QPainterPath shape() const override;
};

#endif // POINTSHAPE_H
