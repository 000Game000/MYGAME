#include "Urethra.h"
namespace MYGAME{
long long Urethra::getExpand() const
{
    return expand;
}

void Urethra::setExpand(long long newExpand)
{
    expand = newExpand;
}

Urethra::Urethra(long long rank, long long EXP, long long pleasure, long long count,long long expand)
    :PositionBase("尿道",rank,EXP,pleasure,count),expand(expand)
{

}
}
