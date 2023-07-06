#include "Player.h"
namespace MYGAME {
unsigned long long Player::getMoney() const
{
    return money;
}

void Player::setMoney(unsigned long long newMoney)
{
    money = newMoney;
}

System_ Player::getSystem() const
{
    return system_;
}

System_&Player::getVariableSystem()
{
    return system_;
}

void Player::setSystem(const System_ &newSystem)
{
    system_ = newSystem;
}

std::vector<ItemBase *> *Player::getItemList() const
{
    return itemList;
}

std::vector<ItemBase *> *Player::getVariableItemList()
{
    return itemList;
}

void Player::setItemList(std::vector<ItemBase *> *newItemList)
{
    itemList = newItemList;
}

Player::Player()
{
    this->itemList=new std::vector<ItemBase*>;
}

void Player::show()
{
    qDebug()<<"主角类";
}
}
