#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QtWidgets>
#include <QThread>

class MyThread:public QThread
{
    Q_OBJECT
public:
    void run();

signals:
    void progress(int);
};

#endif // MYTHREAD_H
