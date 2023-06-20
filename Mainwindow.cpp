#include "Mainwindow.h"
#include "ui_Mainwindow.h"
#include "Windows/BeginWindow.h"
#include "Modules/Global.h"
#include "Windows/CreateLead.h"
#include "Modules/AttributeAdd.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->initWindows();
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    MYGAME::global.setMainWindow(nullptr);
    delete ui;
}

void MainWindow::NewGame(MYGAME::Player *player)
{
    this->peopleList.push_back(player);
    this->initNewGame();
    qDebug()<<time;
    qDebug()<<time->toString("dddd");
    qDebug()<<LONG_LONG_MAX;
    std::vector<MYGAME::Attribute*>list=player->getAttributeList();
    foreach (MYGAME::Attribute*temp, list) {
        if(temp->getName()=="体质"||temp->getName()=="意志"){
            qDebug()<<dynamic_cast<MYGAME::AttributeAdd*>(temp)->getNowValue();
        }
    }
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
    this->time=new QDateTime(QDate(3021,6,30),QTime(7,0,0));
}
