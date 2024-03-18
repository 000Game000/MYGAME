#include "ColorView.h"
#include "ui_ColorView.h"

ColorView::ColorView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColorView)
{
    ui->setupUi(this);
}

ColorView::~ColorView()
{
    delete ui;
}

QColor ColorView::getColor() const
{
    return color;
}

void ColorView::setColor(const QColor &newColor)
{
    color = newColor;
    QPalette p(this->palette());
    p.setColor(QPalette::Window,this->color);
    this->setAutoFillBackground(true);
    this->setPalette(p);
}
