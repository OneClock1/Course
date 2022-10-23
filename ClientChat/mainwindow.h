#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QTcpSocket>
#include <QTime>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_lineEdit_returnPressed();

    void on_action_triggered();

    void on_action_2_triggered();

    void on_action_3_triggered();

private:

    QString username;
    Ui::MainWindow *ui;
    QTcpSocket *socket;
    QByteArray Data;
    quint16 nextBlockSize;
    void SendToServer(QString str);

public slots:
    void slotReadyUsername(QString username);
    void slotReadyRead();
    void slotDisconected();

};
#endif // MAINWINDOW_H
