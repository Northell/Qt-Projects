#ifndef PROGRESS_H
#define PROGRESS_H


#include <QtWidgets>
#include <QObject>


//class QProgressBar; //Непонятная хрень, на приложение никак не влияет

class Progress:public QWidget
{
    Q_OBJECT
private:
    QProgressBar* m_pprb;
    int           m_nStep;
    QLabel*       lbl;

public:
    Progress(QWidget* pobj = 0);


public slots:
    void slotStep();
    void slotReset();




};

#endif // PROGRESS_H
