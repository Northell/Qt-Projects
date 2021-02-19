#include "customwidget.h"

void CustomWidget::paintEvent(QPaintEvent *)
{
    QPainter        painter(this);
    QLinearGradient gradient(0,0,width(),height());
    float           f = m_nProgress/100.0f;

    gradient.setColorAt(0, Qt::black);
    gradient.setColorAt(f,Qt::blue);

    painter.fillRect(rect(),Qt::black);
    painter.setBrush(gradient);
    painter.drawRect(0,0,(int)(width()*f),height());

    painter.setPen(QPen(Qt::yellow));
    QString str = QString().setNum(m_nProgress) + "%";
    painter.drawText(rect(),Qt::AlignCenter,str);

    drawFrame(&painter);
}

CustomWidget::CustomWidget(QWidget *pwgt):QFrame(pwgt)
                                         ,m_nProgress(0)
{
    setLineWidth(3);
    setFrameStyle(Box|Sunken);  //Стиль рамки

    setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
}

QSize CustomWidget::sizeHint() const
{
    return QSize(200,30);
}

void CustomWidget::slotSetProgress(int n)
{
    m_nProgress = n>100?100:n<0?0:n;
    repaint();
    emit progressChanged(m_nProgress);
}
