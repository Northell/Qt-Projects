#include "inputdialog.h"

InputDialog::InputDialog(QWidget *pwgt):QDialog(pwgt,Qt::WindowTitleHint
                                                | Qt::WindowSystemMenuHint)
{
    m_ptxtFirstName = new QLineEdit();
    m_ptxtLastName  = new QLineEdit();

    QLabel* plblFirstName = new QLabel("&First Name: ");
    QLabel* plblLastName  = new QLabel("&Last Name: ");

    plblFirstName->setBuddy(m_ptxtFirstName);
    plblLastName->setBuddy(m_ptxtLastName);

    QPushButton* pcmdOk = new QPushButton("&Ok");
    QPushButton* pcmdCancel = new QPushButton("&Cancel");

    connect(pcmdOk, SIGNAL(clicked()), SLOT(accept()));
    connect(pcmdCancel, SIGNAL(clicked()), SLOT(reject()));

    //Layout

    QGridLayout* layout = new QGridLayout();

    layout->addWidget(plblFirstName,0,0);
    layout->addWidget(plblLastName,1,0);
    layout->addWidget(m_ptxtFirstName,0,1);
    layout->addWidget(m_ptxtLastName,1,1);
    layout->addWidget(pcmdOk,2,0);
    layout->addWidget(pcmdCancel,2,1);

    setLayout(layout);


}

QString InputDialog::firstName() const
{
    return m_ptxtFirstName->text();
}

QString InputDialog::lastName() const
{
    return m_ptxtLastName->text();
}
