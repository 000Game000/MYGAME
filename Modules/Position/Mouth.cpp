#include "Mouth.h"
namespace MYGAME{
Mouth::Mouth(long long rank, long long EXP, long long pleasure, long long count):PositionBase("嘴巴",rank,EXP,pleasure,count)
{

}

Mouth::Mouth()
{

}

QJsonObject *Mouth::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Mouth");
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Mouth::load(QJsonObject obj)
{
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
