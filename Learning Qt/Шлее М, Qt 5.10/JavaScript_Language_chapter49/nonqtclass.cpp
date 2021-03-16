#include "nonqtclass.h"

NonQtClass::NonQtClass():m_bReadOnly(false)
{

}

void NonQtClass::setReadOnly(bool bReadOnly)
{
    m_bReadOnly = bReadOnly;
}

bool NonQtClass::isReadOnly() const
{
    return m_bReadOnly;
}
