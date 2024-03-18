#ifndef OVARY_H
#define OVARY_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 卵巢类
 */
class Ovary : public PositionBase
{
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     */
    Ovary(long long rank, long long EXP, long long pleasure, long long count);
};
}
#endif // OVARY_H
