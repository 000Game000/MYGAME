#ifndef PATH_H
#define PATH_H

#include <QString>

namespace MYGAME{
class Path
{
private:
    QString dest;                                       //目的地id
    QString source;                                     //来源地id
    unsigned long long moneyCost;                       //金钱消耗
    unsigned long long timeCost;                        //时间消耗
    bool ifReachable;                                   //是否可达
public:
    /*
    *目的地
    *来源地
    *金钱消耗
    *时间消耗
    *是否可达
    */
    Path(const QString &dest, const QString &source, unsigned long long timeCost, unsigned long long moneyCost, bool ifReachable);
    unsigned long long getMoneyCost() const;
    void setMoneyCost(unsigned long long newMoneyCost);
    unsigned long long getTimeCost() const;
    void setTimeCost(unsigned long long newTimeCost);
    bool getIfReachable() const;
    void setIfReachable(bool newIfReachable);
    QString getDest() const;
    void setDest(const QString &newDest);
    QString getSource() const;
    void setSource(const QString &newSource);
};
}
#endif // PATH_H
