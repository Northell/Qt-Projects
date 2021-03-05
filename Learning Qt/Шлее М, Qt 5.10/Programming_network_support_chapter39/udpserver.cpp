#include "udpserver.h"

UDPServer::UDPServer(QWidget *pwgt):QTextEdit(pwgt)
{

    setWindowTitle("UdpServer");
    m_pudp = new QUdpSocket(this);
    QTimer* ptimer = new QTimer(this);
    ptimer->setInterval(500);
    ptimer->start();
    connect(ptimer,SIGNAL(timeout()), SLOT (slotSendDatagram()));
}

void UDPServer::slotSendDatagram()
{
    QByteArray baDataGram;
    QDataStream out (&baDataGram, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_0);
    QDateTime dt = QDateTime::currentDateTime();
    append("Sent: " + dt.toString());
    out<< dt;

    m_pudp->writeDatagram(baDataGram,QHostAddress::LocalHost, 2424);
}
