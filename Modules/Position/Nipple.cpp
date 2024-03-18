#include "Nipple.h"
namespace MYGAME{
Nipple::Nipple(long long rank, long long EXP, long long pleasure, long long count,long long length,long long diameter,long long ductusLactiferiDiameter,QColor color)
    :PositionBase("乳头",rank,EXP,pleasure,count),length(length),diameter(diameter),ductusLactiferiDiameter(ductusLactiferiDiameter),color(color)
{

}
}
