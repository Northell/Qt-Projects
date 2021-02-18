
//Листинг 20.1, 20.2 Вывод на экране строки текста методами setPoint() и drawText()
//                   Вывод строки пл центру методами setFobt(), drawRect(), drawText()

/*
#include <QtWidgets>

class MyWidget:public QWidget
{
protected:

    void paintEvent1(QPaintEvent*) //20.1
    {
        QPainter painter(this);
        painter.setFont(QFont("Times",25,QFont::Normal));
        painter.drawText(10,40,"Draw Text");
    }
    void paintEvent2(QPaintEvent*) //20.2
    {
        QPainter painter(this);
        QRect r(0,0,120,200);
        painter.setFont(QFont("Times", 25,QFont::Normal));

        painter.drawRect(r);
        painter.drawText(r,Qt::AlignCenter|Qt::TextWordWrap, "Draw Text");
    }

public:
    MyWidget(QWidget* pwgt = 0):QWidget(pwgt)
    {

    }
};


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget wgt;
    wgt.show();

    return a.exec();
}*/

//Листинг 20.3 Усеченное отображение строк с показов разрыва
/*
#include <QtWidgets>

class ElidedText:public QWidget
{
protected:
    virtual void paintEvent(QPaintEvent*)
    {
        QString str = "This is a long text. Please, resize window";
        QString strElided =
                fontMetrics().elidedText(str,Qt::ElideMiddle,width());
        QPainter painter (this);
        painter.drawText(rect(),strElided);
    }

public:
    ElidedText(QWidget* pwgt = 0):QWidget(pwgt){}
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ElidedText et;
    et.resize(200,20);
    et.show();

    return a.exec();
}*/
