#ifndef VAGINA_H
#define VAGINA_H
#include<QColor>
#include "PositionBase.h"
namespace MYGAME{
/*
 * 阴道类
 */
class Vagina : public PositionBase
{
protected:
    long long maximumDiameter=10;                                      //现有最大直径单位mm萝莉10mm,成年20mm~30mm
    long long length=70;                                               //长度单位mm 萝莉40mm~70mm成人70mm~120mm
    QColor color;                                                      //阴唇颜色
public:
    Vagina();
};
}
#endif // VAGINA_H
