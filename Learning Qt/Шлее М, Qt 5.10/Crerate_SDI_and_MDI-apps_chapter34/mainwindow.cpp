#include "mainwindow.h"

MainWindow::MainWindow(QWidget *pwgt):QMainWindow(pwgt)
{
    addToolBar(Qt::TopToolBarArea, createToolBar());
    addToolBar(Qt::BottomToolBarArea, createToolBar());
    addToolBar(Qt::LeftToolBarArea, createToolBar());
    addToolBar(Qt::RightToolBarArea, createToolBar());
}

QToolBar *MainWindow::createToolBar()
{
    QToolBar* ptb = new QToolBar("Linker ToolBar");

    ptb->addAction(QPixmap(":/image1"), "1", this, SLOT(slotNoImpl()));
    ptb->addAction(QPixmap(":/RedGuy"), "2", this, SLOT(slotNoImpl()));

    ptb->addSeparator();
    ptb->addAction(QPixmap(":/OrangeGuy"), "3", this, SLOT(slotNoImpl()));
    ptb->addAction(QPixmap(":/BlackGuy"), "4", this, SLOT(slotNoImpl()));

    return ptb;
}

void MainWindow::slotNoImpl()
{
    QMessageBox::information(0, "Message", "Not implemented");
}
