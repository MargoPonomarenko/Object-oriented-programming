#include "module1.h"
#include "module1dialog.h"

void createModule1Dialog(QWidget *parent)
{
    Module1Dialog * dialog = new Module1Dialog(parent);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->show();
}
