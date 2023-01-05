#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QClipboard>
#include <QRandomGenerator>

MainWindow::MainWindow(QList<QString> list, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Object 1");

    generateMatrix(list);
    copyMatrixToClipboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generateMatrix(QList<QString> list)
{
    if(list.size()<3){
        return;
    }

    int matrixSize = list.at(0).toInt();
    int minValue = list.at(1).toInt();
    int maxValue = list.at(2).toInt();

    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    int value;
    for(int i=0; i<matrixSize; i++){
        for(int j=0; j<matrixSize; j++){
            value = generator.bounded(minValue, maxValue);
            matrixContent.append(QString::number(value) + "\t");
        }
        matrixContent.append("\n");
    }
    ui->textEdit->setText(matrixContent);
}

void MainWindow::copyMatrixToClipboard()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    clipboard->setText(matrixContent);
}

