#include "server.h"


Server::Server()
{
    if(this->listen(QHostAddress::AnyIPv4, 23235))
    {
        qDebug() << "Start.";
    }
    else
    {
        qDebug() << "Error.";
    }
    nextBlockSize = 0;


}
void Server::incomingConnection(qintptr socketDescriptor)
{
    socket = new QTcpSocket;
    socket->setSocketDescriptor(socketDescriptor);

    connect(socket, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
    connect(socket, SIGNAL(disconnected()), this, SLOT(slotDisconected()));

    socketVector.push_back(socket);
    qDebug()<<"Client connected." << socketDescriptor;

    sendToClient("Ви успішно підключились.");
}
void Server::slotDisconected()
{
    qDebug()<<&socket<<" Client disconected.";
    for(int i = 0; i < socketVector.size(); i++)
    {
        if(socket == socketVector[i])
        {
            socketVector.removeAt(i);
            socket->deleteLater();
            break;
        }
    }

}

void Server::slotReadyRead()
{
    socket = (QTcpSocket*)sender();
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_3);

    if(in.status() == QDataStream::Ok)
    {
        qDebug() << "read...";

        for(;;)
        {

            if(nextBlockSize == 0)
            {
                qDebug() << "nextBlockSize = 0.";
                if(socket->bytesAvailable() < 2)
                {
                    qDebug() << "Data < 2, break";
                    break;
                }
                in >> nextBlockSize;
                 qDebug() << "nextBlockSize = "<< nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                 qDebug() << "Data not full,  break";
                break;
            }

            QString str;
            QTime time;
            in >> time >> str;
            nextBlockSize = 0;
            sendToClients(str);
            break;
        }
    }
    else
    {
        qDebug() << "DataStream error";
    }
}

void Server::sendToClient(QString str)
{

    data.clear();

    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);

}

void Server::sendToClients(QString str)
{

    data.clear();

    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));

    for(int i = 0; i < socketVector.size(); i++)
    {
         socketVector[i]->write(data);

    }
}



