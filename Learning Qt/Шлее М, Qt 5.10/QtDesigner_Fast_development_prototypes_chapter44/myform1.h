#ifndef MYFORM1_H
#define MYFORM1_H


#include <QtWidgets>
#include "ui_MyForm.h"

class MyForm1:public QWidget{
    Q_OBJECT
private:
    Ui::Form m_ui;

public:
    MyForm1(QWidget* pwgt = 0):QWidget(pwgt)
    {
        m_ui.setupUi(this);
        connect(m_ui.m_cmdReset, SIGNAL(clicked()), SLOT(slotReset()));

    }
public slots:
    void slotReset()
    {
        m_ui.m_sld->setText("void");
        m_ui.m_lcd->display(0);
    }
};
#endif // MYFORM1_H
