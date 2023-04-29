#ifndef NIPPLE_H
#define NIPPLE_H
#include<QColor>
#include "PositionBase.h"
namespace MYGAME{
/*乳头类
*/
class Nipple : public PositionBase
{
protected:
    long long length;                                       //长度    15~20mm
    long long diameter;                                     //直径    8~15mm
    long long ductusLactiferiDiameter;                      //乳孔最大直径
    QColor color;                                           //乳头颜色
public:
    Nipple();
};
}
#endif // NIPPLE_H
