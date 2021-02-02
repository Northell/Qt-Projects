
//Листинг 2.2: Определение свойства для управления режимом "только для чтения"
/*
#include <QCoreApplication>
#include <QVariant>
#include <QMetaProperty>


class MyClass : public QObject
{
    Q_OBJECT
    Q_PROPERTY (bool readOnly
               READ isReadOnly
               WRITE setReadOnly
               )

    private:
        bool m_bReadOnly;

public:
    MyClass(QObject* pobj = 0) : QObject(pobj)
                               , m_bReadOnly(false)
    {

    }
public:
    void setReadOnly(bool bReadOnly)
    {
        m_bReadOnly = bReadOnly;
    }

    bool isReadOnly() const
    {
        return m_bReadOnly;
    }
};

int main(int argc, char *argv[])
{
   QCoreApplication a(argc, argv);
   QObject* pobj = new QObject();

   pobj->setProperty("readOnly", true); //Меняем значение свойства
   bool bReadOnly = pobj->property("readOnly").toBool();//Получаем текущее значение

   const QMetaObject* pmo = pobj->metaObject();

   for (int i =0; i<pmo->propertyCount(); ++i)
   {
       const QMetaProperty mp = pmo->property(i);
      qDebug() << "Property#: " <<i;
      qDebug() << "Type: " << mp.typeName();
      qDebug() << "Name: " << mp.name();
      qDebug() << "Value: " << pobj->property(mp.name());
   }

   delete pobj;
    return a.exec();
}*/


//Листинг 2.4 Определение сигнала
/*
  #include <QCoreApplication>
class MySignal
{
    Q_OBJECT
   // ...
signals:
    void doIt();
};
*/


//Листинг 2.5, 2.6 Релизация сигнала
/*
#include <QCoreApplication>
class MySignal:public QObject{
    Q_OBJECT
 public:
    MySignal() {}
    ~MySignal() {}
    void sendSignal()
    {
       // emit doIt(); //Чтобы выслать сигнал, используется emit
        emit sendString("Information"); //2.6 реализация сигнала с параметром
    }
signals:
    //void doIt();
    void sendString(const QString&);
};

*/

//Листинг 2.7 Слоты, реализация слота
/*
#include <QCoreApplication>

class MySlot : public QObject{
    Q_OBJECT

public:
    MySlot();

public slots:
    void slot()
    {
        qDebug() << "I'm a slot";
        //qDebug() << sender()->objectName();
    }
public:
    void Slot()
    {
        qDebug() << "I'm a slot";
    }
};
*/

//Соединение объектов в программе с помощью метода connect()
/*
#include <QCoreApplication>
int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    Object::connect(pSender, SIGNAL(signalMethod()), //первый вариант, минус - обнаружение ошибок уже при исполнении программы
                     pReceiver, SLOT (slotMethod())
                     );

    QObject::connect(pSender, &SenderClass::signalMethod, //Второй вариант
                     pReceiver, &ReceiverClass::slotMethod
                     );
    return app.exec();
}*/

//2.8-2.10 Демонстрация работы с сигналами и слотами (counter.h)
/*
#include <QtWidgets>
#include "counter.h"
#include <QCoreApplication>


int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    QLabel       lbl("0");
    QPushButton  cmd("ADD");
    Counter      counter;

    lbl.show();
    cmd.show();

    QObject::connect(&cmd, SIGNAL(clicked()),
                     &counter, SLOT(slotInc())
                     );

    QObject::connect(&counter, SIGNAL(counterChanged(int)),
                     &lbl, SLOT(setNum(int))
                     );

    QObject::connect(&counter, SIGNAL(goodbye()),
                     &app, SLOT(quit())
                     );

    return app.exec();
}
*/

//Листинг 2.11 Пример переопределения сигналов
/*
#include <QtWidgets>
#include <QCoreApplication>

class MyClass:public QSignalMapper
{
public:
    MyClass (QWidget* pwgt);

    void slotShowAction(const QString& str);

};





MyClass::MyClass(QWidget *pwgt)
{
    QSignalMapper* psigMapper = new QSignalMapper (this);
    connect(psigMapper, SIGNAL (mapped(const QString&)),
            this,       SLOT(slotShowAction(const QString&))
            ); //тут переопределяем connect

    QPushButton* pcmd1 = new QPushButton("Button 1");
    connect (pcmd1, SIGNAL(clicked()), psigMapper, SLOT(map()));
    psigMapper->setMapping(pcmd1, "Button 1 Action");

    QPushButton* pcmd2 = new QPushButton("Button 2");
    connect (pcmd1, SIGNAL(clicked()), psigMapper, SLOT(map()));
    psigMapper->setMapping(pcmd1, "Button 2 Action");


}

void MyClass::slotShowAction(const QString &str)
{
    qDebug() << str;

}
//Лучше не злоупотреблять из-за сложной читаемости кода.
*/

//Листинг 2.12 Пример создания объектной иерархии,
//Листинг 2.13 Вывод имени объектов предков,
//Метаобъектная информация
/*
#include <QObject>
#include <QCoreApplication>


int main(int argc, char** argv)
{
    QCoreApplication app(argc,argv);
    //2.12
    QObject* pobj1 = new QObject;
    QObject* pobj2 = new QObject(pobj1);
    QObject* pobj3 = new QObject(pobj2);
    QObject* pobj4 = new QObject(pobj3);
    QObject* pobj5 = new QObject(pobj2);
    pobj2->setObjectName("the first child of pobj1");
    pobj3->setObjectName("the first child of pobj2");
    pobj4->setObjectName("the first child of pobj3");
    pobj5->setObjectName("the second child of pobj2");

//    При уничтожении созданного объекта (вызове его леструктора)
//    Все присоединенные к нему объекты-потомки уничтожаются автоматически.

    //2.13
    for (QObject* pobj = pobj5; pobj; pobj = pobj->parent())
    {
       // qDebug() << pobj->objectName();
       // pobj->dumpObjectTree(); //Выводит в консоль иерархию объектов

       // pobj->dumpObjectInfo();    //Выводит в консоль информацию об объекте, имя,
                                     //класс, от которого был создан объект, сигнально-слотовые соединения.
       //qDebug()<< pobj->metaObject();//Доступ к метаобъектной инфе
    }


    return app.exec();
}

*/
