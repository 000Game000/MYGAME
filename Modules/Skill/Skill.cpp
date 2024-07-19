#include "Skill.h"
namespace MYGAME {
QString Skill::getName() const
{
    return name;
}

void Skill::setName(const QString &newName)
{
    name = newName;
}

long long Skill::getRank() const
{
    return rank;
}

void Skill::setRank(long long newRank)
{
    rank = newRank;
}

long long Skill::getEXP() const
{
    return EXP;
}

void Skill::setEXP(long long newEXP)
{
    EXP = newEXP;
}

Skill::Skill()
{

}

Skill::Skill(const QString &name, long long rank, long long EXP) : name(name),
    rank(rank),
    EXP(EXP)
{}

QJsonObject*Skill::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Skill");
    obj->insert("Name",this->name);
    obj->insert("Rank",QString::number(this->rank));
    obj->insert("EXP",QString::number(this->EXP));
    return obj;
}

bool Skill::load(QJsonObject obj)
{
    this->name=obj.value("Name").toString();
    this->rank=obj.value("Rank").toString().toLongLong();
    this->EXP=obj.value("EXP").toString().toLongLong();
    return true;
}
}
