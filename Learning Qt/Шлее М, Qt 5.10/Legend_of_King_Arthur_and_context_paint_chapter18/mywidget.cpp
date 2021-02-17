#include "mywidget.h"


MyWidget::MyWidget(QWidget *pwgt):wgt(pwgt)
{




}

//18.1
void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter1;
    QPainter painter2;

    painter1.begin(this);
    //Команды рисования
    painter1.end();

    painter2.begin(this);
    //Команды рисования
    painter2.end();


}


//18.2
void MyWidget::paintEvent1(QPaintEvent *)
{
//    QPainter painter;

//    painter.begin(this);
//    //Команды рисования
//    painter.end();

//    QPixmap pix(rect());
//    painter.begin(&pix); //Контекст растрового изображения
//    //Команды рисования
//    painter.end();
}

//18.3
void MyWidget::paintEvent3(QPaintEvent *)
{
    QPainter        painter(this);
    QLinearGradient gradient(0,0,width(),height());

    gradient.setColorAt(0, Qt::red);
    gradient.setColorAt(0.5, Qt::green);
    gradient.setColorAt(1, Qt::blue);

    painter.setBrush(gradient);
    painter.drawRect(rect());


}

//18.4
void MyWidget::paintEvent4(QPaintEvent *)
{
    QPainter         painter(this);
    QConicalGradient gradient(width() /2 , height() /2, 0);

    gradient.setColorAt(0,Qt::red);
    gradient.setColorAt(0.4,Qt::green);
    gradient.setColorAt(0.8,Qt::blue);
    gradient.setColorAt(1,Qt::red);

    painter.setBrush(gradient);
    painter.drawRect(rect());


}


//18.5
void MyWidget::paintEvent5(QPaintEvent *)
{
    QPainter        painter(this);
    QPointF         ptCenter(rect().center());
    QRadialGradient gradient (ptCenter, width()/2, ptCenter);

    gradient.setColorAt(0,Qt::red);
    gradient.setColorAt(0.5,Qt::green);
    gradient.setColorAt(1,Qt::blue);

    painter.setBrush(gradient);
    painter.drawRect(rect());

}
//18.6
void MyWidget::paintEvent6(QPaintEvent *)
{
    QPainter         painter(this);
    painter.setPen(QPen(Qt::black,3));

    int n = 8;
    for(int i=0;i<n;++i)
    {
        qreal fAngle = ::qDegreesToRadians(360.0*i/n);
        qreal x      = 50 + cos(fAngle) * 40;
        qreal y      = 50 + sin(fAngle) * 40;

        painter.drawPoint(QPointF(x,y));

    }
}


//18.7
void MyWidget::paintEvent7(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.drawLine(QPointF(10,10), QPointF(90,90));
}

//18.8
void MyWidget::paintEvent8(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const int n = 8;
    QPointF a[n];
    for(int i= 0; i< n; ++i)
    {
        qreal fAngle = ::qDegreesToRadians(360.0*i/n);
        qreal x      = 50 + cos(fAngle) * 40;
        qreal y      = 50 + sin(fAngle) * 40;

        a[i] = QPointF (x,y);

    }
    painter.drawPolyline(a,n);
}


//18.9
void MyWidget::paintEvent9(QPaintEvent *)
{
    QPainter painter(this);
    QBrush   brush(Qt::red, Qt::Dense4Pattern);

    painter.fillRect(10,10,100,100,brush);
    painter.eraseRect(20,20,80,80);
}

//18.10
void MyWidget::paintEvent10(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));
    painter.drawRect(QRect(10,10,110,70));
}

//18.11
void MyWidget::paintEvent11(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));
    painter.drawRoundedRect(QRect(10,10,110,70), 30, 30);
}

//18.12
void MyWidget::paintEvent12(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));
    painter.drawEllipse(QRect(10,10,110,70));
}

//18.13
void MyWidget::paintEvent13(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));
    painter.drawChord(QRect(10,10,110,70),45*16,180*16);
}

//18.14
void MyWidget::paintEvent14(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));
    painter.drawPie(QRect(10,10,110,70),90*16,270*16);
}

//18.15
void MyWidget::paintEvent15(QPaintEvent *)
{
    QPainter painter(this);

    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::red, Qt::DiagCrossPattern));
    painter.setPen(QPen(Qt::blue, 3, Qt::DashLine));

    int n = 8;
    QPolygonF polygon;

    for (int i = 0;i<n;++i)
    {
        qreal fAngle = ::qDegreesToRadians(360.0*i/n);
        qreal x      = 50+cos(fAngle)*40;
        qreal y      = 50+sin(fAngle * 40);

        polygon << QPointF(x,y);
    }
    painter.drawPolygon(polygon);
}

//18.16
void MyWidget::paintEvent16(QPaintEvent *)
{
    QPicture pic;
    QPainter painter;

    painter.begin(&pic);
    painter.drawLine(20,20,50,50);
    painter.end();

    if(!pic.save("myline.dat"))
    {
        qDebug() << "Can't save the file";
    }
}

//18.17
void MyWidget::paintEvent17(QPaintEvent *)
{
    QPicture pic;
    if(!pic.load("myline.dat"))
    {
        qDebug() << "Can't load the file";
    }
    QPainter painter;
    painter.begin(this);
    painter.drawPicture(QPoint(0,0), pic);
    painter.end();
}

void MyWidget::paintEvent18(QPaintEvent *)
{
    QPainterPath path;

    QPointF      pt1(width(), height()/2);
    QPointF      pt2(width()/2, -height());
    QPointF      pt3(width()/2, 2*height());
    QPointF      pt4(0, height()/2);

    path.moveTo(pt1);
    path.cubicTo(pt2,pt3,pt4);

    QRect rect(width()/4, height()/4, width()/2, height()/2);
    path.addRect(rect);
    path.addEllipse(rect);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(QPen(Qt::blue,6));

    painter.drawPath(path);
}

//18.19
void MyWidget::paintEvent19(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setClipRect(0,0,100,100);
    painter.setBrush(QBrush(Qt::green));
    painter.setPen(QPen(Qt::black,2));

    painter.drawEllipse(0,0,200,100);
}
