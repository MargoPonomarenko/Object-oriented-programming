#include "shapeobjectseditorview.h"


ShapeObjectsEditorView::ShapeObjectsEditorView(QWidget *parent):QGraphicsView(parent)
{
}

void ShapeObjectsEditorView::setEditor(ShapeObjectsEditor *editor)
{
    this->editor = editor;
    this->setScene(editor);
}

void ShapeObjectsEditorView::drawPoint()
{
    editor->selectPoint();
}

void ShapeObjectsEditorView::drawLine()
{
    editor->selectLine();
}

void ShapeObjectsEditorView::drawRect()
{
    editor->selectRect();
}

void ShapeObjectsEditorView::drawElipse()
{
    editor->selectElipse();
}


