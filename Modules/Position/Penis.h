#ifndef PENIS_H
#define PENIS_H

#include "PositionBase.h"
namespace MYGAME{
/*阴茎类
 */
class Penis : public PositionBase
{
protected:
    long long diameter;                             //直径单位mm长度是它的5倍
    long long semen=5;                              //单次射精量
public:
    Penis();
};
}
#endif // PENIS_H
