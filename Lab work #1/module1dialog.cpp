#include "module1dialog.h"
#include "ui_module1dialog.h"

Module1Dialog::Module1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Module1Dialog)
{
    ui->setupUi(this);
    this->parent = (MainWindowInterface*)parent;
}

Module1Dialog::~Module1Dialog()
{
    delete ui;
}

void Module1Dialog::on_horizontalScrollBar_valueChanged(int value)
{
    ui->spinBox->setValue(value);  //setting changed value on a spin box
}

void Module1Dialog::on_okButton_clicked()
{
    parent->setValue(ui->spinBox->value());  //setting value on parent window
    close();
}

void Module1Dialog::on_cancelButton_clicked()
{
    close();
}
