#include <QApplication>
#include <QObject>
#include <QLineEdit>
#include <QWebEngineView>
#include <QPlainTextEdit>
#include <QWidget>
#include <QHBoxLayout>
#include <./ui_mainwindow.h>
#include <MainWindow.h>

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    //
    auto* window = new MainWindow();
    auto* bluring = new Ui::MainWindow();

    //
    bluring->setupUi(window);
    window->label = bluring->label;
    window->slider = bluring->horizontalSlider;

    //
    bluring->horizontalSlider->setMinimum(0);
    bluring->horizontalSlider->setMaximum(10);

    //
    window->show();

    return QApplication::exec();
}
