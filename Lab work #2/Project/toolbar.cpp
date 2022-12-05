#include <QToolBar>
#include <QIcon>
#include <QAction>
#include "toolbar.h"

Toolbar::Toolbar(QWidget *parent): QToolBar(parent) {
  qDebug()<<"Creating Toolbar";
}

Toolbar::~Toolbar()
{
}




