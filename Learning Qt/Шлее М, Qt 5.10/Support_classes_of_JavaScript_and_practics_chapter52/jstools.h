#ifndef JSTOOLS_H
#define JSTOOLS_H

#include <QtWidgets>

class JsTools:public QObject
{
    Q_OBJECT

public:
    JsTools(QObject* pobj = 0);

public slots:
    void print(const QString& str);
    void alert(const QString& strMessage);
    void quitApplication();
    QStringList dirEntryList( const QString& strDir, const QString& strExt);

};

#endif // JSTOOLS_H
