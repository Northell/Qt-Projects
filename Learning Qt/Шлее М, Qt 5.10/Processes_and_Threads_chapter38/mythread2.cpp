#include "mythread2.h"

MyThread2::MyThread2(QObject *pobjRecceiver):m_pobjReceiver(pobjRecceiver)
{

}

void MyThread2::run()
{
    for (int i = 0; i <= 100; ++i)
    {
        usleep(100000);

        ProgressEvent* pe = new ProgressEvent;
        pe->setValue(i);
        QApplication::postEvent(m_pobjReceiver, pe);
    }

}
