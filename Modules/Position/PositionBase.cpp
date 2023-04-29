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

long long PositionBase::getEXP() const
{
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

PositionBase::PositionBase()
{

}

PositionBase::PositionBase(const QString &name, long long rank, long long EXP, long long pleasure, long long count) : name(name),
    rank(rank),
    EXP(EXP),
    pleasure(pleasure),
    count(count)
{}
}
