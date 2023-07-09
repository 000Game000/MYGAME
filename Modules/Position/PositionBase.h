#ifndef POSITIONBASE_H
#define POSITIONBASE_H
#include<QString>
namespace MYGAME {
/*
 * 人物部位的基础类
 */
class PositionBase
{
protected:
    QString name;                                       //部位名称
    long long rank;                                     //部位感度等级
    long long EXP;                                      //部位经验
    long long pleasure;                                 //快感的最大值
    long long nowValue;                                 //快感的当前数值
    long long count;                                    //部位经验次数
public:
    PositionBase();
    PositionBase(const QString &name, long long rank, long long EXP, long long pleasure, long long count);
    QString getName() const;
    void setName(const QString &newName);
    long long getRank() const;
    void setRank(long long newRank);
    long long getEXP() const;
    void setEXP(long long newEXP);
    long long getPleasure() const;
    void setPleasure(long long newPleasure);
    long long getCount() const;
    void setCount(long long newCount);
    virtual void show();
};
}
#endif // POSITIONBASE_H
