#include "myclass.h"



MyClass::MyClass(QObject *pobj):QObject(pobj), m_bReadOnly(false)
{

}

void MyClass::setReadOnly(bool bReadOnly)
{
    m_bReadOnly = bReadOnly;
    emit readOnlyStateChanged();
}

bool MyClass::isReadOnly() const
{
    return m_bReadOnly;
}
