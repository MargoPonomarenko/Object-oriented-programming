#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "shapeobjectseditorview.h"
#include "toolbar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_drawPoint_triggered();

    void on_drawLine_triggered();

    void on_drawRect_triggered();

    void on_drawElipse_triggered();

private:
    Ui::MainWindow *ui;
    ShapeObjectsEditorView *shapeEditorView;
    Toolbar *toolBar;
    void setUpToolBar();

};
#endif // MAINWINDOW_H
