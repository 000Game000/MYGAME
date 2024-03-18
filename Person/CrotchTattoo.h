#ifndef CROTCHTATTOO_H
#define CROTCHTATTOO_H
#include <QString>
namespace MYGAME {
/*
 * 淫纹
 */
class CrotchTattoo
{
protected:
    long long rank;                                     //等级 负数为没有,种子为零,正数为等级
    long long EXP;                                      //淫纹经验
    QString img;                                        //图片
    std::vector<QString> sList;                         //特质列表
public:
    CrotchTattoo();
    long long getRank() const;
    void setRank(long long newRank);
    long long getEXP() const;
    void setEXP(long long newEXP);
    QString getImg() const;
    void setImg(const QString &newImg);
    std::vector<QString> getSList() const;
    std::vector<QString>&getVariableSList();
    void setSList(const std::vector<QString> &newSList);
};
}
#endif // CROTCHTATTOO_H
