#include "Vagina.h"
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
}
