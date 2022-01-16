#include <QApplication>
#include <./ui_mainwindow.h>
#include <MainWindow.h>

using namespace std;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    //
    auto* window = new MainWindow();
    auto* number = new Ui::MainWindow();

    //
    number->setupUi(window);
    number->lineEdit = window->lineEdit;
    number->label = window->label;

    //
    window->show();

    return QApplication::exec();
}
