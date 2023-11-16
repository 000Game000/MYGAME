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
Room::Room(const QString &name, std::vector<Map *> *list, const QString &img, const QString &type, Map *superiorMap,const QString &roomType) : Map(name, list, img, type,superiorMap)
{
    this->roomType=roomType;
}
}
