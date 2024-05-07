#ifndef ROOM_H
#define ROOM_H
#include<QString>
#include"Map.h"
namespace MYGAME{
/*
 * 房间类
 */
class Room : public Map
{
protected:
    QString roomType;                                       //房间类型
public:
    Room();
    Room(const QString &name, std::vector<Map *> *list, const QString &img, const QString &type, Map *superiorMap,const QString &roomType);

    virtual void show();
    QString getRoomType() const;
    void setRoomType(const QString &newRoomType);
};
}
#endif // ROOM_H
