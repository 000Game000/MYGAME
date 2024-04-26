#ifndef UTERUS_H
#define UTERUS_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 子宫类
 */
class Uterus : public PositionBase
{
protected:
    long long volume=5;                                         //容量单位ml
    short menstrualCycle=28;                                    //月经周期21天~35天 11到18岁来月经
    short ovulation=14;                                         //月经周期的一半为排卵日,排卵日前5天到后4天为排卵期.
    short pregnancyDays=-1;                                     //0为出生日怀孕天数为280天,负数为未怀孕.
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * volume                   子宫容积
     * menstrualCycle           月经周期
     * ovulation                排卵日
     * pregnancyDays            怀孕天数
     */
    Uterus(long long rank, long long EXP, long long pleasure, long long count,long long volume,short menstrualCycle=28,short pregnancyDays=-1);
    virtual QString save();
    long long getVolume() const;
    void setVolume(long long newVolume);
    short getMenstrualCycle() const;
    void setMenstrualCycle(short newMenstrualCycle);
    short getOvulation() const;
    void setOvulation(short newOvulation);
    short getPregnancyDays() const;
    void setPregnancyDays(short newPregnancyDays);
};
}
#endif // UTERUS_H
