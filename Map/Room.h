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
    QString type;                                       //房间类型
public:
    Room();
    QString getType() const;
    void setType(const QString &newType);
    virtual void show();
};
}
#endif // ROOM_H
