#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QtWidgets>
#include <QUdpSocket>
class UDPClient:public QTextEdit
{
    Q_OBJECT
private:
    QUdpSocket* m_pudp;

public:
    UDPClient(QWidget* pwgt = 0);

private slots:
    void slotProcessDatagrams();
};

#endif // UDPCLIENT_H
