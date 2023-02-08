#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    socket = new QTcpSocket(this);
    connect(socket, &QTcpSocket::readyRead, this, &MainWindow::slotReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::slotDisconected);

    nextBlockSize = 0;
    socket->connectToHost("192.168.0.111", 23235);

    if(!socket->waitForConnected(1000))
    {
        QMessageBox::critical(this, tr("Проблемим з підключеням до сервера!"),
                                 tr("Попробуйте перезапустити додаток.\n"
                                    "\nЯкщо вище вказане не вирішить проблему будь ласка, звернітся за допомогою до розробника через Email: maltsevcorp@gmail.com ."), QMessageBox::Ok);

    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sendToServer(QString str)
{
    data.clear();
    QDataStream out(&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_6_3);
    str = username +": "+ str;
    out << quint16(0) << QTime::currentTime() << str;
    out.device()->seek(0);
    out << quint16(data.size() - sizeof(quint16));
    socket->write(data);
    ui->lineEdit->clear();
}

void MainWindow::slotReadyUsername(QString name)
{
    username = name;
}
void MainWindow::slotDisconected()
{
    socket->deleteLater();
}

void MainWindow::slotReadyRead()
{
    QTime time;
    QDataStream in(socket);
    in.setVersion(QDataStream::Qt_6_3);
    if(in.status() == QDataStream::Ok)
    {
        while(true)
        {
            if(nextBlockSize == 0)
            {
                if(socket->bytesAvailable() < 2)
                {
                    break;
                }
                in >> nextBlockSize;
            }
            if(socket->bytesAvailable() < nextBlockSize)
            {
                break;
            }
            QString str;
            in >> time >> str;
            nextBlockSize = 0;
            ui->textBrowser->append(time.toString() + " " + str);
        }
    }
    else
    {
        ui->textBrowser->append(time.toString() + " read error");
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    if(ui->lineEdit->text() != " " && ui->lineEdit->text() != "")
    {

        sendToServer(ui->lineEdit->text());
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    on_pushButton_2_clicked();
}

void MainWindow::on_action_triggered()
{
    QMessageBox::information(this, tr("Відомоті про програму"),
                             tr("Програма створена під час курсової роботи, для системного програмування.\n"
                                "\n\tРозробник:\t\tМальцев Анатолій Анатолійович"
                                "\n\tНавчальний заклад:\t«Тернопільський Фаховий Коледж Тернопільського Національного Технічного Університету Імені Івана Пулюя»"
                                "\n\tГрупа:\t\t\tKI-412"
                                "\n\tEmail:\t\t\tmaltsevcorp@gmail.com"), QMessageBox::Ok);
}


void MainWindow::on_action_2_triggered()
{
    QMessageBox::information(this, tr("Як користуватися?"),
                             tr("Користуватися можна за допомогою вводу тексту в рядок, при нажимані кнопки відправити або клавіши enter, відправляєтся ваше повідомлення."), QMessageBox::Ok);
}


void MainWindow::on_action_3_triggered()
{
    QMessageBox::information(this, tr("Що робити, якщо виникли якісь проблеми, з роботою додатку?"),
                             tr("Якщо в додатку виникли якісь проблеми - попробуйте перезапустити його.\n\n"
                                "Якщо вище сказане не допомогло, будь ласка звернітся до розробника за допомогою через Email: maltsevcorp@gmail.com ."), QMessageBox::Ok);
}

