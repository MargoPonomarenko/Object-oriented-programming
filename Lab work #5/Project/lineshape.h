#ifndef LINESHAPE_H
#define LINESHAPE_H
#include "shape.h"

using namespace MyShapes;
class LineShape: public Shape
{
    Q_OBJECT
public:
    LineShape(DrawType type);
    virtual ~LineShape(){}
    void Show(QColor color) override;
    virtual void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    virtual void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    virtual void endDrawing() override;

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QPainterPath shape() const override;

protected:
    Qt::PenStyle style = Qt::SolidLine;
    int x1,x2,y1,y2;
    int xSize() const;
    int ySize() const;
};

#endif // LINESHAPE_H
