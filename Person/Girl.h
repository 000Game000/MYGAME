#ifndef GIRL_H
#define GIRL_H

#include "People.h"
namespace MYGAME{
/*
 * 妹子们的基类
 */
class Girl : public People
{
protected:
    long long lovept;                                     //好感度
    long long obedience;                                  //服从度
    long long fornication;                                //淫乱度
//    long long
public:
    Girl();
};
}
#endif // GIRL_H
