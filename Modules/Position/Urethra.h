#ifndef URETHRA_H
#define URETHRA_H

#include "PositionBase.h"
namespace MYGAME{
/*尿道类
 */
class Urethra : public PositionBase
{
protected:
    long long expand=6;                                       //尿道最大直径单位mm
public:
    Urethra();
};
}
#endif // URETHRA_H
