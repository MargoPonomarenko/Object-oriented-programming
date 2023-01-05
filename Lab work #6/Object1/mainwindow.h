#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QList<QString> list, QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    QString matrixContent;

    void generateMatrix(QList<QString> list);
    void copyMatrixToClipboard();
};
#endif // MAINWINDOW_H
