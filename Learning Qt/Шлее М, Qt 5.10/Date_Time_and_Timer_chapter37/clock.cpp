#include "clock.h"

Clock::Clock(QWidget *pwgt):QLabel(pwgt)
{
    QTimer* pTimer = new QTimer(this);
    connect(pTimer, &QTimer::timeout, this, &Clock::slotUpdateDateTime);

    pTimer->start(500);
    slotUpdateDateTime();

}

void Clock::slotUpdateDateTime()
{
    QString str =
            QDateTime::currentDateTime().toString();
    setText("<H2><CENTER>" + str + "</CENTER></H2>");

}
