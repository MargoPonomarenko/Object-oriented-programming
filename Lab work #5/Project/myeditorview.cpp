#include "myeditorview.h"

MyEditorView::MyEditorView(QWidget *parent):QGraphicsView(parent)
{
}

void MyEditorView::setEditor(MyEditor *editor)
{
    this->editor = editor;
    connect(editor, &MyEditor::shapeCreated, this, &MyEditorView::onShapeCreated);
    this->setScene(editor);
}

void MyEditorView::drawShape(DrawType shapeType)
{
    editor->selectShape(shapeType);
}

void MyEditorView::onObjectSelected(int index)
{
    editor->onObjectSelected(index);
}

void MyEditorView::onObjectDelete(int row)
{
    editor->onObjectDelete(row);
}

void MyEditorView::drawFromFile(const QVector<QString> &data )
{
    editor->drawFromFile(data);
    qDebug()<<"Draw from file editorview";
}

const QVector<MyShapes::Shape *> MyEditorView::getObjects()
{
    return editor->getObjects();
}

void MyEditorView::onShapeCreated(DrawType type, int x1, int y1, int x2, int y2)
{
    emit shapeCreated(type, x1, y1, x2, y2);
}
