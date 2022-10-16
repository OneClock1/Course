#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QTime>

class Server : public QTcpServer
{
    Q_OBJECT

public:
    Server();
    QTcpSocket *socket;

private:
    QVector <QTcpSocket*> Sockets;
    QByteArray Data;
    quint16 nextBlockSize;


    void SendToClients(QString str);
    void SendToClient(QString str);


public slots:
    void incomingConnection(qintptr socketDescriptor);

    void slotReadyRead();
    void slotDisconected();
};
#endif // SERVER_H
