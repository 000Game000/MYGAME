#include "Vagina.h"
#include "Modules/Global.h"

#include <QJsonArray>
namespace MYGAME{
long long Vagina::getMaximumDiameter() const
{
    return maximumDiameter;
}

void Vagina::setMaximumDiameter(long long newMaximumDiameter)
{
    maximumDiameter = newMaximumDiameter;
}

long long Vagina::getLength() const
{
    return length;
}

void Vagina::setLength(long long newLength)
{
    length = newLength;
}

QColor Vagina::getColor() const
{
    return color;
}

void Vagina::setColor(const QColor &newColor)
{
    color = newColor;
}

Vagina::Vagina(long long rank, long long EXP, long long pleasure, long long count,long long maximumDiameter,long long length,QColor color)
    :PositionBase("阴道",rank,EXP,pleasure,count),maximumDiameter(maximumDiameter),length(length),color(color)
{

}

Vagina::Vagina()
{

}

QJsonObject *Vagina::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Vagina");
    obj->insert("MaximumDiameter",QString::number(this->maximumDiameter));
    obj->insert("Length",QString::number(this->length));
    QJsonArray*color=new QJsonArray();
    int r=0;
    int g=0;
    int b=0;
    this->color.getRgb(&r,&g,&b);
    color->append(r);
    color->append(g);
    color->append(b);
    obj->insert("Color",*color);
    obj->insert("PositionBase",*PositionBase::save());
    return obj;
}

bool Vagina::load(QJsonObject obj)
{
    this->maximumDiameter=obj.value("MaximumDiameter").toString().toLongLong();
    this->length=obj.value("Length").toString().toLongLong();
    QJsonValue value=obj.value("Color");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        this->color=MYGAME::JsonArrToQColor(arr);
    }
    value=obj.value("PositionBase");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        PositionBase::load(o);
    }
    return true;
}
}
