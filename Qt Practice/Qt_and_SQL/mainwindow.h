#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets>
#include <QtSql>

#include "sqlmodel.h"

class MainWindow: public QWidget
{
    Q_OBJECT

private:

    QTableView*  tbl;
    SQLModel*    model;
    QPushButton* btnOk;




public slots:
    void slotBtnClicked();
public:
    MainWindow(QWidget* pwgt =0);

    bool checkEqual (QString str);




};

#endif // MAINWINDOW_H
