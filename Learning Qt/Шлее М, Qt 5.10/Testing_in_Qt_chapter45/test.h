#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "myclass.h"
// ======================================================================
class Test_MyClass : public QObject {
Q_OBJECT
private slots:

    void min_data();
    void max_data();

    void min();
    void max();
};




#endif // TEST_H
