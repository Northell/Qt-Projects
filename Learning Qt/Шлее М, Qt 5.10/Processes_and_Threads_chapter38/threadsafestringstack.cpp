#include "threadsafestringstack.h"

void ThreadSafeStringStack::push(const QString &str)
{
    m_mutex.lock();
    m_stackString.push(str);
    m_mutex.unlock();
}

QString ThreadSafeStringStack::pop()
{
    QMutexLocker locker(&m_mutex);
    return m_stackString.empty() ? QString() : m_stackString.pop();
}
