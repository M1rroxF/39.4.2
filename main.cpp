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
    auto* editor = new Ui::MainWindow();

    //
    editor->setupUi(window);
    window->txtEditor = editor->plainTextEdit;
    window->viewer = editor->widget;

    //
    window->show();

    return QApplication::exec();
}
