#include "Global.h"
#include "QDebug"
namespace MYGAME{
QList<QString> Global::getMajorList() const
{
    return majorList;
}

QList<QString> Global::getCareerList() const
{
    return careerList;
}

Global::Global()
{
    this->initMajorList();
    this->initCareerList();
}

void Global::initMajorList()
{
    this->majorList<<"计算机";
}

void Global::initCareerList()
{
    this->careerList<<"自由职业者";
}
}
