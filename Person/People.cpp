#include "People.h"
namespace MYGAME {
Map *People::getCurrentPosition() const
{
    return currentPosition;
}

void People::setCurrentPosition(Map *newCurrentPosition)
{
    currentPosition = newCurrentPosition;
}

People::People()
{
    this->live=nullptr;
}

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

QString People::getDescribe() const
{
    return describe;
}

void People::setDescribe(const QString &newDescribe)
{
    describe = newDescribe;
}

void People::show()
{
    qDebug()<<"人物基类!!!";
}

std::vector<Attribute *> People::getAttributeList() const
{
    return attributeList;
}

std::vector<Attribute *> &People::getVariableAttributeList()
{
    return attributeList;
}


void People::setAttributeList(const std::vector<Attribute *> &newAttributeList)
{
    attributeList = newAttributeList;
}

std::vector<Skill*> People::getSkillList() const
{
    return skillList;
}

std::vector<Skill*> &People::getVariableSkillList()
{
    return skillList;
}

void People::setSkillList(const std::vector<Skill*> &newSkillList)
{
    skillList = newSkillList;
}

std::vector<PositionBase *> People::getPositionList() const
{
    return positionList;
}

std::vector<PositionBase *> &People::getVariablePositionList()
{
    return positionList;
}

void People::setPositionList(const std::vector<PositionBase *> &newPositionList)
{
    positionList = newPositionList;
}

Room *People::getLive() const
{
    return live;
}

void People::setLive(Room *newLive)
{
    live = newLive;
}

void People::setLive(Map *newLive)
{
    live = dynamic_cast<Room*>(newLive);
}

Cloths People::getCloths() const
{
    return cloths;
}

Cloths &People::getVariableCloths()
{
    return cloths;
}

void People::setCloths(const Cloths &newCloths)
{
    cloths = newCloths;
}

bool People::save()
{
    return true;
}

std::vector<Tag *> People::getTagList() const
{
    return tagList;
}

std::vector<Tag *> &People::getVariableTagList()
{
    return tagList;
}

void People::setTagList(const std::vector<Tag *> &newTagList)
{
    tagList = newTagList;
}

}
