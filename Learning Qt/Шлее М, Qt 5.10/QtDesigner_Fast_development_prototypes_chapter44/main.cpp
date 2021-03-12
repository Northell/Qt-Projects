//Листинг 44.1 Прямой способ использования формы в проекте
/*
#include <QtWidgets>
#include "ui_MyForm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* form = new QWidget();

    Ui::Form ui;
    ui.setupUi(form);

    form->show();
    return a.exec();
}
*/

//Листинг 44.2 Использование формы при помощи наследования
/*
#include <QApplication>
#include "myform1.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyForm1 form;
    form.show();


    return a.exec();
}
*/

//Листинг 44.3. Множественное наследование при использовании дизайна формы
/*#include "myform2.h"
#include <QApplication>

int main(int argc,char** argv)
{
    QApplication a(argc, argv);

    MyForm my;
    my.show();

    return a.exec();
}
*/


//Листинг 44.4-44.6 Динамическая загрузка формы

#include <QtWidgets>
#include "loadmyform.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoadMyForm form;
    form.show();


    return a.exec();
}
