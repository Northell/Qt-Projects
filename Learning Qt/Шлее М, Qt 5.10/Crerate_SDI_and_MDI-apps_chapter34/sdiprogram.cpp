#include "sdiprogram.h"

SDIProgram::SDIProgram(QWidget *pwgt):QMainWindow(pwgt)
{
    QMenu* pmnuFile = new QMenu("&File");
    QMenu* pmnuHelp = new QMenu("&Help");
    DocWindow* pdoc = new DocWindow();

    pmnuFile->addAction("&Open...",
                        pdoc,
                        SLOT(slotLoad()),
                        QKeySequence("CTRL+O")
                        );

    pmnuFile->addAction("&Save",
                        pdoc,
                        SLOT(slotSave()),
                        QKeySequence("CTRL+S")
                        );

    pmnuFile->addAction("&Save As...",
                        pdoc,
                        SLOT(slotSaveAs()),
                        QKeySequence("CTRL+O")
                        );

    pmnuFile->addSeparator();

    pmnuFile->addAction("&Quit...",
                        pdoc,
                        SLOT(quit()),
                        QKeySequence("CTRL+Q")
                        );

    pmnuFile->addAction("&About...",
                        pdoc,
                        SLOT(slotAbout()),
                        Qt::Key_F1
                        );

    menuBar()->addMenu(pmnuFile);
    menuBar()->addMenu(pmnuHelp);

    setCentralWidget(pdoc);

    connect(pdoc,
            SIGNAL(changeWindowTitle(const QString&)),
            SLOT  (slotChangeWIndowTitle(const QString&))
            );
    statusBar()->showMessage("Ready", 2000);

}

void SDIProgram::slotAbout()
{
    QMessageBox::about(this, "Application", "SDI Example");
}

void SDIProgram::slotChangeWindowTitle(const QString &str)
{
    setWindowTitle(str);
}
