#ifndef SYSTEMGIRLONE_H
#define SYSTEMGIRLONE_H

#include "Girl.h"
namespace MYGAME{
/*
 * 系统娘:未柍
 * 作者:经常会摸鱼的树ee,从来没见过他的口上. 3049337017
 */
class SystemGirlOne : public Girl
{
public:
    SystemGirlOne(QDate time,Map*live);
    virtual QString save();
};
}
#endif // SYSTEMGIRLONE_H
