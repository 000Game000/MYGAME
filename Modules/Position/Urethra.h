#ifndef URETHRA_H
#define URETHRA_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 尿道类
 */
class Urethra : public PositionBase
{
protected:
    long long expand=6;                                       //尿道最大直径单位mm
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * expand                   尿道内部的直径
     */
    Urethra(long long rank, long long EXP, long long pleasure, long long count,long long expand);
    virtual QString save();
    long long getExpand() const;
    void setExpand(long long newExpand);
};
}
#endif // URETHRA_H
