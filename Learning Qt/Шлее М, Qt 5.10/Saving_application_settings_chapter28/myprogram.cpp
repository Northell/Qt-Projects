#include "myprogram.h"

MyProgram::MyProgram(QWidget *pwgt):QWidget(pwgt)
                                   , m_settings("BHV","MyProgram")
{

    m_plbl = new QLabel();
    m_ptxt = new QTextEdit();
    m_pcbo = new QComboBox();
    m_pchk = new QCheckBox("Disable edit");

    m_pcbo->addItem("Classic");
    m_pcbo->addItem("Borland");

    connect(m_pchk, &QCheckBox::clicked,
            this, &MyProgram::slotCheckBoxClicked);

    connect(m_pcbo, &QComboBox::activated,
            this, &MyProgram::slotComboBoxActivated);

    readSettings();

    //layout
    QVBoxLayout* vLayout = new QVBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();

    vLayout->setContentsMargins(5,5,5,5);
    hLayout->setSpacing(15);
    vLayout->setSpacing(15);

    vLayout->addWidget(m_plbl);
    vLayout->addWidget(m_ptxt);

    hLayout->addWidget(m_pcbo);
    hLayout->addWidget(m_pchk);

    vLayout->addLayout(hLayout);
    setLayout(vLayout);
}

MyProgram::~MyProgram()
{
    writeSettings();
}

void MyProgram::writeSettings()
{
    m_settings.beginGroup("/Settings");
    m_settings.setValue("/counter", m_nCounter);
    m_settings.setValue("/text", m_ptxt->toPlainText());
    m_settings.setValue("/width", width());
    m_settings.setValue("/height", height());
    m_settings.setValue("/highlight", m_pcbo->currentIndex());
    m_settings.setValue("/edit", m_pchk->isChecked());

    m_settings.endGroup();

}

void MyProgram::readSettings()
{
    m_settings.beginGroup("/Settings");

    QString strText     = m_settings.value("/text", "").toString();
    int     nWidth      = m_settings.value("/width", width()).toInt();
    int     nHeight     = m_settings.value("/height", height()).toInt();
    int     nComboItem  = m_settings.value("/highlight", 0).toInt();
    bool    bEdit       = m_settings.value("/edit", false).toBool();

    m_nCounter = m_settings.value("/counter", 1).toInt();
    QString str = QString().setNum(m_nCounter++);
    m_plbl->setText("This program has been started " +str+ " times");
    m_ptxt->setPlainText(strText);

    resize(nWidth,nHeight);

    m_pchk->setChecked(bEdit);
    slotCheckBoxClicked();

    m_pcbo->setCurrentIndex(nComboItem);
    slotComboBoxActivated(nComboItem);

    m_settings.endGroup();
}

void MyProgram::slotCheckBoxClicked()
{
    m_ptxt->setEnabled(!m_pchk->isChecked());
}

void MyProgram::slotComboBoxActivated(int n)
{
    QPalette pal = m_ptxt->palette();
    pal.setColor(QPalette::Active,
                 QPalette::Base,
                 n?Qt::yellow:Qt::black
                   );
    pal.setColor(QPalette::Active,
                 QPalette::Text,
                 n?Qt::black:Qt::green
                   );

    m_ptxt->setPalette(pal);
}
