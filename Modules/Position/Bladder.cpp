#include "Bladder.h"
namespace MYGAME{
long long Bladder::getVolume() const
{
    return volume;
}

void Bladder::setVolume(long long newVolume)
{
    volume = newVolume;
}

long long Bladder::getStock() const
{
    return stock;
}

void Bladder::setStock(long long newStock)
{
    stock = newStock;
}

long long Bladder::getYield() const
{
    return yield;
}

void Bladder::setYield(long long newYield)
{
    yield = newYield;
}

Bladder::Bladder(long long rank, long long EXP, long long pleasure, long long count,long long volume)
    :PositionBase("膀胱",rank,EXP,pleasure,count),volume(volume)
{
    this->stock=0;
    this->yield=1;
}

}
