#include "user.h"

User::User(qint32 socket, QString name)
{
    this->socket = socket;
    this->name = name;
    Count++;
    id = Count;
}
qint32 User::GetId()
{
    return id;
}
int GetSocket();
QString GetName();

