#include <QGraphicsView>
#include "scenewindow.h"
#include "shapeobjectseditor.h"

ShapeObjectsEditorView *createEditor(QWidget *parent)
{
    const int topMargin = 57;
    int width = parent->width();
    int height = parent->height() - topMargin;

    ShapeObjectsEditor *editor = new ShapeObjectsEditor;  //створення сцени
    editor->setSceneRect(0, 0, width, height);

    ShapeObjectsEditorView * view = new ShapeObjectsEditorView(parent);  //створення view (відображення сцени)
    view->setEditor(editor);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Режим малювання:"));
    view->setGeometry(0, topMargin, width + 2, height + 2);
    view->show();

    return view;
}
