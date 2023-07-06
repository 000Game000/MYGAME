#include "System_.h"
namespace MYGAME{
long long System_::getPoint() const
{
    return point;
}

void System_::setPoint(long long newPoint)
{
    point = newPoint;
}

std::vector<ItemBase *>&System_::getItemList()
{
    return itemList;
}

void System_::setItemList(const std::vector<ItemBase *> &newItemList)
{
    itemList = newItemList;
}

System_::System_()
{
    itemList.push_back(new ItemBase("text","text","text","text","text",1,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",2,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",3,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",4,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",5,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",6,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",7,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",8,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",9,0));
    itemList.push_back(new ItemBase("text","text","text","text","text",10,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",1,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",2,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",3,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",4,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",5,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",6,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",7,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",8,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",9,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",10,0));
}
}
