//В Qt6 не поддерживается, использую Qt 5.12.64bit
//Листинг 46.1 Программа показа веб-содержимого
/*
#include <QtWidgets>
#include <QtWebEngineWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWebEngineView webView;

    webView.load(QUrl("http://www.bhv.ru"));
    webView.show();

    return a.exec();
}
*/

#include <QtWidgets>
#include "webbrowser.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    WebBrowser web;
    web.show();

    return app.exec();
}
