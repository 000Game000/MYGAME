#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Modules/Global.h"
#include "Windows/ItemList.h"
#include "Windows/CreateLead.h"
#include "Windows/BeginWindow.h"
#include "Windows/SystemStore.h"
#include "Modules/AttributeAdd.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->initWindows();
    ui->setupUi(this);
    ui->Information->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
    ui->command->setFeatures(QDockWidget::DockWidgetFloatable | QDockWidget::DockWidgetMovable);
    ui->charaList->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetMovable);
}

MainWindow::~MainWindow()
{
    MYGAME::global.setMainWindow(nullptr);
    delete ui;
}

void MainWindow::NewGame(MYGAME::Player *player)
{
    this->player=player;
    this->initNewGame();
    this->show();
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
    this->refresh();
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

void MainWindow::on_systemStore_clicked()
{
    SystemStore*ss=new SystemStore(player);
    ss->show();
}

void MainWindow::on_itemList_clicked()
{
    ItemList*IL=new ItemList(player);
    IL->show();
}

