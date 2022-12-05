#ifndef SHAPEOBJECTSEDITORVIEW_H
#define SHAPEOBJECTSEDITORVIEW_H
#include <QGraphicsView>
#include <QWidget>
#include "shapeobjectseditor.h"


class ShapeObjectsEditorView:public QGraphicsView
{
public:
    ShapeObjectsEditorView(QWidget *parent);
    void setEditor(ShapeObjectsEditor *editor);

    //action
    void drawPoint();
    void drawLine();
    void drawRect();
    void drawElipse();

private:
    ShapeObjectsEditor *editor;
};

#endif // SHAPEOBJECTSEDITORVIEW_H
