#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include<QString>
#include <QTextStream>
namespace MYGAME {
/*
 * 属性类
 * 基础几个属性 智力 魅力等
 * 属性的基础类
 */
class Attribute
{
protected:
    QString name;                                       //属性名称
    long long rank;                                     //属性等级
    long long EXP;                                      //经验值
public:
    Attribute(const QString &name, long long rank, long long EXP);
    Attribute();
    QString getName() const;
    void setName(const QString &newName);
    virtual long long getRank() const;
    void setRank(long long newRank);
    long long getEXP() const;
    void setEXP(long long newEXP);
    virtual void show();
    virtual QString save();
    virtual void load(QTextStream&ts);
};
}
#endif // ATTRIBUTE_H
