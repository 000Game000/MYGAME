#include "Urethra.h"
namespace MYGAME{
long long Urethra::getExpand() const
{
    return expand;
}

void Urethra::setExpand(long long newExpand)
{
    expand = newExpand;
}

Urethra::Urethra(long long rank, long long EXP, long long pleasure, long long count,long long expand)
    :PositionBase("尿道",rank,EXP,pleasure,count),expand(expand)
{

}

Urethra::Urethra()
{

}

QJsonObject *Urethra::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Urethra");
    obj->insert("Expand",QString::number(this->expand));
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Urethra::load(QJsonObject obj)
{
    this->expand=obj.value("Expand").toString().toLongLong();
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
