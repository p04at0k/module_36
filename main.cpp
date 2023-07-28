#include <QApplication>
#include <QSlider>
#include <QPixmap>
#include <QPainter>
#include <QPaintEvent>
#include <QVBoxLayout>


class ColorfulCircle : public QWidget
{

    Q_OBJECT

public:

    ColorfulCircle(QWidget *parent = nullptr) : QWidget(parent)
    {
        mYellowCircle = QPixmap("A:/C++ and Unreal projects/Qt/yellow");
        mGreenCircle = QPixmap("A:/C++ and Unreal projects/Qt/green");
        mRedCircle = QPixmap("A:/C++ and Unreal projects/Qt/red");
        mCurrentCircle = mGreenCircle;
        setGeometry(mCurrentCircle.rect());
    }

    QSize minimumSizeHint() const override;

public slots:

    void setYellow();
    void setRed();
    void setGreen();

private:

    QPixmap mCurrentCircle;
    QPixmap mYellowCircle;
    QPixmap mGreenCircle;
    QPixmap mRedCircle;

    void paintEvent(QPaintEvent *e) override
    {
        QPainter p(this);
        p.drawPixmap(e->rect(),mCurrentCircle);
    }
};

void ColorfulCircle::setYellow()
{
    mCurrentCircle = mYellowCircle;
    update();
}

void ColorfulCircle::setRed()
{
    mCurrentCircle = mRedCircle;
    update();
}

void ColorfulCircle::setGreen()
{
    mCurrentCircle = mGreenCircle;
    update();
}

QSize ColorfulCircle::minimumSizeHint() const
{
    return QSize(100,100);
}

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setFixedSize(430,450);

    auto *layout = new QVBoxLayout;
    ColorfulCircle *circle = new ColorfulCircle;
    auto *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0, 100);


    layout->addWidget(circle);
    layout->addWidget(slider);
    window.setLayout(layout);

    QObject::connect(slider, &QSlider::valueChanged, [&circle](int newValue)
    {
        if (newValue <= 33)  circle->setGreen();
        else if (newValue <= 66) circle->setYellow();
        else circle->setRed();
    });

    window.show();
    app.exec();
}

#include <main.moc>
