#ifndef MODULE2DIALOG_H
#define MODULE2DIALOG_H

#include <QDialog>
#include "mainwindowInterface.h"

namespace Ui {
class Module2Dialog;
}

class Module2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Module2Dialog(QWidget *parent = nullptr);

    ~Module2Dialog();

private slots:

    void on_nextButton_clicked();
    void on_cancelButton2_clicked();

private:
    Ui::Module2Dialog *ui;
    QWidget* parent;
};

#endif // MODULE2DIALOG_H
