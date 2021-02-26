#ifndef WIDGETDRAG_H
#define WIDGETDRAG_H

#include <QDrag>
#include <QtWidgets>
#include "widgetmimedata.h"

class WidgetDrag:public QDrag
{
public:
    WidgetDrag(QWidget* pwgtDragSource);

    void setWidget(QWidget* pwgt);
};

#endif // WIDGETDRAG_H
