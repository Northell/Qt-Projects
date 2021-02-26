#ifndef WIDGET_H
#define WIDGET_H



#include <QtWidgets>


#include "widgetdrag.h"
#include "widgetmimedata.h"

class Widget:public QLabel
{
    Q_OBJECT
private:
    QPoint m_ptDragPos;

    void startDrag();

protected:
    virtual void mousePressEvent(QMouseEvent* pe);
    virtual void mouseMoveEvent (QMouseEvent* pe);
    virtual void dragEnterEvent (QDragEnterEvent* pe);
    virtual void dropEvent      (QDropEvent* pe);
public:
    Widget(QWidget* pwgt = 0);
};

#endif // WIDGET_H
