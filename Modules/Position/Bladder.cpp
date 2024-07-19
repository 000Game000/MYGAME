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

QJsonObject *Bladder::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Bladder");
    obj->insert("Volume",QString::number(this->volume));
    obj->insert("Stock",QString::number(this->stock));
    obj->insert("Yield",QString::number(this->yield));
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Bladder::load(QJsonObject obj)
{
    this->volume=obj.value("Volume").toString().toLongLong();
    this->stock=obj.value("Stock").toString().toLongLong();
    this->yield=obj.value("Yield").toString().toLongLong();
    QJsonValue value=obj.value("Bladder");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
