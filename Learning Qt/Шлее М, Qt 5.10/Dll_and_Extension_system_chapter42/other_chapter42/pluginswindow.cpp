#include "pluginswindow.h"

PluginsWIndow::PluginsWIndow(QWidget *pwgt):QMainWindow(pwgt)
{
    m_plbl = new QLabel("This is an example tex");
    m_pmnuPlugins = new QMenu ("&PluginOperations");

    loadPlugins();
    setCentralWidget(m_plbl);
    menuBar()->addMenu(m_pmnuPlugins);
}

void PluginsWIndow::loadPlugins()
{
    QDir dir(QCoreApplication::applicationDirPath());
#ifdef Q_OS_OSX
    dir.cdUp();
#endif
    if (!dir.cd("plugins"))
    {
        QMessageBox::critical(0, "", "plugins directory does not exist");
        return;
    }

    foreach(QString strFileName, dir.entryList(QDir::Files))
    {
        QPluginLoader loader(dir.absoluteFilePath(strFileName));
        addToMenu(qobject_cast<QObject*>(loader.instance()));
    }
}

void PluginsWIndow::addToMenu(QObject *pobj)
{
    if(!pobj)
    {
        return;
    }

    StringInterface* pI = qobject_cast<StringInterface*>(pobj);
    if(pI)
    {
        QStringList lstOperations = pI->operations();
        foreach(QString str, lstOperations)
        {
            QAction* pact = new QAction(str,pobj);
            connect(pact, SIGNAL(triggered()),
                    this, SLOT(slotStringOperation()));
            m_pmnuPlugins->addAction(pact);
        }
    }
}

void PluginsWIndow::slotStringOperation()
{
    QAction* pact = qobject_cast<QAction*>(sender());
    StringInterface* pI = qobject_cast<StringInterface*> (pact->parent());
    m_plbl->setText(pI->operation(m_plbl->text(), pact->text()));
}
