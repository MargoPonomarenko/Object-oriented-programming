#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "myeditorview.h"
#include "toolbar.h"
#include "mytable.h"

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

    void on_drawLineWithElipse_triggered();

    void on_drawCube_triggered();

    void on_tableCheck_triggered();

    void onObjectSelected(int index);
    void onObjectDelete(int row);

private:
    Ui::MainWindow *ui;
    MyEditorView *myEditorView;
    Toolbar *toolBar;
    MyTable *table;
    QVector<QString> readFileDataArray;

    void setUpToolBar();
    void drawFromFile(const QVector<QString> &data);

private slots:
    void onShapeCreated(DrawType type, int x1, int y1, int x2, int y2);

    void on_readFile_triggered();

signals:
    void shapeCreated(DrawType type, int x1, int y1, int x2, int y2);

};
#endif // MAINWINDOW_H
