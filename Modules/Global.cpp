#include "Global.h"
#include "QDebug"
namespace MYGAME{
Global global;
QList<QString> Global::getMajorList()
{
    return majorList;
}

QList<QString> Global::getCareerList()
{
    return careerList;
}

MainWindow *Global::getMainWindow() const
{
    return mainWindow;
}

void Global::setMainWindow(MainWindow *newMainWindow)
{
    mainWindow = newMainWindow;
}

BeginWindow *Global::getBeginWindow() const
{
    return beginWindow;
}

void Global::setBeginWindow(BeginWindow *newBeginWindow)
{
    beginWindow = newBeginWindow;
}

CreateLead *Global::getCreateLead() const
{
    return createLead;
}

void Global::setCreateLead(CreateLead *newCreateLead)
{
    createLead = newCreateLead;
}

Global::Global()
{
    this->initMajorList();
    this->initCareerList();
    this->mainWindow=nullptr;
    this->beginWindow=nullptr;
    this->createLead=nullptr;
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
