#ifndef MYDRAGCLASS_H
#define MYDRAGCLASS_H

#include <QtWidgets>

class MyDragClass:public QLabel
{
    Q_OBJECT

private:
    void startDrag();
public:
    MyDragClass();
};

#endif // MYDRAGCLASS_H
