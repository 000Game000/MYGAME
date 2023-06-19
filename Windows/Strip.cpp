#include "Strip.h"
#include "ui_Strip.h"
#include<QPainter>
#include<QDir>
#include<QPaintEvent>
Strip::Strip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Strip)
{
    ui->setupUi(this);
    this->frame=10;
    this->maxValue=1;
    this->nowValue=1;
}

Strip::~Strip()
{
    delete ui;
}

long long Strip::getMaxValue() const
{
    return maxValue;
}

void Strip::setMaxValue(long long newMaxValue)
{
    maxValue = newMaxValue;
    update();
}

long long Strip::getNowValue() const
{
    return nowValue;
}

void Strip::setNowValue(long long newNowValue)
{
    nowValue = newNowValue;
    update();
}

void Strip::paintEvent(QPaintEvent*)
{
    QString str=":/System/D:/img/coc2/korg_dosed_dicked.png";
    QPainter painter(this);
    int x=this->width()-this->frame*2;
    double dx=x*(((double)nowValue)/maxValue);
    if(nowValue<=0){
        dx=0;
    }
    painter.drawPixmap(0,0,this->width(),this->height(),QPixmap(str));
    painter.drawPixmap(this->frame+dx,this->frame,this->width()-2*this->frame-dx,this->height()-2*this->frame,QPixmap(":/System/white.png"));
}

long long Strip::getFrame() const
{
    return frame;
}

void Strip::setFrame(long long newFrame)
{
    frame = newFrame;
    update();
}

QString Strip::getBackground() const
{
    return background;
}

void Strip::setBackground(const QString &newBackground)
{
    background = newBackground;
}

QString Strip::getProspect() const
{
    return prospect;
}

void Strip::setProspect(const QString &newProspect)
{
    prospect = newProspect;
}
