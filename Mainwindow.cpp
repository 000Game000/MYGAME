#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Modules/Global.h"
#include "Windows/ItemList.h"
#include "Windows/CreateLead.h"
#include "Windows/PeopleList.h"
#include "Windows/BeginWindow.h"
#include "Windows/SystemStore.h"
#include "Modules/MYFunctions.h"
#include "Windows/PlayerStatus.h"
#include "Modules/AttributeAdd.h"
#include "Person/SystemGirlOne.h"
#define button_width 130
#define button_height 36
void textMap(std::vector<MYGAME::Map*>&mapList);
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->initWindows();
    this->initMap();
    this->initSystemCommand();
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
    this->player->setLive((*(*(*(*(*this->mapList[6]->getList())[0]->getList())[0]->getList())[0]->getList())[2]->getList())[1]);
    this->player->setCurrentPosition(this->player->getLive());
    this->initNewGame();
    this->show();
    this->initSystemCommandDockWidget();
}

void MainWindow::initWindows()
{
    MYGAME::global.setMainWindow(this);
    MYGAME::global.setBeginWindow(new BeginWindow);
    MYGAME::global.setCreateLead(new CreateLead);
    MYGAME::global.getBeginWindow()->show();
    connect(MYGAME::global.getCreateLead(),&CreateLead::NewGame,this,&MainWindow::NewGame);
}

void MainWindow::initNewGame()
{
    //初始化时间
    this->time=new QDateTime(QDate(3021,6,30),QTime(7,0,0));
    //初始化血条
    ui->staminaBarStrip->setBackground(":/Strip/Strip/Red.png");
    ui->staminaBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->staminaBarStrip->setFrame(1);
    //初始化精力条
    ui->energyBarStrip->setBackground(":/Strip/Strip/Blue.png");
    ui->energyBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->energyBarStrip->setFrame(1);
    //初始化主角所在位置
    ui->position->setText("当前所在地点:"+this->player->getCurrentPosition()->getName());
    ui->position->setToolTip(MYGAME::getSPosition(this->player->getCurrentPosition()));
    initPeople();
    this->refresh();
}

void MainWindow::initSystemCommand()
{
    this->SystemCommandList.push_back(&MainWindow::playerStatusFunction);
    this->SystemCommandList.push_back(&MainWindow::itemList);
    this->SystemCommandList.push_back(&MainWindow::systemStore);
    this->SystemCommandList.push_back(&MainWindow::showPeopleList);
    this->SystemCommandList.push_back(&MainWindow::move);
    this->SystemCommandList.push_back(&MainWindow::text);
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
            QPushButton*pb=new QPushButton(*(this->*(this->SystemCommandList[i]))(2),widget);
            pb->setMinimumSize(this->buttonWidth,this->buttonHeight);
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
    //扇区
    this->mapList.push_back(new MYGAME::Map("中枢扇区",nullptr,"","扇区",nullptr));
    this->mapList.push_back(new MYGAME::Map("生命扇区",nullptr,"","扇区",nullptr));
    this->mapList.push_back(new MYGAME::Map("先锋扇区",nullptr,"","扇区",nullptr));
    this->mapList.push_back(new MYGAME::Map("智能扇区",nullptr,"","扇区",nullptr));
    this->mapList.push_back(new MYGAME::Map("军事扇区",nullptr,"","扇区",nullptr));
    this->mapList.push_back(new MYGAME::Map("娱乐扇区",nullptr,"","扇区",nullptr));
    this->mapList.push_back(new MYGAME::Map("居住扇区",nullptr,"","扇区",nullptr));

    //中枢扇区
    std::vector<MYGAME::Map*>*_0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("天柱区",nullptr,"","区划",this->mapList[0]));
    _0->push_back(new MYGAME::Map("生态模拟区",nullptr,"","区划",this->mapList[0]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[0]));
    this->mapList[0]->setList(_0);
    //天柱区
    std::vector<MYGAME::Map*>*__0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("中枢核电站",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("中央计算机",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("中枢塔",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("天柱塔",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("天柱区站",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //中枢塔
    std::vector<MYGAME::Map*>*___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("能源科技署",nullptr,"","地点分区",(*__0)[2]));
    ___0->push_back(new MYGAME::Map("行政服务中心",nullptr,"","地点分区",(*__0)[2]));
    (*__0)[2]->setList(___0);
    //能源科技署
    std::vector<MYGAME::Map*>*____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("能源工程车间",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("反应炉区",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("能源科技署电梯站",nullptr,"","地点分区1",(*___0)[0]));
    (*___0)[0]->setList(____0);
    //行政服务中心
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("管理中心",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("服务中心",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("中枢塔电梯站",nullptr,"","地点分区1",(*___0)[1]));
    (*___0)[1]->setList(____0);
    //天柱塔
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("观光层",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("维修空间",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("穹顶",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("太空港",nullptr,"","地点分区",(*__0)[3]));
    (*__0)[3]->setList(___0);
    //穹顶
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("货运车站",nullptr,"","地点分区1",(*___0)[2]));
    ____0->push_back(new MYGAME::Map("航空港",nullptr,"","地点分区1",(*___0)[2]));
    ____0->push_back(new MYGAME::Map("雷达站",nullptr,"","地点分区1",(*___0)[2]));
    (*___0)[2]->setList(____0);
    //太空港
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("1",nullptr,"","楼层",(*___0)[3]));
    ____0->push_back(new MYGAME::Map("2",nullptr,"","楼层",(*___0)[3]));
    ____0->push_back(new MYGAME::Map("3",nullptr,"","楼层",(*___0)[3]));
    (*___0)[3]->setList(____0);
    //1
    std::vector<MYGAME::Map*>*_____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("售票",nullptr,"","房间",(*____0)[0],"售票"));
    _____0->push_back(new MYGAME::Room("货运港",nullptr,"","太空港",(*____0)[0],"太空港"));
    (*____0)[0]->setList(_____0);
    //2
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("到达",nullptr,"","房间",(*____0)[1],"太空到达港"));
    (*____0)[1]->setList(_____0);
    //3
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("出发",nullptr,"","房间",(*____0)[2],"太空出发港"));
    (*____0)[2]->setList(_____0);
    //生态模拟区
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("温带生态区",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("热带生态区",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("山地生态区",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("海洋生态区",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("极地生态区",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("赛博娱乐旅游分部",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("生态模拟区枢纽",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Room("生态模拟区站",nullptr,"","车站",(*_0)[1],"车站"));
    (*_0)[1]->setList(__0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("中枢区交通站",nullptr,"","车站",(*_0)[2],"车站"));
    __0->push_back(new MYGAME::Room("中枢区机场",nullptr,"","机场",(*_0)[2],"机场"));
    __0->push_back(new MYGAME::Room("中枢区列车站",nullptr,"","列车站",(*_0)[2],"列车站"));
    __0->push_back(new MYGAME::Room("中枢区港口",nullptr,"","港口",(*_0)[2],"港口"));
    __0->push_back(new MYGAME::Room("中央塔电梯基站",nullptr,"","中央塔电梯",(*_0)[2],"中央塔电梯"));
    (*_0)[2]->setList(__0);

    //生命生命扇区
    _0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("学院联合",nullptr,"","区划",this->mapList[1]));
    _0->push_back(new MYGAME::Map("起源生命",nullptr,"","区划",this->mapList[1]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[1]));
    this->mapList[1]->setList(_0);
    //学院联合
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("生命学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("智能学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("军事学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("娱乐学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("中央学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("能动学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("建设学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("绝色学院",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("学院联合站",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //生命学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("医疗学系",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("仿生学系",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("生物学系",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("农学系",nullptr,"","地点分区",(*__0)[0]));
    (*__0)[0]->setList(___0);
    //智能学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("人工智能学系",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("软件工程系",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("义体机械工程系",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("微电子工程系",nullptr,"","地点分区",(*__0)[1]));
    (*__0)[1]->setList(___0);
    //军事学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("军事科学系",nullptr,"","地点分区",(*__0)[2]));
    ___0->push_back(new MYGAME::Map("军事工程学系",nullptr,"","地点分区",(*__0)[2]));
    (*__0)[2]->setList(___0);
    //娱乐学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("商业学系",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("传媒学系",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("艺术系",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("文学系",nullptr,"","地点分区",(*__0)[3]));
    (*__0)[3]->setList(___0);
    //中央学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("社会科学系",nullptr,"","地点分区",(*__0)[4]));
    ___0->push_back(new MYGAME::Map("自然科学系",nullptr,"","地点分区",(*__0)[4]));
    ___0->push_back(new MYGAME::Map("哲学系",nullptr,"","地点分区",(*__0)[4]));
    ___0->push_back(new MYGAME::Map("政治学系",nullptr,"","地点分区",(*__0)[4]));
    ___0->push_back(new MYGAME::Map("管理学系",nullptr,"","地点分区",(*__0)[4]));
    (*__0)[4]->setList(___0);
    //能动学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("能源与动力工程学系",nullptr,"","地点分区",(*__0)[5]));
    ___0->push_back(new MYGAME::Map("机械工程学系",nullptr,"","地点分区",(*__0)[5]));
    ___0->push_back(new MYGAME::Map("航空航天工程学系",nullptr,"","地点分区",(*__0)[5]));
    (*__0)[5]->setList(___0);
    //建设学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("规划学系",nullptr,"","地点分区",(*__0)[6]));
    ___0->push_back(new MYGAME::Map("建筑学系",nullptr,"","地点分区",(*__0)[6]));
    ___0->push_back(new MYGAME::Map("景观学系",nullptr,"","地点分区",(*__0)[6]));
    ___0->push_back(new MYGAME::Map("土木学系",nullptr,"","地点分区",(*__0)[6]));
    (*__0)[6]->setList(___0);
    //绝色学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("性学院",nullptr,"","地点分区",(*__0)[7]));
    (*__0)[7]->setList(___0);
    //起源生命
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("研究院",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("起源综合医院",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("起源养老院",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Room("起源生命站",nullptr,"","车站",(*_0)[1],"车站"));
    (*_0)[1]->setList(__0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("生命扇区交通站",nullptr,"","车站",(*_0)[2],"车站"));
    __0->push_back(new MYGAME::Room("生命扇区列车站",nullptr,"","列车站",(*_0)[2],"列车站"));
    __0->push_back(new MYGAME::Room("生命扇区机场",nullptr,"","机场",(*_0)[2],"机场"));
    (*_0)[2]->setList(__0);

    //先锋扇区
    _0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("\"希伯\"农业园区",nullptr,"","区划",this->mapList[2]));
    _0->push_back(new MYGAME::Map("燧人工业区",nullptr,"","区划",this->mapList[2]));
    _0->push_back(new MYGAME::Map("先锋科技园",nullptr,"","区划",this->mapList[2]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[2]));
    this->mapList[2]->setList(_0);
    //“希伯”农业园区
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("农业中心",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("农业试验场",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("农业园站",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //燧人工业区
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("祝融重工",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("工业园",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Room("工业区站",nullptr,"","车站",(*_0)[1],"车站"));
    __0->push_back(new MYGAME::Room("工业港",nullptr,"","港口",(*_0)[1],"港口"));
    (*_0)[1]->setList(__0);
    //先锋科技园
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("艾斯忒拉研究所",nullptr,"","设施",(*_0)[2]));
    __0->push_back(new MYGAME::Room("科技园区站",nullptr,"","车站",(*_0)[2],"车站"));
    (*_0)[2]->setList(__0);
    //艾斯忒拉研究所
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("艾斯忒拉研究所™先锋体验中心",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("科研园",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("制造所",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("妖精之梦产研会所",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("艾斯忒拉会议中心",nullptr,"","地点分区",(*__0)[0]));
    (*__0)[0]->setList(___0);
    //艾斯忒拉研究所™先锋体验中心
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("服装店",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("家具店",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("百货商店",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("五金工具店",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("机电商城",nullptr,"","地点分区1",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("药店",nullptr,"","地点分区1",(*___0)[0]));
    (*___0)[0]->setList(____0);
    //科研园
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("生命科学研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("机械与义体研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("军事军工研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("机械工程与动力工程研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("电子信息研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("规划与设计研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("文艺与哲学研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("自然科学研究院",nullptr,"","地点分区1",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("政治经济与管理研究院",nullptr,"","地点分区1",(*___0)[1]));
    (*___0)[1]->setList(____0);
    //制造所
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("复合工厂",nullptr,"","地点分区1",(*___0)[2]));
    ____0->push_back(new MYGAME::Map("装备试验场",nullptr,"","地点分区1",(*___0)[2]));
    (*___0)[2]->setList(____0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("先锋扇区交通站",nullptr,"","车站",(*_0)[2],"车站"));
    __0->push_back(new MYGAME::Room("先锋扇区列车站",nullptr,"","列车站",(*_0)[2],"列车站"));
    __0->push_back(new MYGAME::Room("先锋扇区机场",nullptr,"","机场",(*_0)[2],"机场"));
    __0->push_back(new MYGAME::Room("先锋扇区港口",nullptr,"","港口",(*_0)[2],"港口"));
    (*_0)[3]->setList(__0);

    //智能扇区
    _0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("91Lab",nullptr,"","区划",this->mapList[3]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[3]));
    this->mapList[3]->setList(_0);
    //91Lab
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("科研区",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("人形试验区",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("91Lab站",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("智能扇区交通站",nullptr,"","车站",(*_0)[1],"车站"));
    __0->push_back(new MYGAME::Room("智能扇区列车站",nullptr,"","列车站",(*_0)[1],"列车站"));
    __0->push_back(new MYGAME::Room("智能扇区机场",nullptr,"","机场",(*_0)[1],"机场"));
    (*_0)[1]->setList(__0);

    //军事扇区
    _0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("军工委员会",nullptr,"","区划",this->mapList[4]));
    _0->push_back(new MYGAME::Map("铁锈PMC",nullptr,"","区划",this->mapList[4]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[4]));
    this->mapList[4]->setList(_0);
    //军工委员会
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("军营",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("东风工坊",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("东风军工军港",nullptr,"","军港",(*_0)[0],"军港"));
    __0->push_back(new MYGAME::Map("巅峰科技",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("军工委站",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //铁锈PMC
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("铁锈PMC总部",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("铁锈工坊",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("铁锈PMC站",nullptr,"","车站",(*_0)[1]));
    (*_0)[1]->setList(__0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("军事扇区交通站",nullptr,"","车站",(*_0)[2],"车站"));
    __0->push_back(new MYGAME::Room("军事扇区列车站",nullptr,"","列车站",(*_0)[2],"列车站"));
    __0->push_back(new MYGAME::Room("军事扇区机场",nullptr,"","机场",(*_0)[2],"机场"));
    __0->push_back(new MYGAME::Room("军事扇区港口",nullptr,"","港口",(*_0)[2],"港口"));
    (*_0)[2]->setList(__0);

    //娱乐扇区
    _0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("赛博娱乐",nullptr,"","区划",this->mapList[5]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[5]));
    this->mapList[5]->setList(_0);
    //赛博娱乐
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("赛博广播电视台",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("赛博商业中心",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("俱乐部区",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("红灯区",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Map("绯色幻想",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("赛博娱乐站",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //赛博商业中心
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("服装店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("家具店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("工具店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("礼品店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("药店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("电子产品店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("餐饮店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("咖啡厅",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("酒店",nullptr,"","地点分区",(*__0)[1]));
    ___0->push_back(new MYGAME::Map("成人用品店",nullptr,"","地点分区",(*__0)[1]));
    (*__0)[1]->setList(___0);
    //俱乐部区
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("酒吧/清吧",nullptr,"","地点分区",(*__0)[2]));
    ___0->push_back(new MYGAME::Map("女仆俱乐部",nullptr,"","地点分区",(*__0)[2]));
    ___0->push_back(new MYGAME::Map("萝莉俱乐部",nullptr,"","地点分区",(*__0)[2]));
    ___0->push_back(new MYGAME::Map("足控俱乐部",nullptr,"","地点分区",(*__0)[2]));
    (*__0)[2]->setList(___0);
    //红灯区
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("情趣酒店",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("风俗店",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("风俗店",nullptr,"","地点分区",(*__0)[3]));
    ___0->push_back(new MYGAME::Map("高端会所",nullptr,"","地点分区",(*__0)[3]));
    (*__0)[3]->setList(___0);
    //绯色幻想
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("极乐广场",nullptr,"","地点分区",(*__0)[4]));
    ___0->push_back(new MYGAME::Map("阿尔忒弥斯药房",nullptr,"","地点分区",(*__0)[4]));
    (*__0)[4]->setList(___0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("赛博娱乐交通站",nullptr,"","车站",(*_0)[1],"车站"));
    __0->push_back(new MYGAME::Room("赛博娱乐列车站",nullptr,"","列车站",(*_0)[1],"列车站"));
    __0->push_back(new MYGAME::Room("赛博娱乐机场",nullptr,"","机场",(*_0)[1],"机场"));
    (*_0)[1]->setList(__0);

    //居住扇区
    _0=new std::vector<MYGAME::Map*>;
    _0->push_back(new MYGAME::Map("居住区",nullptr,"","区划",this->mapList[6]));
    _0->push_back(new MYGAME::Map("学院联合分部",nullptr,"","区划",this->mapList[6]));
    _0->push_back(new MYGAME::Map("扇区枢纽",nullptr,"","区划",this->mapList[6]));
    this->mapList[6]->setList(_0);
    //居住区
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("0区",nullptr,"","设施",(*_0)[0]));
    __0->push_back(new MYGAME::Room("居住区站.",nullptr,"","车站",(*_0)[0],"车站"));
    (*_0)[0]->setList(__0);
    //0区
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("父母家",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("艾斯忒拉家",nullptr,"","地点分区",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("HK家",nullptr,"","地点分区",(*__0)[0]));
    __0->push_back(new MYGAME::Room("0区站.",nullptr,"","车站",(*__0)[0],"车站"));
    (*__0)[0]->setList(___0);
    //父母家(主角)
    //楼层
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("-1楼",nullptr,"","楼层",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("1楼",nullptr,"","楼层",(*___0)[0]));
    ____0->push_back(new MYGAME::Map("2楼",nullptr,"","楼层",(*___0)[0]));
    ____0->push_back(new MYGAME::Room("后花园",nullptr,"","房间",(*___0)[0],"后花园"));
    (*___0)[0]->setList(____0);
    //-1
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("地下室",nullptr,"","房间",(*____0)[0],"地下室"));
    _____0->push_back(new MYGAME::Room("储藏室",nullptr,"","房间",(*____0)[0],"储藏室"));
    (*____0)[0]->setList(_____0);
    //1
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("门口",nullptr,"","房间",(*____0)[1],"门口"));
    _____0->push_back(new MYGAME::Room("客厅",nullptr,"","房间",(*____0)[1],"客厅"));
    _____0->push_back(new MYGAME::Room("餐厅",nullptr,"","房间",(*____0)[1],"餐厅"));
    _____0->push_back(new MYGAME::Room("厨房",nullptr,"","房间",(*____0)[1],"厨房"));
    _____0->push_back(new MYGAME::Room("父母房间",nullptr,"","房间",(*____0)[1],"父母房间"));
    _____0->push_back(new MYGAME::Room("厕所",nullptr,"","房间",(*____0)[1],"厕所"));
    (*____0)[1]->setList(_____0);
    //2
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("妹妹房间",nullptr,"","房间",(*____0)[2],"妹妹房间"));
    _____0->push_back(new MYGAME::Room("自室",nullptr,"","房间",(*____0)[2],"自室"));
    _____0->push_back(new MYGAME::Room("娜娜莉房间",nullptr,"","房间",(*____0)[2],"娜娜莉房间"));
    _____0->push_back(new MYGAME::Room("客房",nullptr,"","房间",(*____0)[2],"客房"));
    _____0->push_back(new MYGAME::Room("厕所",nullptr,"","房间",(*____0)[2],"厕所"));
    (*____0)[2]->setList(_____0);
    //艾斯忒拉家
    ____0=new std::vector<MYGAME::Map*>;
    ____0->push_back(new MYGAME::Map("庭院",nullptr,"","楼层",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("-1楼",nullptr,"","楼层",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("1楼",nullptr,"","楼层",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("2楼",nullptr,"","楼层",(*___0)[1]));
    ____0->push_back(new MYGAME::Map("后院",nullptr,"","楼层",(*___0)[1]));
    (*___0)[1]->setList(____0);
    //庭院
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("储藏室",nullptr,"","房间",(*____0)[0],"储藏室"));
    _____0->push_back(new MYGAME::Room("花圃",nullptr,"","房间",(*____0)[0],"花圃"));
    (*____0)[0]->setList(_____0);
    //-1
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("车库",nullptr,"","房间",(*____0)[1],"车库"));
    (*____0)[1]->setList(_____0);
    //1
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("玄关",nullptr,"","房间",(*____0)[2],"玄关"));
    _____0->push_back(new MYGAME::Room("客厅",nullptr,"","房间",(*____0)[2],"客厅"));
    _____0->push_back(new MYGAME::Room("餐厅",nullptr,"","房间",(*____0)[2],"餐厅"));
    _____0->push_back(new MYGAME::Room("厨房",nullptr,"","房间",(*____0)[2],"厨房"));
    _____0->push_back(new MYGAME::Room("卫生间",nullptr,"","房间",(*____0)[2],"卫生间"));
    _____0->push_back(new MYGAME::Room("浴室",nullptr,"","房间",(*____0)[2],"浴室"));
    _____0->push_back(new MYGAME::Room("机房",nullptr,"","房间",(*____0)[2],"机房"));
    (*____0)[2]->setList(_____0);
    //2
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("娜娜莉卧室",nullptr,"","房间",(*____0)[3],"娜娜莉卧室"));
    _____0->push_back(new MYGAME::Room("实验室",nullptr,"","房间",(*____0)[3],"实验室"));
    _____0->push_back(new MYGAME::Room("卫生间",nullptr,"","房间",(*____0)[3],"卫生间"));
    _____0->push_back(new MYGAME::Room("浴室",nullptr,"","房间",(*____0)[3],"浴室"));
    _____0->push_back(new MYGAME::Room("客卧",nullptr,"","房间",(*____0)[3],"客卧"));
    _____0->push_back(new MYGAME::Room("露台",nullptr,"","露台",(*____0)[3],"玄关"));
    (*____0)[3]->setList(_____0);
    //后院
    _____0=new std::vector<MYGAME::Map*>;
    _____0->push_back(new MYGAME::Room("阳台",nullptr,"","房间",(*____0)[4],"阳台"));
    _____0->push_back(new MYGAME::Room("花园",nullptr,"","房间",(*____0)[4],"花园"));
    (*____0)[4]->setList(_____0);
    //学院联合分部
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Map("初等学院",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("图书馆",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Map("幼儿教育学院",nullptr,"","设施",(*_0)[1]));
    __0->push_back(new MYGAME::Room("学院联合分部站",nullptr,"","车站",(*_0)[1],"车站"));
    (*_0)[1]->setList(__0);
    //初等学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("高级中学",nullptr,"","设施",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("初级中学",nullptr,"","设施",(*__0)[0]));
    ___0->push_back(new MYGAME::Map("通识学院",nullptr,"","设施",(*__0)[0]));
    (*__0)[0]->setList(___0);
    //幼儿教育学院
    ___0=new std::vector<MYGAME::Map*>;
    ___0->push_back(new MYGAME::Map("学前教育院",nullptr,"","设施",(*__0)[2]));
    ___0->push_back(new MYGAME::Map("保育院",nullptr,"","设施",(*__0)[2]));
    (*__0)[2]->setList(___0);
    //扇区枢纽
    __0=new std::vector<MYGAME::Map*>;
    __0->push_back(new MYGAME::Room("居住扇区交通站",nullptr,"","车站",(*_0)[2],"车站"));
    __0->push_back(new MYGAME::Room("居住扇区列车站",nullptr,"","列车站",(*_0)[2],"列车站"));
    __0->push_back(new MYGAME::Room("居住扇区机场",nullptr,"","机场",(*_0)[1],"机场"));
    (*_0)[2]->setList(__0);
}

void MainWindow::initPeople()
{
    this->peopleList.push_back(new MYGAME::SystemGirlOne(this->time->date(),this->player->getLive()));
    this->peopleList[0]->setCurrentPosition(this->player->getCurrentPosition());
}

void textMap(std::vector<MYGAME::Map*>&mapList){
    for(auto i:mapList){
        if(i->getType()=="扇区"){
            qDebug()<<i->getName();
        }else if(i->getType()=="区划"){
            qDebug()<<"-"<<i->getName();
        }else if(i->getType()=="设施"){
            qDebug()<<"--"<<i->getName();
        }else if(i->getType()=="地点分区"){
            qDebug()<<"---"<<i->getName();
        }else if(i->getType()=="地点分区1"){
            qDebug()<<"----"<<i->getName();
        }else if(i->getType()=="楼层"){
            qDebug()<<"-----"<<i->getName();
        }else if(i->getType()=="房间"){
            qDebug()<<"------"<<i->getName();
        }else {
            qDebug()<<"其他:"<<i->getName();
        }
        if(i->getList()!=nullptr){
            textMap(*(i->getList()));
        }
    }
}

void MainWindow::refresh()
{
    //刷新时间
    QString SFormat="yyyy年MM月dd日 hh:mm dddd";
    QLocale locale=QLocale::Chinese;
    ui->date->setText(locale.toString(*this->time,SFormat));
    //刷新角色类内部内容
    //刷新系统点数
    ui->points->setText("点数:"+QString::number(player->getSystem().getPoint()));
    //刷新金钱
    ui->money->setText("金钱:"+QString::number(player->getMoney()));
    std::vector<MYGAME::Attribute*>list=player->getAttributeList();
    for(size_t i=0;i<list.size();i++){
        //刷新体质条
        if(list[i]->getName()=="体质"){
            MYGAME::AttributeAdd*temp=dynamic_cast<MYGAME::AttributeAdd*>(list[i]);
            ui->staminaBarStrip->setMaxValue(temp->getRank());
            ui->staminaBarStrip->setNowValue(temp->getNowValue());
            ui->staminaBarNumberLabel->setText(QString::number(temp->getNowValue())+"/"+QString::number(temp->getRank()));
        }
        //刷新精力条
        if(list[i]->getName()=="意志"){
            MYGAME::AttributeAdd*temp=dynamic_cast<MYGAME::AttributeAdd*>(list[i]);
            ui->energyBarStrip->setMaxValue(temp->getRank());
            ui->energyBarStrip->setNowValue(temp->getNowValue());
            ui->energyBarNumberLabel->setText(QString::number(temp->getNowValue())+"/"+QString::number(temp->getRank()));
        }
    }
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
    SystemStore*Ss=new SystemStore(this->player);
    Ss->show();
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
    PeopleList*Pl=new PeopleList(&(this->peopleList),this->time);
    Pl->show();
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
    qDebug()<<"移动";
    //PeopleList*Pl=new PeopleList(&(this->peopleList));
    //Pl->show();
    return new QString("移动");
}

QString *MainWindow::text(UC flag)
{
    if(flag==1){
        return new QString("true");
    }
    if(flag==2){
        return new QString("测试");
    }
    qDebug()<<"测试";
    return new QString("测试");
}

void MainWindow::on_systemCommand_visibilityChanged(bool visible)
{
    if(visible){
        qDebug()<<"显示";
    }else{
        qDebug()<<"隐藏";
    }
}
