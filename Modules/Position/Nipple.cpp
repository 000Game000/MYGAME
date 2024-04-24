#include "Nipple.h"
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
}
