#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H
#include<QString>
namespace MYGAME {
class Attribute;
}
/*属性类
 *
 */
class Attribute
{
private:
    QString name;                                       //属性名称
    long long rank;                                     //属性等级
    long long EXP;                                      //经验值
public:
    QString getName() const;
    void setName(const QString &newName);
    long long getRank() const;
    void setRank(long long newRank);
    long long getEXP() const;
    void setEXP(long long newEXP);
};

#endif // ATTRIBUTE_H
