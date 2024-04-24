
#ifndef PLAYER_H
#define PLAYER_H

#include "People.h"
#include "Modules/System_.h"
#include <vector>
namespace MYGAME{
/*
 * 玩家类
 */
class Player : public People
{
private:
    unsigned long long money;                                       //金钱
    std::vector<ItemBase*>*itemList;                                //物品表列
    System_ system_;                                                //系统哦

public:
    Player();
    void show();
    unsigned long long getMoney() const;
    void setMoney(unsigned long long newMoney);
    System_ getSystem() const;
    System_&getVariableSystem();
    void setSystem(const System_ &newSystem);
    std::vector<ItemBase *> *getItemList() const;
    std::vector<ItemBase *> *getVariableItemList();
    void setItemList(std::vector<ItemBase *> *newItemList);
};
}
#endif // PLAYER_H
