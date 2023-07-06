#include "ItemBase.h"

namespace MYGAME {
ItemBase::ItemBase()
{

}
QString ItemBase::getDescribe() const
{
    return describe;
}

void ItemBase::setDescribe(const QString &newDescribe)
{
    describe = newDescribe;
}

QString ItemBase::getItemFunction() const
{
    return itemFunction;
}

void ItemBase::setItemFunction(const QString &newItemFunction)
{
    itemFunction = newItemFunction;
}

QString ItemBase::getItemType() const
{
    return itemType;
}

void ItemBase::setItemType(const QString &newItemType)
{
    itemType = newItemType;
}

QString ItemBase::getLocation() const
{
    return location;
}

void ItemBase::setLocation(const QString &newLocation)
{
    location = newLocation;
}

long long ItemBase::getMoney() const
{
    return money;
}

void ItemBase::setMoney(long long newMoney)
{
    money = newMoney;
}

long long ItemBase::getCount() const
{
    return count;
}

void ItemBase::setCount(long long newCount)
{
    count = newCount;
}

QString ItemBase::getName() const
{
    return name;
}

void ItemBase::setName(const QString &newName)
{
    name = newName;
}

void ItemBase::show()
{

}

ItemBase::ItemBase(const QString &name, const QString &describe, const QString &itemFunction, const QString &itemType, const QString &location, long long money, long long count) : name(name),
    describe(describe),
    itemFunction(itemFunction),
    itemType(itemType),
    location(location),
    money(money),
    count(count)
{}

}
