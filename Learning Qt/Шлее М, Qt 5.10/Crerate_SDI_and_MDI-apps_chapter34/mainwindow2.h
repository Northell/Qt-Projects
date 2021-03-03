#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QtWidgets>

class MainWindow2:public QMainWindow
{
    Q_OBJECT
private:
    QLabel* m_plblX;
    QLabel* m_plblY;

protected:
    virtual void mouseMoveEvent(QMouseEvent* pe);


public:
    MainWindow2(QWidget* pwgt = 0);
};

#endif // MAINWINDOW2_H
