#include "Urethra.h"
#include "Modules/Modules.h"
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

Urethra::Urethra()
{

}

QString Urethra::save()
{
    QString str=PositionBase::save()+"\nexpand:"+QString::number(this->expand);
    return str;
}

bool Urethra::load(QTextStream &ts)
{
    PositionBase::load(ts);
    this->expand=getValue(ts.readLine()).toLongLong();
    return true;
}
}
