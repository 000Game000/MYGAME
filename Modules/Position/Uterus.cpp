#include "Uterus.h"
namespace MYGAME{

Uterus::Uterus(long long rank, long long EXP, long long pleasure, long long count, long long volume, short menstrualCycle, short pregnancyDays)
    :PositionBase("子宫",rank,EXP,pleasure,count),volume(volume),menstrualCycle(menstrualCycle),pregnancyDays(pregnancyDays)
{
    this->ovulation=this->menstrualCycle/2;
}

}
