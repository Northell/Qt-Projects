//Листинг 35.1-35.7 Виджет из области уведомлений

/*
#include <QtWidgets>
#include "systemtray.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemTray   st;

    QApplication::setQuitOnLastWindowClosed(false);
    return a.exec();
}*/


#include <QtWidgets>
#include "grabwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GrabWidget   wgt;

    wgt.show();
    return a.exec();
}
