#include "Ovary.h"
namespace MYGAME{
Ovary::Ovary(long long rank, long long EXP, long long pleasure, long long count):PositionBase("卵巢",rank,EXP,pleasure,count)
{

}

Ovary::Ovary()
{

}

QJsonObject *Ovary::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Ovary");
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Ovary::load(QJsonObject obj)
{
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
