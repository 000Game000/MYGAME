#include "Map/Path.h"
#include "Mainwindow.h"
#include "Windows/Load.h"
#include "Person/MengLi.h"
#include "Person/People.h"
#include "Windows/MapList.h"
#include "ui_Mainwindow.h"
#include "Modules/Global.h"
#include "Windows/ItemList.h"
#include "Windows/CreateLead.h"
#include "Windows/PeopleList.h"
#include "Windows/BeginWindow.h"
#include "Windows/SystemStore.h"
#include "Windows/PlayerStatus.h"
#include "Modules/AttributeAdd.h"

#include <QDir>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>

#define button_width 130
#define button_height 36

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initWindows();
    this->initMap();
    this->initSystemCommand();
    this->_system=new MYGAME::System_();
    ui->Information->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
    ui->systemCommand->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
}

MainWindow::~MainWindow()
{
    MYGAME::global.setMainWindow(nullptr);
    delete ui;
}

void MainWindow::NewGame(MYGAME::Player *player)
{
    this->player=player;
    //初始化时间
    this->time=new QDateTime(QDate(3021,6,30),QTime(7,0,0));
    this->initPeople();
    this->show();
    this->recovery();
}

void MainWindow::loadGame(QString sdir)
{
    this->read(sdir);
    this->recovery();
    this->show();
}

void MainWindow::initWindows()
{
    MYGAME::global.setMainWindow(this);
    MYGAME::global.setBeginWindow(new BeginWindow);
    MYGAME::global.setCreateLead(new CreateLead);
    MYGAME::global.getBeginWindow()->show();
    connect(MYGAME::global.getCreateLead(),&CreateLead::NewGame,this,&MainWindow::NewGame);
    connect(MYGAME::global.getBeginWindow(),&BeginWindow::sdirSignals,this,&MainWindow::loadGame);
}

void MainWindow::initSystemCommand()
{
    this->SystemCommandList.push_back(&MainWindow::playerStatusFunction);
    this->SystemCommandList.push_back(&MainWindow::itemList);
    this->SystemCommandList.push_back(&MainWindow::systemStore);
    this->SystemCommandList.push_back(&MainWindow::showPeopleList);
    this->SystemCommandList.push_back(&MainWindow::move);
    this->SystemCommandList.push_back(&MainWindow::addTime);
}

void MainWindow::initSystemCommandDockWidget()
{
    QScrollArea*SystemCommandSA=new QScrollArea(ui->systemCommand);
    ui->systemCommand->setWidget(SystemCommandSA);

    QWidget*widget=new QWidget(SystemCommandSA);
    widget->setAttribute(Qt::WA_DeleteOnClose);
    SystemCommandSA->setWidget(widget);
    widget->resize(SystemCommandSA->size());

    this->gridLayoutWidget(widget,this,&this->SystemCommandList);
    SystemCommandSA->setWidgetResizable(true);
}

template<class T>
void MainWindow::gridLayoutWidget(QWidget*widget,T*type,std::vector<QString*(T::*)(UC)>*list)
{
    QGridLayout*gl=new QGridLayout(widget);
    size_t count=0;
    for(size_t i=0;i<list->size();i++){
        if((type->*(*list)[i])(1)->compare(QString("true"))==0){
            QPushButton*pb=new QPushButton(*(type->*(this->SystemCommandList[i]))(2),widget);
            pb->setMinimumSize(type->buttonWidth,type->buttonHeight);
            connect(pb,&QPushButton::clicked,type,(*list)[i]);
            gl->addWidget(pb,count/5,count%5);
            pb->show();
            count++;
        }
    }
    widget->setLayout(gl);
}

void MainWindow::initMap()
{
    MYGAME::Node*P;
    P=new MYGAME::Node("1-0-0-0-0-0-0","生命扇区（BIO）","扇区");
    std::vector<MYGAME::Path *> *pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),50,90,true));
    pathList->push_back(new MYGAME::Path("3-0-0-0-0-0-0",P->getId(),100,180,true));
    pathList->push_back(new MYGAME::Path("4-0-0-0-0-0-0",P->getId(),150,270,true));
    pathList->push_back(new MYGAME::Path("5-0-0-0-0-0-0",P->getId(),100,180,true));
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),50,90,true));
    pathList->push_back(new MYGAME::Path("6-0-0-0-0-0-0",P->getId(),50,90,true));
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-2-0-0-0-0-0",P->getId(),45,8,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-0-0-0-0-0","学院联合（AU）","区划");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-2-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-1-0-0-0-0","生命学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-2-0-0-0-0","智能学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-3-0-0-0-0","军事学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-4-0-0-0-0","娱乐学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-5-0-0-0-0","中央学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-6-0-0-0-0","能动学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-7-0-0-0-0","建设学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-8-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-1-8-0-0-0-0","绝色学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-1-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-3-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-5-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-6-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-1-7-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-2-0-0-0-0-0","起源生命（OCL）","区划");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-2-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("1-2-3-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-2-2-0-0-0-0","起源综合医院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-2-3-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("1-2-3-0-0-0-0","起源养老院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-1-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("1-2-2-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-0-0-0-0-0-0","先锋扇区（VAN）","扇区");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),50,90,true));
    pathList->push_back(new MYGAME::Path("3-0-0-0-0-0-0",P->getId(),50,90,true));
    pathList->push_back(new MYGAME::Path("4-0-0-0-0-0-0",P->getId(),100,180,true));
    pathList->push_back(new MYGAME::Path("5-0-0-0-0-0-0",P->getId(),150,270,true));
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),100,180,true));
    pathList->push_back(new MYGAME::Path("6-0-0-0-0-0-0",P->getId(),50,90,true));
    pathList->push_back(new MYGAME::Path("2-3-0-0-0-0-0",P->getId(),45,8,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-0-0-0-0-0","先锋科技园","区划");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("2-3-1-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-0-0-0-0","艾斯忒拉研究所(Astra Lab.)","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("2-3-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-0-0-0","艾斯忒拉研究所™先锋体验中心","区域");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("2-3-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-1-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-2-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-3-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-4-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-5-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-6-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-1-0-0","服装店","二级区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-2-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-3-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-4-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-5-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-6-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-2-0-0","家具店","二级区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-1-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-3-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-4-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-5-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-6-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-3-0-0","百货商店","二级区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-1-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-2-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-4-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-5-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-6-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-4-0-0","五金工具店","二级区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-1-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-2-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-3-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-5-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-6-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-5-0-0","机电商城","二级区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-1-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-2-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-3-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-4-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-6-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-1-6-0-0","药店","二级区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-1-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-2-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-3-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-4-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-5-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-2-0-0-0","科研园","区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("2-3-1-4-0-0-0","妖精之梦产研会所","区域");
    pathList=new std::vector<MYGAME::Path*>();
    pathList->push_back(new MYGAME::Path("2-3-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("2-3-1-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("3-0-0-0-0-0-0","智能扇区（INT）","扇区");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("4-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("5-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),270,150,true));
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("6-0-0-0-0-0-0",P->getId(),90,50,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("4-0-0-0-0-0-0","军事扇区（MIL）","扇区");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),270,150,true));
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("3-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("6-0-0-0-0-0-0",P->getId(),90,50,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-0-0-0-0-0-0","娱乐扇区（ENT）","扇区");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),270,150,true));
    pathList->push_back(new MYGAME::Path("3-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("4-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("6-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("5-1-0-0-0-0-0",P->getId(),45,8,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-0-0-0-0-0","赛博娱乐","区划");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("5-1-2-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("5-1-4-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-2-0-0-0-0","赛博商业中心","区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("5-1-4-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("5-1-2-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-4-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-9-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-2-1-0-0-0","服装店","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-4-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-9-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-2-4-0-0-0","礼品店","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-9-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-2-9-0-0-0","成人用品店","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-2-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-4-0-0-0-0","红灯区","区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("5-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-3-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-4-1-0-0-0","情趣酒店","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-3-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-4-2-0-0-0","风俗店","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-3-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-4-3-0-0-0","夜总会","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-4-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("5-1-4-4-0-0-0","高端会所","二级区域");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("5-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("5-1-4-3-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("6-0-0-0-0-0-0","中枢扇区（CORE）（合并能源扇区）","扇区");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("3-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("4-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("5-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),90,50,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-0-0-0-0-0-0","居住扇区（LIV）","扇区");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("1-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("2-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("3-0-0-0-0-0-0",P->getId(),270,150,true));
    pathList->push_back(new MYGAME::Path("4-0-0-0-0-0-0",P->getId(),180,100,true));
    pathList->push_back(new MYGAME::Path("5-0-0-0-0-0-0",P->getId(),90,50,true));
    pathList->push_back(new MYGAME::Path("6-0-0-0-0-0-0",P->getId(),90,50,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-0-0-0-0-0","居住区","区划");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("7-2-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-3-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-0-0","父母家(主角家)","设施");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-0-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-3-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-4-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-1-0","-1F","楼层");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-1-1","地下室","房间");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-1-2","储藏室","房间");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-0","1F","楼层");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-1","门厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-2","客厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-3","餐厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-4","厨房","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-5","父母房间","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-2-6","厕所","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-3-0","2F","楼层");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-3-1","厕所","房间");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-3-2","妹妹房间","房间");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-3-3","自室","房间");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-3-4","娜娜莉房间","房间");
    pathList=new  std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-3-5","客房","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-4",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-1-0-0-4-0","后花园","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-3-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-0-0","艾斯忒拉家","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-0-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-3-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-1-0","庭院","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-1-1","储藏室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-1-2","花圃","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-0","1F","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-1","门厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-2","客厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-3","餐厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-4","厨房","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-5","卫生间","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-6","浴室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-7",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-2-7","机房","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-0","2F","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-1","娜娜莉卧室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-2","实验室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-3","卫生间","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-4","浴室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-5",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-5","客卧","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-6",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-3-6","露台","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-4",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-5",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-4-0","-1F","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-4-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-4-1","车库","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-4-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-5-0","后院","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-4-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-5-1","阳台","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-2-0-0-5-2","花园","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-5-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-3-0-0-0-0","小餐馆","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-0-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-4-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    //pathList->push_back(new MYGAME::Path("7-1-5-0-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-4-0-0-0-0","小卖部","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-0-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-2-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-3-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    //pathList->push_back(new MYGAME::Path("7-1-5-0-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-0-0","梦璃家","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-0-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-1",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-1-0","-1F","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-3",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-1-1","出口","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-3",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-1-2","作战实验室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-3",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-1-3","灵衣调整室","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-2-0","1F","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-4",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-2-1","大门","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-4",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-2-2","客厅","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-3",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-4",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-2-3","厨房","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-4",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-2-4","洗手间","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-4",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-3-0","2F","楼层");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-1-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-2-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-3",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-3-1","梦璃房间","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-2",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-3",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-3-2","客房","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-3",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-1-6-0-0-3-3","阳台","房间");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-1",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-1-6-0-0-3-2",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-2-0-0-0-0-0","学院联合分部","区划");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-0-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("7-1-0-0-0-0-0",P->getId(),45,8,true));
    pathList->push_back(new MYGAME::Path("7-2-1-0-0-0-0",P->getId(),5,2,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-2-1-0-0-0-0","初等学院","设施");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-2-0-0-0-0-0",P->getId(),5,2,true));
    pathList->push_back(new MYGAME::Path("7-2-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-2-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-2-1-1-0-0-0","高级中学","区域");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-2-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-2-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-3-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-2-1-2-0-0-0","初级中学","区域");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-2-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-3-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));

    P=new MYGAME::Node("7-2-1-3-0-0-0","通识学院","区域");
    pathList=new std::vector<MYGAME::Path *>();
    pathList->push_back(new MYGAME::Path("7-2-1-0-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-1-0-0-0",P->getId(),1,0,true));
    pathList->push_back(new MYGAME::Path("7-2-1-2-0-0-0",P->getId(),1,0,true));
    P->setPathList(pathList);
    this->mapList.insert(std::pair(P->getId(),P));
}

void MainWindow::recovery()
{

    //初始化血条
    ui->staminaBarStrip->setBackground(":/Strip/Strip/Red.png");
    ui->staminaBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->staminaBarStrip->setFrame(1);
    //初始化精力条
    ui->energyBarStrip->setBackground(":/Strip/Strip/Blue.png");
    ui->energyBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->energyBarStrip->setFrame(1);
    //初始化指令
    this->initSystemCommandDockWidget();
    this->refresh();
}

void MainWindow::initPeople()
{
    this->peopleList.push_back(new MYGAME::MengLi(this->time->date().year()));
}

void MainWindow::refresh()
{
    //刷新时间
    QString SFormat="yyyy年MM月dd日 hh:mm dddd";
    QLocale locale=QLocale::Chinese;
    ui->date->setText(locale.toString(*this->time,SFormat));
    //刷新角色类内部内容
    //刷新主角所在位置
    ui->position->setText("当前所在地点:"+this->mapList[this->player->getCurrentPosition()]->getName());
    ui->position->setToolTip(this->player->getCurrentPosition());
    //刷新系统点数
    ui->points->setText("点数:"+QString::number(player->getPoint()));
    //刷新金钱
    ui->money->setText("金钱:"+QString::number(player->getMoney()));
    std::vector<MYGAME::Attribute*>list=player->getAttributeList();
    for(size_t i=0;i<list.size();i++){
        //刷新体质条
        if(list[i]->getName().compare("体质")==0){
            MYGAME::AttributeAdd*temp=dynamic_cast<MYGAME::AttributeAdd*>(list[i]);
            ui->staminaBarStrip->setMaxValue(temp->getRank());
            ui->staminaBarStrip->setNowValue(temp->getNowValue());
            ui->staminaBarNumberLabel->setText(QString::number(temp->getNowValue())+"/"+QString::number(temp->getRank()));
        }
        //刷新精力条
        if(list[i]->getName().compare("意志")==0){
            MYGAME::AttributeAdd*temp=dynamic_cast<MYGAME::AttributeAdd*>(list[i]);
            ui->energyBarStrip->setMaxValue(temp->getRank());
            ui->energyBarStrip->setNowValue(temp->getNowValue());
            ui->energyBarNumberLabel->setText(QString::number(temp->getNowValue())+"/"+QString::number(temp->getRank()));
        }
    }
    this->initSystemCommandDockWidget();
}

QString*MainWindow::playerStatusFunction(UC flag)
{
    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("玩家状态");
    }
    PlayerStatus*Ps=new PlayerStatus(this->player);
    Ps->show();
    this->refresh();
    return nullptr;
}

QString *MainWindow::itemList(UC flag)
{
    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("所持物品");
    }
    ItemList*IL=new ItemList(this->player);
    IL->show();
    this->refresh();
    return nullptr;
}

QString *MainWindow::systemStore(UC flag)
{
    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("系统商城");
    }
    SystemStore*Ss=new SystemStore(this->player,this->_system);
    Ss->show();
    this->refresh();
    return nullptr;
}

QString *MainWindow::showPeopleList(UC flag)
{
    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("人物表列");
    }
    qDebug()<<this->peopleList.size();
    PeopleList*Pl=new PeopleList(&(this->peopleList),this->time,&(this->mapList));
    Pl->show();
    this->refresh();
    return nullptr;
}

QString *MainWindow::move(UC flag)
{

    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("移动");
    }
    MapList*P=new MapList(this->time,this->player,ui->textBrowser,&this->mapList);
    P->exec();
    this->refresh();
    return nullptr;
}

QString *MainWindow::addTime(UC flag)
{
    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("增加时间");
    }
    this->addT(this->time);
    this->refresh();
    return nullptr;
}

void MainWindow::addT(QDateTime *t)
{
    (*t)=t->addSecs(60);
    (*t)=t->addSecs(60*60);
}

void MainWindow::on_systemCommand_visibilityChanged(bool visible)
{
    if(visible){
        qDebug()<<"显示";
    }else{
        qDebug()<<"隐藏";
    }
}

void MainWindow::on_actionSave_S_triggered()
{
    QString time=QDateTime::currentDateTime().toString("yyyy.MM.dd   hh.mm.ss.zzz");
    QString sdir=QDir::currentPath()+"/save";
    QDir dir(sdir);
    if(!dir.exists()){
        if(!dir.mkdir(sdir)){
            QMessageBox::critical(this,"严重错误","save文件夹不存在并且无法创建",QMessageBox::Ok);
            return;
        }
    }
    sdir+="/"+time+".save";
    QFile file(sdir);
    if(file.exists()){
        file.remove();
    }
    file.open(QIODevice::ReadWrite);
    QJsonObject rootObject;
    rootObject.insert("Time",time);
    rootObject.insert("Version",MYGAME::Version);
    rootObject.insert("GameTime",this->time->toString("yyyy.MM.dd.hh.mm.ss.zzz"));
    rootObject.insert("Player",*this->player->save());
    QJsonArray*arr=new QJsonArray();
    for(MYGAME::People*i:this->peopleList){
        arr->append(*i->save());
    }
    rootObject.insert("PeopleList",*arr);
    QTextStream stream(&file);
    QJsonDocument doc;
    doc.setObject(rootObject);
    stream<<doc.toJson();
    file.close();
    qDebug()<<sdir;
}


void MainWindow::on_actionread_S_triggered()
{
    Load *P=new Load();
    connect(P,&Load::sdir,this,&MainWindow::read);
    P->show();
}

void MainWindow::read(QString sdir)
{
    ui->textBrowser->clear();
    this->peopleList.clear();                                                                                               //解决读档出现的多人物问题,其实会导致内存泄漏
    QFile file(sdir);
    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        QTextStream stream(&file);
        QString str=stream.readAll();
        QJsonParseError jsonError;
        QJsonDocument doc=QJsonDocument::fromJson(str.toUtf8());
        if(jsonError.error!=QJsonParseError::NoError){
            QMessageBox::critical(this,"严重错误","存档文件解析失败!!!",QMessageBox::Ok);
            this->close();
        }
        QJsonObject rootObj=doc.object();
        this->time=new QDateTime(QDateTime::fromString(rootObj.value("GameTime").toString(),"yyyy.MM.dd.hh.mm.ss.zzz"));
        this->player=new MYGAME::Player();
        QJsonValue jsonValue=rootObj.value("Player");
        if(jsonValue.isObject()){
            QJsonObject playerObj=jsonValue.toObject();
            this->player->load(playerObj);
        }else{
            QMessageBox::critical(this,"严重错误","存档文件解析失败!!!",QMessageBox::Ok);
            this->close();
        }
        jsonValue=rootObj.value("PeopleList");
        if(jsonValue.isArray()){
            QJsonArray arr=jsonValue.toArray();
            for(long long i=0;i<arr.size();i++){
                QJsonValue v=arr.at(i);
                if(v.isObject()){
                    QJsonObject o=v.toObject();
                    if(o.value("ClassType").toString().compare("MengLi")==0){
                        MYGAME::MengLi*mengli=new MYGAME::MengLi();
                        mengli->load(o);
                        this->peopleList.push_back(mengli);
                    }
                }
            }
        }
    }else{
        QMessageBox::critical(this,"严重错误","无法读取存档文件!!!",QMessageBox::Ok);
        this->close();
    }
    file.close();
}
