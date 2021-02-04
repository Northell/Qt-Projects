//Листинг 6.1, 6.2 Добавление виджетов в компоновку с указанием в дополнительном
//                 параметре фатора растяжения,
//                 Вместо одной из кнопок добавляется фактор растяжения
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");

    //Ставим слой
    QBoxLayout* pbxLayout = new QBoxLayout(QBoxLayout::LeftToRight);
    pbxLayout->addWidget(pcmdA, 1);
    pbxLayout->addWidget(pcmdB, 2); //второе значение параметра - фактор растяжения виджета относительно других
   // pbxLayout->addStretch(3);       //фактор растяжения, установленный ручками (6.2
    pbxLayout->addWidget(pcmdC, 3);

    wgt.setLayout(pbxLayout);

    wgt.resize(450,40);
    wgt.show();


    return app.exec();
}
*/

//Листинг 6.3 Упорядочивание виджетов при помощи объекта класса QHBoxLayout
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");

    //Ставим слой
    QHBoxLayout* phbxLayout = new QHBoxLayout();
    phbxLayout->setContentsMargins(10, 10, 10, 10); //Тощина рамки
    phbxLayout->setSpacing(20);                     //Пространство между виджетами
    phbxLayout->addWidget(pcmdA, 1);
    phbxLayout->addWidget(pcmdB, 2);                //второе значение параметра - фактор растяжения виджета относительно других
   // pbxLayout->addStretch(3);                     //фактор растяжения, установленный ручками (6.2
    phbxLayout->addWidget(pcmdC, 3);

    wgt.setLayout(phbxLayout);

    wgt.resize(450,40);
    wgt.show();


    return app.exec();
}
*/

//Листинг 6.4 Вложенное размещение двух менеджеров компоновки
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QWidget wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");
    QPushButton* pcmdD = new QPushButton("D");


    //Ставим слой
    QHBoxLayout* pHbxLayout = new QHBoxLayout();
    QVBoxLayout* pVbxLayout = new QVBoxLayout();

    pHbxLayout->setContentsMargins(5, 5, 5, 5);
    pHbxLayout->setSpacing(15);
    pHbxLayout->addWidget(pcmdC);
    pHbxLayout->addWidget(pcmdD);

    pVbxLayout->setContentsMargins(5, 5, 5, 5);
    pVbxLayout->setSpacing(15);
    pVbxLayout->addWidget(pcmdA);
    pVbxLayout->addWidget(pcmdB);
    pVbxLayout->addLayout(pHbxLayout);  //Добавляем горизонтальный лэйаут


    wgt.setLayout(pVbxLayout);
    wgt.show();


    return app.exec();
}*/

//Листинг 6.5 Размещение кнопок в табличном порядке
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget      wgt;

    QPushButton* pcmdA = new QPushButton("A");
    QPushButton* pcmdB = new QPushButton("B");
    QPushButton* pcmdC = new QPushButton("C");
    QPushButton* pcmdD = new QPushButton("D");

    QGridLayout* pgrdLayout = new QGridLayout();
    pgrdLayout->setContentsMargins(5,5,5,5);
    pgrdLayout->setSpacing(25);

    pgrdLayout->addWidget(pcmdA,0,0);       //Тут посление два параметра - координаты ячейки сетки
    pgrdLayout->addWidget(pcmdB,0,1);       //Размер таблицы динамический
    pgrdLayout->addWidget(pcmdC,1,0);
    pgrdLayout->addWidget(pcmdD,1,1);

    wgt.setLayout(pgrdLayout);
    wgt.show();



    return app.exec();
}
*/


//Листинг 6.6 - 6.11 Пилим калькулятор с помощью сетки
/*#include <QApplication>
#include "calculator.h"

int main(int argc, char** argv)
{
    QApplication app (argc,argv);
    Calculator calc;

    calc.setWindowTitle("Calculatior");
    calc.resize(230,200);

    calc.show();
    return app.exec();
}
*/

//листинг 6.12 Создание виджета вертикального разделителя
/*#include <QtWidgets>

int main(int argc, char** argv) {

    QApplication app(argc, argv);
    //QSplitter sp1(Qt::Vertical);
    QSplitter sp1(Qt::Horizontal);
    QTextEdit* ptxt1 = new QTextEdit();
    QTextEdit* ptxt2 = new QTextEdit();

    sp1.addWidget(ptxt1);
    sp1.addWidget(ptxt2);

    ptxt1->setPlainText("Line1\n"
                        "Line2\n"
                        "Line3\n"
                        "Line4\n"
                        "Line5\n"
                        "Line6\n"
                        "Line7\n"
                       );

    ptxt2->setPlainText(ptxt1->toPlainText());
    sp1.resize(200, 220);
    sp1.show();

    return app.exec();
}
*/
