#ifndef THREADSAFESTRINGSTACK_H
#define THREADSAFESTRINGSTACK_H

#include <QMutex>
#include <QStack>
class ThreadSafeStringStack
{
private:
    QMutex          m_mutex;
    QStack<QString> m_stackString;
public:
    void push(const QString& str);
    QString pop();


};

#endif // THREADSAFESTRINGSTACK_H
