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
    QString describe;                               //人物描述
public:
    People();
    People(const QString &name, const QString &nickName, const QString &claimed, const QDate &birthday, const QString &occupation, const QString &major, const QList<Attribute> &attributeList, const QColor &hairColor, const QColor &skinColor, Height height, Weight weight, const QColor &RPupilColor, const QColor &LPupilColor, const QList<QString> &tag, const QList<Skill> &skills, const QList<PositionBase> &positions, const QString &describe);
    QList<QString>&getVariableTag();
    QList<Skill>&getVariableSkills();
    QList<Attribute>&getVariableAttributeList();
    QList<PositionBase>&getVariablePositions();
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
    QList<Attribute> getAttributeList() const;
    void setAttributeList(const QList<Attribute> &newAttributeList);
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
    QList<QString> getTag() const;
    void setTag(const QList<QString> &newTag);
    QList<Skill> getSkills() const;
    void setSkills(const QList<Skill> &newSkills);
    QList<PositionBase> getPositions() const;
    void setPositions(const QList<PositionBase> &newPositions);
    QString getDescribe() const;
    void setDescribe(const QString &newDescribe);
};
}
#endif // PEOPLE_H
