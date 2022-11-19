#include "module2dialog.h"
#include "ui_module2dialog.h"
#include "module3.h"

Module2Dialog::Module2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Module2Dialog)
{
    ui->setupUi(this);
    this->parent = parent;
}


Module2Dialog::~Module2Dialog()
{
    delete ui;
}

void Module2Dialog::on_nextButton_clicked()
{
    close();
    createModule3Dialog(parent);

}

void Module2Dialog::on_cancelButton2_clicked()
{
    close();
}

