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
    shapeEditorView = createEditor(this);
}

void MainWindow::on_drawPoint_triggered()
{
    setWindowTitle("Режим малювання: крапка");
    ui->drawLine->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawElipse->setChecked(false);

    shapeEditorView->drawPoint();
}


void MainWindow::on_drawLine_triggered()
{
    setWindowTitle("Режим малювання: лінія");
    ui->drawPoint->setChecked(false);
    ui->drawRect->setChecked(false);
    ui->drawElipse->setChecked(false);

    shapeEditorView->drawLine();
}


void MainWindow::on_drawRect_triggered()
{
    setWindowTitle("Режим малювання: прямокутник");
    ui->drawPoint->setChecked(false);
    ui->drawLine->setChecked(false);
    ui->drawElipse->setChecked(false);

    shapeEditorView->drawRect();
}


void MainWindow::on_drawElipse_triggered()
{
    setWindowTitle("Режим малювання: еліпс");
    ui->drawPoint->setChecked(false);
    ui->drawLine->setChecked(false);
    ui->drawRect->setChecked(false);

    shapeEditorView->drawElipse();
}

void MainWindow::setUpToolBar()
{
    toolBar->addAction(ui->actionNew);
    toolBar->addSeparator();
    toolBar->addAction(ui->drawPoint);
    toolBar->addAction(ui->drawLine);
    toolBar->addAction(ui->drawRect);
    toolBar->addAction(ui->drawElipse);
}

