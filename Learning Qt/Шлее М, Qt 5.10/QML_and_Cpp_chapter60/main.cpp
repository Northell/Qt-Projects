//Листинг 60.1-60.3 Hello QML (не робит)

//#include <QApplication>
//#include "mywidget.h"

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);

//    MyWidget wgt;

//    wgt.show();
//    return a.exec();
//}

//Листинг 60.4-60.6 Соединение QML-сигналов со слотами
//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include <QQmlComponent>
//#include "cppconnect.h"

//int main(int argc, char** argv)
//{
//    QGuiApplication app(argc,argv);
//    QQmlApplicationEngine eng;
//    QQmlComponent comp(&eng, ":/main");
//    CppConnect cc;
//    QObject* pobj = comp.create();
//    QObject* pcmdQuitButton = pobj->findChild<QObject*>("QuitButton");
//    if (pcmdQuitButton)
//    {
//        QObject::connect(pcmdQuitButton, SIGNAL (quitClicked()),
//                         &cc, SLOT(slotQuit()));
//    }
//    QObject* pcmdInfoButton = pobj->findChild<QObject*>("InfoButton");
//    if(pcmdInfoButton)
//    {
//        QObject::connect(pcmdInfoButton,SIGNAL (infoClicked(QString)),
//                         &cc, SLOT(slotInfo(QString)));

//    }
//    return app.exec();

//}

//Листинг 60.7-60.8 Публикация объектов Qt (так же не робит, как 60.1)
//#include <QApplication>
//#include "mywidget1.h"

//int main(int argc, char** argv)
//{
//    QApplication app(argc, argv);
//    MyWidget1 wgt;
//    wgt.show();
//    return app.exec();
//}

//Листинг 60.9- 60.13 Вычисление факториала
//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include "calculation.h"

//int main(int argc, char** argv)
//{
//    QGuiApplication app(argc, argv);
//    qmlRegisterType<Calculation> ("com.myinc.Calculation" , 1, 0, "Calculation");

//    QQmlApplicationEngine engine;
//    engine.load(":/main");
//    return app.exec();
//}

//Листинг 60.14-60.17 Ellipse
//#include <QGuiApplication>
//#include <QQmlApplicationEngine>
//#include "ellipse.h"

//int main(int argc, char** argv)
//{
//    QGuiApplication app(argc,argv);

//    qmlRegisterType<EEllipse>("com.myinc.Ellipse", 1, 0, "Ellipse");

//    QQmlApplicationEngine engine;
//    engine.load(":/main");
//    return app.exec();
//}

//Листинг 60.18-
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "imageprovider.h"

int main(int argc, char** argv)
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine eng;
    eng.addImageProvider(QLatin1String("brightness"), new ImageProvider);
    eng.load(":/main");
    return app.exec();
}
