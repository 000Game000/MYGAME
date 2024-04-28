#include "Bladder.h"
#include "Modules/Modules.h"
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

Bladder::Bladder()
{

}

QString Bladder::save()
{
    QString str=PositionBase::save()+"\nvolume:"+QString::number(this->volume)+"\nstock:"+QString::number(this->stock)
                  +"\nyield:"+QString::number(this->yield);
    return str;
}

bool Bladder::load(QTextStream &ts)
{
    PositionBase::load(ts);
    this->volume=getValue(ts.readLine()).toLongLong();
    this->stock=getValue(ts.readLine()).toLongLong();
    this->yield=getValue(ts.readLine()).toLongLong();
    return true;
}
}
