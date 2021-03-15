
//Листинг 45.1-45.3 Написание теста
/*
#include <QTest>
#include "test.h"

using namespace std;

int main(int argc, char** argv)
{
    freopen("testing.log", "w", stdout);
    QApplication app(argc,argv);
    QTest::qExec(new Test_MyClass, argc,argv);
    return 0;
}
*/

//Литсинг 45.9 Тестирование графических элементов
/*
#include <QtTest>
#include <QtWidgets>
#include "test_qlineedit.h"

int main(int argc, char** argv)
{
    freopen("testing.log","w",stdout);
    QApplication app(argc, argv);
    QTest::qExec(new Test_QLineEdit, argc,argv);
    return app.exec();

}
*/
