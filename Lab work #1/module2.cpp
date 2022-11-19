#include "module2.h"
#include "module2dialog.h"

void createModule2Dialog(QWidget *parent)
{
    Module2Dialog * dialog = new Module2Dialog(parent);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->show();
}
