
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

Player::Player()
{

}

void Player::show()
{
    qDebug()<<"主角类";
}
}
