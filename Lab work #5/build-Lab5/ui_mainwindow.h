/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *drawPoint;
    QAction *drawLine;
    QAction *drawRect;
    QAction *drawElipse;
    QAction *drawLineWithElipse;
    QAction *drawCube;
    QAction *tableCheck;
    QAction *readFile;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/img/add-file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        drawPoint = new QAction(MainWindow);
        drawPoint->setObjectName(QString::fromUtf8("drawPoint"));
        drawPoint->setCheckable(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/img/dot.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawPoint->setIcon(icon1);
        drawLine = new QAction(MainWindow);
        drawLine->setObjectName(QString::fromUtf8("drawLine"));
        drawLine->setCheckable(true);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/img/diagonal-line.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawLine->setIcon(icon2);
        drawRect = new QAction(MainWindow);
        drawRect->setObjectName(QString::fromUtf8("drawRect"));
        drawRect->setCheckable(true);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/img/rectangular-shape-outline.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawRect->setIcon(icon3);
        drawElipse = new QAction(MainWindow);
        drawElipse->setObjectName(QString::fromUtf8("drawElipse"));
        drawElipse->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/img/elipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawElipse->setIcon(icon4);
        drawLineWithElipse = new QAction(MainWindow);
        drawLineWithElipse->setObjectName(QString::fromUtf8("drawLineWithElipse"));
        drawLineWithElipse->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/img/lineWithElipse.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawLineWithElipse->setIcon(icon5);
        drawCube = new QAction(MainWindow);
        drawCube->setObjectName(QString::fromUtf8("drawCube"));
        drawCube->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/img/cubePNG.png"), QSize(), QIcon::Normal, QIcon::Off);
        drawCube->setIcon(icon6);
        tableCheck = new QAction(MainWindow);
        tableCheck->setObjectName(QString::fromUtf8("tableCheck"));
        readFile = new QAction(MainWindow);
        readFile->setObjectName(QString::fromUtf8("readFile"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu_2 = new QMenu(menubar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_3 = new QMenu(menubar);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_4 = new QMenu(menubar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menu_2->menuAction());
        menubar->addAction(menu_4->menuAction());
        menubar->addAction(menu_3->menuAction());
        menu->addAction(actionNew);
        menu->addAction(readFile);
        menu_2->addAction(drawPoint);
        menu_2->addAction(drawLine);
        menu_2->addAction(drawRect);
        menu_2->addAction(drawElipse);
        menu_2->addAction(drawLineWithElipse);
        menu_2->addAction(drawCube);
        menu_4->addAction(tableCheck);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\320\265 \320\277\320\276\320\273\320\276\321\202\320\275\320\276", nullptr));
        drawPoint->setText(QCoreApplication::translate("MainWindow", "\320\232\321\200\320\260\320\277\320\272\320\260", nullptr));
        drawLine->setText(QCoreApplication::translate("MainWindow", "\320\233\321\226\320\275\321\226\321\217", nullptr));
        drawRect->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\321\217\320\274\320\276\320\272\321\203\321\202\320\275\320\270\320\272", nullptr));
        drawElipse->setText(QCoreApplication::translate("MainWindow", "\320\225\320\273\321\226\320\277\321\201", nullptr));
        drawLineWithElipse->setText(QCoreApplication::translate("MainWindow", "\320\233\321\226\320\275\321\226\321\217 \320\267 \320\272\321\200\321\203\320\266\320\265\321\207\320\272\320\260\320\274\320\270", nullptr));
        drawCube->setText(QCoreApplication::translate("MainWindow", "\320\232\321\203\320\261", nullptr));
        tableCheck->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\263\320\273\321\217\320\264 \320\261\320\260\320\267\320\270", nullptr));
        readFile->setText(QCoreApplication::translate("MainWindow", "\320\222\320\270\320\262\320\265\321\201\321\202\320\270 \320\262\320\274\321\226\321\201\321\202", nullptr));
        menu->setTitle(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273", nullptr));
        menu_2->setTitle(QCoreApplication::translate("MainWindow", "\320\236\320\261'\321\224\320\272\321\202\320\270", nullptr));
        menu_3->setTitle(QCoreApplication::translate("MainWindow", "\320\224\320\276\320\262\321\226\320\264\320\272\320\260", nullptr));
        menu_4->setTitle(QCoreApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\321\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
