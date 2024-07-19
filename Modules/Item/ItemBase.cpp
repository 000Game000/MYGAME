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

ItemBase::~ItemBase()
{

}

QJsonObject*ItemBase::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("Type","ItemBase");
    obj->insert("Name",this->name);
    obj->insert("Describe",this->describe);
    obj->insert("ItemFunction",this->itemFunction);
    obj->insert("ItemType",this->itemType);
    obj->insert("Location",this->location);
    obj->insert("Money",QString::number(this->money));
    obj->insert("Count",QString::number(this->count));
    return obj;
}

bool ItemBase::load(QJsonObject obj)
{
    this->name=obj.value("Name").toString();
    this->describe=obj.value("Describe").toString();
    this->itemFunction=obj.value("ItemFunction").toString();
    this->itemType=obj.value("ItemType").toString();
    this->location=obj.value("Location").toString();
    this->money=obj.value("Money").toString().toULongLong();
    this->count=obj.value("Count").toString().toULongLong();
    return true;
}
}
