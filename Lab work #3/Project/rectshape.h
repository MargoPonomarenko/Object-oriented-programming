#ifndef RECTSHAPE_H
#define RECTSHAPE_H
#include "shape.h"

class RectShape: public Shape
{
public:
    RectShape();
    void Show(QColor color) override;
    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

private:
    Qt::PenStyle style = Qt::SolidLine;
    int xSize() const;
    int ySize() const;
};

#endif // RECTSHAPE_H
