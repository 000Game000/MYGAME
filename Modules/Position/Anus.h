#ifndef ANUS_H
#define ANUS_H

#include "PositionBase.h"
namespace MYGAME{
/*肛门类
 */
class Anus : public PositionBase
{
protected:
    long long expand=15;                                        //最大直径单位mm
    long long volume=500;                                       //容量单位ml 500ml~800ml
public:
    Anus();
    Anus(long long expand, long long volume);
    long long getExpand() const;
    void setExpand(long long newExpand);
    long long getVolume() const;
    void setVolume(long long newVolume);
    void show();
};
}
#endif // ANUS_H
