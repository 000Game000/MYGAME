#include "People.h"
//#include "Modules/MYFunctions.h"
#include "Modules/Global.h"
#include <Modules/AttributeAdd.h>

#include <Modules/Position/Anus.h>
#include <Modules/Position/Bladder.h>
#include <Modules/Position/Breast.h>
#include <Modules/Position/Clit.h>
#include <Modules/Position/Mouth.h>
#include <Modules/Position/Nipple.h>
#include <Modules/Position/Ovary.h>
#include <Modules/Position/Penis.h>
#include <Modules/Position/Urethra.h>
#include <Modules/Position/Uterus.h>
#include <Modules/Position/Vagina.h>

#include <QJsonArray>
namespace MYGAME {

QString People::getLive() const
{
    return live;
}

void People::setLive(QString newLive)
{
    live = newLive;
}

QString People::getCurrentPosition() const
{
    return currentPosition;
}

void People::setCurrentPosition(QString newCurrentPosition)
{
    currentPosition = newCurrentPosition;
}

People::People(int year,int month,int day)
{
    this->birthday.setDate(year,month,day);
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

QJsonObject*People::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","People");
    obj->insert("Name",this->name);
    obj->insert("NickName",this->nickName);
    obj->insert("Claimed",this->claimed);
    obj->insert("Birthday",this->birthday.toString("yyyy-MM-dd"));
    obj->insert("Occupation",this->occupation);
    obj->insert("Major",this->major);
    QJsonArray*JAttributeList=new QJsonArray();
    for(Attribute*i:this->attributeList){
        JAttributeList->append(*i->save());
    }
    obj->insert("Attribute",*JAttributeList);
    obj->insert("Height",this->height);
    obj->insert("Weight",this->weight);

    QJsonArray*JHairColor=new QJsonArray();
    int r=0;
    int g=0;
    int b=0;
    this->hairColor.getRgb(&r,&g,&b);
    JHairColor->append(r);
    JHairColor->append(g);
    JHairColor->append(b);
    obj->insert("HairColor",*JHairColor);

    QJsonArray*JSkinColor=new QJsonArray();
    this->skinColor.getRgb(&r,&g,&b);
    JSkinColor->append(r);
    JSkinColor->append(g);
    JSkinColor->append(b);
    obj->insert("SkinColor",*JSkinColor);

    QJsonArray*JRPupilColor=new QJsonArray();
    this->RPupilColor.getRgb(&r,&g,&b);
    JRPupilColor->append(r);
    JRPupilColor->append(g);
    JRPupilColor->append(b);
    obj->insert("RPupilColor",*JRPupilColor);

    QJsonArray*JLPupilColor=new QJsonArray();
    this->LPupilColor.getRgb(&r,&g,&b);
    JLPupilColor->append(r);
    JLPupilColor->append(g);
    JLPupilColor->append(b);
    obj->insert("LPupilColor",*JLPupilColor);

    QJsonArray*JTagList=new QJsonArray();
    for(Tag*i:this->tagList){
        JTagList->append(*i->save());
    }
    obj->insert("TagList",*JTagList);

    QJsonArray*JSkillList=new QJsonArray();
    for(Skill*i:this->skillList){
        JSkillList->append(*i->save());
    }
    obj->insert("SkillList",*JSkillList);

    QJsonArray*JPositionList=new QJsonArray();
    for(PositionBase*i:this->positionList){
        JPositionList->append(*i->save());
    }
    obj->insert("PositionList",*JPositionList);
    obj->insert("Describe",this->describe);
    obj->insert("Live",this->live);
    obj->insert("CurrentPosition",this->currentPosition);
    return obj;
}

bool People::load(QJsonObject obj)
{
    this->name=obj.value("Name").toString();
    this->nickName=obj.value("NickName").toString();
    this->claimed=obj.value("Claimed").toString();
    this->birthday=QDate::fromString(obj.value("Birthday").toString(),"yyyy-MM-dd");
    //qDebug()<<this->birthday.toString("yyyy-MM-dd");
    this->occupation=obj.value("Occupation").toString();
    this->major=obj.value("Major").toString();
    QJsonValue value=obj.value("Attribute");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        for(long long i=0;i<arr.size();i++){
            QJsonValue v=arr.at(i);
            if(v.isObject()){
                QJsonObject o=v.toObject();
                if(o.value("ClassType").toString().compare("Attribute")==0){
                    Attribute*a=new Attribute();
                    a->load(o);
                    this->attributeList.push_back(a);
                }else{
                    AttributeAdd*a=new AttributeAdd();
                    a->load(o);
                    this->attributeList.push_back(a);
                }
            }
        }
    }
    this->height=(Height)obj.value("Height").toInt();
    this->weight=(Weight)obj.value("Weight").toInt();
    value=obj.value("HairColor");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        this->hairColor=MYGAME::JsonArrToQColor(arr);
    }
    value=obj.value("SkinColor");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        this->skinColor=MYGAME::JsonArrToQColor(arr);
    }
    value=obj.value("RPupilColor");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        this->RPupilColor=MYGAME::JsonArrToQColor(arr);
    }
    value=obj.value("LPupilColor");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        this->LPupilColor=MYGAME::JsonArrToQColor(arr);
    }
    value=obj.value("TagList");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        for(long long i=0;i<arr.size();i++){
            QJsonValue t=arr.at(i);
            if(t.isObject()){
                QJsonObject o=t.toObject();
                Tag*tag=new Tag();
                tag->load(o);
                this->tagList.push_back(tag);
            }
        }
    }
    value=obj.value("SkillList");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        for(long long i=0;i<arr.size();i++){
            QJsonValue s=arr.at(i);
            if(s.isObject()){
                QJsonObject o=s.toObject();
                Skill*s=new Skill();
                s->load(o);
                this->skillList.push_back(s);
            }
        }
    }
    value=obj.value("PositionList");
    if(value.isArray()){
        QJsonArray arr=value.toArray();
        for(long long i=0;i<arr.size();i++){
            QJsonValue s=arr.at(i);
            if(s.isObject()){
                QJsonObject o=s.toObject();
                if(o.value("ClassType").toString().compare("Anus")==0){
                    Anus*a=new Anus();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Bladder")==0){
                    Bladder*a=new Bladder();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Breast")==0){
                    Breast*a=new Breast();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Clit")==0){
                    Clit*a=new Clit();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Mouth")==0){
                    Mouth*a=new Mouth();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Nipple")==0){
                    Nipple*a=new Nipple();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Ovary")==0){
                    Ovary*a=new Ovary();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Penis")==0){
                    Penis*a=new Penis();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Urethra")==0){
                    Urethra*a=new Urethra();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Uterus")==0){
                    Uterus*a=new Uterus();
                    a->load(o);
                    this->positionList.push_back(a);
                }else if(o.value("ClassType").toString().compare("Vagina")==0){
                    Vagina*a=new Vagina();
                    a->load(o);
                    this->positionList.push_back(a);
                }
            }
        }
    }
    this->describe=obj.value("Describe").toString();
    this->live=obj.value("Live").toString();
    this->currentPosition=obj.value("CurrentPosition").toString();
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
