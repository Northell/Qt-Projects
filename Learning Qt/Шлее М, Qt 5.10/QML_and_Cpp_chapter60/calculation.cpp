#include "calculation.h"

Calculation::Calculation(QObject *pobj): QObject(pobj)
                                       , m_nInput(0)
                                       , m_nResult(1)
{

}

qulonglong Calculation::factorial(const qulonglong &n)
{
    return n? (n*factorial(n-1)) : 1;
}

qulonglong Calculation::inputValue() const
{
    return m_nInput;
}

void Calculation::setInputValue(const qulonglong & n)
{
    m_nInput = n;
    m_nResult = factorial(m_nInput);

    emit inputValueChanged(m_nInput);
    emit resultValueChanged(m_nResult);
}

qulonglong Calculation::resultValue() const
{
    return m_nResult;
}
