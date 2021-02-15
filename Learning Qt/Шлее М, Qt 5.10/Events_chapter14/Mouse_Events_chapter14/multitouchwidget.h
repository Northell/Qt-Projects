#ifndef MULTITOUCHWIDGET_H
#define MULTITOUCHWIDGET_H

#include <QWidget>
#include <QtWidgets>
class MultiTouchWidget:public QWidget
{
private:
    QList<QColor>                   m_lstCols;
    QList<QTouchEvent::TouchPoint>  m_lstTps; //Список точек касания

protected:
    virtual void paintEvent(QPaintEvent*);
    virtual bool event     (QEvent* pe);

public:
    MultiTouchWidget(QWidget* pwgt = 0);
};

#endif // MULTITOUCHWIDGET_H
