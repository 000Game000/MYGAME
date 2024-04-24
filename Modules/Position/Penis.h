#ifndef PENIS_H
#define PENIS_H

#include "PositionBase.h"
#include "Modules/Modules.h"
namespace MYGAME{
/*
 * 阴茎类
 */
class Penis : public PositionBase
{
protected:
    long long diameter;                             //直径单位mm长度是它的5倍
    long long semen=5;                              //单次射精量单位ml
    DickSize dickSize;                              //鸡儿大小的tag
public:
    Penis();
    long long getDiameter() const;
    void setDiameter(long long newDiameter);
    long long getSemen() const;
    void setSemen(long long newSemen);
    DickSize getDickSize() const;
    void show();
};
}
#endif // PENIS_H
