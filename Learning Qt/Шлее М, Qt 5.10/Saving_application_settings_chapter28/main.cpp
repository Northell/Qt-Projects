

//Листинг 28.1-28.8 Создание виджета класса MyРrogram
/*
#include <QtWidgets>
#include "myprogram.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyProgram mP;

    mP.show();



    return a.exec();
}
*/

//Листинг 28.9 Пример для централизованного использования объекта настроек

#include <QtWidgets>
#include "app.h"

int main(int argc, char *argv[])
{
    App app(argc,argv,"MyCompany","MyApp");

    QSettings* pst = App::theApp()->settings();
    //pst->setValue("Language", "en");
    qDebug() << pst->value("Language").toString();



    return app.exec();
}
