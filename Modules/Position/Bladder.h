#ifndef BLADDER_H
#define BLADDER_H

#include "PositionBase.h"
namespace MYGAME{
/*膀胱类
 */
class Bladder : public PositionBase
{
protected:
    long long volume;                                       //容量300ml~500ml
    long long stock;                                        //现有量 尿液产生=A（现在执行指令的时间）*1（ml/min，基础值）+X（利尿剂使用量）*1+Y（射入精液量）+Z（执行饮水指令时取Z=1，否则Z=0）*100（饮水增加尿液常量）
public:
    Bladder();
    void show();
};
}
#endif // BLADDER_H
