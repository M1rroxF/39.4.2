#include <QApplication>
#include <QObject>
#include <QPixmap>
#include <QPaintEvent>
#include <QPainter>
#include <QSlider>
#include <QPushButton>
#include <QTimer>
#include <QMediaPlayer>

//your path to image button down
#define PATH_IMG_BUTTON_DOWN R"(D:\Programming\c++\QtProjects\origin\ButtonDown.png)"
//your path to image button up
#define PATH_IMG_BUTTON_UP R"(D:\Programming\c++\QtProjects\origin\ButtonUp.png)"
//your path to mp3 button sound
#define PATH_MP3_BUTTON_SOUND R"(D:\Programming\c++\QtProjects\origin\buttonDown.mp3)"


using namespace std;

class ImageButton : public QPushButton
{
Q_OBJECT
    QMediaPlayer* player = new QMediaPlayer;
    QPixmap QPixCurrent;
    QPixmap QPixButtonUp;
    QPixmap QPixButtonDown;
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
public slots:
    void setDown();
    void setUp();
};

ImageButton::ImageButton(QWidget *parent) {
    setParent(parent);
    setToolTip("Color");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    QPixButtonDown = QPixmap(PATH_IMG_BUTTON_DOWN);
    QPixButtonUp = QPixmap(PATH_IMG_BUTTON_UP);
    QPixCurrent = QPixButtonUp;
    setGeometry(QPixCurrent.rect());
    player->setMedia(QUrl::fromLocalFile(PATH_MP3_BUTTON_SOUND));
    player->setVolume(75);
    QObject::connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
}
void ImageButton::paintEvent(QPaintEvent *e) {
    QPainter painter(this);
    painter.drawPixmap(e->rect(), QPixCurrent);
}
QSize ImageButton::sizeHint() const {
    return {250, 250};
}
QSize ImageButton::minimumSizeHint() const {
    return sizeHint();
}
void ImageButton::setDown() {
    QPixCurrent = QPixButtonDown;
    update();

    player->play();

    QTimer::singleShot(100, this, &ImageButton::setUp);
}
void ImageButton::setUp() {
    QPixCurrent = QPixButtonUp;
    update();
}

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    //
    auto* button = new ImageButton(nullptr);
    button->show();

    return QApplication::exec();
}

#include <main.moc>
