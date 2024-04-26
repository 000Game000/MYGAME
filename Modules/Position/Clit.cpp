#include "Clit.h"
namespace MYGAME{
long long Clit::getLength() const
{
    return length;
}

void Clit::setLength(long long newLength)
{
    length = newLength;
}

long long Clit::getDiameter() const
{
    return diameter;
}

void Clit::setDiameter(long long newDiameter)
{
    diameter = newDiameter;
}

Clit::Clit(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter)
    :PositionBase("阴蒂",rank,EXP,pleasure,count),length(length),diameter(diameter)
{

}

QString Clit::save()
{
    QString str=PositionBase::save()+"\nlength:"+QString::number(this->length)+"\ndiameter:"+QString::number(this->diameter);
    return str;
}
}
