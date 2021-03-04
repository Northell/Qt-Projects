//Листинг 37.1-37.2 Программа мигающей надписи
/*
#include <QtWidgets>
#include "blinklabel.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BlinkLabel lbl("<FONT COLOR = BLUE><CENTER>Blink</CENTER></FONT>");

    lbl.show();
    return a.exec();
}*/


//Листинг 37.3 Завершение работы программы после 5 минут работы

/*
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QTimer::singleShot(5*60*1000, &a, SLOT(quit()));

    wgt.show();

    return a.exec();
}*/

//Листинг 37.4 Функция задержки
/*
#include <QtWidgets>

void delay(int n)
{
    QEventLoop loop;
    QTimer::singleShot(n, &loop, SLOT (quit()));
    loop.exec();                //Блокирует выполнение программы
}
*/

//Листинг 37.5 Программа реализации электронных часов
#include <QtWidgets>
#include "clock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Clock clock;

    clock.show();

    return a.exec();
}

