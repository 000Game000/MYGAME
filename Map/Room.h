#ifndef ROOM_H
#define ROOM_H
#include<QString>
#include<map>
namespace MYGAME{
class Room
{
    QString name;                                       //房间名称
    QString type;                                       //房间类型
    std::map<Room*,long long> roomList;                 //从此房间可到达的房间和所花时间
public:
    Room();
    QString getName() const;
    void setName(const QString &newName);
    QString getType() const;
    void setType(const QString &newType);
    std::map<Room *, long long> getRoomList() const;
    void setRoomList(const std::map<Room *, long long> &newRoomList);
    virtual void show();
};
}
#endif // ROOM_H
