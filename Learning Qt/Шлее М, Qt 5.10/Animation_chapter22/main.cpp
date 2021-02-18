//Листинг 22.1 Создание анимации
/*
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLabel lbl;
    QMovie mov (":/mov.gif");

    mov.start();

    lbl.setMovie(&mov);
    lbl.resize(mov.frameRect().size());
    lbl.show();

    return a.exec();
}
*/

//Листинг 22.2 Создание векторной анимации
/*
#include <QtSvgWidgets>// в 6.0 все лежит тут, вместо QtSvg


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSvgWidget svg(":/mov.svg");
    svg.show();

    QObject::connect (svg.renderer(), SIGNAL(repaintNeeded()),
                      &svg,           SLOT(repaint())
                      );

    return a.exec();
}
*/

//Листинг 22.3 Анимация цвета
/*
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLabel       lbl;
    lbl.setPixmap(QPixmap(":/mov.gif"));

    QGraphicsColorizeEffect effect;
    lbl.setGraphicsEffect(&effect);

    QPropertyAnimation anim(&effect, "color");
    anim.setStartValue(QColor(Qt::gray));
    anim.setKeyValueAt(0.25f,QColor(Qt::green));
    anim.setKeyValueAt(0.5f,QColor(Qt::blue));
    anim.setKeyValueAt(0.75f,QColor(Qt::red));
    anim.setEndValue(QColor(Qt::black));

    anim.setDuration(3000);     //Время продолжительности изменения значений в мс
    anim.setLoopCount(-1);      //Кол-во повторений. -1 = бесконечность
    anim.start();

    lbl.show();
    return a.exec();
}
*/

//Листинг 22.4 Группы анимации
/*
#include <QtWidgets>
int main()
{
    QParallelAnimationGroup* pgroup1 = new QParallelAnimationGroup();
    pgroup1->addAnimation(panim1);
    pgroup1->addAnimation(panim2);

    QSequentialAnimationGroup* pgroup2 = new QSequentialAnimationGroup();
    pgroup2->addAnimation(panim3);

    pgroup2->start();
    return 0;
}
*/


//Листинг 22.5 Смягчающие линии

/*
#include <QtWidgets>

int main(int argc,char** argv)
{
    QApplication app(argc,argv);
    QLabel       lbl1("Animated Window 1");
    QLabel       lbl2("Animated Window 2");

    QPropertyAnimation* panim1 =
            new QPropertyAnimation (&lbl1, "geometry");

    panim1->setDuration(3000);
    panim1->setStartValue(QRect(120,0,100,100));
    panim1->setEndValue(QRect(480,380,200,200));
    panim1->setEasingCurve(QEasingCurve::InOutExpo);

    QPropertyAnimation* panim2 = new QPropertyAnimation(&lbl2,"pos");
    panim2->setDuration(3000);
    panim2->setStartValue(QPoint(240,0));
    panim2->setEndValue(QPoint(240,480));
    panim2->setEasingCurve(QEasingCurve::OutBounce);

    QParallelAnimationGroup group;
    group.addAnimation(panim1);
    group.addAnimation(panim2);

    group.setLoopCount(3);
    group.start();

    lbl1.show();
    lbl2.show();
    return app.exec();
}
*/

//Листинг 22.6 Состояния и переходы //Не робит, возможно QStateMachine в другом месте

/*
#include <QtWidgets>
#include <QObject>



int main(int argc, char** argv)
{

    QApplication app(argc,argv);
    QWidget      wgt;

    wgt.setFixedSize(300,50);
    wgt.show();

    QLabel* plblOff = new QLabel("Off");
    QLabel* plblOn  = new QLabel("On");

    QHBoxLayout* phbx = new QHBoxLayout();
    phbx->addWidget(plblOn);
    phbx->addStretch();
    phbx->addWidget(plblOff);
    wgt.setLayout(phbx);

    QPushButton* pcmd = new QPushButton("Push", & wgt);
    pcmd->setAutoFillBackground(true);
    pcmd->show();

    int nButtonWidth = wgt.width()/2;
    QStateMachine* psm = new QStateMachine;

    QState* pStateOff = new QState(psm);
    QRect   rect1(0, 0, nButtonWidth, wgt.height());
    pStateOff->assignProperty(pcmd, "geometry", rect1);
    pStateOff->assignProperty(plblOff, "visible", true);
    pStateOff->assignProperty(plblOn, "visible", false);
    psm->setInitialState(pStateOff);

    QState* pStateOn = new QState(psm);
    QRect   rect2(nButtonWidth, 0, nButtonWidth, wgt.height());
    pStateOn->assignProperty(pcmd, "geometry", rect2);
    pStateOn->assignProperty(plblOff, "visible", false);
    pStateOn->assignProperty(plblOn, "visible", true);

    QSignalTransition* ptrans1 =
        pStateOff->addTransition(pcmd, SIGNAL(clicked()), pStateOn);

    QSignalTransition* ptrans2 =
        pStateOn->addTransition(pcmd, SIGNAL(clicked()), pStateOff);

    QPropertyAnimation* panim1 =
        new QPropertyAnimation(pcmd, "geometry");
    ptrans1->addAnimation(panim1);

    QPropertyAnimation* panim2 =
        new QPropertyAnimation(pcmd, "geometry");
    ptrans2->addAnimation(panim2);

    psm->start();

    return app.exec();



}
*/

