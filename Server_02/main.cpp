#include <QCoreApplication>
#include "server.h"
#include <locale>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server s;


    return a.exec();

}
