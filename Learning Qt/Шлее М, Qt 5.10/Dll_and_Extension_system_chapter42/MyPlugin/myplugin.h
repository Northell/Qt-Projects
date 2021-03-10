#ifndef MYPLUGIN_H
#define MYPLUGIN_H

#include "MyPlugin_global.h"

#include <QObject>
#include <QCoreApplication>
#include "../other_chapter42/interfaces.h"

class MYPLUGIN_EXPORT MyPlugin:public QObject, public StringInterface
{
    Q_OBJECT
    Q_INTERFACES(StringInterface)
    Q_PLUGIN_METADATA(IID "com.mysoft.Application.StringInterface" FILE "stringinterface.json")

private:
    QString oddUpper (const QString& str);

public:
    virtual ~MyPlugin();
    virtual QStringList operations() const;
    virtual QString     operation(const QString&, const QString&);
};

#endif // MYPLUGIN_H
