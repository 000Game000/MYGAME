#include "AttributeAdd.h"
#include "Modules/Modules.h"
namespace MYGAME{
long long AttributeAdd::getNowValue() const
{
    return nowValue;
}

void AttributeAdd::setNowValue(long long newNowValue)
{
    nowValue = newNowValue;
}

QString AttributeAdd::save()
{
    QString str="\n类型:AttributeAdd\nname:"+this->name+"\nrank:"+QString::number(this->rank)
                  +"\nEXP:"+QString::number(this->EXP)+"\nnowValue:"+QString::number(this->nowValue);
    return str;
}

void AttributeAdd::load(QTextStream &ts)
{
    this->name=getValue(ts.readLine());
    //qDebug()<<this->name;
    this->rank=getValue(ts.readLine()).toLongLong();
    //qDebug()<<this->rank;
    this->EXP=getValue(ts.readLine()).toLongLong();
    //qDebug()<<this->EXP;
    this->nowValue=getValue(ts.readLine()).toLongLong();
    //qDebug()<<this->nowValue;
}

void AttributeAdd::show()
{

}

AttributeAdd::AttributeAdd(const QString &name, long long rank, long long EXP,long long nowValue) : Attribute(name,rank,EXP),nowValue(nowValue)
{}

AttributeAdd::AttributeAdd()
{

}

}
