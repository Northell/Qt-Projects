//Листинг 5.1, 5.2 Создание виджета верзнего уровня, Изменение указателя мыши
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget wgt;

    //pwht1
    QWidget *pwgt1 = new QWidget(&wgt);
    QPalette pall;

    pall.setColor(pwgt1->backgroundRole(), Qt::blue);
    pwgt1->setPalette(pall);
    pwgt1->resize(100,100);
    pwgt1->move (25,25);
    pwgt1->setAutoFillBackground(true);
    wgt.setWindowTitle("Piska");
    //

    //pwgt2
    QWidget *pwgt2 = new QWidget(&wgt);
    QPalette pall2;

    pall2.setBrush(pwgt2->backgroundRole(), QBrush(QPixmap(":/stone.jpg"))); // Для работки с файлами пихуем сюда псевдоним из файла qrc
                                                                             // Созданного для хранения ресов
    pwgt2->setPalette(pall2);
    pwgt2->resize(100,100);
    pwgt2->move(75,75);
    pwgt2->setAutoFillBackground(true);


    //5.2
    //Изменяем указатель мыши
    QPixmap pix(":/Cursor.png");
    pix = pix.scaled(50,100,Qt::KeepAspectRatio);
    QCursor cur(pix);
    app.setOverrideCursor(cur); //Чтобы курсор изменился во всем приложении
  //  wgt.setCursor(cur);       //только в это виджете
    //

    wgt.resize(200,200);
    wgt.show();




    return app.exec();
}*/

//Листинг 5.3 Применение видовой прокрутки
/*

#include <QtWidgets>

int main(int argc, char ** argv)
{
    QApplication app(argc,argv);
    QScrollArea sa;

    QWidget*   pwgt = new QWidget();
    QPixmap    pix(":/stone.jpg");
    pix = pix.scaled(500,500, Qt::KeepAspectRatio);

    QPalette pal;
    pal.setBrush(pwgt->backgroundRole(), QBrush(pix));
    pwgt->setPalette(pal);
    pwgt->setAutoFillBackground(true);
    pwgt->setFixedSize(pix.width(), pix.height());

    sa.setWidget(pwgt);
    sa.resize(350,150);
    sa.show();

    return app.exec();
}
*/
