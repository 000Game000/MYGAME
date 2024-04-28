#include "Ovary.h"
namespace MYGAME{
Ovary::Ovary(long long rank, long long EXP, long long pleasure, long long count):PositionBase("卵巢",rank,EXP,pleasure,count)
{

}

Ovary::Ovary()
{

}

QString Ovary::save()
{
    QString str=PositionBase::save();
    return str;
}

bool Ovary::load(QTextStream &ts)
{
    PositionBase::load(ts);
    return true;
}
}
