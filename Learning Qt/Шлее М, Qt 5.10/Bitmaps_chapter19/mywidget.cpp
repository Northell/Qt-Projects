#include "mywidget.h"

MyWidget::MyWidget()
{




}

//19.3
void MyWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(":/lisa.jpg");
    painter.drawImage(0, 0, img);
}

//19.4
void MyWidget::paintEvent2(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(":/lisa.jpg");
    painter.drawImage(0, 0, img,30,30,110,100);
}

//19.5
void MyWidget::paintEvent3(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(":/lisa.jpg");
    painter.drawImage(0, 0, img);

    img.invertPixels(QImage::InvertRgb);
    painter.drawImage(img.width(),0,img);
}

//19.6
void MyWidget::paintEvent4(QPaintEvent *)
{
    QPainter painter(this);

    QImage img1(":/lisa.jpg");
    painter.drawImage(0,0,img1);

    QImage img2 =
            img1.scaled(img1.width(), img1.height()/2, Qt::IgnoreAspectRatio);
    painter.drawImage(img1.width(),0,img2);

    QImage img3 =
            img1.scaled(img1.width(), img1.height()/2, Qt::IgnoreAspectRatio);
    painter.drawImage(img1.height(),0,img3);

    QImage img4 =
            img1.scaled(img1.width()/2, img1.height(), Qt::KeepAspectRatio);
    painter.drawImage(img1.width(),img1.height(),img4);


}

//19.7
void MyWidget::paintEvent5(QPaintEvent *)
{
    QPainter painter(this);
    QImage img(":/lisa.jpg");
    painter.drawImage(0, 0, img);
    painter.drawImage(img.width(),0,img.mirrored(true,true));
}

//19.8
void MyWidget::paintEvent6(QPaintEvent *)
{
    QImage img(size(), QImage::Format_ARGB32_Premultiplied);
    QPainter painter;

    painter.begin(&img);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.eraseRect(rect());
    painter.drawEllipse(0,0,size().width(), size().height());

    painter.begin(this);
    painter.drawImage(0,0,img);
    painter.end();
}
//19.9
void MyWidget::paintEvent7(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix(":/forest.jpg");
    painter.drawPixmap(0,0,pix);

    QRect r(pix.width(),0,pix.width()/2,pix.height());
    painter.drawPixmap(r,pix);
}
