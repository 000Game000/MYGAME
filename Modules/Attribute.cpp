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

QString Attribute::save()
{
    QString str="\nname:"+this->name+"\nrank:"+QString::number(this->rank)+"\nEXP:"+QString::number(this->EXP);
    return str;
}
Attribute::Attribute(const QString &name, long long rank, long long EXP) : name(name),
    rank(rank),
    EXP(EXP)
{}

}
