#include <QMessageBox>
#include "CreateLead.h"
#include "ui_CreateLead.h"
#include "Modules/Global.h"
#include "Modules/Modules.h"
#include "Modules/AttributeAdd.h"
CreateLead::CreateLead(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateLead)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    initPlayer();
    initUI();
}

CreateLead::~CreateLead()
{

    MYGAME::global.setCreateLead(nullptr);
    delete ui;
}

void CreateLead::initUI()
{
    ui->nameInput->setText("主角");
    ui->nickNameInput->setText("主角");
    ui->claimedInput->setText("我");
    ui->selectOccupation->addItems(MYGAME::global.getCareerList());
    ui->selectMajor->addItems(MYGAME::global.getMajorList());
    ui->monthInput->setText("1");
    ui->dayInput->setText("1");
    this->point=20;
    ui->PointsRemaining->setText("剩余点数:"+QString::number(this->point));
    //设置输入框与对应属性的关联
    maps.insert(ui->WillpowerInput,new MYGAME::AttributeAdd("意志",100,0,100));
    maps.insert(ui->QuickInput,new MYGAME::Attribute("敏捷",100,0));
    maps.insert(ui->PhysiqueInput,new MYGAME::AttributeAdd("体质",100,0,100));
    maps.insert(ui->CharmInput,new MYGAME::Attribute("魅力",100,0));
    maps.insert(ui->IntelligenceInput,new MYGAME::Attribute("智力",100,0));
    ui->WillpowerInput->setRange(60,120);
    QList<QSpinBox*>list=maps.keys();
    foreach (QSpinBox*temp, list) {
        temp->setKeyboardTracking(false);
    }
    //设置默认打开第一页
    ui->tabWidget->setCurrentIndex(0);
    //设置身高
    ui->heightHorizontalSlider->setMaximum(MYGAME::Height::heightCount-1);
    ui->heightHorizontalSlider->setSliderPosition(MYGAME::Height::heightCount/2);
    ui->heightTipsLable->setText("普通");
    //设置胖瘦
    ui->weightHorizontalSlider->setMaximum(MYGAME::Weight::weightCount-1);
    ui->weightHorizontalSlider->setSliderPosition(MYGAME::Weight::weightCount/2);
    ui->heightTipsLable->setText("普通");
    //设置penis
    ui->dickSizeHorizontalSlider->setMaximum(MYGAME::DickSize::sizeCount-1);
    ui->dickSizeHorizontalSlider->setSliderPosition(0);
    ui->dickSizeHorizontalSlider->setRange(6,30);
    ui->dickSizeTipsLable->setText("可爱的");
    //设置颜色
    ui->hairColorSelect->setColor(0,0,0,0);
    ui->REyeColorsSelect->setColor(0,0,0,0);
    ui->LEyeColorsSelect->setColor(0,0,0,0);
    ui->skinColorSelect->setColor(0xf0,0xd5,0x8c,0xff);
    //
    connect(ui->LEyeColorsSelect,&ColorSelection::clicked,this,[=](){
        if(ui->EyeColorsEqual->isChecked()){
            ui->REyeColorsSelect->setColor(ui->LEyeColorsSelect->getColor());
        }
    });
    connect(ui->REyeColorsSelect,&ColorSelection::clicked,this,[=](){
        if(ui->EyeColorsEqual->isChecked()){
            ui->LEyeColorsSelect->setColor(ui->REyeColorsSelect->getColor());
        }
    });
}

void CreateLead::initPlayer()
{
    this->player=new MYGAME::Player;
    this->penis=new MYGAME::Penis;
}

void CreateLead::attributeChanged(QSpinBox *input)
{
    int difference=input->value()-maps.value(input)->getRank();
    if(difference>0){
        if(difference>this->point){
            difference=this->point;
            input->setValue(maps.value(input)->getRank()+difference);
        }
    }
    this->point-=difference;
    maps.value(input)->setRank(input->value());
    ui->PointsRemaining->setText("剩余点数:"+QString::number(this->point));
    foreach (QSpinBox*temp, maps.keys()) {
        temp->setMaximum(maps.value(temp)->getRank()+this->point);
    }
}

void CreateLead::on_WillpowerInput_valueChanged(int)
{
    attributeChanged(ui->WillpowerInput);
}


void CreateLead::on_QuickInput_valueChanged(int)
{
    attributeChanged(ui->QuickInput);
}


void CreateLead::on_PhysiqueInput_valueChanged(int)
{
    attributeChanged(ui->PhysiqueInput);
}


void CreateLead::on_CharmInput_valueChanged(int)
{
    attributeChanged(ui->CharmInput);
}


void CreateLead::on_IntelligenceInput_valueChanged(int)
{
    attributeChanged(ui->IntelligenceInput);
}


void CreateLead::on_heightHorizontalSlider_valueChanged(int value)
{
    switch(value){
    case 0:
        ui->heightTipsLable->setText("幼小");
        this->player->setHeight(MYGAME::young);
        break;
    case 1:
        ui->heightTipsLable->setText("娇小");
        this->player->setHeight(MYGAME::Petite);
        break;
    case 2:
        ui->heightTipsLable->setText("普通");
        this->player->setHeight(MYGAME::ordinary);
        break;
    case 3:
        ui->heightTipsLable->setText("高大");
        this->player->setHeight(MYGAME::tall);
        break;
    case 4:
        ui->heightTipsLable->setText("巨大");
        this->player->setHeight(MYGAME::huge);
        break;
    }
}


void CreateLead::on_weightHorizontalSlider_valueChanged(int value)
{
    switch(value){
    case 0:
        ui->weightTipsLable->setText("瘦削");
        this->player->setWeight(MYGAME::emaciation);
        break;
    case 1:
        ui->weightTipsLable->setText("纤细");
        this->player->setWeight(MYGAME::slender);
        break;
    case 2:
        ui->weightTipsLable->setText("普通");
        this->player->setWeight(MYGAME::common);
        break;
    case 3:
        ui->weightTipsLable->setText("丰满");
        this->player->setWeight(MYGAME::plump);
        break;
    case 4:
        ui->weightTipsLable->setText("肥胖");
        this->player->setWeight(MYGAME::obesity);
        break;
    }
}


void CreateLead::on_dickSizeHorizontalSlider_valueChanged(int value)
{
    ui->diameterLable->setText("直径:"+QString::number(value)+"mm");
    ui->lengthLable->setText("长度:"+QString::number(value*5)+"mm");
    this->penis->setDiameter(value);
    if(value<11){
        ui->dickSizeTipsLable->setText("可爱的");
    }else if(value<21){
        ui->dickSizeTipsLable->setText("短小的");
    }else if(value<31){
        ui->dickSizeTipsLable->setText("普通的");
    }else if(value<41){
        ui->dickSizeTipsLable->setText("巨根");
    }else if(value<61){
        ui->dickSizeTipsLable->setText("规格外");
    }else if(value<81){
        ui->dickSizeTipsLable->setText("非人类");
    }else{
        ui->dickSizeTipsLable->setText("怪兽");
    }
}

void CreateLead::on_EyeColorsEqual_stateChanged(int)
{
    ui->LEyeColorsSelect->setColor(ui->REyeColorsSelect->getColor());
}


void CreateLead::on_complete_clicked()
{
    //进行输入检查
    if(ui->nameInput->text()==""){
        QMessageBox::critical(this,"错误","请输入姓名");
        return;
    }
    if(ui->nickNameInput->text()==""){
        QMessageBox::critical(this,"错误","请输入昵称");
        return;
    }
    if(ui->CharmInput->text()==""){
        QMessageBox::critical(this,"错误","请输入自称");
        return;
    }
    QString str="3000";
    if(ui->monthInput->text().toLongLong()<10){
        str+="0";
    }
    str+=ui->monthInput->text();
    if(ui->dayInput->text().toLongLong()<10){
        str+="0";
    }
    str+=ui->dayInput->text();
    QDate date=QDate::fromString(str,"yyyyMMdd");
    if(!date.isValid()){
        QMessageBox::critical(this,"错误","日期输入有误");
        return;
    }
    //存入对象
    //设置名称
    this->player->setName(ui->nameInput->text());
    //设置昵称
    this->player->setNickName(ui->nickNameInput->text());
    //设置自称
    this->player->setClaimed(ui->claimedInput->text());
    //设置生日
    this->player->setBirthday(date);
    //设置专业
    this->player->setMajor(ui->selectMajor->currentText());
    //设置职业
    this->player->setOccupation(ui->selectOccupation->currentText());
    //设置五项基本属性
    std::vector<MYGAME::Attribute*>*attributeList=new std::vector<MYGAME::Attribute*>();
    foreach (QSpinBox*temp, maps.keys()) {
        if(maps.value(temp)->getName()=="体质"||maps.value(temp)->getName()=="意志"){
            dynamic_cast<MYGAME::AttributeAdd*>(maps.value(temp))->setNowValue(maps.value(temp)->getRank());
        }
        attributeList->push_back(maps.value(temp));
    }
    this->player->setAttributeList(*attributeList);
    //设置发色
    this->player->setHairColor(ui->hairColorSelect->getColor());
    //设置肤色
    this->player->setSkinColor(ui->skinColorSelect->getColor());
    //设置右眼颜色
    this->player->setRPupilColor(ui->REyeColorsSelect->getColor());
    //设置左眼颜色
    this->player->setLPupilColor(ui->LEyeColorsSelect->getColor());
    //设置标签
    this->player->setTagList(std::vector<QString>());
    //设置技能
    std::vector<MYGAME::Skill*>*skillList=new std::vector<MYGAME::Skill*>();
    skillList->push_back(new MYGAME::Skill("计算机",1,0));
    this->player->setSkillList(*skillList);
    //设置部位表列
    std::vector<MYGAME::PositionBase*>*positionList=new std::vector<MYGAME::PositionBase*>();
    positionList->push_back(this->penis);
    this->player->setPositionList(*positionList);
    //设置初始金钱
    this->player->setMoney(3000);
    //触发信号
    emit this->NewGame(this->player);
    //关闭窗口
    this->close();
}

