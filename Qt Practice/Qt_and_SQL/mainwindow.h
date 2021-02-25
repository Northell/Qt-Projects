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

    QLabel*      lbl;
    QPushButton* btnOk;
    QCheckBox*   enabledValues;     //отображение данных
    QTextEdit*   txt;

    QVBoxLayout* layout;




public slots:
    void slotBtnClicked();
public:
    MainWindow(QWidget* pwgt =0);

    QStringList ParsingHeader(QString str);


};

#endif // MAINWINDOW_H
