#ifndef MYWIDGET1_H
#define MYWIDGET1_H

#include <QtWidgets>

class MyWidget1: public QWidget
{
    Q_OBJECT
public:
    MyWidget1(QWidget* pwgt = 0);

public slots:
    void slotDisplayDialog();
};

#endif // MYWIDGET1_H
