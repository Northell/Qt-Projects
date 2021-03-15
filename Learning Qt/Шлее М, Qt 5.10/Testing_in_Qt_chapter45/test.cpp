#include "test.h"

// ----------------------------------------------------------------------
void Test_MyClass::min_data()
{
    QTest::addColumn<int>("arg1");
    QTest::addColumn<int>("arg2");
    QTest::addColumn<int>("result");

    QTest::newRow("min_test1") << 25<<1<<1;
    QTest::newRow("min_test2") << -12<<0<<-12;
    QTest::newRow("min_test3") << 0<<0<<0;
    QTest::newRow("min_test4") << 4<<5<<4;

}

void Test_MyClass::max_data()
{
    QTest::addColumn<int>("arg1");
    QTest::addColumn<int>("arg2");
    QTest::addColumn<int>("result");

    QTest::newRow("min_test1") << 25<<1<<25;
    QTest::newRow("min_test2") << -12<<0<<0;
    QTest::newRow("min_test3") << 0<<0<<0;
    QTest::newRow("min_test4") << 4<<5<<5;
}

void Test_MyClass::min()
{
    //45.1
//    MyClass myClass;
//    QCOMPARE(myClass.min(25, 0), 0);
//    QCOMPARE(myClass.min(-12, -5), -12);
//    QCOMPARE(myClass.min(2007, 2007), 2007);
//    QCOMPARE(myClass.min(-12, 5), -12);

    //45.2
    MyClass myClass;
    QFETCH(int,arg1);
    QFETCH(int,arg2);
    QFETCH(int,result);
    QCOMPARE(myClass.min(arg1,arg2),result);
}

// ----------------------------------------------------------------------
void Test_MyClass::max()
{
    //45.1
//    MyClass myClass;
//    QCOMPARE(myClass.max(25, 0), 25);
//    QCOMPARE(myClass.max(-12, -5), -5);
//    QCOMPARE(myClass.max(2007, 2007), 2007);
//    QCOMPARE(myClass.max(-12, 5), 5);

    //45.2
    MyClass myClass;
    QFETCH(int,arg1);
    QFETCH(int,arg2);
    QFETCH(int,result);
    QCOMPARE(myClass.max(arg1,arg2),result);

}
