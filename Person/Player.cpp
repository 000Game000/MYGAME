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

unsigned long long Player::getPoint() const
{
    return point;
}

void Player::setPoint(unsigned long long newPoint)
{
    point = newPoint;
}

Player::Player()
{
    this->itemList=new std::vector<ItemBase*>;
}

QString Player::save()
{
    QString str=People::save()+"\nmoney:"+QString::number(this->money)+"\npoint:"+QString::number(this->point);
    for(size_t i=0;i<this->itemList->size();i++){
        str+=(*this->itemList)[i]->save();
    }
    return str;
}
void Player::show()
{
    qDebug()<<"主角类";
}
}
