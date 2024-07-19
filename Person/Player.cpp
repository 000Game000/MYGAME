#include "Player.h"

#include <QJsonArray>
#include <QJsonObject>
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

Player::Player(int year,int month,int day):People(year,month,day)
{
}

// Player::~Player()
// {
//     for(ItemBase*item:this->itemList){
//         delete item;
//     }
// }

QJsonObject*Player::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("Type","Player");
    obj->insert("Money",QString::number(this->money));
    obj->insert("Point",QString::number(this->point));
    QJsonArray*array=new QJsonArray();
    for(ItemBase*i:this->itemList){
        array->append(*(i->save()));
    }
    obj->insert("Item",*array);
    obj->insert("People",*People::save());
    return obj;
}

bool Player::load(QJsonObject obj)
{
    this->money=obj.value("Money").toString().toULongLong();
    this->point=obj.value("Point").toString().toULongLong();
    QJsonValue value=obj.value("Item");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        for(long long i=0;i<arr.size();i++){
            QJsonValue v=arr.at(i);
            if(v.isObject()){
                QJsonObject o=v.toObject();
                ItemBase*item=new ItemBase();
                item->load(o);
                itemList.push_back(item);
            }
        }
    }
    value=obj.value("People");
    if(value.isObject()){
        QJsonObject people=value.toObject();
        People::load(people);
    }
    return true;
}
void Player::show()
{
    qDebug()<<"主角类";
}
}
