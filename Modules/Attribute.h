#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include<QString>
namespace MYGAME {
/*属性类
 *基础几个属性 智力 速度等
 *属性的基础类
 */
class Attribute
{
protected:
    QString name;                                       //属性名称
    long long rank;                                     //属性等级
    long long EXP;                                      //经验值
public:
    Attribute(const QString &name, long long rank, long long EXP);
    QString getName() const;
    void setName(const QString &newName);
    virtual long long getRank() const;
    void setRank(long long newRank);
    long long getEXP() const;
    void setEXP(long long newEXP);
    virtual void show();
};
}
#endif // ATTRIBUTE_H
