#include "Room.h"
namespace MYGAME{
QString Room::getName() const
{
    return name;
}

void Room::setName(const QString &newName)
{
    name = newName;
}

QString Room::getType() const
{
    return type;
}

void Room::setType(const QString &newType)
{
    type = newType;
}

std::map<Room *, long long> Room::getRoomList() const
{
    return roomList;
}

void Room::setRoomList(const std::map<Room *, long long> &newRoomList)
{
    roomList = newRoomList;
}

void Room::show()
{

}

Room::Room()
{

}
}
