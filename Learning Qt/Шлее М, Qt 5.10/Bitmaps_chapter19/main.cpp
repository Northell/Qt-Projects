//Листинг 19.1, 19.2 Увеличение/уменьшение яркости
/*
#include <QtWidgets>

QImage brightness (const QImage& imgOrig, int n)
{
    QImage imgTemp = imgOrig;

    qint32 nHeight = imgTemp.height();
    qint32 nWidth  = imgTemp.width();

    for(qint32 y = 0; y<nHeight; ++y)
    {
        QRgb* tempLine = reinterpret_cast<QRgb*>(imgTemp.scanLine(y));

        for(qint32 x =0;x<nWidth; ++x)
        {
            int r = qRed(*tempLine) + n;
            int g = qGreen(*tempLine)+n;
            int b = qBlue(*tempLine) + n;
            int a = qAlpha(*tempLine);

            *tempLine++ = qRgba (r>255?255:r<0?0:r,
                                 g>255?255:g<0?0:g,
                                 b>255?255:b<0?0:b,
                                 a
                                 );

        }
    }
    return imgTemp;


}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QImage img(":/img");
    QWidget wgt;

    QHBoxLayout* layout = new QHBoxLayout();
    layout -> setSpacing(0);

    for (int i = -150; i<150; i+=50)
    {
        QLabel* plbl = new QLabel;
        plbl->setFixedSize(img.size());
        plbl->setPixmap(QPixmap::fromImage(brightness(img,i)));
        layout->addWidget(plbl);
    }
    wgt.setLayout(layout);
    wgt.show();


    return a.exec();
}
*/

//Листинг 19.10-19.11 Создание нестандартного окна виджета
/*
#include <QtWidgets>
#include "window.h"

int main(int argc, char**argv)
{
    QApplication app(argc,argv);
    Window              wnd;

    wnd.setAttribute(Qt::WA_TranslucentBackground);
    wnd.setPixmap(QPixmap(":/img"));

    QPushButton* pcmdQuit = new QPushButton("X");
    pcmdQuit->setFixedSize(16,16);

    QObject::connect(pcmdQuit, &QPushButton::clicked,
                     &app, &QApplication::quit);

    //layout setup

    QVBoxLayout* pvbx = new QVBoxLayout();
    pvbx->addWidget(pcmdQuit);
    pvbx->addStretch(1);
    wnd.setLayout(pvbx);

    wnd.show();



    return app.exec();
}
*/
