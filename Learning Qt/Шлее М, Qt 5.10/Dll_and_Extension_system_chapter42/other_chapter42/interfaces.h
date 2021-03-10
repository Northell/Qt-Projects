#pragma once


#include<QString>
#include <QStringList>
#include <QtPlugin>

class StringInterface
{


public:
    virtual ~StringInterface() {}
    virtual QStringList operations() const = 0;
    virtual QString operation(const QString& strText,
                              const QString& strOperatuib) =0;

};


Q_DECLARE_INTERFACE (StringInterface, "com.mysoft.Application.StringInterface")
