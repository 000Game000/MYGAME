#include "CreateLead.h"
#include "ui_CreateLead.h"
#include "Modules/Global.h"
CreateLead::CreateLead(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreateLead)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose, true);
    init();
}

CreateLead::~CreateLead()
{
    delete ui;
}

void CreateLead::init()
{
    ui->nameInput->setText("主角");
    ui->nickNameInput->setText("主角");
    ui->claimedInput->setText("我");
    ui->selectOccupation->addItems(global->getCareerList());
    ui->selectMajor->addItems(global->getMajorList());
    boxs.Charm=ui->CharmInput;
}
