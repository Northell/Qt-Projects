#ifndef CALCULATOR_H
#define CALCULATOR_H
//6.6-6.11

#include <QStack>
#include <QtWidgets>

#include <QLCDNumber>
#include <QRegularExpression> //В версии Qt6.0 убрали QRegExp, и заменили на это

class QLCDNumber;
class QPushButton;

//=========================================
class Calculator:public QWidget
{
    Q_OBJECT
private:
    QLCDNumber*      m_plcd;
    QStack <QString> m_stk;
    QString          m_strDisplay;

public:
    Calculator(QWidget* pwgt = 0);

    QPushButton* createButton(const QString& str);
    void calculate();

public slots:
    void slotButtonClicked();
};

#endif // CALCULATOR_H
