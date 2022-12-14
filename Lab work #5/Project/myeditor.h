#ifndef MYEDITOR_H
#define MYEDITOR_H
#include <QGraphicsScene>
#include "shape.h"

using namespace MyShapes;
const int capasity = 129;

class MyEditor: public QGraphicsScene
{
    Q_OBJECT
public:
    static MyEditor& getInstance();

    void selectShape(DrawType shapeType);

    void onObjectSelected(int index);
    void onObjectDelete(int row);
    void drawFromFile(const QVector<QString> &data);
    const QVector<MyShapes::Shape *> getObjects();

private:
    MyEditor();
    MyEditor( const MyEditor&);
    MyEditor& operator=( MyEditor& );

    DrawType drawType = DrawType::POINT;
    bool drawStatus = false;
    Shape *currentShape;

    int size = 0;
    MyShapes::Shape *objects [capasity];  //масив вказівників на об'єкти типу Shape

    void deleteObject(int index);

    Shape * createShape(QString strType);
    QMap<QString, DrawType> shapeConvert;
    void initConverter();

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
