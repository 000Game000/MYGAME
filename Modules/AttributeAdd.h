#ifndef ATTRIBUTEADD_H
#define ATTRIBUTEADD_H

#include "Attribute.h"

#include <QTextStream>
namespace MYGAME{
/*
 * 属性类
 * 基础几个属性 智力 魅力等
 * 增加了现在值
 */
class AttributeAdd : public Attribute
{
protected:
    long long nowValue;
public:
    AttributeAdd(const QString &name, long long rank, long long EXP,long long nowValue);
    AttributeAdd();
    void show();
    long long getNowValue() const;
    void setNowValue(long long newNowValue);
    virtual QString save();
    virtual void load(QTextStream&ts);
};
}
#endif // ATTRIBUTEADD_H

