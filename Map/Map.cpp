#include "Map.h"
namespace MYGAME{
QString Map::getName() const
{
    return name;
}

void Map::setName(const QString &newName)
{
    name = newName;
}

std::vector<Map *> *Map::getList() const
{
    return list;
}

void Map::setList(std::vector<Map *> *newList)
{
    list = newList;
}

Map *Map::getSuperiorMap() const
{
    return superiorMap;
}

void Map::setSuperiorMap(Map *newSuperiorMap)
{
    superiorMap = newSuperiorMap;
}

QString Map::getImg() const
{
    return img;
}

void Map::setImg(const QString &newImg)
{
    img = newImg;
}

QString Map::getType() const
{
    return type;
}

void Map::setType(const QString &newType)
{
    type = newType;
}

Map::Map()
{

}

void Map::show()
{

}

Map::Map(const QString &name, std::vector<Map *> *list, const QString &img, const QString &type, Map *superiorMap) : name(name),
    list(list),
    img(img),
    type(type),
    superiorMap(superiorMap)
{}

}
