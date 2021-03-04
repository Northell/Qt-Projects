#ifndef CLOCK_H
#define CLOCK_H

#include <QtWidgets>

class Clock:public QLabel
{
    Q_OBJECT
public:
    Clock(QWidget* pwgt = 0);

public slots:
    void slotUpdateDateTime();
};

#endif // CLOCK_H
