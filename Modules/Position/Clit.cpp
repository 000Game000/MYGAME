#include "Clit.h"
namespace MYGAME{
long long Clit::getLength() const
{
    return length;
}

void Clit::setLength(long long newLength)
{
    length = newLength;
}

long long Clit::getDiameter() const
{
    return diameter;
}

void Clit::setDiameter(long long newDiameter)
{
    diameter = newDiameter;
}

Clit::Clit(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter)
    :PositionBase("阴蒂",rank,EXP,pleasure,count),length(length),diameter(diameter)
{

}

Clit::Clit()
{

}

QJsonObject *Clit::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Clit");
    obj->insert("Length",QString::number(this->length));
    obj->insert("Diameter",QString::number(this->diameter));
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Clit::load(QJsonObject obj)
{
    this->length=obj.value("Length").toString().toLongLong();
    this->diameter=obj.value("Diameter").toString().toLongLong();
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
