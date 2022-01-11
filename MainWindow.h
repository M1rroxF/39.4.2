#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

//
#include <QString>
#include <QFileDialog>
#include <QGraphicsBlurEffect>
#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include <QPainter>
#include <QRectF>

#include <QWidget>
//widgets
#include <QSlider>
#include <QLabel>
#include <QImage>

using namespace std;


QImage blurImage(QImage source, int radius) {
    if (source.isNull()) return QImage();
    QGraphicsScene scene;
    QGraphicsPixmapItem item;
    item.setPixmap(QPixmap::fromImage(source));
    //
    auto* blur = new QGraphicsBlurEffect;
    blur->setBlurRadius(radius);
    item.setGraphicsEffect(blur);
    scene.addItem(&item);
    QImage result(source.size(), QImage::Format_ARGB32);
    result.fill(Qt::transparent);
    QPainter painter(&result);
    scene.render(&painter, QRectF(),
                 QRectF(0, 0, source.width(), source.height()));
    return result;
    return QImage();
}

class MainWindow: public QMainWindow
{
    Q_OBJECT

public:
    QSlider* slider;
    QLabel* label;
    QImage sourceImage;

    MainWindow(QWidget* parent = nullptr): QMainWindow(parent) {}

public slots:
    void setBlur(int blurRadius) {
        QImage img = blurImage(sourceImage, blurRadius);
        label->setPixmap(QPixmap::fromImage(img.scaled(
                                            sourceImage.width(),
                                            sourceImage.height(),
                                            Qt::KeepAspectRatio)));
        update();
    }
    void openNewImg() {
        QString filePath;
        filePath = QFileDialog::getOpenFileName(nullptr,
                                                "Open png",
                                                "C:/",
                                                "png files (*.png)");
        sourceImage.load(filePath);
        setBlur(0);
    }
};

#endif // MAINWINDOW_H
