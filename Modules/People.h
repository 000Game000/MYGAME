#ifndef PEOPLE_H
#define PEOPLE_H
#include<QString>
#include<QDate>
#include<QColor>
#include"Modules.h"
#include"Attribute.h"
#include"Skill/Skill.h"
#include"Position/PositionBase.h"
namespace MYGAME{
/*人物基础类
 */
class People
{
protected:
    QString name;                                   //姓名
    QString nickName;                               //昵称
    QString claimed;                                //自称
    QDate birthday;                                 //出生日期
    QString occupation;                             //职业
    QString major;                                  //专业
    QList<Attribute> attributeList;                 //属性表列
    QColor hairColor;                               //发色
    QColor skinColor;                               //肤色
    Height height;                                  //身高
    Weight weight;                                  //胖瘦
    QColor RPupilColor;                             //右眼颜色
    QColor LPupilColor;                             //左眼颜色
    QList<QString> tag;                             //人物素质
    QList<Skill> skills;                            //技能表列
    QList<PositionBase> positions;                  //部位表列
public:
    People();
};
}
#endif // PEOPLE_H
