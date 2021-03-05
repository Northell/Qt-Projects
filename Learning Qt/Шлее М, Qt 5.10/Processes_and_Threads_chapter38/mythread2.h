#ifndef MYTHREAD2_H
#define MYTHREAD2_H

#include <QThread>
#include <QtWidgets>
#include "progressevent.h"
class MyThread2:public QThread
{
private:
    QObject* m_pobjReceiver;
public:
    MyThread2(QObject* pobjRecceiver);
    void run();
};

#endif // MYTHREAD2_H
