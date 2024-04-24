#ifndef NIPPLE_H
#define NIPPLE_H
#include<QColor>
#include "PositionBase.h"
namespace MYGAME{
/*
 * 乳头类
*/
class Nipple : public PositionBase
{
protected:
    long long length;                                       //长度    15~20mm
    long long diameter;                                     //直径    8~15mm
    long long ductusLactiferiDiameter;                      //乳孔最大可插入直径
    QColor color;                                           //乳头颜色
public:
    /* rank                     感度等级
     * EXP                      经验(达到后升级部位等级)
     * pleasure                 快感的最大值
     * count                    当前部位的经验次数
     * length                   乳头长度
     * diameter                 乳头直径
     * ductusLactiferiDiameter  乳孔直径
     * color                    乳头颜色
     */
    Nipple(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter,long long ductusLactiferiDiameter,QColor color);
    long long getLength() const;
    void setLength(long long newLength);
    long long getDiameter() const;
    void setDiameter(long long newDiameter);
    long long getDuctusLactiferiDiameter() const;
    void setDuctusLactiferiDiameter(long long newDuctusLactiferiDiameter);
    QColor getColor() const;
    void setColor(const QColor &newColor);
};
}
#endif // NIPPLE_H
