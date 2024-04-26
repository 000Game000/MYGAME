#ifndef CLIT_H
#define CLIT_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 阴蒂类
 */
class Clit : public PositionBase
{
protected:
    long long length;                                       //长度    10~40mm
    long long diameter;                                     //直径    10~40mm
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * length                   阴蒂长度
     * diameter                 阴蒂直径
     */
    Clit(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter);
    virtual QString save();
    long long getLength() const;
    void setLength(long long newLength);
    long long getDiameter() const;
    void setDiameter(long long newDiameter);
};
}
#endif // CLIT_H
