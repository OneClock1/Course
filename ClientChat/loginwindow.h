#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include <mainwindow.h>
#include <QMessageBox>


namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_pushButton_clicked();

    void on_lineEdit_returnPressed();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    QString username;
    bool checkUsername(QString username);

signals:
    void signal(QString username);
};

#endif // LOGINWINDOW_H
