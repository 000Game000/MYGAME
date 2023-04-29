#ifndef CLIT_H
#define CLIT_H

#include "PositionBase.h"
namespace MYGAME{
/*阴蒂类
 *
 */
class Clit : public PositionBase
{
protected:
    long long length;                                       //长度    10~40mm
    long long diameter;                                     //直径    10~40mm
public:
    Clit();
};
}
#endif // CLIT_H
