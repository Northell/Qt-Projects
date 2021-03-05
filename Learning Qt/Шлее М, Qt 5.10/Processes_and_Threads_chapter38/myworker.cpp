#include "myworker.h"

MyWorker::MyWorker(QObject *pobj):QObject(pobj), m_nValue(10)
{
    m_pTimer = new QTimer(this);
    connect(m_pTimer, &QTimer::timeout, this, &MyWorker::setNextValue);
}

void MyWorker::slotDoWork()
{
    m_pTimer->start(1000);

}

void MyWorker::setNextValue()
{
    emit valueChanged(--m_nValue);
    if(!m_nValue)
    {
        m_pTimer->stop();
        emit finished();
    }
}
