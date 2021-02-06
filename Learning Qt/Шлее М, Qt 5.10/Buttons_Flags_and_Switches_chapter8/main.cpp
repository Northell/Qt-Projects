//Листинг 8.1 Создание кнопок
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    QPushButton* pcmdNormal = new QPushButton("&Normal Button");

    QPushButton* pcmdToggle = new QPushButton("&Toggle Button");
    pcmdToggle->setCheckable(true);
    pcmdToggle->setChecked(true);

    QPushButton* pcmdFlat = new QPushButton("&Flat Button");
    pcmdFlat->setFlat(true);

    QPixmap pix(":/Image1.png");
    QPushButton* pcmdPix = new QPushButton("&Pixmap Button");
    pcmdPix->setIcon(pix);
    pcmdPix->setIconSize(pix.size());

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(pcmdNormal);
    pvbxLayout->addWidget(pcmdToggle);
    pvbxLayout->addWidget(pcmdFlat);
    pvbxLayout->addWidget(pcmdPix);

    wgt.setLayout(pvbxLayout);
    //мой код
    wgt.setWindowIcon(pix); //Тут ставится иконка приложения
    //============

    wgt.show();
    return a.exec();
}
*/
//Листинг 8.2 Создание кнопки со всплывающим меню
/*
#include <QtWidgets>

int main (int argc, char** argv)
{
    QApplication app(argc,argv);

    QPushButton cmd("Menu");
    QMenu*      pmnu = new QMenu(&cmd);
    pmnu->addAction("Item1");
    pmnu->addAction("Item2");
    pmnu->addAction("&Quit", &app, SLOT (quit()));

    cmd.setMenu(pmnu);
    cmd.show();

    return app.exec();



}
*/

//Листинг 8.3 Создание флажков
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget      wgt;

    QCheckBox* pchkNormal = new QCheckBox("&Normal Check Box");
    pchkNormal->setChecked(true);

    QCheckBox* pchkTristate = new QCheckBox("&Tristate Check Box");
    pchkTristate->setTristate(true);
    pchkTristate->setCheckState(Qt::PartiallyChecked);

   //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(pchkNormal);
    pvbxLayout->addWidget(pchkTristate);

    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}*/

//Листинг 8.4 Создание виджета для группы переключателей
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget      wgt;

    QRadioButton* pradRed = new QRadioButton("Red");
    QRadioButton* pradGreen = new QRadioButton("Green");
    QRadioButton* pradBlue = new QRadioButton("Blue");

    pradBlue->setChecked(true);

   //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(pradRed);
    pvbxLayout->addWidget(pradGreen);
    pvbxLayout->addWidget(pradBlue);

    wgt.setLayout(pvbxLayout);
    wgt.show();

    return app.exec();
}
*/

//Листинг 8.5-8.8 Создание группы переключателей
/*
#include <QApplication>
#include "buttons.h"

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    Buttons but;
    but.show();

    return app.exec();

}
*/
