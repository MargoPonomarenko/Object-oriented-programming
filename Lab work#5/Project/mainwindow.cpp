#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "scenewindow.h"
#include "toolbar.h"



#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QApplication::instance()->setAttribute(Qt::AA_DontShowIconsInMenus, true);

    toolBar = new Toolbar(this);
    addToolBar(toolBar);
    setUpToolBar();


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    myEditorView = createEditor(this);
    connect(myEditorView, &MyEditorView::shapeCreated, this, &MainWindow::onShapeCreated);
}

void MainWindow::on_drawPoint_triggered()
{
    setWindowTitle("Режим малювання: крапка");
    ui->drawLine->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawElipse->setChecked(false);
    ui->drawLineWithElipse->setChecked(false);
    ui->drawCube->setChecked(false);

    myEditorView->drawShape(DrawType::POINT);
}

void MainWindow::on_drawLine_triggered()
{
    setWindowTitle("Режим малювання: лінія");
    ui->drawPoint->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawElipse->setChecked(false);
    ui->drawLineWithElipse->setChecked(false);
    ui->drawCube->setChecked(false);

    myEditorView->drawShape(DrawType::LINE);
}

void MainWindow::on_drawRect_triggered()
{
    setWindowTitle("Режим малювання: прямокутник");
    ui->drawPoint->setChecked(false);
    ui->drawLine->setChecked(false);
    ui->drawElipse->setChecked(false);
    ui->drawLineWithElipse->setChecked(false);
    ui->drawCube->setChecked(false);

    myEditorView->drawShape(DrawType::RECT);
}

void MainWindow::on_drawElipse_triggered()
{
    setWindowTitle("Режим малювання: еліпс");
    ui->drawPoint->setChecked(false);
    ui->drawLine->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawLineWithElipse->setChecked(false);
    ui->drawCube->setChecked(false);

    myEditorView->drawShape(DrawType::ELIPSE);
}

void MainWindow::on_drawLineWithElipse_triggered()
{
    setWindowTitle("Режим малювання: лінія з еліпсами");
    ui->drawPoint->setChecked(false);
    ui->drawLine->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawElipse->setChecked(false);
    ui->drawCube->setChecked(false);

    myEditorView->drawShape(DrawType::LINEWITHELIPSE);
}

void MainWindow::on_drawCube_triggered()
{
    setWindowTitle("Режим малювання: куба");
    ui->drawPoint->setChecked(false);
    ui->drawLine->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawElipse->setChecked(false);
    ui->drawLineWithElipse->setChecked(false);

    myEditorView->drawShape(DrawType::CUBE);
}

void MainWindow::setUpToolBar()
{
    toolBar->addAction(ui->actionNew);
    toolBar->addSeparator();
    toolBar->addAction(ui->drawPoint);
    toolBar->addAction(ui->drawLine);
    toolBar->addAction(ui->drawRect);
    toolBar->addAction(ui->drawElipse);
    toolBar->addAction(ui->drawLineWithElipse);
    toolBar->addAction(ui->drawCube);
}

void MainWindow::onShapeCreated(DrawType type, int x1, int y1, int x2, int y2)
{
    table->onShapeCreated(type, x1, y1, x2, y2);

}

void MainWindow::on_tableCheck_triggered()
{
    table->clearFile();
    table = new MyTable(this);
    connect(table, &MyTable::objectSelected, this, &MainWindow::onObjectSelected);

}

void MainWindow::onObjectSelected(int index)
{
    myEditorView->onObjectSelected(index);
}


void MainWindow::on_readFile_triggered()
{

}

