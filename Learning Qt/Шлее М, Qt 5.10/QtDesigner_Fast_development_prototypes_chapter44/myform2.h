#ifndef MYFORM2_H
#define MYFORM2_H


#include"ui_MyForm.h"
#include <QtWidgets>

class MyForm:public QWidget, public Ui::Form
{

    Q_OBJECT

public:
    MyForm(QWidget* pwgt = 0):QWidget(pwgt)
    {
        setupUi(this);
        connect(m_cmdReset, SIGNAL(clicked()), SLOT(slotReset()));
    }
public slots:
    void slotReset()
    {
        m_sld->setText("void");
        m_lcd->display(0);
    }
};
#endif // MYFORM2_H
