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

}
