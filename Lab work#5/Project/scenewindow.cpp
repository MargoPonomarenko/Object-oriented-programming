#include <QGraphicsView>
#include "scenewindow.h"
#include "myeditorview.h"

MyEditorView *createEditor(QWidget *parent)
{
    const int topMargin = 57;
    int width = parent->width();
    int height = parent->height() - topMargin;

    MyEditor &editor = MyEditor::getInstance();  //створення сцени
    editor.setSceneRect(0, 0, width, height);

    MyEditorView * view = new MyEditorView(parent);  //створення view (відображення сцени)
    view->setEditor(&editor);
    view->setWindowTitle(QT_TRANSLATE_NOOP(QGraphicsView, "Режим малювання:"));
    view->setGeometry(0, topMargin, width + 2, height + 2);
    view->show();

    return view;
}
