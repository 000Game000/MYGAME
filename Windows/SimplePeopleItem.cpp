#include "SimplePeopleItem.h"
#include "ui_SimplePeopleItem.h"

#include <Modules/AttributeAdd.h>

SimplePeopleItem::SimplePeopleItem(const MYGAME::Girl*girl,const QDateTime*time,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimplePeopleItem)
{
    ui->setupUi(this);
    ui->name->setText(girl->getName());
    ui->age->setText("年龄:"+QString::number(time->date().year()-girl->getBirthday().year()));
    ui->lovept->setText("好感度:"+QString::number(girl->getLovept()));
    ui->obedience->setText("服从度:"+QString::number(girl->getObedience()));
    ui->fornication->setText("淫乱度:"+QString::number(girl->getFornication()));
    //初始化血条
    ui->staminaBarStrip->setBackground(":/Strip/Strip/Red.png");
    ui->staminaBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->staminaBarStrip->setFrame(1);
    //初始化精力条
    ui->energyBarStrip->setBackground(":/Strip/Strip/Blue.png");
    ui->energyBarStrip->setProspect(":/Strip/Strip/bg.png");
    ui->energyBarStrip->setFrame(1);
    //显示血条与精力条
    std::vector<MYGAME::Attribute*>list=girl->getAttributeList();
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
}

SimplePeopleItem::~SimplePeopleItem()
{
    delete ui;
}
