#ifndef SDIPROGRAM_H
#define SDIPROGRAM_H

#include <QtWidgets>
#include "docwindow.h"

class SDIProgram : public QMainWindow
{
    Q_OBJECT
public:
    SDIProgram(QWidget* pwgt = 0);

public slots:
    void slotAbout();
    void slotChangeWindowTitle(const QString& str);
};

#endif // SDIPROGRAM_H
