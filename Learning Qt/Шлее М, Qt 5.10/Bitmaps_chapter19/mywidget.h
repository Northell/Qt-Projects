#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QtWidgets>

class MyWidget: public QWidget
{
public:
    MyWidget();

    void paintEvent (QPaintEvent*); //19.3 Вывод растрового изображения
    void paintEvent2(QPaintEvent*); //19.4 Вывод части растрового изображения
    void paintEvent3(QPaintEvent*); //19.5 Инвертирование пикселей
    void paintEvent4(QPaintEvent*); //19.6 Изменение размеров растрового изображения
    void paintEvent5(QPaintEvent*); //19.7 Отражение изображения
    void paintEvent6(QPaintEvent*); //19.8 Рисование на объекте QImage
    void paintEvent7(QPaintEvent*); //19.9 Вывод растрового изображения


};

#endif // MYWIDGET_H
