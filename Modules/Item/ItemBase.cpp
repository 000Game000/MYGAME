#include "ItemBase.h"
#include "Modules/Modules.h"

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

unsigned long long ItemBase::getMoney() const
{
    return money;
}

void ItemBase::setMoney(unsigned long long newMoney)
{
    money = newMoney;
}

unsigned long long ItemBase::getCount() const
{
    return count;
}

void ItemBase::setCount(unsigned long long newCount)
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

QString ItemBase::save()
{
    QString str="\n类型:ItemBase\nname:"+this->name+"\ndescribe:"+this->describe+"\nitemFunction:"+this->itemFunction+"\nitemType:"+this->itemType
                  +"\nlocation:"+this->location+"\nmoney:"+QString::number(this->money)+"\ncount:"+QString::number(this->count);
    return str;
}

bool ItemBase::load(QTextStream &ts)
{
    this->name=getValue(ts.readLine());
    this->describe=getValue(ts.readLine());
    this->itemFunction=getValue(ts.readLine());
    this->itemType=getValue(ts.readLine());
    this->location=getValue(ts.readLine());
    this->money=getValue(ts.readLine()).toULongLong();
    this->count=getValue(ts.readLine()).toULongLong();
    return true;
}
}
