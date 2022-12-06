#ifndef ELIPSESHAPE_H
#define ELIPSESHAPE_H
#include "shape.h"

class ElipseShape: public Shape
{
public:
    ElipseShape();
    virtual ~ElipseShape(){}
    void Show(QColor color) override;
    virtual void  startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    virtual void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    virtual void endDrawing() override;


    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

protected:
    Qt::PenStyle style = Qt::SolidLine;
    int xSize() const;
    int ySize() const;
};

#endif // ELIPSESHAPE_H
