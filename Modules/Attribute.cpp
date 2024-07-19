#include "Attribute.h"
namespace MYGAME{
QString Attribute::getName() const
{
    return name;
}

void Attribute::setName(const QString &newName)
{
    name = newName;
}

long long Attribute::getRank() const
{
    return rank;
}

void Attribute::setRank(long long newRank)
{
    rank = newRank;
}

long long Attribute::getEXP() const
{
    return EXP;
}

void Attribute::setEXP(long long newEXP)
{
    EXP = newEXP;
}

void Attribute::show()
{

}

QJsonObject*Attribute::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Attribute");
    obj->insert("Name",this->name);
    obj->insert("Rank",QString::number(this->rank));
    obj->insert("EXP",this->EXP);
    return obj;
}

bool Attribute::load(QJsonObject obj)
{
    this->name=obj.value("Name").toString();
    this->EXP=obj.value("EXP").toString().toLongLong();
    this->rank=obj.value("Rank").toString().toLongLong();
    return true;
}
Attribute::Attribute(const QString &name, long long rank, long long EXP) : name(name),
    rank(rank),
    EXP(EXP)
{}

Attribute::Attribute()
{

}

}
