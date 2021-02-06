//Листинг 9.1 Создание ползунка
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    QSlider* psld = new QSlider(Qt::Horizontal);
    QLabel*  plbl = new QLabel("3");

    psld->setRange(0,9);
    psld->setPageStep(2);
    psld->setValue(3);
    psld->setTickInterval(2);
    psld->setTickPosition(QSlider::TicksBelow);

    QObject::connect(psld, SIGNAL(valueChanged(int)),
                     plbl, SLOT (setNum(int))
                     );

    //Layout setup
    QHBoxLayout* phbxLayout = new QHBoxLayout();

    phbxLayout->addWidget(psld);
    phbxLayout->addWidget(plbl);

    wgt.setLayout(phbxLayout);

    wgt.show();


    return a.exec();
}
*/

//Листинг 9.2 Создание электронного индикатора и полосы прокрутки
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

   QLCDNumber* plcd = new QLCDNumber(4);
   QScrollBar* phsb = new QScrollBar(Qt::Horizontal);

    QObject::connect(phsb, SIGNAL(valueChanged(int)),
                     plcd, SLOT (display(int))
                     );

    //Layout setup
    QVBoxLayout* phbxLayout = new QVBoxLayout();

    phbxLayout->addWidget(plcd);
    phbxLayout->addWidget(phsb);

    wgt.setLayout(phbxLayout);

    wgt.resize(250,150);
    wgt.show();


    return a.exec();
}*/

//Листинг 9.3 Создание установщика и индикатора выполнения
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    QDial*       pdia = new QDial();
    QProgressBar* pprb = new QProgressBar();

    pdia->setRange(0,100);
    pdia->setNotchTarget(5);    //шаг рисок
    pdia->setNotchesVisible(true);  //делает риски видимыми


    QObject::connect(pdia, SIGNAL(valueChanged(int)),
                     pprb, SLOT (setValue(int))
                     );

    //Layout setyp
    QVBoxLayout* phbxLayout = new QVBoxLayout();

    phbxLayout->addWidget(pdia);
    phbxLayout->addWidget(pprb);

    wgt.setLayout(phbxLayout);
    wgt.resize(180,200);

    wgt.show();


    return a.exec();
}*/
