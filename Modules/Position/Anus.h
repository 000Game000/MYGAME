#ifndef ANUS_H
#define ANUS_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 肛门类
 */
class Anus : public PositionBase
{
protected:
    long long expand=15;                                        //最大直径单位mm
    long long volume=500;                                       //容量单位ml 500ml~800ml
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * expand                   最大直径单位mm
     * volume                   容量单位ml
     */
    Anus(long long rank, long long EXP, long long pleasure, long long count,long long expand, long long volume);
    virtual QString save();
    long long getExpand() const;
    void setExpand(long long newExpand);
    long long getVolume() const;
    void setVolume(long long newVolume);
    void show();
};
}
#endif // ANUS_H
