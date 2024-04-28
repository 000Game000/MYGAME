#include "Anus.h"
#include "Modules/Modules.h"
namespace MYGAME{

long long Anus::getExpand() const
{
    return expand;
}

void Anus::setExpand(long long newExpand)
{
    expand = newExpand;
}

long long Anus::getVolume() const
{
    return volume;
}

void Anus::setVolume(long long newVolume)
{
    volume = newVolume;
}

void Anus::show()
{

}

Anus::Anus(long long rank, long long EXP, long long pleasure, long long count,long long expand, long long volume)
    :PositionBase("肛门",rank,EXP,pleasure,count),expand(expand),volume(volume)
{

}

Anus::Anus()
{

}

QString Anus::save()
{
    QString str=PositionBase::save()+"\nexpand:"+QString::number(this->expand)+"\nvolume:"+QString::number(this->volume);
    return str;
}

bool Anus::load(QTextStream &ts)
{
    PositionBase::load(ts);
    this->expand=getValue(ts.readLine()).toLongLong();
    this->volume=getValue(ts.readLine()).toLongLong();
    return true;
}
}
