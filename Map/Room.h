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
    QString type;                                       //房间类型
public:
    Room();
    Room(const QString &name, std::vector<Map *> *list, const QString &img, Map *superiorMap,const QString &type);
    QString getType() const;
    void setType(const QString &newType);
    virtual void show();
};
}
#endif // ROOM_H
