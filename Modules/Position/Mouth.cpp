#include "Mouth.h"
namespace MYGAME{
Mouth::Mouth(long long rank, long long EXP, long long pleasure, long long count):PositionBase("嘴巴",rank,EXP,pleasure,count)
{

}

QString Mouth::save()
{
    QString str=PositionBase::save();
    return str;
}
}
