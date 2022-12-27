#ifndef LINEWITHELIPSESHAPE_H
#define LINEWITHELIPSESHAPE_H
#include "lineshape.h"
#include "elipseshape.h"

using namespace MyShapes;
class LineWithElipseShape:  public LineShape
{
    Q_OBJECT
public:
    LineWithElipseShape(DrawType type);

    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


private:
    int phaze = 0;
};

#endif // LINEWITHELIPSESHAPE_H
