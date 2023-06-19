#ifndef PEOPLE_H
#define PEOPLE_H
#include<QString>
#include<QDate>
#include<QColor>
#include<vector>
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
    std::vector<Attribute*> attributeList;          //属性表列
    Height height;                                  //身高
    Weight weight;                                  //胖瘦
    QColor hairColor;                               //发色
    QColor skinColor;                               //肤色
    QColor RPupilColor;                             //右眼颜色
    QColor LPupilColor;                             //左眼颜色
    std::vector<QString> tagList;                   //人物素质
    std::vector<Skill*> skillList;                  //技能表列
    std::vector<PositionBase*> positionList;        //部位表列
    QString describe;                               //人物描述
public:
    People();
    QString getName() const;
    void setName(const QString &newName);
    QString getNickName() const;
    void setNickName(const QString &newNickName);
    QString getClaimed() const;
    void setClaimed(const QString &newClaimed);
    QDate getBirthday() const;
    void setBirthday(const QDate &newBirthday);
    QString getOccupation() const;
    void setOccupation(const QString &newOccupation);
    QString getMajor() const;
    void setMajor(const QString &newMajor);
    QColor getHairColor() const;
    void setHairColor(const QColor &newHairColor);
    QColor getSkinColor() const;
    void setSkinColor(const QColor &newSkinColor);
    Height getHeight() const;
    void setHeight(Height newHeight);
    Weight getWeight() const;
    void setWeight(Weight newWeight);
    QColor getRPupilColor() const;
    void setRPupilColor(const QColor &newRPupilColor);
    QColor getLPupilColor() const;
    void setLPupilColor(const QColor &newLPupilColor);
    QString getDescribe() const;
    void setDescribe(const QString &newDescribe);
    virtual void show();
    std::vector<Attribute *> getAttributeList() const;
    std::vector<Attribute *>&getVariableAttributeList();
    void setAttributeList(const std::vector<Attribute *> &newAttributeList);
    std::vector<QString> getTagList() const;
    std::vector<QString>&getVariableTagList();
    void setTagList(const std::vector<QString> &newTagList);
    std::vector<Skill*> getSkillList() const;
    std::vector<Skill*>&getVariableSkillList();
    void setSkillList(const std::vector<Skill*> &newSkillList);
    std::vector<PositionBase *> getPositionList() const;
    std::vector<PositionBase *>&getVariablePositionList();
    void setPositionList(const std::vector<PositionBase *> &newPositionList);
};
}
#endif // PEOPLE_H
