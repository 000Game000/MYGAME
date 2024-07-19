#include "MengLi.h"
#include "Modules/Position/Mouth.h"

#include <Modules/Position/Anus.h>
#include <Modules/Position/Bladder.h>
#include <Modules/Position/Breast.h>
#include <Modules/Position/Clit.h>
#include <Modules/Position/Nipple.h>
#include <Modules/Position/Ovary.h>
#include <Modules/Position/Urethra.h>
#include <Modules/Position/Uterus.h>
#include <Modules/Position/Vagina.h>

#include <Modules/AttributeAdd.h>
namespace MYGAME{
MengLi::MengLi(int year,int month,int day):Girl(year,month,day) {
    this->id=9;
    this->name="梦璃";
    this->nickName="小璃";
    this->claimed="我";
    this->birthday.setDate(year-14,7,12);
    this->occupation="学生";
    this->major="";
    Attribute*att=new Attribute("智力",220,0);
    this->attributeList.push_back(att);
    att=new Attribute("魅力",215,0);
    this->attributeList.push_back(att);
    att=new Attribute("敏捷",200,0);
    this->attributeList.push_back(att);
    AttributeAdd*attadd=new AttributeAdd("体质",220,0,220);
    this->attributeList.push_back(attadd);
    attadd=new AttributeAdd("意志",200,0,200);
    this->attributeList.push_back(attadd);
    this->height=Petite;
    this->weight=slender;
    this->hairColor.setRgb(204,255,255);
    this->skinColor.setRgb(242,185,178);
    this->RPupilColor.setRgb(179,0,255);
    this->LPupilColor.setRgb(179,0,255);
    Tag*tag=new Tag("魔法少女","大幅度增加五维属性，年龄永远定格在变成魔法少女的那一刻，达到一定条件变为恶堕魔法少女");
    this->tagList.push_back(tag);
    tag=new Tag("纳米紧身衣","固定内衣为纳米紧身衣，除特殊事件外不可更改");
    this->tagList.push_back(tag);
    tag=new Tag("恶（魅）魔契约","被中出时回复体力，身体敏感度大幅度提高");
    this->tagList.push_back(tag);
    Mouth*m=new Mouth(0,0,0,0);
    this->positionList.push_back(m);
    Breast*b=new Breast(3,0,0,0,false,136);
    this->positionList.push_back(b);
    QColor color;
    color.setRgb(255,153,153);
    Nipple*n=new Nipple(3,0,0,0,18,10,1,color);
    this->positionList.push_back(n);
    Clit*c=new Clit(3,0,0,0,12,13);
    this->positionList.push_back(c);
    Urethra*u=new Urethra(3,0,0,0,3);
    this->positionList.push_back(u);
    Bladder*bl=new Bladder(3,0,0,0,500);
    this->positionList.push_back(bl);
    color.setRgb(255,204,204);
    Vagina*v=new Vagina(3,0,0,0,70,13,color);
    this->positionList.push_back(v);
    Uterus*ut=new Uterus(5,0,0,0,10);
    this->positionList.push_back(ut);
    Ovary*o=new Ovary(5,0,0,0);
    this->positionList.push_back(o);
    Anus*a=new Anus(3,0,0,0,15,800);
    this->positionList.push_back(a);
    this->describe="因为接受了一份独特的契约成为了拥有光与暗两种属性的魔法少女并且大幅度强化了少女变身前的身体素质，代价是这份独特的契约会把魔法少女本人变身前的身体敏感度变得非常高，所以穿上了一件高科技纳米紧身衣。这件衣服可以随意更改颜色，大小，甚至可以变成透明的。这件衣服由无数的纳米机器人构成薄如蝉翼，完全不会影响少女的日常生活.";
    this->live="7-1-6-0-0-3-1";
    this->currentPosition="7-1-6-0-0-3-1";
    this->lovept=0;
    this->obedience=0;
    this->fornication=0;
    this->desire=0;
    this->sm=0;
    this->exposing=0;
    this->img="";
    this->thought="";
    this->selfIntroduction="";
    this->crotchTattoo=new CrotchTattoo();
}

QJsonObject *MengLi::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","MengLi");
    obj->insert("Girl",*Girl::save());
    return obj;
}

bool MengLi::load(QJsonObject obj)
{
    QJsonValue v=obj.value("Girl");
    if(v.isObject()){
        QJsonObject o=v.toObject();
        return Girl::load(o);
    }
    return false;
}
}
