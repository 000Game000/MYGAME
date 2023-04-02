#ifndef POSITIONBASE_H
#define POSITIONBASE_H
#include<QString>
namespace MYGAME {
class PositionBase;
}
class PositionBase
{
private:
    QString name;                                       //部位名称
    long long rank;                                     //部位感度等级
    long long EXP;                                      //部位经验
    long long pleasure;                                 //快感
    long long count;                                    //部位经验次数
public:
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
    virtual void show()=0;
};

#endif // POSITIONBASE_H
