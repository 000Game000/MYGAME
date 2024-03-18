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

Girl::Girl()
{
    this->crotchTattoo=new CrotchTattoo();
}
}
