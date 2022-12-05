#ifndef SHAPE_H
#define SHAPE_H
#include <QGraphicsItem>


enum class DrawType{
    POINT = 0,
    LINE,
    RECT,
    ELIPSE,
};

class Shape:public QGraphicsItem
{
public:
    Shape();
    virtual ~Shape();
    void Set(int x1, int y1, int x2, int y2);
    virtual void Show(QColor color) = 0;  //віртуальний метод Show


    int getXs1() const;
    int getYs1() const;
    int getXs2() const;
    int getYs2() const;

    static Shape * createShape(DrawType type);
    virtual void startDrawing(QGraphicsSceneMouseEvent *event, QGraphicsScene * scene) = 0;
    virtual void drawOnMove(QGraphicsSceneMouseEvent *event) {}
    virtual void endDrawing() {}

protected:
    int xs1=0;
    int ys1=0;
    int xs2=0;
    int ys2=0;

    QGraphicsScene * scene;
    QColor color = Qt::black;
};

#endif // SHAPE_H
