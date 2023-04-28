#include "Global.h"
#include "QDebug"
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
