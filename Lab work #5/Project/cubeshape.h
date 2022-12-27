#ifndef CUBESHAPE_H
#define CUBESHAPE_H
#include "lineshape.h"
#include "rectshape.h"

using namespace MyShapes;
class CubeShape:  public LineShape
{
    Q_OBJECT
public:
    CubeShape(DrawType type);

    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int phaze = 0;
};

#endif // CUBESHAPE_H
