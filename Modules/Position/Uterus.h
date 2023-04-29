#ifndef UTERUS_H
#define UTERUS_H

#include "PositionBase.h"
namespace MYGAME{
/*子宫类
 */
class Uterus : public PositionBase
{
protected:
    long long volume=5;                                         //容量单位ml
    short menstrualCycle=28;                                    //月经周期21天~35天 11到18岁来月经
    short ovulation=14;                                         //月经周期的一半为排卵日,排卵日前5天到后4天为排卵期.
    short pregnancyDays=0;                                      //0为出生日怀孕天数为280天,负数为未怀孕.
public:
    Uterus();
};
}
#endif // UTERUS_H
