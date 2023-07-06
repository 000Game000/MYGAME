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
    long long point;                                        //系统点数
    std::vector<ItemBase*> itemList;                        //系统贩卖的物品表列
public:
    System_();
    long long getPoint() const;
    void setPoint(long long newPoint);
    std::vector<ItemBase *>&getItemList();
    void setItemList(const std::vector<ItemBase *> &newItemList);
};
}
#endif // SYSTEM__H
