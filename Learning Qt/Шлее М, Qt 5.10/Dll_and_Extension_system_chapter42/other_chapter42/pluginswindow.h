#ifndef PLUGINSWINDOW_H
#define PLUGINSWINDOW_H

#include <QMainWindow>
#include "interfaces.h"
#include <QtWidgets>

class PluginsWIndow:public QMainWindow
{
    Q_OBJECT

private:
    QLabel* m_plbl;
    QMenu*  m_pmnuPlugins;
public:
    PluginsWIndow(QWidget* pwgt = 0);

    void loadPlugins();
    void addToMenu(QObject* pobj);

protected slots:
    void slotStringOperation();
};

#endif // PLUGINSWINDOW_H
