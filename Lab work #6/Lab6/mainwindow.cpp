#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Lab 6");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_generateButton_pressed()
{
    first = new QProcess(this);
    second = new QProcess(this);
    QStringList arguments;
    arguments << ui->numberValue->text() << ui->minValue->text() << ui->maxValue->text()<<QString::number(this->width())<<QString::number(this->x());
    qDebug()<<arguments;
    first->start("Object1.exe", arguments);
}


void MainWindow::on_generateButton_released()
{
    QStringList arguments;
    second->start("Object2.exe", arguments);
}

