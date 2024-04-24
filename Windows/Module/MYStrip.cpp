#include "MYStrip.h"
#include "ui_MYStrip.h"
#include<QPainter>

MYStrip::MYStrip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MYStrip)
{
    ui->setupUi(this);
    this->frame=1;
}

MYStrip::~MYStrip()
{
    delete ui;
}

unsigned long long MYStrip::getMaxValue() const
{
    return maxValue;
}

void MYStrip::setMaxValue(unsigned long long newMaxValue)
{
    maxValue = newMaxValue;
    update();
}

unsigned long long MYStrip::getNowValue() const
{
    return nowValue;
}

void MYStrip::setNowValue(unsigned long long newNowValue)
{
    nowValue = newNowValue;
    update();
}

unsigned long long MYStrip::getFrame() const
{
    return frame;
}

void MYStrip::setFrame(unsigned long long newFrame)
{
    frame = newFrame;
    update();
}

QString MYStrip::getBackground() const
{
    return background;
}

void MYStrip::setBackground(const QString &newBackground)
{
    background = newBackground;
    update();
}

QString MYStrip::getProspect() const
{
    return prospect;
}

void MYStrip::setProspect(const QString &newProspect)
{
    prospect = newProspect;
    update();
}

void MYStrip::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    int x=this->width();
    //int x=this->width()-this->frame*2;
    double dx=x*(((double)nowValue)/maxValue);
    if(nowValue<=0){
        dx=0;
    }
    // qDebug()<<x;
    // qDebug()<<dx;
    // qDebug()<<"";
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(this->background));
    painter.drawPixmap(this->frame+dx,this->frame,this->width()-2*this->frame-dx,this->height()-2*this->frame,QPixmap(this->prospect));
}
