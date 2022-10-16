
#include "loginwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    mainWindow = new MainWindow;
    connect(this, &LoginWindow::signal, mainWindow, &MainWindow::slotReadyUsername);

}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{

    username = ui->lineEdit->text();

    if(checkUsername(username)&& username != "")
    {
        hide();
        mainWindow->show();
        emit signal(username);


    }
    else
    {

     QMessageBox::information(this, tr("Не коректне імя!"),tr("Будь лакса, введіть імя без пропусків та спец. символів.\n\n"
                                                              "Потрібна мінімальна кількість символів: 3."), QMessageBox::Ok);
    }
}


void LoginWindow::on_lineEdit_returnPressed()
{
    on_pushButton_clicked();
}
bool LoginWindow::checkUsername(QString name)
{
    for(int i = 0; name.length() > i; i++ )
    {
        if(name[i] != '/' && name[i] != ' ' && name[i] != '.' && name.length() >= 3)
        {
            return true;

        }
    }
    return false;

}

