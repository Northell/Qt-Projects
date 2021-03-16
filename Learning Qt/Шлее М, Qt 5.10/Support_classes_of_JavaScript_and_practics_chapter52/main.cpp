//Листинг 52.1-52.6 "Черепашья графика"
/*
#include <QtWidgets>
#include "turtleworkarea.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TurtleWorkArea tWA;
    tWA.show();

    return a.exec();
}
*/

//Листинг 52.7-52.8 Программа для демонстрации соединения сигнала разными способами
/*
#include <QtWidgets>
#include <QJSEngine>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* pwgt = new QWidget();

    QLineEdit* ptxt = new QLineEdit();
    ptxt->setObjectName("lineedit");

    QLabel* plbl1 = new QLabel("1");
    plbl1->setObjectName("label1");

    QLabel* plbl2 = new QLabel("2");
    plbl2->setObjectName("label2");

    QLabel* plbl3 = new QLabel("3");
    plbl3->setObjectName("label3");

    QLabel* plbl4 = new QLabel("4");
    plbl4->setObjectName("label4");

    //layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(ptxt);
    layout->addWidget(plbl1);
    layout->addWidget(plbl2);
    layout->addWidget(plbl3);
    layout->addWidget(plbl4);

    pwgt->setLayout(layout);

    //Script part
    QJSEngine se;
    QFile file(":/script.js");
    if(file.open(QFile::ReadOnly))
    {
        QJSValue sw = se.newQObject(pwgt);
        se.globalObject().setProperty("wgt", sw);
        QList<QObject*> lst = pwgt->findChildren<QObject*>();
        foreach(QObject* pobj, lst)
        {
            sw = se.newQObject(pobj);
            se.globalObject().setProperty(pobj->objectName(),sw);
        }

        QJSValue result = se.evaluate(QLatin1String(file.readAll()));
        if(result.isError())
        {
            QMessageBox::critical(0, "Evaluaing error", result.toString(), QMessageBox::Yes);

        }
    }
    else
    {
        QMessageBox::critical(0,"File open error", "Can not open the script file", QMessageBox::Yes);
    }


    pwgt->show();
    return a.exec();
}
*/


//Листинг 52.9 Полезные функции для JavaScript

#include <QtWidgets>
#include <QJSEngine>
#include "jstools.h"

int main(int argc, char** argv)
{
    QApplication app(argc,argv);
    QWidget* wgt = new QWidget();

    QPushButton* pcmdFiles = new QPushButton("Show Files");
    pcmdFiles->setObjectName("cmdFiles");

    QPushButton* pcmdQuit = new QPushButton("Quit");
    pcmdQuit->setObjectName("cmdQuit");

    //layout
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(pcmdFiles);
    layout->addWidget(pcmdQuit);
    wgt->setLayout(layout);
    wgt->show();

    //script part
    QJSEngine se;
    QFile file(":/script1.js");
    if(file.open(QFile::ReadOnly))
    {
        QJSValue sw =se.newQObject(wgt);
        se.globalObject().setProperty("wgt",sw);
        QList<QObject*> lst = wgt->findChildren<QObject*>();
        foreach(QObject* pobj, lst)
        {
            sw = se.newQObject(pobj);
            se.globalObject().setProperty(pobj->objectName(), sw);
        }
        JsTools* pjt = new JsTools();
        sw = se.newQObject(pjt);
        QString strClassName = pjt->metaObject()->className();
        se.globalObject().setProperty(strClassName, sw);

        QJSValue result = se.evaluate(QLatin1String(file.readAll()));
        if(result.isError())
        {
            QMessageBox::critical(0,"evaulatuing error", result.toString(), QMessageBox::Yes);
        }
    }
    else
    {
        QMessageBox::critical(0, "File open err"," Can not open the script file", QMessageBox::Yes);
    }
    return app.exec();
}
