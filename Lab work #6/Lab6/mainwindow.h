#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

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

    void on_generateButton_pressed();

    void on_generateButton_released();

private:
    Ui::MainWindow *ui;
    QProcess *first;
    QProcess *second;
};
#endif // MAINWINDOW_H
