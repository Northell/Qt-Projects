
//Листинг 26.1 Пример отображения виджетов с различными стилями

/*#include <QtWidgets>

QWidget* styledWidget(QStyle* pstyle)
{
    QGroupBox*      pgr = new QGroupBox(pstyle->metaObject()->className());
    QScrollBar*     psbr = new QScrollBar(Qt::Horizontal);
    QCheckBox*      pchk = new QCheckBox("&Check Box");
    QSlider*        psld = new QSlider(Qt::Horizontal);
    QRadioButton*   prad = new QRadioButton("Radio button");
    QPushButton*    pcmd = new QPushButton("Push button");

    //layout
    QVBoxLayout* layout = new QVBoxLayout();

    layout->addWidget(psbr);
    layout->addWidget(pchk);
    layout->addWidget(psld);
    layout->addWidget(prad);
    layout->addWidget(pcmd);

    pgr->setLayout(layout);

    QList<QWidget*> pwgtList = pgr->findChildren<QWidget*>();
    foreach(QWidget* pwgt, pwgtList)
    {
        pwgt->setStyle(pstyle);
    }
    return pgr;

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget      wgt;

    //layout
    QHBoxLayout* layout = new QHBoxLayout();
    foreach(QString str, QStyleFactory::keys())
    {
        layout->addWidget(styledWidget(QStyleFactory::create(str)));
    }
    wgt.setLayout(layout);
    wgt.show();


    return a.exec();
}
*/

//Листинг 26.2 Изменение стиля для всего приложения
// в Qt6 не робит?
/*
#include <QApplication>
#include "myapplication.h"

int main( int argc, char**argv)
{
    QApplication app(argc,argv);
    MyApplication myApp;
    myApp.show();

    return app.exec();
}

*/


//Листинг 26.5-26.9 Стиль, изменяющий вид кнопки
/*
#include <QtWidgets>
#include "customstyle.h"

int main( int argc, char**argv)
{
    QApplication app(argc,argv);
    QWidget      wgt;

    QPushButton* pcmdA = new QPushButton("Button 1");
    QPushButton* pcmdB = new QPushButton("Button 2");
    QPushButton* pcmdC = new QPushButton("Button 3");

    //layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(pcmdA);
    layout->addWidget(pcmdB);
    layout->addWidget(pcmdC);

    wgt.setLayout(layout);
    app.setStyle(new CustomStyle);  //Ставим свой стиль
    wgt.show();


    return app.exec();
}
*/


//Листинг 26.10- 26.16 Реализация собственного стиля через CSS
#include <QtWidgets>


int main( int argc, char**argv)
{
    QApplication app(argc,argv);
    QWidget      wgt;

    QPushButton* pcmdA = new QPushButton("Button 1");
    QPushButton* pcmdB = new QPushButton("Button 2");
    QPushButton* pcmdC = new QPushButton("Button 3");

    //layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(pcmdA);
    layout->addWidget(pcmdB);
    layout->addWidget(pcmdC);

    wgt.setLayout(layout);

    QFile file (":/style.qss");
    file.open(QFile::ReadOnly);
    QString strCSS = QLatin1String(file.readAll());

    qApp->setStyleSheet(strCSS);
    wgt.show();


    return app.exec();
}

