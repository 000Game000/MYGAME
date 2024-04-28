#include "Clit.h"
#include "Modules/Modules.h"
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

Clit::Clit()
{

}

QString Clit::save()
{
    QString str=PositionBase::save()+"\nlength:"+QString::number(this->length)+"\ndiameter:"+QString::number(this->diameter);
    return str;
}

bool Clit::load(QTextStream &ts)
{
    PositionBase::load(ts);
    this->length=getValue(ts.readLine()).toLongLong();
    this->diameter=getValue(ts.readLine()).toLongLong();
    return true;
}
}
