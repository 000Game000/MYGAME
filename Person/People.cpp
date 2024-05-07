#include "People.h"
#include "Modules/MYFunctions.h"

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

// Cloths People::getCloths() const
// {
//     return cloths;
// }

// Cloths &People::getVariableCloths()
// {
//     return cloths;
// }

// void People::setCloths(const Cloths &newCloths)
// {
//     cloths = newCloths;
// }

QString People::save()
{
    QString str="\nname:"+this->name+"\nnickName:"+this->nickName+"\nclaimed:"+this->claimed
                  +"\nbirthday:"+this->birthday.toString("yyyy-MM-dd")+"\noccupation:"+this->occupation
                  +"\nmajor:"+this->major;
    str+="\n数量:"+QString::number(this->attributeList.size());
    for(size_t i=0;i<this->attributeList.size();i++){
        str+=attributeList[i]->save();
    }
    str+="\nheight:"+QString::number(this->height)+"\nweight:"+QString::number(this->height)+"\nhairColor:";
    int r=0;
    int g=0;
    int b=0;
    this->hairColor.getRgb(&r,&g,&b);
    str+="\nr:"+QString::number(r);
    str+="\ng:"+QString::number(g);
    str+="\nb:"+QString::number(b);
    str+="\nskinColor:";
    this->skinColor.getRgb(&r,&g,&b);
    str+="\nr:"+QString::number(r);
    str+="\ng:"+QString::number(g);
    str+="\nb:"+QString::number(b);
    str+="\nRPupilColor:";
    this->RPupilColor.getRgb(&r,&g,&b);
    str+="\nr:"+QString::number(r);
    str+="\ng:"+QString::number(g);
    str+="\nb:"+QString::number(b);
    str+="\nLPupilColor:";
    this->LPupilColor.getRgb(&r,&g,&b);
    str+="\nr:"+QString::number(r);
    str+="\ng:"+QString::number(g);
    str+="\nb:"+QString::number(b);
    str+="\n数量:"+QString::number(this->tagList.size());
    for(size_t i=0;i<this->tagList.size();i++){
        str+=this->tagList[i]->save();
    }
    str+="\n数量:"+QString::number(this->skillList.size());
    for(size_t i=0;i<this->skillList.size();i++){
        str+=this->skillList[i]->save();
    }
    str+="\n数量:"+QString::number(this->positionList.size());
    for(size_t i=0;i<this->positionList.size();i++){
        str+=this->positionList[i]->save();
    }
    str+="\ndescribe:"+this->describe;
    str+="\nlive:"+MYGAME::getSPosition(this->live);
    str+="\ncurrentPosition:"+MYGAME::getSPosition(this->currentPosition);
    return str;
}

bool People::load(QTextStream &ts,std::vector<MYGAME::Map*>*mapList)
{
    this->name=getValue(ts.readLine());
    this->nickName=getValue(ts.readLine());
    this->claimed=getValue(ts.readLine());
    this->birthday=QDate::fromString(getValue(ts.readLine()),"yyyy-MM-dd");
    this->occupation=getValue(ts.readLine());
    this->major=getValue(ts.readLine());
    size_t max=getValue(ts.readLine()).toULongLong();
    for(size_t i=0;i<max;i++){
        QString type=getValue(ts.readLine());
        if(type.compare("AttributeAdd")==0){
            AttributeAdd*add=new AttributeAdd();
            add->load(ts);
            this->attributeList.push_back(add);
        }else if(type.compare("Attribute")==0){
            Attribute*a=new Attribute();
            a->load(ts);
            this->attributeList.push_back(a);
        }
    }
    this->height=(Height)getValue(ts.readLine()).toInt();
    this->weight=(Weight)getValue(ts.readLine()).toInt();
    ts.readLine();
    int r=getValue(ts.readLine()).toInt();
    int g=getValue(ts.readLine()).toInt();
    int b=getValue(ts.readLine()).toInt();
    this->hairColor.setRgb(r,g,b);
    ts.readLine();
    r=getValue(ts.readLine()).toInt();
    g=getValue(ts.readLine()).toInt();
    b=getValue(ts.readLine()).toInt();
    this->skinColor.setRgb(r,g,b);
    ts.readLine();
    r=getValue(ts.readLine()).toInt();
    g=getValue(ts.readLine()).toInt();
    b=getValue(ts.readLine()).toInt();
    this->RPupilColor.setRgb(r,g,b);
    ts.readLine();
    r=getValue(ts.readLine()).toInt();
    g=getValue(ts.readLine()).toInt();
    b=getValue(ts.readLine()).toInt();
    this->LPupilColor.setRgb(r,g,b);
    max=getValue(ts.readLine()).toULongLong();
    for(size_t i=0;i<max;i++){
        Tag*P=new Tag();
        P->load(ts);
        this->tagList.push_back(P);
    }
    max=getValue(ts.readLine()).toULongLong();
    for(size_t i=0;i<max;i++){
        Skill*P=new Skill();
        P->load(ts);
        this->skillList.push_back(P);
    }
    max=getValue(ts.readLine()).toULongLong();
    for(size_t i=0;i<max;i++){
        QString name=getValue(ts.readLine());
        if(name.compare("肛门")==0){
            Anus*P=new Anus();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("膀胱")==0){
            Bladder*P=new Bladder();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("乳房")==0){
            Breast*P=new Breast();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("阴蒂")==0){
            Clit*P=new Clit();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("嘴巴")==0){
            Mouth*P=new Mouth();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("乳头")==0){
            Nipple*P=new Nipple();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("卵巢")==0){
            Ovary*P=new Ovary();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("阴茎")==0){
            Penis*P=new Penis();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("尿道")==0){
            Urethra*P=new Urethra();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("子宫")==0){
            Uterus*P=new Uterus();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
        if(name.compare("阴道")==0){
            Vagina*P=new Vagina();
            P->setName(name);
            P->load(ts);
            this->positionList.push_back(P);
        }
    }
    this->describe=getValue(ts.readLine());
    QString str=getValue(ts.readLine());
    QStringList slist=str.split("\\");
    for(qsizetype i=0;i<slist.size();i++){
        for(size_t j=0;j<mapList->size();j++){
            if(slist[i].compare((*mapList)[j]->getName())==0){
                if((*mapList)[j]->getList()==nullptr){
                    this->live=dynamic_cast<Room*>((*mapList)[j]);
                    break;
                }
                mapList=(*mapList)[j]->getList();
                break;
            }
        }
    }
    str=getValue(ts.readLine());
    slist=str.split("\\");
    for(qsizetype i=0;i<slist.size();i++){
        for(size_t j=0;j<mapList->size();j++){
            if(slist[i].compare((*mapList)[j]->getName())==0){
                if((*mapList)[j]->getList()==nullptr){
                    this->currentPosition=(*mapList)[j];
                    break;
                }
                mapList=(*mapList)[j]->getList();
                break;
            }
        }
    }
    return true;
}
std::vector<Attribute*> attributeList;          //属性表列
Height height;                                  //身高
Weight weight;                                  //胖瘦
QColor hairColor;                               //发色
QColor skinColor;                               //肤色
QColor RPupilColor;                             //右眼颜色
QColor LPupilColor;                             //左眼颜色
std::vector<Tag*> tagList;                      //人物素质
std::vector<Skill*> skillList;                  //技能表列
std::vector<PositionBase*> positionList;        //部位表列
QString describe;                               //人物描述
Room *live;                                     //人物居住地址
Map*currentPosition;                            //当前所在地点
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
