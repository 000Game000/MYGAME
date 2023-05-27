#include "ColorSelection.h"
#include "ui_ColorSelection.h"

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
    color = newColor;
    QPalette p(this->palette());
    p.setColor(QPalette::Window,this->color);
    this->setAutoFillBackground(true);
    this->setPalette(p);
    this->show();
}

void ColorSelection::mouseReleaseEvent(QMouseEvent *)
{
    this->setColor(QColorDialog::getColor(Qt::white,this,tr("选择颜色")));
    emit this->clicked();
}
