/*Подключиться к бд postgres, обработать скрипт, вывести в приложение результат.
  Найти ячейки с типом Equipment, закраить найденную строку в какой-нибудь цвет*/

#include <QtWidgets>
#include "mainwindow.h"



int main(int argc, char *argv[])
{

   QApplication app (argc,argv);
   QWidget wgt;
   MainWindow *window = new MainWindow(&wgt);
   wgt.resize(window->size());
   wgt.show();





   return app.exec();

}
