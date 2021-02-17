#ifndef MYWIDGET_H
#define MYWIDGET_H
#include <QtWidgets>

class MyWidget:public QWidget
{
private:

    QWidget wgt;
public:
    MyWidget(QWidget *pwgt = 0);

    void paintEvent  (QPaintEvent*);// Листинг 18.1  Рисование двумя объектами QPainter в одном контексте
    void paintEvent1 (QPaintEvent*);// Листинг 18.2  Рисование одним объектом QPainter В двух разных контекстах

    void paintEvent3 (QPaintEvent*);// Листинг 18.3  Линейный градиент
    void paintEvent4 (QPaintEvent*);// Листинг 18.4  Конический градиент
    void paintEvent5 (QPaintEvent*);// Листинг 18.5  Радиальный(лучевой) градиент

    void paintEvent6 (QPaintEvent*);// Листинг 18.6  Рисование точек методом

    void paintEvent7 (QPaintEvent*);// Листинг 18.7  Рисование линий методом
    void paintEvent8 (QPaintEvent*);// Листинг 18.8  Рисование фигуры методом drawPolyline()

    void paintEvent9 (QPaintEvent*);// Листинг 18.9  Рисование сплошных прямоугольников методами fillRect(), eraseRect()
    void paintEvent10(QPaintEvent*);// Листинг 18.10 Рисование заполненного прямоугольника методом drawRect()
    void paintEvent11(QPaintEvent*);// Листинг 18.10 Рисование заполненного прямоугольника с закругленными углами методом drawRoundRect()
    void paintEvent12(QPaintEvent*);// Листинг 18.12 Рисование заполненного эллипса методом drawEllipse()
    void paintEvent13(QPaintEvent*);// Листинг 18.13 Рисование хорды, отсекающей часть эллипса методом drawChord()
    void paintEvent14(QPaintEvent*);// Листинг 18.14 Рисование круговой диаграммы методом drawPie()
    void paintEvent15(QPaintEvent*);// Листинг 18.15 Рисование заполненного многоугольника методом drawPolygon()

    void paintEvent16(QPaintEvent*);// Листинг 18.16 Протоколирование комманд рисования
    void paintEvent17(QPaintEvent*);// Листинг 18.17 Загрузка и выполнение команды в другом контексте рисования

    void paintEvent18(QPaintEvent*);// Листинг 18.18 Создание графической траектории
    void paintEvent19(QPaintEvent*);// Листинг 18.19 Отсечение фигуры эллипса прямоугольной областью

    QLabel* lbl(const QPainter::CompositionMode& mode);// Листинг 18.20 Фнкция lbl() - создание виджетов надписей
                                                       //                              с установленными растровыми изображениями


};
#endif // MYWIDGET_H
