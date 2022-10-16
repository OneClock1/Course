/********************************************************************************
** Form generated from reading UI file 'runwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNWINDOW_H
#define UI_RUNWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RunWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *RunWindow)
    {
        if (RunWindow->objectName().isEmpty())
            RunWindow->setObjectName(QString::fromUtf8("RunWindow"));
        RunWindow->resize(387, 351);
        RunWindow->setIconSize(QSize(24, 24));
        centralwidget = new QWidget(RunWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 40, 151, 41));
        QFont font;
        font.setPointSize(22);
        label->setFont(font);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 210, 111, 31));
        QFont font1;
        font1.setPointSize(12);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 210, 101, 31));
        pushButton_2->setFont(font1);
        RunWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(RunWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        RunWindow->setStatusBar(statusbar);

        retranslateUi(RunWindow);

        QMetaObject::connectSlotsByName(RunWindow);
    } // setupUi

    void retranslateUi(QMainWindow *RunWindow)
    {
        RunWindow->setWindowTitle(QCoreApplication::translate("RunWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("RunWindow", "Online chat", nullptr));
        pushButton->setText(QCoreApplication::translate("RunWindow", "login", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RunWindow", "Registration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RunWindow: public Ui_RunWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNWINDOW_H
