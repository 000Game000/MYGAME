#ifndef BLADDER_H
#define BLADDER_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 膀胱类
 */
class Bladder : public PositionBase
{
protected:
    long long volume;                                       //容量300ml~500ml
    long long stock;                                        //现有量
    long long yield;                                        //尿液产生=A（现在执行指令的时间）*1（ml/min，基础值）+X（利尿剂使用量）*1+Y（射入精液量）+Z（执行饮水指令时取Z=1，否则Z=0）*100（饮水增加尿液常量）
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * volume                   膀胱的容量
     */
    Bladder(long long rank, long long EXP, long long pleasure, long long count,long long volume);
    long long getVolume() const;
    void setVolume(long long newVolume);
    long long getStock() const;
    void setStock(long long newStock);
    long long getYield() const;
    void setYield(long long newYield);
};
}
#endif // BLADDER_H
