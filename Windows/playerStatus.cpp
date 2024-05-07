#include "PlayerStatus.h"
#include "ui_PlayerStatus.h"
#include "Modules/AttributeAdd.h"
#include "Modules/Position/Penis.h"
PlayerStatus::PlayerStatus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PlayerStatus)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
}

PlayerStatus::PlayerStatus(MYGAME::Player *player, QWidget *parent):PlayerStatus(parent)
{
    this->player=player;
    init();
}

PlayerStatus::~PlayerStatus()
{
    delete ui;
}

void PlayerStatus::init()
{
    ui->name->setText("姓名:"+this->player->getName());
    ui->NickName->setText("昵称:"+this->player->getNickName());
    ui->claimed->setText("自称:"+this->player->getClaimed());
    ui->Major->setText("专业:"+this->player->getMajor());
    ui->Occupation->setText("职业:"+this->player->getOccupation());
    ui->birthday->setText("生日:"+this->player->getBirthday().toString("yyyy年MM月dd日"));
    switch(this->player->getHeight()){
    case MYGAME::Height::young:
        ui->height->setText("身高:幼小");
        break;
    case MYGAME::Height::Petite:
        ui->height->setText("身高:娇小");
        break;
    case MYGAME::Height::ordinary:
        ui->height->setText("身高:普通");
        break;
    case MYGAME::Height::tall:
        ui->height->setText("身高:高大");
        break;
    case MYGAME::Height::huge:
        ui->height->setText("身高:巨大");
        break;
    case MYGAME::Height::heightCount:
        ui->height->setText("身高:计数");
        break;
    }
    switch(this->player->getWeight()){
    case MYGAME::Weight::emaciation:
        ui->weight->setText("体重:瘦削");
        break;
    case MYGAME::Weight::slender:
        ui->weight->setText("体重:纤细");
        break;
    case MYGAME::Weight::common:
        ui->weight->setText("体重:普通");
        break;
    case MYGAME::Weight::plump:
        ui->weight->setText("体重:丰满");
        break;
    case MYGAME::Weight::obesity:
        ui->weight->setText("体重:肥胖");
        break;
    case MYGAME::Weight::weightCount:
        ui->weight->setText("体重:计数");
        break;
    }
    ui->hairColorView->setColor(this->player->getHairColor());
    ui->REyeColorsView->setColor(this->player->getRPupilColor());
    ui->LEyeColorsView->setColor(this->player->getLPupilColor());
    ui->skinColorView->setColor(this->player->getSkinColor());
    std::vector<MYGAME::Attribute*>attributeList = this->player->getVariableAttributeList();
    for(size_t i=0;i<attributeList.size();i++){
        MYGAME::Attribute*P=attributeList[i];
        if(P->getName()=="意志"||P->getName()=="体质"){
            MYGAME::AttributeAdd*P=dynamic_cast<MYGAME::AttributeAdd*>(attributeList[i]);
            if(P->getName()=="意志"){
                //精力
                ui->energyBarStrip->setMaxValue(P->getRank());
                ui->energyBarStrip->setNowValue(P->getNowValue());
                ui->energyBarStrip->setFrame(1);
                ui->energyBarStrip->setBackground(":/Strip/Strip/Blue.png");
                ui->energyBarStrip->setProspect(":/Strip/Strip/bg.png");
                ui->energyBarNumberLabel->setText(QString::number(P->getNowValue())+"/"+QString::number(P->getRank()));
                //意志经验
                qDebug()<<P->getEXP();
                ui->willpowerStrip->setMaxValue(P->getRank());
                ui->willpowerStrip->setNowValue(P->getEXP());
                ui->willpowerStrip->setBackground(":/Strip/Strip/Green.png");
                ui->willpowerStrip->setProspect(":/Strip/Strip/bg.png");
                ui->willpowerBarNumberLabel->setText(QString::number(P->getEXP())+"/"+QString::number(P->getRank()));

            }else{
                //体力
                ui->staminaBarStrip->setMaxValue(P->getRank());
                ui->staminaBarStrip->setNowValue(P->getNowValue());
                ui->staminaBarStrip->setBackground(":/Strip/Strip/Red.png");
                ui->staminaBarStrip->setProspect(":/Strip/Strip/bg.png");
                ui->staminaBarNumberLabel->setText(QString::number(P->getNowValue())+"/"+QString::number(P->getRank()));
                //体质经验
                ui->physiqueStrip->setMaxValue(P->getRank());
                ui->physiqueStrip->setNowValue(P->getEXP());
                ui->physiqueStrip->setBackground(":/Strip/Strip/Green.png");
                ui->physiqueStrip->setProspect(":/Strip/Strip/bg.png");;
                ui->physiqueBarNumberLabel->setText(QString::number(P->getEXP())+"/"+QString::number(P->getRank()));
            }
        }
        else if(P->getName()=="敏捷"){
            ui->quickStrip->setMaxValue(P->getRank());
            ui->quickStrip->setNowValue(P->getEXP());
            ui->quickStrip->setBackground(":/Strip/Strip/Green.png");
            ui->quickStrip->setProspect(":/Strip/Strip/bg.png");
            ui->quickBarNumberLabel->setText(QString::number(P->getEXP())+"/"+QString::number(P->getRank()));
        }else if(P->getName()=="魅力"){
            ui->charmStrip->setMaxValue(P->getRank());
            ui->charmStrip->setNowValue(P->getEXP());
            ui->charmStrip->setBackground(":/Strip/Strip/Green.png");
            ui->charmStrip->setProspect(":/Strip/Strip/bg.png");
            ui->charmBarNumberLabel->setText(QString::number(P->getEXP())+"/"+QString::number(P->getRank()));
        }else if(P->getName()=="智力"){
            ui->intelligenceStrip->setMaxValue(P->getRank());
            ui->intelligenceStrip->setNowValue(P->getEXP());
            ui->intelligenceStrip->setBackground(":/Strip/Strip/Green.png");
            ui->intelligenceStrip->setProspect(":/Strip/Strip/bg.png");
            ui->intelligenceBarNumberLabel->setText(QString::number(P->getEXP())+"/"+QString::number(P->getRank()));
        }
    }

    MYGAME::Penis*P=dynamic_cast<MYGAME::Penis*>(this->player->getVariablePositionList()[0]);
    if(P->getDiameter()>10){
        ui->penisEnum->setText("大小:短小");
    }else if(P->getDiameter()>20){
        ui->penisEnum->setText("大小:普通");
    }else if(P->getDiameter()>30){
        ui->penisEnum->setText("大小:巨根");
    }else if(P->getDiameter()>40){
        ui->penisEnum->setText("大小:规格外");
    }else if(P->getDiameter()>60){
        ui->penisEnum->setText("大小:非人类");
    }else if(P->getDiameter()>80){
        ui->penisEnum->setText("大小:怪兽");
    }else{
        ui->penisEnum->setText("大小:可爱");
    }
    ui->penisLong->setText("长度:"+QString::number(P->getDiameter()*5));
    ui->penisDiameter->setText("直径:"+QString::number(P->getDiameter()));
    ui->penisCount->setText("使用次数:"+QString::number(P->getCount()));
    ui->penisSemen->setText("单次射精数量:"+QString::number(P->getSemen())+"ML");
}
