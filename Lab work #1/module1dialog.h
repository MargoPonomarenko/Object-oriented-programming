#ifndef MODULE1DIALOG_H
#define MODULE1DIALOG_H

#include <QDialog>
#include "mainwindowInterface.h"

namespace Ui {
class Module1Dialog;
}

class Module1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Module1Dialog(QWidget *parent = nullptr);
    ~Module1Dialog();

private slots:
    void on_horizontalScrollBar_valueChanged(int value);  //scrolling horizontal bar
    void on_okButton_clicked();
    void on_cancelButton_clicked();

private:
    Ui::Module1Dialog *ui;
    MainWindowInterface* parent;
};

#endif // MODULE1DIALOG_H
