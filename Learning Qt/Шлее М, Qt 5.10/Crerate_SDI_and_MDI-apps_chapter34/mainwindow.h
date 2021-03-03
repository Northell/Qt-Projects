#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>

class MainWindow:public QMainWindow
{
Q_OBJECT
public:
    MainWindow(QWidget* pwgt = 0);
    QToolBar* createToolBar();

public slots:
    void slotNoImpl();
};

#endif // MAINWINDOW_H
