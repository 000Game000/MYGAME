#include "Attribute.h"
#include "Modules/Modules.h"
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
    QString str="\n类型:Attribute\nname:"+this->name+"\nrank:"+QString::number(this->rank)+"\nEXP:"+QString::number(this->EXP);
    return str;
}

void Attribute::load(QTextStream &ts)
{
    this->name=getValue(ts.readLine());
    //qDebug()<<this->name;
    this->rank=getValue(ts.readLine()).toLongLong();
    //qDebug()<<this->rank;
    this->EXP=getValue(ts.readLine()).toLongLong();
    //qDebug()<<this->EXP;
}
Attribute::Attribute(const QString &name, long long rank, long long EXP) : name(name),
    rank(rank),
    EXP(EXP)
{}

Attribute::Attribute()
{

}

}
