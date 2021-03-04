#include "blinklabel.h"

void BlinkLabel::timerEvent(QTimerEvent *)
{
    m_Blink = !m_Blink;
    setText(m_Blink ? m_strText : "");
}

BlinkLabel::BlinkLabel(const QString &strText, int nInterval, QWidget *pwgt)
                        :QLabel(strText,pwgt)
                        , m_Blink(true)
                        , m_strText(strText)
{
    startTimer(nInterval);
}
