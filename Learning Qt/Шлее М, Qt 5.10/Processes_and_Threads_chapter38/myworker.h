#ifndef MYWORKER_H
#define MYWORKER_H

#include <QtWidgets>
class MyWorker:public QObject
{
    Q_OBJECT

private:
    int m_nValue;
    QTimer* m_pTimer;


public:
    MyWorker(QObject* pobj = 0);

signals:
    void valueChanged(int);
    void finished();

public slots:
    void slotDoWork();

private slots:
    void setNextValue();
};

#endif // MYWORKER_H
