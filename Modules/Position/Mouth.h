#ifndef MOUTH_H
#define MOUTH_H

#include "PositionBase.h"
namespace MYGAME{
/*
 * 嘴类
 */
class Mouth : public PositionBase
{
public:
    Mouth(long long rank, long long EXP, long long pleasure, long long count);
    Mouth();
    virtual QString save();
    virtual bool load(QTextStream&ts);
};
}
#endif // MOUTH_H
