#ifndef MYPROGRESSBAR_H
#define MYPROGRESSBAR_H


#include <QtWidgets>
#include "progressevent.h"
class MyProgressBar:public QProgressBar
{
public:
    MyProgressBar(QWidget* pwgt = 0);

    void customEvent(QEvent* pe);
};

#endif // MYPROGRESSBAR_H
