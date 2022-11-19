#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "datamodel.h"
#include "mainwindowInterface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow :public MainWindowInterface
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setValue(int value) override;

private slots:
    void on_actionWork_1_triggered();  //action Work_1 clicked
    void onValueChanged(int value);
    void on_actionWork_2_triggered();  //action Work_2 clicked

private:
    Ui::MainWindow *ui;
    DataModel* dataModel;

};
#endif // MAINWINDOW_H
