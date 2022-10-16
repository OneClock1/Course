#ifndef USER_H
#define USER_H

#include <QObject>

class User
{


public:
    static qint32 Count;

    User(qint32 socket, QString name);
    qint32 GetId();
    qint32 GetSocket();
    QString GetName();

private:
    qint32 id;
    QString name;
    qint32 socket;

};

#endif // USER_H
