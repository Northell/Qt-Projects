#ifndef BLINKLABEL_H
#define BLINKLABEL_H

#include <QtWidgets>
class BlinkLabel:public QLabel
{
    Q_OBJECT

private:
    bool m_Blink;
    QString m_strText;

protected:
    virtual void timerEvent(QTimerEvent*);

public:
    BlinkLabel(const QString& strText,
               int nInterval = 200,
               QWidget* pwgt = 0);
};

#endif // BLINKLABEL_H
