#include "mainwindow2.h"

void MainWindow2::mouseMoveEvent(QMouseEvent *pe)
{
    m_plblX->setText("X=" + QString().setNum(pe->x()));
    m_plblY->setText("Y=" + QString().setNum(pe->y()));
}

MainWindow2::MainWindow2(QWidget *pwgt): QMainWindow(pwgt)
{

    setMouseTracking(true);
    m_plblX = new QLabel(this);
    m_plblY = new QLabel(this);

    statusBar()->addWidget(m_plblY);
    statusBar()->addWidget(m_plblX);
}
