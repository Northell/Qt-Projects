//Листинг 14.1-14.3 Обработка событий мыши
/*
#include <QtWidgets>
#include "mouseobserver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MouseObserver wgt;
    wgt.resize(250,130);
    wgt.show();

    return a.exec();
}*/

//Листинг 14.4 Перезапись метода resizeEvent()
/*
#include <QtWidgets>

class ResizeObserver : public QLabel
{
public:
    ResizeObserver(QWidget* pwgt = 0) : QLabel(pwgt)
    {
        setAlignment(Qt::AlignCenter);
    }
protected:
    virtual void resizeEvent (QResizeEvent* pe)
    {
        setText(QString("Resized")
                + "\n width()+" + QString::number(pe->size().width())
                + "\n height()+" + QString::number(pe->size().height())
                );
    }

};

int main(int argc, char** argv)
{
    QApplication app (argc,argv);
    ResizeObserver wgt;

    wgt.resize(250,130);

    wgt.show();
    return app.exec();
}*/

//Листинг 14.5-14.9 Отображение множественных касаний
//Хз, почему, но программа не работает, проверял исходники.
//Возможно из за версии

#include <QtWidgets>
#include "multitouchwidget.h"

int main(int argc, char** argv)
{
    QApplication app(argc, argv);

    MultiTouchWidget wgt;

    wgt.resize(640,480);
    wgt.show();

    return app.exec();
}

