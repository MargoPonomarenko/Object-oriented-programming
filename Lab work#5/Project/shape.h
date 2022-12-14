#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>
#include <QObject>
#include "drawtype.h"


class Shape:public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Shape(DrawType type);
    virtual ~Shape();
    void Set(int x1, int y1, int x2, int y2);
    virtual void Show(QColor color) = 0;

    int getXs1() const;
    int getYs1() const;
    int getXs2() const;
    int getYs2() const;

    static Shape * createShape(DrawType type);
    virtual void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) {};
    virtual void drawRubberFootprint(QGraphicsSceneMouseEvent *event) {}
    virtual void endDrawing();

    void selectShape();
    void unselectShape();

    DrawType getType() const;
    void setType(DrawType newType);

    QColor color = Qt::black;

protected:
    int xs1=0;
    int ys1=0;
    int xs2=0;
    int ys2=0;
    DrawType type;

    QGraphicsScene * scene;

    QColor selectedColor = Qt::black;

signals:
    void shapeCreated(DrawType type, int x1, int y1, int x2, int y2);

};

#endif // SHAPE_H
