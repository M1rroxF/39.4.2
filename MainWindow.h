#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMainWindow>
#include <QString>
#include <QLineEdit>
#include <QLabel>
#include <QRegularExpression>

using namespace std;

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    QLabel* label;
    QLineEdit* lineEdit;

    MainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

public slots:
    void textChecked(QString text) {
        QRegularExpression exp("^+(\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d\\d)$");
        if (exp.match(text).hasMatch()) {
            label->setText("Ok");
            label->setStyleSheet("QLabel {color : green}");
        }
        else {
            label->setText("Not ok");
            label->setStyleSheet("QLabel {color : red}");
        }
    }
};

#endif // MAINWINDOW_H
