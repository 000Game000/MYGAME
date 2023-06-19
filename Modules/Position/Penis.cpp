#include "Penis.h"
namespace MYGAME{
long long Penis::getDiameter() const
{
    return diameter;
}

void Penis::setDiameter(long long newDiameter)
{
    diameter = newDiameter;
}

long long Penis::getSemen() const
{
    return semen;
}

void Penis::setSemen(long long newSemen)
{

    semen = newSemen;
}

DickSize Penis::getDickSize() const
{
    return dickSize;
}

void Penis::show()
{
    qDebug()<<"Penis类";
}

Penis::Penis()
{
    this->name="阴茎";
    this->rank=2;
    this->EXP=0;
    this->count=0;
    this->pleasure=0;
    this->diameter=10;
    this->dickSize=Lovely;
}
}
