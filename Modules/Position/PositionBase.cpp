#include "PositionBase.h"
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
