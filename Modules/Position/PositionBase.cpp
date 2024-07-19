#include "PositionBase.h"
#include "Modules/Modules.h"
namespace MYGAME{
QString PositionBase::getName() const
{
    return name;
}

void PositionBase::setName(const QString &newName)
{
    name = newName;
}

long long PositionBase::getRank() const
{
    return rank;
}

void PositionBase::setRank(long long newRank)
{
    rank = newRank;
}

long long PositionBase::getEXP()
{
    this->setEXPValue();
    return EXP;
}

void PositionBase::setEXP(long long newEXP)
{
    EXP = newEXP;
}

long long PositionBase::getPleasure() const
{
    return pleasure;
}

void PositionBase::setPleasure(long long newPleasure)
{
    pleasure = newPleasure;
}

long long PositionBase::getCount() const
{
    return count;
}

void PositionBase::setCount(long long newCount)
{
    count = newCount;
}

void PositionBase::show()
{

}

long long PositionBase::getNowEXP() const
{
    return nowEXP;
}

void PositionBase::setNowEXP(long long newNowEXP)
{
    nowEXP = newNowEXP;
}

long long PositionBase::getNowPleasure() const
{
    return nowPleasure;
}

void PositionBase::setNowPleasure(long long newNowPleasure)
{
    nowPleasure=newNowPleasure;
}

PositionBase::PositionBase(const QString &name, long long rank, long long EXP, long long pleasure, long long count) : name(name),
    rank(rank),
    EXP(EXP),
    pleasure(pleasure),
    count(count)
{
    this->nowPleasure=0;
    this->nowEXP=0;
}

PositionBase::PositionBase()
{

}

QJsonObject*PositionBase::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","PositionBase");
    obj->insert("Name",this->name);
    obj->insert("Rank",QString::number(this->rank));
    obj->insert("NowEXP",QString::number(this->nowEXP));
    obj->insert("EXP",QString::number(this->EXP));
    obj->insert("Pleasure",QString::number(this->pleasure));
    obj->insert("nowPleasure",QString::number(this->nowPleasure));
    obj->insert("Count",QString::number(this->count));
    return obj;
}

bool PositionBase::load(QJsonObject obj)
{
    this->name=obj.value("Name").toString();
    this->rank=obj.value("Rank").toString().toLongLong();
    this->nowEXP=obj.value("NowEXP").toString().toLongLong();
    this->EXP=obj.value("EXP").toString().toLongLong();
    this->pleasure=obj.value("Pleasure").toString().toLongLong();
    this->nowPleasure=obj.value("nowPleasure").toString().toLongLong();
    this->count=obj.value("Count").toString().toLongLong();
    return true;
}

void PositionBase::setEXPValue()
{
    const long long num[3] = { 10,30,60 };
    if (abs(this->rank) < 3) {
        this->EXP=num[abs(this->rank)];
    }
    else if (abs(this->rank) == 3) {
        this->EXP=(abs(this->rank) - 2) * 100;
    }
    else {
        long long exp = 0;
        for (long long i = 0; i <abs(this->rank)-1; i++) {
            exp += i * 100;
        }
        this->EXP=exp;
    }
}
}
