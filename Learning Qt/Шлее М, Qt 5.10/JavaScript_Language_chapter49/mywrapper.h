#ifndef MYWRAPPER_H
#define MYWRAPPER_H

#include "nonqtclass.h"
#include <QtWidgets>

class MyWrapper:public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool readOnly READ isReadOnly WRITE setReadOnly )

private:
    NonQtClass m_nonQtObject;

public:
    MyWrapper(QObject* pobj =0);

public slots:
    void setReadOnly(bool bReadOnly);
    bool isReadOnly() const;

signals:
    void readOnlyStateChanged();

};

#endif // MYWRAPPER_H
