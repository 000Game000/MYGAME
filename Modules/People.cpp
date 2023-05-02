#include "People.h"
namespace MYGAME {
QString People::getName() const
{
    return name;
}

void People::setName(const QString &newName)
{
    name = newName;
}

QString People::getNickName() const
{
    return nickName;
}

void People::setNickName(const QString &newNickName)
{
    nickName = newNickName;
}

QString People::getClaimed() const
{
    return claimed;
}

void People::setClaimed(const QString &newClaimed)
{
    claimed = newClaimed;
}

QDate People::getBirthday() const
{
    return birthday;
}

void People::setBirthday(const QDate &newBirthday)
{
    birthday = newBirthday;
}

QString People::getOccupation() const
{
    return occupation;
}

void People::setOccupation(const QString &newOccupation)
{
    occupation = newOccupation;
}

QString People::getMajor() const
{
    return major;
}

void People::setMajor(const QString &newMajor)
{
    major = newMajor;
}

QList<Attribute> People::getAttributeList() const
{
    return attributeList;
}

void People::setAttributeList(const QList<Attribute> &newAttributeList)
{
    attributeList = newAttributeList;
}

QColor People::getHairColor() const
{
    return hairColor;
}

void People::setHairColor(const QColor &newHairColor)
{
    hairColor = newHairColor;
}

QColor People::getSkinColor() const
{
    return skinColor;
}

void People::setSkinColor(const QColor &newSkinColor)
{
    skinColor = newSkinColor;
}

Height People::getHeight() const
{
    return height;
}

void People::setHeight(Height newHeight)
{
    height = newHeight;
}

Weight People::getWeight() const
{
    return weight;
}

void People::setWeight(Weight newWeight)
{
    weight = newWeight;
}

QColor People::getRPupilColor() const
{
    return RPupilColor;
}

void People::setRPupilColor(const QColor &newRPupilColor)
{
    RPupilColor = newRPupilColor;
}

QColor People::getLPupilColor() const
{
    return LPupilColor;
}

void People::setLPupilColor(const QColor &newLPupilColor)
{
    LPupilColor = newLPupilColor;
}

QList<QString> People::getTag() const
{
    return tag;
}

void People::setTag(const QList<QString> &newTag)
{
    tag = newTag;
}

QList<Skill> People::getSkills() const
{
    return skills;
}

void People::setSkills(const QList<Skill> &newSkills)
{
    skills = newSkills;
}

QList<PositionBase> People::getPositions() const
{
    return positions;
}

void People::setPositions(const QList<PositionBase> &newPositions)
{
    positions = newPositions;
}

QString People::getDescribe() const
{
    return describe;
}

void People::setDescribe(const QString &newDescribe)
{
    describe = newDescribe;
}

People::People()
{
}

People::People(const QString &name, const QString &nickName, const QString &claimed, const QDate &birthday, const QString &occupation, const QString &major, const QList<Attribute> &attributeList, const QColor &hairColor, const QColor &skinColor, Height height, Weight weight, const QColor &RPupilColor, const QColor &LPupilColor, const QList<QString> &tag, const QList<Skill> &skills, const QList<PositionBase> &positions, const QString &describe) : name(name),
    nickName(nickName),
    claimed(claimed),
    birthday(birthday),
    occupation(occupation),
    major(major),
    attributeList(attributeList),
    hairColor(hairColor),
    skinColor(skinColor),
    height(height),
    weight(weight),
    RPupilColor(RPupilColor),
    LPupilColor(LPupilColor),
    tag(tag),
    skills(skills),
    positions(positions),
    describe(describe)
{}

QList<Attribute> &People::getVariableAttribute()
{
    return this->attributeList;
}

QList<QString> &People::getVariableTag()
{
    return this->tag;
}

QList<Skill> &People::getVariableSkills()
{
    return this->skills;
}

QList<PositionBase> &People::getVariablePositions()
{
    return this->positions;
}

}
