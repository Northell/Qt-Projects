//Листинг 7.1 Создание виджета надписи с использованием формата HTML
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
   QApplication app(argc, argv);
   QPixmap pix(":/Image1.png");
    QLabel lbl ("<H1><CENTER>QLabel - HTML Demo </CENTER></H1>"
                "<H2><CENTER>Image</CENTER></H2>"
                "<CENTER><IMG BORDER =\"0\" SRC = \":/Image1.png\"></CENTER>"
                "<H2><CENTER>List </CENTER></H2>"
                "<Ol><LI>One   </LI>"
                "    <LI>Two   </LI>"
                "    <LI>Three </LI>"
                "</OL>"
                "<H2><CENTER>Font Style</CENTER></H2>"
                "<CENTER><FONT COLOR = RED>"
                "<B>Bold</B>, <I>Italic</I>, <U>Underline</U>"
                "</FONT></CENTER>"
                "<H2><CENTER>Table</CENTER></H2>"
                "<CENTER><TABLE>"
                "   <TR BGCOLOR = #ff00ff>"
                "       <TD>1,1</TD><TD>1,2</TD><TD>1,3</TD><TD>1,4</TD>"
                "   </TR>"
                "   <TR BGCOLOR = YELLOW>"
                "       <TD>2,1</TD><TD>2,2</TD><TD>2,3</TD><TD>2,4</TD>"
                "   </TR>"
                "   <TR BGCOLOR = #00f000>"
                "       <TD>3,1</TD><TD>3,2</TD><TD>3,3</TD><TD>3,4</TD>"
                "   </TR>"
                "</TABLE></CENTER>"
                );

    lbl.show();


    return app.exec();
}*/

//Листинг 7.2 Создание виджета надписи без использования формата HTMl
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    QPixmap pix;
    pix.load(":/Image1.png");

    QLabel lbl;

    lbl.resize(pix.size());
    lbl.setPixmap(pix);

    lbl.show();

    return app.exec();
}*/


//Листинг 7.3 Определение в тексте виджета символов быстрого доступа с помощью знака &
/*
#include <QtWidgets>

int main(int argc, char**argv)
{
    QApplication app(argc, argv);


    QWidget wgt;
    QLabel* plbName = new QLabel("&Name:");
    QLineEdit* ptxtName = new QLineEdit();
    plbName->setBuddy(ptxtName);

    QLabel* plbAge = new QLabel("&Age:");
    QSpinBox* pspbAge = new QSpinBox();
    plbAge->setBuddy(pspbAge);

    //LayOutSetup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(plbName);
    pvbxLayout->addWidget(ptxtName);
    pvbxLayout->addWidget(plbAge);
    pvbxLayout->addWidget(pspbAge);

    wgt.setLayout(pvbxLayout);
    wgt.show();
    return app.exec();
}
*/

//Листинг 7.4-7.6 Создание индикатора выполнения
/*
#include <QApplication>
#include "progress.h"

int main(int argc, char**argv)
{
    QApplication app(argc,argv);
    Progress progress;

    progress.show();
    return app.exec();
}*/
/*
#include <QtWidgets>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QWidget     wgt;
    QLCDNumber* plcd = new QLCDNumber;
    QSpinBox*   pspb = new QSpinBox;

    plcd->setSegmentStyle(QLCDNumber::Filled);
    plcd->setMode(QLCDNumber::Hex);

    pspb->setFixedHeight(30);
    pspb->setMaximum(999999);

    QObject::connect(pspb, SIGNAL(valueChanged(int)),
                     plcd, SLOT (display(int))
                                  );

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();
    pvbxLayout->addWidget(plcd);
    pvbxLayout->addWidget(pspb);

    wgt.setLayout(pvbxLayout);
    wgt.resize(250,150);

    wgt.show();
    return app.exec();

}*/

