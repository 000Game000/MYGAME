#include "ColorSelection.h"
#include "ui_ColorSelection.h"
#include<QPainter>
ColorSelection::ColorSelection(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorSelection)
{
    ui->setupUi(this);
}

ColorSelection::~ColorSelection()
{
    delete ui;
}

QColor ColorSelection::getColor() const
{
    return color;
}

void ColorSelection::setColor(const QColor &newColor)
{
    this->color = newColor;
//    int a;
//    int b;
//    int c;
//    int d;
//    this->color.getRgb(&a,&b,&c,&d);
//    qDebug()<<a<<b<<c<<d;
    QPalette p(this->palette());
    p.setColor(QPalette::Window,this->color);
    this->setAutoFillBackground(true);
    this->setPalette(p);
    this->update();
}

void ColorSelection::setColor(int R, int G, int B, int A)
{
    setColor(qRgba(R,G,B,A));
}

void ColorSelection::mouseReleaseEvent(QMouseEvent *)
{
    this->setColor(QColorDialog::getColor(Qt::white,this,tr("选择颜色")));
    emit this->clicked();
}
