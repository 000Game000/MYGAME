#ifndef ATTRIBUTEADD_H
#define ATTRIBUTEADD_H

#include "Attribute.h"
namespace MYGAME{
class AttributeAdd : public Attribute
{
protected:
    long long nowValue;
public:
    AttributeAdd(const QString &name, long long rank, long long EXP,long long nowValue);
    void show();
    long long getNowValue() const;
    void setNowValue(long long newNowValue);
};
}
#endif // ATTRIBUTEADD_H
