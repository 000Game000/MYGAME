#include "Vagina.h"
#include "Modules/Modules.h"
namespace MYGAME{
long long Vagina::getMaximumDiameter() const
{
    return maximumDiameter;
}

void Vagina::setMaximumDiameter(long long newMaximumDiameter)
{
    maximumDiameter = newMaximumDiameter;
}

long long Vagina::getLength() const
{
    return length;
}

void Vagina::setLength(long long newLength)
{
    length = newLength;
}

QColor Vagina::getColor() const
{
    return color;
}

void Vagina::setColor(const QColor &newColor)
{
    color = newColor;
}

Vagina::Vagina(long long rank, long long EXP, long long pleasure, long long count,long long maximumDiameter,long long length,QColor color)
    :PositionBase("阴道",rank,EXP,pleasure,count),maximumDiameter(maximumDiameter),length(length),color(color)
{

}

Vagina::Vagina()
{

}

QString Vagina::save()
{
    QString str=PositionBase::save()+"\nmaximumDiameter:"+QString::number(this->maximumDiameter)+"\nlength:"+QString::number(this->length)
                  +"\ncolor:";
    int r=0;
    int g=0;
    int b=0;
    this->color.getRgb(&r,&g,&b);
    str+="\nr:"+QString::number(r);
    str+="\ng:"+QString::number(g);
    str+="\nb:"+QString::number(b);
    return str;
}

bool Vagina::load(QTextStream &ts)
{
    PositionBase::load(ts);
    this->maximumDiameter=getValue(ts.readLine()).toLongLong();
    this->length=getValue(ts.readLine()).toLongLong();
    ts.readLine();
    int r=getValue(ts.readLine()).toInt();
    int g=getValue(ts.readLine()).toInt();
    int b=getValue(ts.readLine()).toInt();
    this->color.setRgb(r,g,b);
    return true;
}
long long maximumDiameter=10;                                      //现有最大直径单位mm萝莉10mm,成年20mm~30mm
long long length=70;                                               //长度单位mm 萝莉40mm~70mm成人70mm~120mm
QColor color;                                                      //阴唇颜色
}
