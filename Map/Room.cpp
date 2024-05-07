#include "Room.h"
namespace MYGAME{
void Room::show()
{

}

QString Room::getRoomType() const
{
    return roomType;
}

void Room::setRoomType(const QString &newRoomType)
{
    roomType = newRoomType;
}

Room::Room()
{
}
Room::Room(const QString &name, std::vector<Map *> *list, const QString &img, const QString &type, Map *superiorMap,const QString &roomType) : Map(name, list, img, type,superiorMap)
{
    this->roomType=roomType;
}
}
