#include "mywrapper.h"

MyWrapper::MyWrapper(QObject *pobj):QObject(pobj)
{

}

void MyWrapper::setReadOnly(bool bReadOnly)
{
    m_nonQtObject.setReadOnly(bReadOnly);
    emit readOnlyStateChanged();
}

bool MyWrapper::isReadOnly() const
{
    return m_nonQtObject.isReadOnly();
}
