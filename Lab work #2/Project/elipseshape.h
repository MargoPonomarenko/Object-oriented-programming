#ifndef ELIPSESHAPE_H
#define ELIPSESHAPE_H
#include "shape.h"

class ElipseShape: public Shape
{
public:
    ElipseShape();

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

#endif // ELIPSESHAPE_H
