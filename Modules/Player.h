
#ifndef PLAYER_H
#define PLAYER_H

#include "People.h"


namespace MYGAME{
/*
 * 玩家类
 */
class Player : public People
{
private:
    unsigned long long money;
public:
    Player();
    void show();
    unsigned long long getMoney() const;
    void setMoney(unsigned long long newMoney);
};
}
#endif // PLAYER_H
