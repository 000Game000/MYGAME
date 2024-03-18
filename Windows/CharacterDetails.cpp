#include "CharacterDetails.h"
#include "ui_CharacterDetails.h"
#include "Modules/MYFunctions.h"
#include "Modules/AttributeAdd.h"
#include "Modules/Position/Breast.h"
CharacterDetails::CharacterDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterDetails)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
}

CharacterDetails::CharacterDetails(MYGAME::Girl *girl, QWidget *parent):CharacterDetails(parent)
{
    this->girl=girl;
    this->setWindowTitle(this->girl->getName());
    this->init();
}

CharacterDetails::~CharacterDetails()
{
    delete ui;
}

void CharacterDetails::init()
{
    ui->name->setText("姓名:"+this->girl->getName());
    ui->NickName->setText("昵称:"+this->girl->getNickName());
    ui->claimed->setText("自称:"+this->girl->getClaimed());
    ui->Major->setText("专业:"+this->girl->getMajor());
    ui->Occupation->setText("职业:"+this->girl->getOccupation());
    ui->birthday->setText("生日"+this->girl->getBirthday().toString("yyyy年MM月dd日"));
    switch(this->girl->getHeight()){
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
    switch(this->girl->getWeight()){
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
    ui->hairColorView->setColor(this->girl->getHairColor());
    ui->REyeColorsView->setColor(this->girl->getRPupilColor());
    ui->LEyeColorsView->setColor(this->girl->getLPupilColor());
    ui->skinColorView->setColor(this->girl->getSkinColor());
    ui->lovept->setText("好感度:"+QString::number(this->girl->getLovept()));
    ui->obedience->setText("服从度:"+QString::number(this->girl->getObedience()));
    ui->fornication->setText("淫乱度:"+QString::number(this->girl->getFornication()));
    ui->currentLocation->setText("当前所在地点:"+MYGAME::getSPosition(this->girl->getCurrentPosition()));
    ui->housingLocation->setText("家庭住址:"+MYGAME::getSPosition(this->girl->getLive()));
    std::vector<MYGAME::Attribute*>attributeList = this->girl->getVariableAttributeList();
    for(size_t i=0;i<attributeList.size();i++){
        MYGAME::Attribute*P=attributeList[i];
        if(P->getName()=="意志"||P->getName()=="体质"){
            MYGAME::AttributeAdd*P=dynamic_cast<MYGAME::AttributeAdd*>(attributeList[i]);
            if(P->getName()=="意志"){
                //精力
                ui->energyBarStrip->setMaxValue(P->getRank());
                ui->energyBarStrip->setNowValue(P->getNowValue());
                ui->energyBarStrip->setBackground(":/Strip/Strip/Blue.png");
                ui->energyBarStrip->setProspect(":/Strip/Strip/bg.png");
                ui->energyBarNumberLabel->setText(QString::number(P->getNowValue())+"/"+QString::number(P->getRank()));
                //意志经验
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
    std::vector<MYGAME::PositionBase*>positionList=this->girl->getPositionList();
    for(unsigned long long i=0;i<positionList.size();i++){
        if(positionList[i]->getName().compare("嘴巴")==0){
            ui->mouthRank->setText("敏感度:"+QString::number(positionList[i]->getRank()));
            ui->mouthCount->setText("经验次数:"+QString::number(positionList[i]->getCount()));
            ui->mouthEXPStrip->setMaxValue(positionList[i]->getEXP());
            ui->mouthEXPStrip->setNowValue(positionList[i]->getNowEXP());
            ui->mouthEXPStrip->setBackground(":/Strip/Strip/Green.png");
            ui->mouthEXPStrip->setProspect(":/Strip/Strip/bg.png");
            ui->mouthEXPBarNumberLabel->setText(QString::number(positionList[i]->getNowEXP())+"/"+QString::number(positionList[i]->getEXP()));

            ui->mouthPleasureStrip->setMaxValue(positionList[i]->getPleasure());
            ui->mouthPleasureStrip->setNowValue(positionList[i]->getNowPleasure());
            ui->mouthPleasureStrip->setBackground(":/Strip/Strip/Pink.png");
            ui->mouthPleasureStrip->setProspect(":/Strip/Strip/bg.png");
            ui->mouthPleasureBarNumberLabel->setText(QString::number(positionList[i]->getNowPleasure())+"/"+QString::number(positionList[i]->getPleasure()));
            continue;
        }else if(positionList[i]->getName().compare("乳房")==0){
            MYGAME::Breast*P=dynamic_cast<MYGAME::Breast*>(positionList[i]);
            ui->breastRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->breastCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->breastEXPStrip->setMaxValue(P->getEXP());
            ui->breastEXPStrip->setNowValue(P->getNowEXP());
            ui->breastEXPStrip->setBackground(":/Strip/Strip/Green.png");
            ui->breastEXPStrip->setProspect(":/Strip/Strip/bg.png");
            ui->breastEXPBarNumberLabel->setText(QString::number(P->getNowEXP())+"/"+QString::number(P->getEXP()));

            ui->breastPleasureStrip->setMaxValue(P->getPleasure());
            ui->breastPleasureStrip->setNowValue(P->getNowPleasure());
            ui->breastPleasureStrip->setBackground(":/Strip/Strip/Pink.png");
            ui->breastPleasureStrip->setProspect(":/Strip/Strip/bg.png");
            ui->breastPleasureBarNumberLabel->setText(QString::number(P->getNowPleasure())+"/"+QString::number(P->getPleasure()));

            ui->breastSize->setText("乳房大小:"+QString::number(P->getSize())+"mm");
            ui->breastMilkStrip->setMaxValue(P->getVolume());
            ui->breastMilkStrip->setNowValue(P->getStock());
            ui->breastMilkStrip->setBackground(":/Strip/Strip/MilkyWhite.png");
            ui->breastMilkStrip->setProspect(":/Strip/Strip/bg.png");
            ui->breastMilkBarNumberLabel->setText(QString::number(P->getStock())+"/"+QString::number(P->getVolume())+"ML");
            ui->breastMilkYield->setText("母乳产量:"+QString::number(P->getMilkYield()));
            ui->breastNumber->setText("乳腺数量:"+QString::number(P->getGalactophore()));
            continue;
        }
    }
}
