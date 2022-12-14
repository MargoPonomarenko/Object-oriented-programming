#ifndef LINEWITHELIPSESHAPE_H
#define LINEWITHELIPSESHAPE_H
#include "lineshape.h"
#include "elipseshape.h"

class LineWithElipseShape:  public LineShape
{
public:
    LineWithElipseShape();

    void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) override;
    void drawRubberFootprint(QGraphicsSceneMouseEvent *event) override;
    void endDrawing() override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;


private:
    int phaze = 0;
};

#endif // LINEWITHELIPSESHAPE_H
