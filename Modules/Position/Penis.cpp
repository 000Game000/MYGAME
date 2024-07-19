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

QJsonObject *Penis::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Penis");
    obj->insert("Diameter",QString::number(this->diameter));
    obj->insert("Semen",QString::number(this->semen));
    obj->insert("DickSize",this->dickSize);
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Penis::load(QJsonObject obj)
{
    this->diameter=obj.value("Diameter").toString().toLongLong();
    this->semen=obj.value("Semen").toString().toLongLong();
    this->dickSize=(DickSize)obj.value("DickSize").toString().toInt();
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
