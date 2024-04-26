#include "Uterus.h"
namespace MYGAME{

long long Uterus::getVolume() const
{
    return volume;
}

void Uterus::setVolume(long long newVolume)
{
    volume = newVolume;
}

short Uterus::getMenstrualCycle() const
{
    return menstrualCycle;
}

void Uterus::setMenstrualCycle(short newMenstrualCycle)
{
    menstrualCycle = newMenstrualCycle;
}

short Uterus::getOvulation() const
{
    return ovulation;
}

void Uterus::setOvulation(short newOvulation)
{
    ovulation = newOvulation;
}

short Uterus::getPregnancyDays() const
{
    return pregnancyDays;
}

void Uterus::setPregnancyDays(short newPregnancyDays)
{
    pregnancyDays = newPregnancyDays;
}

Uterus::Uterus(long long rank, long long EXP, long long pleasure, long long count, long long volume, short menstrualCycle, short pregnancyDays)
    :PositionBase("子宫",rank,EXP,pleasure,count),volume(volume),menstrualCycle(menstrualCycle),pregnancyDays(pregnancyDays)
{
    this->ovulation=this->menstrualCycle/2;
}

QString Uterus::save()
{
    QString str=PositionBase::save()+"\nvolume:"+QString::number(this->volume)+"\nmenstrualCycle:"+QString::number(this->menstrualCycle)
                  +"\novulation:"+QString::number(this->ovulation)+"\npregnancyDays:"+QString::number(this->pregnancyDays);
    return str;
}
}
