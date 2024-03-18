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
    long long nowEXP;                                   //部位经验
    long long EXP;                                      //当前等级部位经验最大值
    long long pleasure;                                 //快感的最大值
    long long nowPleasure;                              //快感的当前数值
    long long count;                                    //部位经验次数
public:
    /* name     部位名称
     * rank     感度等级
     * EXP      经验(达到后升级部位等级)
     * pleasure 快感的最大值
     * count    当前部位的经验次数
     */
    PositionBase(const QString &name, long long rank, long long EXP=0, long long pleasure=100, long long count=0);
    /* 设置每级的部位经验
     */
    virtual void setEXPValue();
    QString getName() const;
    void setName(const QString &newName);
    long long getRank() const;
    void setRank(long long newRank);
    long long getEXP();
    void setEXP(long long newEXP);
    long long getPleasure() const;
    void setPleasure(long long newPleasure);
    long long getCount() const;
    void setCount(long long newCount);
    virtual void show();
    long long getNowEXP() const;
    void setNowEXP(long long newNowEXP);
    long long getNowPleasure()const;
    void setNowPleasure(long long newNowPleasure);
};
}
#endif // POSITIONBASE_H
