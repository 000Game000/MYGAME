#include "Breast.h"
namespace MYGAME{
const long double PI=3.141592654;

double Breast::getMilkYield() const
{
    return milkYield;
}

void Breast::setMilkYield(double newMilkYield)
{
    milkYield = newMilkYield;
}
long long Breast::getVolume() const
{
    return volume;
}

void Breast::setVolume(long long newVolume)
{
    volume = newVolume;
}

long long Breast::getSize() const
{
    return size;
}

void Breast::setSize(long long newSize)
{
    size = newSize;
}

long long Breast::getGalactophore() const
{
    return galactophore;
}

void Breast::setGalactophore(long long newGalactophore)
{
    galactophore = newGalactophore;
}

long long Breast::getStock() const
{
    return stock;
}

void Breast::setStock(long long newStock)
{
    stock = newStock;
}

Breast::Breast(long long rank, long long EXP, long long pleasure, long long count, bool milkYield, long long size)
    :PositionBase("乳房",rank,EXP,pleasure,count),size(size)
{
    //    50/2=25
    //    2 pi*R
    //    4/3*pi*r*r*r
    long double R=size/PI;
    this->volume=(4/3*PI*R*R*R)/1000;
    this->galactophore=10+size*0.1;
    this->stock=0;
    if(milkYield){
        this->milkYield=1+this->galactophore*0.1;
        if(this->milkYield<=0){
            this->milkYield=1;
        }
    }
}
}
