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
}
