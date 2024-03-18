#ifndef VAGINA_H
#define VAGINA_H
#include<QColor>
#include "PositionBase.h"
namespace MYGAME{
/*
 * 阴道类
 */
class Vagina : public PositionBase
{
protected:
    long long maximumDiameter=10;                                      //现有最大直径单位mm萝莉10mm,成年20mm~30mm
    long long length=70;                                               //长度单位mm 萝莉40mm~70mm成人70mm~120mm
    QColor color;                                                      //阴唇颜色
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * maximumDiameter          阴道的直径
     * length                   阴道的长度
     * color                    阴唇的颜色
     */
    Vagina(long long rank, long long EXP, long long pleasure, long long count,long long maximumDiameter,long long length,QColor color);
};
}
#endif // VAGINA_H
