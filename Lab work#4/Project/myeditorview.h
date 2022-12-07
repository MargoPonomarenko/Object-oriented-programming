#ifndef MYEDITORVIEW_H
#define MYEDITORVIEW_H
#include <QGraphicsView>
#include <QWidget>
#include "myeditor.h"

class MyEditorView:public QGraphicsView
{
public:
    MyEditorView(QWidget *parent);
    void setEditor(MyEditor *editor);

    void drawShape(DrawType shapeType);

private:
    MyEditor *editor;
};

#endif // MYEDITORVIEW_H
