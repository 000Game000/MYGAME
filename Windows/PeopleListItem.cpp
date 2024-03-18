#include "PeopleListItem.h"
#include "ui_PeopleListItem.h"
#include "Modules/AttributeAdd.h"
PeopleListItem::PeopleListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PeopleListItem)
{
    ui->setupUi(this);
}

PeopleListItem::~PeopleListItem()
{
    delete ui;
}

PeopleListItem::PeopleListItem(MYGAME::Girl *girl,const QDateTime*const time,QWidget *parent):PeopleListItem(parent)
{
    this->girl=girl;
    ui->name->setText(this->girl->getName());
    ui->age->setText(QString::number(time->date().year()-this->girl->getBirthday().year()));
    ui->lovept->setText("好感度:"+QString::number(this->girl->getLovept()));
    ui->obedience->setText("服从度:"+QString::number(this->girl->getObedience()));
    ui->fornication->setText("淫乱度:"+QString::number(this->girl->getFornication()));
    //初始化血条
    ui->staminaBarStrip->setBackground(":/Strip/Strip/Red.png");
    ui->staminaBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->staminaBarStrip->setFrame(1);
    //初始化精力条
    ui->energyBarStrip->setBackground(":/Strip/Strip/Blue.png");
    ui->energyBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->energyBarStrip->setFrame(1);
    //显示血条与精力条
    std::vector<MYGAME::Attribute*>list=this->girl->getAttributeList();
    for(size_t i=0;i<list.size();i++){
        //刷新血条
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
    ui->position->setText(this->girl->getCurrentPosition()->getName());
}
