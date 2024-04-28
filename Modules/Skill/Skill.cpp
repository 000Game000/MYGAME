#include "Skill.h"
#include "Modules/Modules.h"
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

QString Skill::save()
{
    QString str="\nname:"+this->name+"\nrank:"+QString::number(this->rank)+"\nEXP:"+QString::number(this->EXP);
    return str;
}

bool Skill::load(QTextStream &ts)
{
    this->name=getValue(ts.readLine());
    this->rank=getValue(ts.readLine()).toLongLong();
    this->EXP=getValue(ts.readLine()).toLongLong();
    return true;
}
}
