#ifndef SHELL_H
#define SHELL_H


#include <QtWidgets>

class Shell:public QWidget
{
    Q_OBJECT
private:
    QProcess*  m_process;
    QLineEdit* m_ptxtCommand;
    QTextEdit* m_ptxtDisplay;

public:
    Shell(QWidget * pwgt =0);

public slots:

    void slotDataOnStdout();
    void slotReturnPressed();
};

#endif // SHELL_H
