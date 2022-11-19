#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "module1.h"
#include "module2.h"

MainWindow::MainWindow(QWidget *parent)
    : MainWindowInterface(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dataModel = new DataModel(this);
    connect(dataModel, &DataModel::valueChanged, this, &MainWindow::onValueChanged);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setValue(int value)
{
   dataModel->setValue(value);
}

void MainWindow::on_actionWork_1_triggered()
{
    createModule1Dialog(this);
}

void MainWindow::onValueChanged(int value)
{
    ui->textBrowser->clear();
    ui->textBrowser->insertPlainText(QString::number (value));
}

void MainWindow::on_actionWork_2_triggered()
{
    createModule2Dialog(this);
}




