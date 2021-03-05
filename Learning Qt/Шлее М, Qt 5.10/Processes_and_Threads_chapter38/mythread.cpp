#include "mythread.h"

void MyThread::run()
{
    for(int i = 0; i<=100; ++i)
    {
        usleep(100000);
        emit progress(i);
    }
}


