#ifndef UDPSERVER_H
#define UDPSERVER_H

#include <QUdpSocket>
#include <QtWidgets>

class UDPServer:public QTextEdit
{
    Q_OBJECT
private:
    QUdpSocket* m_pudp;

public:
    UDPServer(QWidget* pwgt = 0);

public slots:
    void slotSendDatagram();
};

#endif // UDPSERVER_H
