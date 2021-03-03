#include "filefinder.h"

void FileFinder::start(const QDir &dir)
{
    QApplication::processEvents();

    QStringList listFiles =
            dir.entryList(m_ptxtMask->text().split(" "), QDir::Files);

    foreach(QString file, listFiles)
    {
        m_ptxtResult->append(dir.absoluteFilePath(file));
    }

    QStringList listDir = dir.entryList(QDir::Dirs);

    foreach(QString subdir, listDir)
    {
        if(subdir == "."||subdir == "..")
        {
            continue;
        }
        start(QDir(dir.absoluteFilePath(subdir)));
    }
}

FileFinder::FileFinder(QWidget *pwgt):QWidget(pwgt)
{
    m_ptxtDir    = new QLineEdit(QCoreApplication::applicationDirPath());
    m_ptxtMask   = new QLineEdit("*");
    m_ptxtResult = new QTextEdit();

    QLabel* plblDir = new QLabel ("&Directory");
    QLabel* plblMask = new QLabel("&Mask");
    QPushButton* pcmdDir = new QPushButton(QPixmap(":/img1"), "");
    QPushButton* pcmdFind = new QPushButton("&Find");

    connect(pcmdDir, &QPushButton::clicked, this, &FileFinder::slotBrowse);
    connect(pcmdFind, &QPushButton::clicked, this, &FileFinder::slotFind);

    plblDir->setBuddy(m_ptxtDir);
    plblMask->setBuddy(m_ptxtMask);

    //layout
    QGridLayout* layout = new QGridLayout();
    layout->setContentsMargins(5,5,5,5);
    layout->setSpacing(15);

    layout->addWidget(plblDir, 0,0);
    layout->addWidget(plblMask,1,0);
    layout->addWidget(m_ptxtDir,0,1);
    layout->addWidget(m_ptxtMask,1,1);

    layout->addWidget(pcmdDir,0,2);
    layout->addWidget(pcmdFind,1,2);

    layout->addWidget(m_ptxtResult,2,0,1,3);

    setLayout(layout);

}

void FileFinder::slotBrowse()
{
    QString str= QFileDialog::getExistingDirectory(0,
                                                   "Select a Directory",
                                                   m_ptxtDir->text());

    if(!str.isEmpty())
    {
        m_ptxtDir->setText(str);
    }
}

void FileFinder::slotFind()
{
    start(QDir(m_ptxtDir->text()));
}
