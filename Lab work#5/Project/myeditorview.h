#ifndef MYEDITORVIEW_H
#define MYEDITORVIEW_H
#include <QGraphicsView>
#include <QWidget>
#include "myeditor.h"

class MyEditorView:public QGraphicsView
{
    Q_OBJECT
public:
    MyEditorView(QWidget *parent);
    void setEditor(MyEditor *editor);

    void drawShape(DrawType shapeType);

private:
    MyEditor *editor;

private slots:
    void onShapeCreated(DrawType type, int x1, int y1, int x2, int y2);

signals:
    void shapeCreated(DrawType type, int x1, int y1, int x2, int y2);
};

#endif // MYEDITORVIEW_H