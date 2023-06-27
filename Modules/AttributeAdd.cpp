#include "AttributeAdd.h"
namespace MYGAME{
long long AttributeAdd::getNowValue() const
{
    return nowValue;
}

void AttributeAdd::setNowValue(long long newNowValue)
{
    nowValue = newNowValue;
}

void AttributeAdd::show()
{

}

AttributeAdd::AttributeAdd(const QString &name, long long rank, long long EXP,long long nowValue) : Attribute(name,rank,EXP),nowValue(nowValue)
{}

}
