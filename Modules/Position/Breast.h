#ifndef BREAST_H
#define BREAST_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 乳房类
 */
class Breast : public PositionBase
{
    //    乳汁分泌量=
    //    1（基础值ml/min）+
    //    [A（角色乳腺数量）-20（标准乳腺数量）]*0.1(ml/min)+B（分泌改造值（ml/min））
    //    角色乳腺数量=
    //    10（最低乳腺数量）+X（胸围数值）*0.1
    //    计算案例
    //    150（c杯）
    //    乳腺数量=10+150*0.1=25条
    //    乳汁分泌量=1+5*0.1+0=1.5ml/min
    //    0（AAA杯绝壁，改造值1ml/min）
    //    乳腺数量=10+0=10条
    //    乳汁分泌量=1-10*0.1+1
    //    259（g杯，改造值1ml/min）
    //    乳腺数量=10+259*0.1=35.9=35（取整）
    //    乳汁分泌量=1+15*0.1+1=3.5
protected:
    long double milkYield=1;                                    //母乳产量默认1ml1分钟 如果为0为无泌乳
    long long volume;                                           //母乳容量单位为ml
    long long size;                                             //乳房大小单位mm 0~49为AAA 50~99为AA 100~124为A 以类推每个等级+25
    long long galactophore;                                     //乳腺数量
    long long stock;                                            //现有量
public:
    Breast();
};
}
#endif // BREAST_H
