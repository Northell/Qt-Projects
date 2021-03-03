
//Листинг 34.1 Использование панелей инструментов
/*
#include <QtWidgets>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow   wnd;

    wnd.show();

    return a.exec();
}
*/

//Листинг 34.2 Формирование строки состояния, отображающей актуальную позицию
//             указателя мыши
/*#include <QtWidgets>
#include "mainwindow2.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow2   wnd;

    wnd.show();

    return a.exec();
}*/


//Листинг 34.3 Создание окна заставки (Исправлено под Qt 6)
/*
#include <QtWidgets>

void loadModules (QSplashScreen* psplash)
{
    QTime time;
    time.currentTime();

    for(int i =0; i<100; ++i)
    {
        if(time.msec()>100)
        {
            time.currentTime();
        }


    psplash->showMessage("Loading modules"
                         + QString::number(i) + "%",
                         Qt::AlignCenter | Qt::AlignBottom,
                         Qt::black
                         );
    qApp->processEvents();
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen splash(QPixmap(":/RedGuy"));

    splash.show();

    QLabel lbl("<H1><CENTER>My Application <BR>"
               "Is ready!</CENTER><H1>"
              );

    loadModules(&splash);
    splash.finish(&lbl);
    lbl.resize(250,250);
    lbl.show();





    return a.exec();
}*/

//Листинг 34.4-34.9 Упрощенный вариант блокнота

//#include <QtWidgets>
//#include "sdiprogram.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    SDIProgram sdi;

//    sdi.show();



//    return a.exec();
//}

//Листинг 34.10.34.20 MDI приложения

#include <QtWidgets>
#include "mdiprogram.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MDIProgram sdi;

    sdi.show();



    return a.exec();
}
