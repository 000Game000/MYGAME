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

Uterus::Uterus()
{

}

QJsonObject *Uterus::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Uterus");
    obj->insert("Volume",QString::number(this->volume));
    obj->insert("MenstrualCycle",QString::number(this->menstrualCycle));
    obj->insert("Ovulation",QString::number(this->ovulation));
    obj->insert("PregnancyDays",QString::number(this->pregnancyDays));
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Uterus::load(QJsonObject obj)
{
    this->volume=obj.value("Volume").toString().toLongLong();
    this->menstrualCycle=obj.value("MenstrualCycle").toString().toShort();
    this->ovulation=obj.value("Ovulation").toString().toShort();
    this->pregnancyDays=obj.value("PregnancyDays").toString().toShort();
    QJsonValue value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
