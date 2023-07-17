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
}
