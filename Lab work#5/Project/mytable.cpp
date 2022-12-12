#include "mytable.h"
#include "mytable.h"

//#include "drawtype.h"

#include <QDialog>

#include <QFile>
#include <QHBoxLayout>

MyTable::MyTable(QWidget *parent)
{
//    MyTable *table = new MyTable(parent);

    //connect(Shape::createShape(), &Shape::shapeCreated, table, &MyTable::onShapeCreated); BEFORE


    table = new QTableWidget;
    connect(table, &QTableWidget::cellClicked, this, &MyTable::onCellClicked);
    table->setEditTriggers(QTableWidget::NoEditTriggers);
    table->setFixedSize(550, 450);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels(columnLabels);
    table->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //tableWidget.setColumnCount

    QDialog *tableWin = new QDialog(parent);

    QHBoxLayout *HLayout = new QHBoxLayout(tableWin);
    HLayout->addWidget(table);
    tableWin->setLayout(HLayout);
    tableWin->show();

//    KeyboardWidget *keyboardWidget = new KeyboardWidget(parent);
//    MainWindow *window = (MainWindow *)parent;
//    window->setKeyboardWidget(keyboardWidget);

//     ui->centralwidget->layout()->addWidget(widget);
}

MyTable::~MyTable()
{

}

void MyTable::onShapeCreated(DrawType type, int x1, int y1, int x2, int y2)
{
    QString shapeType;
    switch (type){
    case DrawType::POINT:
        shapeType = "Point";
        break;
    case DrawType::LINE:
        shapeType = "Line";
        break;
    case DrawType::RECT:
        shapeType = "Rect";
        break;
    case DrawType::ELIPSE:
        shapeType = "Elipse";
        break;
    case DrawType::LINEWITHELIPSE:
        shapeType = "LineWithShape";
        break;
    case DrawType::CUBE:
        shapeType = "Cube";
        break;

    }
    qDebug()<<"Shape label: "<<shapeType<<" added to table";
    table->setRowCount(table->rowCount() + 1);
    int row = table->rowCount() - 1;
    qDebug()<<"MyTable xs1: "<<x1;
    table->setItem(row, 0, new QTableWidgetItem(shapeType));
    table->setItem(row, 1, new QTableWidgetItem(QString::number(x1)));
    table->setItem(row, 2, new QTableWidgetItem(QString::number(y1)));
    table->setItem(row, 3, new QTableWidgetItem(QString::number(x2)));
    table->setItem(row, 4, new QTableWidgetItem(QString::number(y2)));
    saveRow(shapeType, x1, y1, x2, y2);
}

QTableWidget *MyTable::getTable() const
{
    return table;
}

void MyTable::clearFile()
{
    QFile tableDataFile("TableData.txt");
    if(!tableDataFile.open(QIODevice::WriteOnly | QIODevice::Text)){
        return;
    }
    tableDataFile.close();
}

void MyTable::saveRow(QString shapeType, int x1, int y1, int x2, int y2)
{
    QFile tableDataFile("TableData.txt");
    if(!tableDataFile.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)){
        return;
    }

    QTextStream textOut(&tableDataFile);
    textOut << shapeType << "\t" << x1 << "\t"<< y1 << "\t" << x2 << "\t"<< y2 <<'\n';
    tableDataFile.close();
    qDebug() << "Writing finished";

}

void MyTable::onCellClicked(int row, int col)
{
    table->selectRow(row);
    emit objectSelected(row);
}


