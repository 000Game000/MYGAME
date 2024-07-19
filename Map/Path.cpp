#include "Path.h"
namespace MYGAME{
unsigned long long Path::getMoneyCost() const
{
    return moneyCost;
}

void Path::setMoneyCost(unsigned long long newMoneyCost)
{
    moneyCost = newMoneyCost;
}

unsigned long long Path::getTimeCost() const
{
    return timeCost;
}

void Path::setTimeCost(unsigned long long newTimeCost)
{
    timeCost = newTimeCost;
}

bool Path::getIfReachable() const
{
    return ifReachable;
}

void Path::setIfReachable(bool newIfReachable)
{
    ifReachable = newIfReachable;
}

QString Path::getDest() const
{
    return dest;
}

void Path::setDest(const QString &newDest)
{
    dest = newDest;
}

QString Path::getSource() const
{
    return source;
}

void Path::setSource(const QString &newSource)
{
    source = newSource;
}

Path::Path(const QString &dest, const QString &source, unsigned long long timeCost, unsigned long long moneyCost, bool ifReachable) : dest(dest),
    source(source),
    moneyCost(moneyCost),
    timeCost(timeCost),
    ifReachable(ifReachable)
{}

}
