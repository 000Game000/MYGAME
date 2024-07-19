
#ifndef PLAYER_H
#define PLAYER_H

#include "People.h"
#include <vector>
#include <Modules/Item/ItemBase.h>
namespace MYGAME{
/*
 * 玩家类
 */
class Player : public People
{
private:
    unsigned long long money;                                       //金钱
    unsigned long long point;                                       //系统点数
    std::vector<ItemBase*>itemList;                                 //物品表列
public:
    Player(int year=1,int month=1,int day=1);
    //virtual ~Player();
    virtual QJsonObject*save();
    virtual bool load(QJsonObject obj);
    void show();
    unsigned long long getMoney() const;
    void setMoney(unsigned long long newMoney);
    std::vector<ItemBase *> getItemList() const;
    std::vector<ItemBase *> &getVariableItemList();
    void setItemList(std::vector<ItemBase *> newItemList);
    unsigned long long getPoint() const;
    void setPoint(unsigned long long newPoint);
};
}
#endif // PLAYER_H
