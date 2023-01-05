#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QClipboard>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Object 2");
    readFromClipboard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readFromClipboard()
{
    QClipboard *clipboard = QGuiApplication::clipboard();
    matrixContentRead = clipboard->text();
    ui->label->setText(matrixContentRead );

    int matrixSize = matrixContentRead.count('\n');
    ui->label->setText(QString::number(matrixSize));

    QList<QString> splitByChar = matrixContentRead.split("\n");
    matrixContentRead = "";
    for(int n=0; n<splitByChar.length(); n++){
        ui->lineEdit->insert(splitByChar.at(n));
        matrixContentRead.append(splitByChar.at(n));
    }
    ui->label->setText(QString::number(splitByChar.length()));

    QVector<int> matrixContent;
    QString tempNum = "";
    for(auto slotN:splitByChar){
        for(auto charact:slotN){
            if(charact == '\t'){
                matrixContent.append(tempNum.toInt());
                tempNum = "";
            }
            if(charact != '\t'){
                tempNum += charact;
            }
        }
    }
    for(auto item:matrixContent){
        ui->lineEdit->insert(QString::number(item));
    }

    QVector <QVector <int> > secondMatrixContent;
    int tempCounter = 0;
    for(int i=0; i<matrixSize; i++){
        QVector<int> tempVector;
        for(int j=0; j<matrixSize; j++){
            tempVector.push_back(matrixContent.at(tempCounter));
            tempCounter++;
        }
        secondMatrixContent.push_back(tempVector);
    }

    ui->lineEdit->setText("");
    for(auto item:secondMatrixContent){
        for(auto subItem:item){
            ui->lineEdit->insert(QString::number(subItem) + " ");
        }
         ui->lineEdit->insert("\n");
    }

    int determinant = calculateDeterminant(secondMatrixContent, matrixSize);
    ui->label->setText("Determinant of matrix is : " + QString::number(determinant));

}

int MainWindow::calculateDeterminant(QVector<QVector<int> > matrix, int matrixSize)
{
    int det = 0;
    QVector<QVector<int> > submatrix(10, QVector <int>(10));
    if (matrixSize == 2){
        return ((matrix[0][0] * matrix[1][1]) - (matrix[1][0] * matrix[0][1]));
    }
    else {
        for (int x = 0; x < matrixSize; x++) {
            int subi = 0;
            for (int i = 1; i < matrixSize; i++) {
                int subj = 0;
                for (int j = 0; j < matrixSize; j++) {
                    if (j == x)
                        continue;
                    submatrix[subi][subj] = matrix[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * matrix[0][x] * calculateDeterminant( submatrix, matrixSize - 1 ));
        }
    }
    return det;
}



