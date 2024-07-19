#ifndef MENGLI_H
#define MENGLI_H

#include "Girl.h"

namespace MYGAME{
class MengLi : public Girl
{
public:
    MengLi(int year=1,int month=1,int day=1);
    virtual QJsonObject*save();
    virtual bool load(QJsonObject obj);
};
}
#endif // MENGLI_H
