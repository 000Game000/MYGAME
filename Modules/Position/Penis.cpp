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

Penis::Penis():PositionBase("阴茎",2,0,0,0)
{
    this->diameter=10;
    this->dickSize=Lovely;
}

QString Penis::save()
{
    QString str=PositionBase::save()+"\ndiameter:"+QString::number(this->diameter)+"\nsemen:"+QString::number(this->semen)
                  +"\ndickSize:"+QString::number(this->dickSize);
    return str;
}
}
