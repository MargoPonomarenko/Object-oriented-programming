#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QToolBar>
#include <QApplication>

class Toolbar : public QToolBar
{
    Q_OBJECT

public:
    Toolbar(QWidget *parent = nullptr);
    ~Toolbar();

private:
};

#endif // TOOLBAR_H
