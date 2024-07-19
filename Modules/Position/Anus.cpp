#include "Anus.h"
namespace MYGAME{

long long Anus::getExpand() const
{
    return expand;
}

void Anus::setExpand(long long newExpand)
{
    expand = newExpand;
}

long long Anus::getVolume() const
{
    return volume;
}

void Anus::setVolume(long long newVolume)
{
    volume = newVolume;
}

void Anus::show()
{

}

Anus::Anus(long long rank, long long EXP, long long pleasure, long long count,long long expand, long long volume)
    :PositionBase("肛门",rank,EXP,pleasure,count),expand(expand),volume(volume)
{

}

Anus::Anus()
{

}

QJsonObject*Anus::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Anus");
    obj->insert("Expand",QString::number(this->expand));
    obj->insert("Volume",QString::number(this->volume));
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Anus::load(QJsonObject obj)
{
    this->expand=obj.value("Expand").toString().toLongLong();
    this->volume=obj.value("Volume").toString().toLongLong();
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}


}
