#include "Room.h"
namespace MYGAME{

QString Room::getType() const
{
    return type;
}

void Room::setType(const QString &newType)
{
    type = newType;
}

void Room::show()
{

}

Room::Room()
{

}

MYGAME::Room::Room(const QString &name, std::vector<Map *> *list, const QString &img, Map *superiorMap, const QString &type):Map(name,list,img,superiorMap)
{
    this->type=type;
}
}
