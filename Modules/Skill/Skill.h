#ifndef SKILL_H
#define SKILL_H
#include<QString>
namespace MYGAME{
/*
 * 人物技能类
 */
class Skill
{
protected:
    QString name;                                       //技能名称
    long long rank;                                     //技能等级
    long long EXP;                                      //经验值
public:
    Skill();
    Skill(const QString &name, long long rank, long long EXP);

    QString getName() const;
    void setName(const QString &newName);
    long long getRank() const;
    void setRank(long long newRank);
    long long getEXP() const;
    void setEXP(long long newEXP);
};
}
#endif // SKILL_H
