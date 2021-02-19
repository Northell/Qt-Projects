#include <QtWidgets>

//Листинг 25.1 класс HexLineEdit
/*
class HexLineEdit:public QLineEdit
{
public:
    HexLineEdit(QWidget* pwgt = 0):QLineEdit(pwgt)
    {
        QRegularExpression rxp("[0-9A-Fa-f]+");
        setValidator(new QRegularExpressionValidator(rxp,this));
    }
};
*/

//Листинг 25.2 Вызов методов sizeHunt()
/*
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;
    QString str = "Button";
    QPushButton* pcmd1 = new QPushButton(str);

    QSize size = pcmd1->sizeHint(); //size = (75,23)

    str = "this is very long button label";
    QPushButton* pcmd2 = new QPushButton(str);
    size = pcmd2->sizeHint();       //size = (145,23)
    QHBoxLayout* layout = new QHBoxLayout(&wgt);

    layout->addWidget(pcmd1);
    layout->addWidget(pcmd2);

    wgt.setLayout(layout);
    wgt.show();




    return a.exec();
}
*/

//Листинг 25.3 Создание собственного виджета индикатора выполнения

#include <QtWidgets>
#include "customwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget wgt;

    CustomWidget* pcw = new CustomWidget();
    QScrollBar* phsb  = new QScrollBar(Qt::Horizontal);

    phsb->setRange(0,100);

    QObject::connect(phsb, &QScrollBar::valueChanged,
            pcw, &CustomWidget::slotSetProgress);

    QVBoxLayout* layout = new QVBoxLayout(&wgt);

    layout->addWidget(pcw);
    layout->addWidget(phsb);

    wgt.setLayout(layout);
    wgt.show();




    return a.exec();
}
