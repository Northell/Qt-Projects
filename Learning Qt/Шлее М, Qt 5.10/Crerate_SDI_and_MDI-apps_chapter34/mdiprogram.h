#ifndef MDIPROGRAM_H
#define MDIPROGRAM_H

#include <QtWidgets>
#include "docwindow.h"

class MDIProgram:public QMainWindow
{
    Q_OBJECT
private:
    QMdiArea*      m_pma;
    QMenu*         m_pmnuWindows;
    QSignalMapper* m_psigMapper;

    DocWindow* createNewDoc();

public:
    MDIProgram(QWidget* pwgt = 0);

private slots:
    void slotChangeWindowTitle(const QString&);

private slots:
    void slotNewDoc();
    void slotLoad();
    void slotSave();
    void slotSaveAs();
    void slotAbout();
    void slotWindows();
    void slotSetActiveSubWindow(QObject* pwgt);
};

#endif // MDIPROGRAM_H
