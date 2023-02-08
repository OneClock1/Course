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

private:
    QTcpSocket *socket;
    QVector <QTcpSocket*> socketVector;
    QByteArray data;
    quint16 nextBlockSize;


    void sendToClients(QString str);
    void sendToClient(QString str);


public slots:
    void incomingConnection(qintptr socketDescriptor);

    void slotReadyRead();
    void slotDisconected();

};
#endif // SERVER_H
