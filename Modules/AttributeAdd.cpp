#include "AttributeAdd.h"
namespace MYGAME{
long long AttributeAdd::getNowValue() const
{
    return nowValue;
}

void AttributeAdd::setNowValue(long long newNowValue)
{
    nowValue = newNowValue;
}

QJsonObject* AttributeAdd::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","AttributeAdd");
    obj->insert("nowValue",QString::number(this->nowValue));
    obj->insert("Attribute",*Attribute::save());
    return obj;
}

bool AttributeAdd::load(QJsonObject obj)
{
    this->setNowValue(obj.value("nowValue").toString().toLongLong());
    QJsonValue value=obj.value("Attribute");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        Attribute::load(o);
    }
    return true;
}

void AttributeAdd::show()
{

}

AttributeAdd::AttributeAdd(const QString &name, long long rank, long long EXP,long long nowValue) : Attribute(name,rank,EXP),nowValue(nowValue)
{}

AttributeAdd::AttributeAdd()
{

}

}
