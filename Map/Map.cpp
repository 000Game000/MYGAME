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

Map::Map()
{

}

void Map::show()
{

}

Map::Map(const QString &name, std::vector<Map *> *list, const QString &img, Map *superiorMap) : name(name),
    list(list),
    img(img),
    superiorMap(superiorMap)
{}

}
