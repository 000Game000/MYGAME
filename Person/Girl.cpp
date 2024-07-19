#include "Girl.h"
namespace MYGAME {
long long Girl::getId() const
{
    return id;
}

void Girl::setId(long long newId)
{
    id = newId;
}

long long Girl::getLovept() const
{
    return lovept;
}

void Girl::setLovept(long long newLovept)
{
    lovept = newLovept;
}

long long Girl::getObedience() const
{
    return obedience;
}

void Girl::setObedience(long long newObedience)
{
    obedience = newObedience;
}

long long Girl::getFornication() const
{
    return fornication;
}

void Girl::setFornication(long long newFornication)
{
    fornication = newFornication;
}

QString Girl::getImg() const
{
    return img;
}

void Girl::setImg(const QString &newImg)
{
    img = newImg;
}

QString Girl::getThought() const
{
    return thought;
}

void Girl::setThought(const QString &newThought)
{
    thought = newThought;
}

QString Girl::getSelfIntroduction() const
{
    return selfIntroduction;
}

void Girl::setSelfIntroduction(const QString &newSelfIntroduction)
{
    selfIntroduction = newSelfIntroduction;
}

CrotchTattoo *Girl::getCrotchTattoo() const
{
    return crotchTattoo;
}

CrotchTattoo *Girl::getVariableCrotchTattoo()
{
    return crotchTattoo;
}

void Girl::setCrotchTattoo(CrotchTattoo *newCrotchTattoo)
{
    crotchTattoo = newCrotchTattoo;
}

long long Girl::getSm() const
{
    return sm;
}

void Girl::setSm(long long newSm)
{
    sm = newSm;
}

long long Girl::getExposing() const
{
    return exposing;
}

void Girl::setExposing(long long newExposing)
{
    exposing = newExposing;
}

Girl::Girl(int year,int month,int day):People(year,month,day)
{
    this->crotchTattoo=new CrotchTattoo();
}

QJsonObject *Girl::save()
{
    QJsonObject*obj=new QJsonObject();
    obj->insert("ClassType","Girl");
    obj->insert("Id",QString::number(this->id));
    obj->insert("Lovept",QString::number(this->lovept));
    obj->insert("Obedience",QString::number(this->obedience));
    obj->insert("Fornication",QString::number(this->fornication));
    obj->insert("Desire",QString::number(this->desire));
    obj->insert("SM",QString::number(this->sm));
    obj->insert("Exposing",QString::number(this->exposing));
    obj->insert("Img",this->img);
    obj->insert("Thought",this->thought);
    obj->insert("SelfIntroduction",this->selfIntroduction);
    obj->insert("CrotchTattoo",*this->crotchTattoo->save());
    obj->insert("People",*People::save());
    return obj;
}

bool Girl::load(QJsonObject obj)
{
    this->id=obj.value("Id").toString().toLongLong();
    this->lovept=obj.value("Lovept").toString().toLongLong();
    this->obedience=obj.value("Obedience").toString().toLongLong();
    this->fornication=obj.value("Fornication").toString().toLongLong();
    this->desire=obj.value("Desire").toString().toLongLong();
    this->sm=obj.value("SM").toString().toLongLong();
    this->exposing=obj.value("Exposing").toString().toLongLong();
    this->img=obj.value("Img").toString();
    this->thought=obj.value("Thought").toString();
    this->selfIntroduction=obj.value("SelfIntroduction").toString();
    QJsonValue value=obj.value("CrotchTattoo");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        this->crotchTattoo=new CrotchTattoo();
        this->crotchTattoo->load(o);
    }
    value=obj.value("People");
    if(value.isObject()){
        QJsonObject o=value.toObject();
        People::load(o);
    }
    return true;
}
}
