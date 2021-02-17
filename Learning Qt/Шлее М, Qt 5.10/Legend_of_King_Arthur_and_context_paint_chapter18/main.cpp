#include <QtWidgets>

//Листинг 18.1-18.19 Рисование двумя объектами Qpainter в одном контексте
/*mywidget.h*/



//Листинг 18.20, 18.21 Создание виджетов надписей с изображениями
/*
QLabel* lbl (const QPainter::CompositionMode& mode)
{
    QLabel* plbl = new QLabel;
    plbl->setFixedSize(100,100);

    QRect    rect(plbl->contentsRect());
    QPainter painter;

    QImage sourceImage(rect.size(),QImage::Format_ARGB32_Premultiplied);
    sourceImage.fill(QColor(0,0,0,0));
    painter.begin(&sourceImage);
    painter.setRenderHint(QPainter::Antialiasing,true);;
    painter.setBrush(QBrush(QColor(0,255,0)));
    painter.drawPolygon(QPolygon() << rect.bottomLeft()
                                   << QPoint(rect.center().x(),0)
                                   << rect.bottomRight()
                        );
    painter.end();


    QImage resultImage(rect.size(),QImage::Format_ARGB32_Premultiplied);
    painter.begin(&resultImage);
    painter.setRenderHint(QPainter::Antialiasing,true);;
    painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
    painter.setPen(QPen(QColor(0,255,0),4));
    painter.setBrush(QBrush(QColor(0,255,0)));
    painter.drawEllipse(rect);
    painter.setCompositionMode(mode);
    painter.drawImage(rect,sourceImage);
    painter.end();

    plbl->setPixmap(QPixmap::fromImage(resultImage));
    return plbl;



}
int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    QWidget      wgt;

    //Layout setup
    QGridLayout* pgrd = new QGridLayout();

    pgrd->addWidget(lbl(QPainter::CompositionMode_Source),0,0);
    pgrd->addWidget(new QLabel ("<CENTER>SOURCE</CENTER>"),1,0);
    pgrd->addWidget(lbl(QPainter::CompositionMode_SourceOver),0,1);
    pgrd->addWidget(new QLabel ("<CENTER>SOURCE Over</CENTER>"),1,1);
    pgrd->addWidget(lbl(QPainter::CompositionMode_SourceIn),0,2);
    pgrd->addWidget(new QLabel ("<CENTER>SOURCE In</CENTER>"),1,2);
    pgrd->addWidget(lbl(QPainter::CompositionMode_SourceOut),0,3);
    pgrd->addWidget(new QLabel ("<CENTER>SOURCE Out</CENTER>"),1,3);
    pgrd->addWidget(lbl(QPainter::CompositionMode_SourceAtop),0,4);
    pgrd->addWidget(new QLabel ("<CENTER>SOURCE Atop</CENTER>"),1,4);

    pgrd->addWidget(lbl(QPainter::CompositionMode_Clear),0,5);
    pgrd->addWidget(new QLabel ("<CENTER>Clear</CENTER>"),1,5);
    pgrd->addWidget(lbl(QPainter::CompositionMode_Destination),2,0);
    pgrd->addWidget(new QLabel ("<CENTER>Destination</CENTER>"),3,0);
    pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationOver),2,1);
    pgrd->addWidget(new QLabel ("<CENTER>Destination Over</CENTER>"),3,1);
    pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationIn),2,2);
    pgrd->addWidget(new QLabel ("<CENTER>Destination In</CENTER>"),3,2);
    pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationOut),2,3);
    pgrd->addWidget(new QLabel ("<CENTER>Destination Out</CENTER>"),3,3);

    pgrd->addWidget(lbl(QPainter::CompositionMode_DestinationAtop),2,4);
    pgrd->addWidget(new QLabel ("<CENTER>Destination Atop</CENTER>"),3,4);
    pgrd->addWidget(lbl(QPainter::CompositionMode_Xor),2,5);
    pgrd->addWidget(new QLabel ("<CENTER>XOR</CENTER>"),3,5);

    wgt.setLayout(pgrd);
    wgt.show();
    return app.exec();
}
*/

//Листинг 18.22-18.23 Создание эффектов

QLabel* lbl(QGraphicsEffect* pge)
{
    QLabel* plbl = new QLabel();
    plbl->setPixmap(QPixmap(":/happyos.png"));

    if(pge)
    {
        plbl->setGraphicsEffect(pge);
    }
    return plbl;
}

int main (int argc, char** argv)
{
    QApplication               app(argc,argv);
    QWidget                    wgt;
    QGraphicsBlurEffect*       pBlur     = new QGraphicsBlurEffect();
    QGraphicsDropShadowEffect* pShadow   = new QGraphicsDropShadowEffect();
    QGraphicsColorizeEffect*   pColorize = new QGraphicsColorizeEffect();


    //layout setup
    QFormLayout* pform = new QFormLayout;
    pform->addRow("No Effects", lbl(0));
    pform->addRow("Blur", lbl(pBlur));
    pform->addRow("Drop Shadow", lbl(pShadow));
    pform->addRow("Colorize", lbl(pColorize));

    wgt.setLayout(pform);
    wgt.show();

    return app.exec();
}
