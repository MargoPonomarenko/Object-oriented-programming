#include "module3.h"
#include "module3dialog.h"

void createModule3Dialog(QWidget *parent)
{
    Module3Dialog * dialog = new Module3Dialog(parent);
    dialog->setWindowModality(Qt::ApplicationModal);
    dialog->show();
}
