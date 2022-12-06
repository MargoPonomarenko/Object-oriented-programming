#include "myeditorview.h"

MyEditorView::MyEditorView(QWidget *parent):QGraphicsView(parent)
{
}

void MyEditorView::setEditor(MyEditor *editor)
{
    this->editor = editor;
    this->setScene(editor);
}

void MyEditorView::drawShape(DrawType shapeType)
{
    editor->selectShape(shapeType);
}
