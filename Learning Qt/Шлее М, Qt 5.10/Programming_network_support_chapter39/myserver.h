#ifndef MYSERVER_H
#define MYSERVER_H

#include <QtWidgets>
#include <QTcpServer>
#include <QTcpSocket>

class MyServer:public QWidget
{
    Q_OBJECT
private:
    QTcpServer* m_ptcpServer;
    QTextEdit*  m_ptxt;
    qint16      m_nNextBlockSize;

    void sendToClient(QTcpSocket* pSocket, const QString& str);
public:
    MyServer(int nPort, QWidget* pwgt = 0);

public slots:
    virtual void slotNewConnection();
            void slotReadClient();
};

#endif // MYSERVER_H
