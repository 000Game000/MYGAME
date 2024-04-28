#include "CharacterDetails.h"
#include "ui_CharacterDetails.h"
#include "Modules/MYFunctions.h"
#include "Modules/AttributeAdd.h"
#include "Modules/Position/Breast.h"
#include <Modules/Position/Anus.h>
#include <Modules/Position/Bladder.h>
#include <Modules/Position/Clit.h>
#include <Modules/Position/Nipple.h>
#include <Modules/Position/Ovary.h>
#include <Modules/Position/Urethra.h>
#include <Modules/Position/Uterus.h>
#include <Modules/Position/Vagina.h>
CharacterDetails::CharacterDetails(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CharacterDetails)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
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

            ui->mouthEXP->setName("EXP");
            ui->mouthEXP->setMAXValue(positionList[i]->getEXP());
            ui->mouthEXP->setNOWValue(positionList[i]->getNowEXP());
            ui->mouthEXP->setBackground(":/Strip/Strip/Green.png");
            ui->mouthEXP->setProspect(":/Strip/Strip/bg.png");

            ui->mouthPleasure->setName("快感");
            ui->mouthPleasure->setMAXValue(positionList[i]->getPleasure());
            ui->mouthPleasure->setNOWValue(positionList[i]->getNowPleasure());
            ui->mouthPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->mouthPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }else if(positionList[i]->getName().compare("乳房")==0){
            MYGAME::Breast*P=dynamic_cast<MYGAME::Breast*>(positionList[i]);
            ui->breastRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->breastCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->breastSize->setText("乳房大小:"+QString::number(P->getSize())+"mm");
            ui->breastMilkYield->setText("母乳产量:"+QString::number((unsigned long long)P->getMilkYield()));
            ui->breastNumber->setText("乳腺数量:"+QString::number(P->getGalactophore()));

            ui->breastEXP->setName("EXP");
            ui->breastEXP->setMAXValue(P->getEXP());
            ui->breastEXP->setNOWValue(P->getNowEXP());
            ui->breastEXP->setBackground(":/Strip/Strip/Green.png");
            ui->breastEXP->setProspect(":/Strip/Strip/bg.png");

            ui->breastPleasure->setName("快感");
            ui->breastPleasure->setMAXValue(P->getPleasure());
            ui->breastPleasure->setNOWValue(P->getNowPleasure());
            ui->breastPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->breastPleasure->setProspect(":/Strip/Strip/bg.png");

            ui->breastMilk->setName("母乳");
            ui->breastMilk->setMAXValue(P->getVolume());
            ui->breastMilk->setNOWValue(P->getStock());
            ui->breastMilk->setBackground(":/Strip/Strip/MilkyWhite.png");
            ui->breastMilk->setProspect(":/Strip/Strip/bg.png");
            continue;
        }else if(positionList[i]->getName().compare("乳头")==0){
            MYGAME::Nipple*P=dynamic_cast<MYGAME::Nipple*>(positionList[i]);
            ui->nippleRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->nippleCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->nippleLength->setText("长度:"+QString::number(P->getLength()));
            ui->nippleDiameter->setText("直径:"+QString::number(P->getDiameter()));
            ui->nippleDuctusLactiferiDiameter->setText("乳孔直径:"+QString::number(P->getDuctusLactiferiDiameter()));
            ui->nippleColorView->setColor(P->getColor());

            ui->nippleEXP->setName("EXP");
            ui->nippleEXP->setMAXValue(P->getEXP());
            ui->nippleEXP->setNOWValue(P->getNowEXP());
            ui->nippleEXP->setBackground(":/Strip/Strip/Green.png");
            ui->nippleEXP->setProspect(":/Strip/Strip/bg.png");

            ui->nipplePleasure->setName("快感");
            ui->nipplePleasure->setMAXValue(P->getPleasure());
            ui->nipplePleasure->setNOWValue(P->getNowPleasure());
            ui->nipplePleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->nipplePleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("阴蒂")==0){
            MYGAME::Clit*P=dynamic_cast<MYGAME::Clit*>(positionList[i]);
            ui->clitRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->clitCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->clitLength->setText("长度:"+QString::number(P->getLength()));
            ui->clitDiameter->setText("直径:"+QString::number(P->getDiameter()));

            ui->clitEXP->setName("EXP");
            ui->clitEXP->setMAXValue(P->getEXP());
            ui->clitEXP->setNOWValue(P->getNowEXP());
            ui->clitEXP->setBackground(":/Strip/Strip/Green.png");
            ui->clitEXP->setProspect(":/Strip/Strip/bg.png");

            ui->clitPleasure->setName("快感");
            ui->clitPleasure->setMAXValue(P->getPleasure());
            ui->clitPleasure->setNOWValue(P->getNowPleasure());
            ui->clitPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->clitPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("尿道")==0){
             MYGAME::Urethra*P=dynamic_cast<MYGAME::Urethra*>(positionList[i]);
            ui->urethraRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->urethraCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->urethraDiameter->setText("直径:"+QString::number(P->getExpand()));

            ui->urethraEXP->setName("EXP");
            ui->urethraEXP->setMAXValue(P->getEXP());
            ui->urethraEXP->setNOWValue(P->getNowEXP());
            ui->urethraEXP->setBackground(":/Strip/Strip/Green.png");
            ui->urethraEXP->setProspect(":/Strip/Strip/bg.png");

            ui->urethraPleasure->setName("快感");
            ui->urethraPleasure->setMAXValue(P->getPleasure());
            ui->urethraPleasure->setNOWValue(P->getNowPleasure());
            ui->urethraPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->urethraPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("膀胱")==0){
            MYGAME::Bladder*P=dynamic_cast<MYGAME::Bladder*>(positionList[i]);
            ui->bladderRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->bladderCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->bladderYield->setText("尿液产量:"+QString::number(P->getYield()));

            ui->bladderEXP->setName("EXP");
            ui->bladderEXP->setMAXValue(P->getEXP());
            ui->bladderEXP->setNOWValue(P->getNowEXP());
            ui->bladderEXP->setBackground(":/Strip/Strip/Green.png");
            ui->bladderEXP->setProspect(":/Strip/Strip/bg.png");

            ui->bladderPleasure->setName("快感");
            ui->bladderPleasure->setMAXValue(P->getPleasure());
            ui->bladderPleasure->setNOWValue(P->getNowPleasure());
            ui->bladderPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->bladderPleasure->setProspect(":/Strip/Strip/bg.png");

            ui->bladderVolume->setName("膀胱容量");
            ui->bladderVolume->setMAXValue(P->getVolume());
            ui->bladderVolume->setNOWValue(P->getStock());
            ui->bladderVolume->setBackground(":/Strip/Strip/Yellow.png");
            ui->bladderVolume->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("阴道")==0){
            MYGAME::Vagina*P=dynamic_cast<MYGAME::Vagina*>(positionList[i]);
            ui->vaginaRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->vaginaCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->vaginaLength->setText("长度:"+QString::number(P->getLength()));
            ui->vaginaDiameter->setText("直径:"+QString::number(P->getMaximumDiameter()));
            ui->vaginaColorView->setColor(P->getColor());

            ui->vaginaEXP->setName("EXP");
            ui->vaginaEXP->setMAXValue(P->getEXP());
            ui->vaginaEXP->setNOWValue(P->getNowEXP());
            ui->vaginaEXP->setBackground(":/Strip/Strip/Green.png");
            ui->vaginaEXP->setProspect(":/Strip/Strip/bg.png");

            ui->vaginaPleasure->setName("快感");
            ui->vaginaPleasure->setMAXValue(P->getPleasure());
            ui->vaginaPleasure->setNOWValue(P->getNowPleasure());
            ui->vaginaPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->vaginaPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("阴道")==0){
            MYGAME::Vagina*P=dynamic_cast<MYGAME::Vagina*>(positionList[i]);
            ui->vaginaRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->vaginaCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->vaginaLength->setText("长度:"+QString::number(P->getLength()));
            ui->vaginaDiameter->setText("直径:"+QString::number(P->getMaximumDiameter()));
            ui->vaginaColorView->setColor(P->getColor());

            ui->vaginaEXP->setName("EXP");
            ui->vaginaEXP->setMAXValue(P->getEXP());
            ui->vaginaEXP->setNOWValue(P->getNowEXP());
            ui->vaginaEXP->setBackground(":/Strip/Strip/Green.png");
            ui->vaginaEXP->setProspect(":/Strip/Strip/bg.png");

            ui->vaginaPleasure->setName("快感");
            ui->vaginaPleasure->setMAXValue(P->getPleasure());
            ui->vaginaPleasure->setNOWValue(P->getNowPleasure());
            ui->vaginaPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->vaginaPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("子宫")==0){
            MYGAME::Uterus*P=dynamic_cast<MYGAME::Uterus*>(positionList[i]);
            ui->uterusRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->uterusCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->uterusVolume->setText("容量:"+QString::number(P->getVolume()));
            ui->uterusMenstrualCycle->setText("月经周期:"+QString::number(P->getMenstrualCycle()));
            if(P->getPregnancyDays()<0){
                ui->uterusPregnancyDays->setText("怀孕天数:未怀孕");
            }else{
                ui->uterusPregnancyDays->setText("怀孕天数:"+QString::number(P->getPregnancyDays()));
            }

            ui->uterusEXP->setName("EXP");
            ui->uterusEXP->setMAXValue(P->getEXP());
            ui->uterusEXP->setNOWValue(P->getNowEXP());
            ui->uterusEXP->setBackground(":/Strip/Strip/Green.png");
            ui->uterusEXP->setProspect(":/Strip/Strip/bg.png");

            ui->uterusPleasure->setName("快感");
            ui->uterusPleasure->setMAXValue(P->getPleasure());
            ui->uterusPleasure->setNOWValue(P->getNowPleasure());
            ui->uterusPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->uterusPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("卵巢")==0){
            MYGAME::Ovary*P=dynamic_cast<MYGAME::Ovary*>(positionList[i]);
            ui->ovaryRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->ovaryCount->setText("经验次数:"+QString::number(P->getCount()));

            ui->ovaryEXP->setName("EXP");
            ui->ovaryEXP->setMAXValue(P->getEXP());
            ui->ovaryEXP->setNOWValue(P->getNowEXP());
            ui->ovaryEXP->setBackground(":/Strip/Strip/Green.png");
            ui->ovaryEXP->setProspect(":/Strip/Strip/bg.png");

            ui->ovaryPleasure->setName("快感");
            ui->ovaryPleasure->setMAXValue(P->getPleasure());
            ui->ovaryPleasure->setNOWValue(P->getNowPleasure());
            ui->ovaryPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->ovaryPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
        else if(positionList[i]->getName().compare("肛门")==0){
            MYGAME::Anus*P=dynamic_cast<MYGAME::Anus*>(positionList[i]);
            ui->anusRank->setText("敏感度:"+QString::number(P->getRank()));
            ui->anusCount->setText("经验次数:"+QString::number(P->getCount()));
            ui->anusDiameter->setText("肛门直径:"+QString::number(P->getExpand()));
            ui->anusVolume->setText("肛门容量:"+QString::number(P->getVolume()));

            ui->anusEXP->setName("EXP");
            ui->anusEXP->setMAXValue(P->getEXP());
            ui->anusEXP->setNOWValue(P->getNowEXP());
            ui->anusEXP->setBackground(":/Strip/Strip/Green.png");
            ui->anusEXP->setProspect(":/Strip/Strip/bg.png");

            ui->anusPleasure->setName("快感");
            ui->anusPleasure->setMAXValue(P->getPleasure());
            ui->anusPleasure->setNOWValue(P->getNowPleasure());
            ui->anusPleasure->setBackground(":/Strip/Strip/Pink.png");
            ui->anusPleasure->setProspect(":/Strip/Strip/bg.png");
            continue;
        }
    }
    MYGAME::CrotchTattoo*ct=this->girl->getCrotchTattoo();
    ui->crotchTattooRank->setText("淫纹等级:"+QString::number(ct->getRank()));
    ui->crotchTattooEXP->setName("淫纹");
    ui->crotchTattooEXP->setMAXValue(ct->getMAXEXP());
    ui->crotchTattooEXP->setNOWValue(ct->getEXP());
    ui->crotchTattooEXP->setBackground(":/Strip/Strip/Green.png");
    ui->crotchTattooEXP->setProspect(":/Strip/Strip/bg.png");
    ui->crotchTattooTags->setText("");
}
