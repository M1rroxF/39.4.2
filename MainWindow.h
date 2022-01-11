#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPlainTextEdit>
#include <QWebEngineView>

using namespace std;

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    QWebEngineView* viewer;
    QPlainTextEdit* txtEditor;

    MainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

public slots:
    void loadHtmlCode() { viewer->setHtml(txtEditor->toPlainText()); }
};

#endif // MAINWINDOW_H
