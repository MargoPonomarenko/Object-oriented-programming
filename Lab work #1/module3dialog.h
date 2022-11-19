#ifndef MODULE3DIALOG_H
#define MODULE3DIALOG_H

#include <QDialog>
#include "mainwindowInterface.h"

namespace Ui {
class Module3Dialog;
}

class Module3Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Module3Dialog(QWidget *parent = nullptr);
    ~Module3Dialog();

private slots:

    void on_backButton_clicked();
    void on_okButton3_clicked();
    void on_cancelButton3_clicked();

private:
    Ui::Module3Dialog *ui;
    QWidget* parent;
};

#endif // MODULE3DIALOG_H
