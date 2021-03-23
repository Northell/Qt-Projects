#include "cppconnect.h"

CppConnect::CppConnect(QObject *pobj):QObject(pobj)
{

}

void CppConnect::slotQuit()
{
    qApp->quit();
}

void CppConnect::slotInfo(const QString& str)
{
    qDebug() << str;
}
