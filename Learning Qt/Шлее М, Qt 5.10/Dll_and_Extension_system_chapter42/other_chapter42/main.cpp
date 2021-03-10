//Листинг 42.5-42.7 Хз как делать, автор, видимо, покурил что-то запрещенное.
//                  Релизация в customstyleplugin.h и cpp без изменений

//#include <QStyleFactory>
//#include <QApplication>
//void main()
//{
//    QApplication::setStyle(QStyleFactory::create("CustomStyle"));
//}


#include <QCoreApplication>
#include "pluginswindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    PluginsWIndow wnd;
    wnd.show();

    return a.exec();
}
