#ifndef ITEMBASE_H
#define ITEMBASE_H
#include <QString>
#include <QTextStream>
namespace MYGAME{
/*
 * 物品
 */
class ItemBase
{
protected:
    QString name;                                       //物品名称
    QString describe;                                   //物品描述
    QString itemFunction;                               //物品作用
    QString itemType;                                   //物品类别
    QString location;                                   //物品购买地点
    unsigned long long money;                           //购买物品所花的点数/金钱
    unsigned long long count;                           //持有的物品数量
public:
    ItemBase();
    ItemBase(const QString &name, const QString &describe, const QString &itemFunction, const QString &itemType, const QString &location, long long money, long long count);
    virtual QString save();
    virtual bool load(QTextStream&ts);
    QString getName() const;
    void setName(const QString &newName);
    QString getDescribe() const;
    void setDescribe(const QString &newDescribe);
    QString getItemFunction() const;
    void setItemFunction(const QString &newItemFunction);
    QString getItemType() const;
    void setItemType(const QString &newItemType);
    QString getLocation() const;
    void setLocation(const QString &newLocation);
    unsigned long long getMoney() const;
    void setMoney(unsigned long long newMoney);
    unsigned long long getCount() const;
    void setCount(unsigned long long newCount);
    virtual void show();
};
}
#endif // ITEMBASE_H
