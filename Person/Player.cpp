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

std::vector<ItemBase *> Player::getItemList() const
{
    return itemList;
}

std::vector<ItemBase *> &Player::getVariableItemList()
{
    return itemList;
}

void Player::setItemList(std::vector<ItemBase *> newItemList)
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
}

QString Player::save()
{
    QString str="\n类型:Player\nmoney:"+QString::number(this->money)+"\npoint:"+QString::number(this->point);
    str+="\n数量:"+QString::number(this->itemList.size());
    for(size_t i=0;i<this->itemList.size();i++){
        str+=this->itemList[i]->save();
    }
    str+=People::save();
    return str;
}

bool Player::load(QTextStream &ts,std::vector<MYGAME::Map*>*mapList)
{
    this->money=getValue(ts.readLine()).toULongLong();
    this->point=getValue(ts.readLine()).toULongLong();
    size_t max=getValue(ts.readLine()).toLongLong();
    for(size_t i=0;i<max;i++){
        QString type=getValue(ts.readLine());{
            if(type.compare("ItemBase")==0){
                ItemBase*P=new ItemBase();
                P->load(ts);
            }
        }
    }
    People::load(ts,mapList);
    return true;
}
void Player::show()
{
    qDebug()<<"主角类";
}
}
