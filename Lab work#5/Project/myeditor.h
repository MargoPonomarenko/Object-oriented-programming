#ifndef MYEDITOR_H
#define MYEDITOR_H
#include <QGraphicsScene>
#include "shape.h"

const int capasity = 129;

class MyEditor: public QGraphicsScene
{
    Q_OBJECT
public:
    static MyEditor& getInstance();

    void selectShape(DrawType shapeType);

    void onObjectSelected(int index);

private:
    MyEditor() {}
    MyEditor( const MyEditor&);
    MyEditor& operator=( MyEditor& );

    DrawType drawType = DrawType::POINT;
    bool drawStatus = false;
    Shape *currentShape;

    int size = 0;
    Shape *objects [capasity];  //масив вказівників на об'єкти типу Shape

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private slots:
    void onShapeCreated(DrawType type, int x1, int y1, int x2, int y2);


signals:
    void shapeCreated(DrawType type, int x1, int y1, int x2, int y2);
};

#endif // MYEDITOR_H
