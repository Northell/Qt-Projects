//Листинг 38.1 Простейшая командная оболочка
//Работоспособность в Qt6?
/*
#include <QtWidgets>
#include "shell.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Shell wgt;
    wgt.show();

    return a.exec();
}
*/
//Листинг 38.2-38.4 Реализация таймера через потоки
/*
#include <QtWidgets>
#include "myworker.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLCDNumber   lcd;
    QThread      thread;
    MyWorker     worker;

    QObject::connect(&worker, SIGNAL(valueChanged(int)), &lcd, SLOT(display(int)));

    lcd.setSegmentStyle(QLCDNumber::Filled);
    lcd.display(10);
    lcd.resize(220,90);
    lcd.show();

    worker.moveToThread(&thread);
    QObject::connect(&thread, SIGNAL (started()), &worker, SLOT(slotDoWork()));
    QObject::connect(&worker, SIGNAL (finished()), &a, SLOT(quit()));


    thread.start();

    int nResult = a.exec();
    thread.quit();
    thread.wait();

    return nResult;
}*/

//Листинг 38.4-38.5 Демонстрация управления потоком
/*
#include <QtWidgets>
#include "mythread.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QProgressBar prb;
    MyThread     thread;

    QObject::connect(&thread, SIGNAL(progress(int)), &prb, SLOT(setValue(int)));

    prb.show();
    thread.start();

    return a.exec();
}
*/
//Листинг 38.6-38.9 То же самое, но через события
/*
#include <QtWidgets>
#include "mythread2.h"
#include "myprogressbar.h"

int main(int argc, char *argv[])
{
    QApplication  a(argc, argv);
    MyProgressBar prb;
    MyThread2     thread(&prb);

    prb.show();
    thread.start();

    return a.exec();
}
*/

//Листинг 38.10 Работа с мьютексами
//#include <QtWidgets>
//#include "threadsafestringstack.h"

//Листинг 38.11 Использование фреймворка QtConcurrent
/*#include <QtCore>
#include <QtConcurrent/QtConcurrent>

QString myToUpper (const QString& str)
{
    return str.toUpper();
}

int main(int argc, char *argv[])
{
    QCoreApplication  a(argc, argv);
    QFuture<QString> future =
            QtConcurrent::run(myToUpper, QString ("test"));
   // future.waitForFinished();  Можно обойтись без этого
    qDebug() << future.result();

    return 0;
}*/

//Листинг 38.12 Ипользование QtConcurrent для списка

#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>


QString myToUpper (const QString& str)
{
    return str.toUpper();
}


int main(int argc, char *argv[])
{
    QCoreApplication  a(argc, argv);

    QStringList lst(QStringList() << "one" << "two"<<"three");
    QFuture<QString> future =
            QtConcurrent::mapped(lst.begin(),lst.end(), myToUpper);
   // future.waitForFinished();  Можно обойтись без этого
    qDebug() << future.results();


    return 0;
}
