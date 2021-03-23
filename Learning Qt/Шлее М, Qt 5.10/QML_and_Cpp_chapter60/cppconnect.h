#ifndef CPPCONNECT_H
#define CPPCONNECT_H

#include <QtCore>


class CppConnect:public QObject
{
    Q_OBJECT
public:
    CppConnect(QObject* pobj = 0);

public slots:
    void slotQuit();
    void slotInfo(const QString& str);
};

#endif // CPPCONNECT_H
