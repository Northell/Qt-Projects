//Листинг 49.1 Класс, доступный JavaScript
//#include "myclass.h"
//#include "mywrapper.h"


//Листинг 49.4 Минимальная программа использования JavaScript
/*#include <QApplication>
#include <QtCore>
#include <QJSEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QJSEngine scriptEngine;
    QJSValue value = scriptEngine.evaluate("2*2");
    qDebug() << value.toInt();
    return a.exec();
}
*/

//Листинг 49.5 Виджет надписи, управляемый из языка сценариев

#include <QtWidgets>
#include <QJSEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel* plbl = new QLabel();

    QJSEngine scriptEngine;
    QJSValue scriptLbl = scriptEngine.newQObject(plbl);
    scriptEngine.globalObject().setProperty("lbl", scriptLbl);
    scriptEngine.evaluate("lbl.text = 'Hello, JavScript!'");
    scriptEngine.evaluate("lbl.show()");
    return a.exec();
}
