//Листинг 2.10

#include "counter.h"

Counter::Counter():QObject(), m_nValue(0)
{

}


void Counter::slotInc()
{
    emit counterChanged(++m_nValue);

    if (m_nValue ==5)
    {
        emit goodbye();
    }
}
