#ifndef LINESHAPE_H
#define LINESHAPE_H
#include "shape.h"

class LineShape: public Shape
{
public:
    LineShape();
    void Show(QColor color) override;
    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawOnMove(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

private:
    int xSize() const;
    int ySize() const;
};

#endif // LINESHAPE_H
