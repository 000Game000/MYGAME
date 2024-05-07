#include "Nipple.h"
#include "Modules/Modules.h"
namespace MYGAME{
long long Nipple::getLength() const
{
    return length;
}

void Nipple::setLength(long long newLength)
{
    length = newLength;
}

long long Nipple::getDiameter() const
{
    return diameter;
}

void Nipple::setDiameter(long long newDiameter)
{
    diameter = newDiameter;
}

long long Nipple::getDuctusLactiferiDiameter() const
{
    return ductusLactiferiDiameter;
}

void Nipple::setDuctusLactiferiDiameter(long long newDuctusLactiferiDiameter)
{
    ductusLactiferiDiameter = newDuctusLactiferiDiameter;
}

QColor Nipple::getColor() const
{
    return color;
}

void Nipple::setColor(const QColor &newColor)
{
    color = newColor;
}

Nipple::Nipple(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter,long long ductusLactiferiDiameter,QColor color)
    :PositionBase("乳头",rank,EXP,pleasure,count),length(length),diameter(diameter),ductusLactiferiDiameter(ductusLactiferiDiameter),color(color)
{

}

Nipple::Nipple()
{

}

QString Nipple::save()
{
    QString str=PositionBase::save()+"\nlength:"+QString::number(this->length)+"\ndiameter:"+QString::number(this->diameter)
                  +"\nductusLactiferiDiameter:"+QString::number(this->ductusLactiferiDiameter)+"\ncolor:";
    int r=0;
    int g=0;
    int b=0;
    this->color.getRgb(&r,&g,&b);
    str+="\nr:"+QString::number(r);
    str+="\ng:"+QString::number(g);
    str+="\nb:"+QString::number(b);
    return str;
}

bool Nipple::load(QTextStream &ts)
{
    PositionBase::load(ts);
    this->length=getValue(ts.readLine()).toLongLong();
    this->diameter=getValue(ts.readLine()).toLongLong();
    this->ductusLactiferiDiameter=getValue(ts.readLine()).toLongLong();
    ts.readLine();
    int r=getValue(ts.readLine()).toInt();
    int g=getValue(ts.readLine()).toInt();
    int b=getValue(ts.readLine()).toInt();
    this->color.setRgb(r,g,b);
    return true;
}
}
