#include "Nipple.h"
#include "Modules/Global.h"

#include <QJsonArray>
namespace MYGAME{
long long Nipple::getLength() const
{
    return length;
}

void Nipple::setLength(long long newLength)
{
    length = newLength;
}

long long Nipple::getDiameter() const
{
    return diameter;
}

void Nipple::setDiameter(long long newDiameter)
{
    diameter = newDiameter;
}

long long Nipple::getDuctusLactiferiDiameter() const
{
    return ductusLactiferiDiameter;
}

void Nipple::setDuctusLactiferiDiameter(long long newDuctusLactiferiDiameter)
{
    ductusLactiferiDiameter = newDuctusLactiferiDiameter;
}

QColor Nipple::getColor() const
{
    return color;
}

void Nipple::setColor(const QColor &newColor)
{
    color = newColor;
}

Nipple::Nipple(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter,long long ductusLactiferiDiameter,QColor color)
    :PositionBase("乳头",rank,EXP,pleasure,count),length(length),diameter(diameter),ductusLactiferiDiameter(ductusLactiferiDiameter),color(color)
{

}

Nipple::Nipple()
{

}

QJsonObject *Nipple::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Nipple");
    obj->insert("Length",QString::number(this->length));
    obj->insert("Diameter",QString::number(this->diameter));
    obj->insert("DuctusLactiferiDiameter",QString::number(this->ductusLactiferiDiameter));
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

bool Nipple::load(QJsonObject obj)
{
    this->length=obj.value("Length").toString().toLongLong();
    this->diameter=obj.value("Diameter").toString().toLongLong();
    this->ductusLactiferiDiameter=obj.value("DuctusLactiferiDiameter").toString().toLongLong();
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
