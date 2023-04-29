#ifndef GLOBAL_H
#define GLOBAL_H
#include<QList>
#include<QString>
namespace MYGAME {
/*全局单例类
 * 1.包含现有专业
 * 2.包含职业
 */
class Global
{
protected:
    QList<QString> majorList;                                       //专业列表
    QList<QString> careerList;                                      //职业列表
public:
    Global();
    void initMajorList();                                           //初始化专业表列
    void initCareerList();                                          //初始化职业表列
    QList<QString> getMajorList() const;
    QList<QString> getCareerList() const;
};
}
#endif // GLOBAL_H
