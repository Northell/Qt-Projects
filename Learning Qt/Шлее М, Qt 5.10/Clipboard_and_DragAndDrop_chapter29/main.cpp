
//Листинг 29.1-29.3 Реализация Drag and Drop

/*#include <QtWidgets>
#include "drag.h"
#include "drop.h"
#include "mydragclass.h" //29.3 Тут, собственный тип перетаскивания, пример

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Drag* drag = new Drag();    //29.1
    Drop drop;                  //29.2


    drop.resize(200,200);

    drag->show();
    drop.show();



    delete drag;
    return a.exec();
}*/

//Листинг 29.4-29.13 Создание двух виджетов, которые могут общаться между собой методом drag&drop(внешние перетаскивания запрещены)
#include <QApplication>
#include "widget.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    Widget wgt1;
    Widget wgt2;

    wgt1.setWindowTitle("Widget1");
    wgt1.setObjectName("Widget1");
    wgt1.resize(200,200);
    wgt1.show();

    wgt2.setWindowTitle("Widget2");
    wgt2.setObjectName("Widget2");
    wgt2.resize(200,200);
    wgt2.show();

    return app.exec();
}
