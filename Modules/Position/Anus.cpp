#include "Anus.h"
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

Anus::Anus()
{
    this->name="肛门";
    this->EXP=0;
    this->count=0;
    this->pleasure=0;
    this->rank=-1;
}

Anus::Anus(long long expand, long long volume) : expand(expand),
    volume(volume)
{}

}
