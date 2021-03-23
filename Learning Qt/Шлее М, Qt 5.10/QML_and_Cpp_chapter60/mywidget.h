#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets>
#include <QQuickWidget>
#include <QQuickItem>

class MyWidget:public QWidget
{
    Q_OBJECT
public:
    MyWidget(QWidget *pwgt = 0);
};

#endif // MYWIDGET_H
