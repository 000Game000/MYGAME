#include "System_.h"
namespace MYGAME{
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
    itemList.push_back(new ItemBase("text1","text","text","text","text",2,0));
    itemList.push_back(new ItemBase("text2","text","text","text","text",3,0));
    itemList.push_back(new ItemBase("text2","text","text","text","text",4,0));
    itemList.push_back(new ItemBase("text3","text","text","text","text",5,0));
    itemList.push_back(new ItemBase("text4","text","text","text","text",6,0));
    itemList.push_back(new ItemBase("text5","text","text","text","text",7,0));
    itemList.push_back(new ItemBase("text6","text","text","text","text",8,0));
    itemList.push_back(new ItemBase("text7","text","text","text","text",9,0));
    itemList.push_back(new ItemBase("text8","text","text","text","text",10,0));
    itemList.push_back(new ItemBase("temp","text","text","text","text",1,0));
    itemList.push_back(new ItemBase("temp1","text","text","text","text",2,0));
    itemList.push_back(new ItemBase("temp2","text","text","text","text",3,0));
    itemList.push_back(new ItemBase("temp3","text","text","text","text",4,0));
    itemList.push_back(new ItemBase("temp4","text","text","text","text",5,0));
    itemList.push_back(new ItemBase("temp5","text","text","text","text",6,0));
    itemList.push_back(new ItemBase("temp6","text","text","text","text",7,0));
    itemList.push_back(new ItemBase("temp7","text","text","text","text",8,0));
    itemList.push_back(new ItemBase("temp8","text","text","text","text",9,0));
    itemList.push_back(new ItemBase("temp9","text","text","text","text",10,0));
}
}
