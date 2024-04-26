#ifndef SYSTEM__H
#define SYSTEM__H
#include <vector>
#include "Item/ItemBase.h"
namespace MYGAME{
/*
 * 主角身上的系统
 */
class System_
{
protected:
    std::vector<ItemBase*> itemList;                        //系统贩卖的物品表列
public:
    System_();
    std::vector<ItemBase *>&getItemList();
    void setItemList(const std::vector<ItemBase *> &newItemList);
};
}
#endif // SYSTEM__H
