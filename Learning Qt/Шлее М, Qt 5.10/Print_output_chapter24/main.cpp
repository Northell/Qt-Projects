
//Листинг 24.1-24.7 Вывод на печать картинки
#include <QtWidgets>
#include "printer.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    Printer* pprinter = new Printer();
    QPushButton* pcmd = new QPushButton("&Print");

    QObject::connect(pcmd, &QPushButton::clicked,
                     pprinter, &Printer::slotPrint);

    //Layout setup
    QVBoxLayout* pvbxLayout = new QVBoxLayout();

    pvbxLayout->setContentsMargins(0,0,0,0);

    pvbxLayout->setSpacing(0);
    pvbxLayout->addWidget(pprinter);
    pvbxLayout->addWidget(pcmd);

    wgt.setLayout(pvbxLayout);
    wgt.resize(250,320);
    wgt.show();


    return a.exec();
}
