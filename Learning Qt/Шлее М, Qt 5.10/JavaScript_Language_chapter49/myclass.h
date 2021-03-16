#ifndef MYCLASS_H
#define MYCLASS_H

#include <QtWidgets>

class MyClass:public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool readOnly READ isReadOnly WRITE setReadOnly)

private:
    bool m_bReadOnly;

public:
    MyClass(QObject* pobj=0);

public slots:
    void setReadOnly(bool bReadOnly);
    bool isReadOnly() const;

signals:
    void readOnlyStateChanged();
};

#endif // MYCLASS_H
