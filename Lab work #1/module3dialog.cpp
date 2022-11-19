#include "module3dialog.h"
#include "ui_module3dialog.h"
#include "module2.h"

Module3Dialog::Module3Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Module3Dialog)
{
    ui->setupUi(this);
    this->parent = parent;
}

Module3Dialog::~Module3Dialog()
{
    delete ui;
}

void Module3Dialog::on_backButton_clicked()
{
    close();
    createModule2Dialog(parent);
}

void Module3Dialog::on_okButton3_clicked()
{
    close();
}

void Module3Dialog::on_cancelButton3_clicked()
{
    close();
}

