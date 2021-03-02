#include "helpbrowser.h"

HelpBrowser::HelpBrowser(const QString &strPath, const QString &strFileName, QWidget *pwgt)
                         :QWidget(pwgt)
{
    QPushButton* pcmdBack      = new QPushButton("<<");
    QPushButton* pcmdHome      = new QPushButton("Home");
    QPushButton* pcmdForward   = new QPushButton(">>");
    QTextBrowser* ptxtBrowser  = new QTextBrowser();

    connect (pcmdBack, SIGNAL (clicked()),
             ptxtBrowser, SLOT (backward()));

    connect (pcmdHome, SIGNAL (clicked()),
             ptxtBrowser, SLOT (home()));

    connect (pcmdForward, SIGNAL (clicked()),
             ptxtBrowser, SLOT (forward()));

    connect (ptxtBrowser, SIGNAL (bacwardAvailable(bool)),
             pcmdBack, SLOT (setEnabled(bool)));

    connect (ptxtBrowser, SIGNAL (forwardAvailable(bool)),
             pcmdForward, SLOT (setEnabled(bool)));

    ptxtBrowser->setSearchPaths(QStringList() << strPath);
    ptxtBrowser->setSource     (QString(strFileName));

    //Layout
    QVBoxLayout* vLayout = new QVBoxLayout();
    QHBoxLayout* hLayout = new QHBoxLayout();

    hLayout->addWidget(pcmdBack);
    hLayout->addWidget(pcmdHome);
    hLayout->addWidget(pcmdForward);

    vLayout->addLayout(hLayout);
    vLayout->addWidget(ptxtBrowser);

    setLayout(vLayout);



}
