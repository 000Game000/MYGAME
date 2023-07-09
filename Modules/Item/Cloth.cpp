#include "Cloth.h"
namespace MYGAME{
QString Cloth::getImg() const
{
    return img;
}

void Cloth::setImg(const QString &newImg)
{
    img = newImg;
}

Cloth::Cloth()
{

}

Cloth::Cloth(const QString &name, const QString &describe, const QString &itemFunction, const QString &itemType, const QString &location, long long money, long long count,const QString &img) : ItemBase(name,describe,itemFunction,itemType,location,money,count)
{
    this->img=img;
}

}
