#include "SystemStore.h"
#include "ui_SystemStore.h"
#include "ItemBaseWidget.h"
#include <QMessageBox>
SystemStore::SystemStore(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SystemStore)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
}

SystemStore::SystemStore(MYGAME::Player *p, MYGAME::System_*_system, QWidget *parent):SystemStore(parent)
{
    this->player=p;
    ui->point->setText(tr("系统点数:")+QString::number(this->player->getPoint()));
    itemList=&_system->getItemList();
    for(size_t i=0;i<itemList->size();i++){
        QListWidgetItem*qlwi=new QListWidgetItem();
        ItemBaseWidget*ibw=new ItemBaseWidget((*this->itemList)[i]);
        qlwi->setSizeHint(ibw->size());
        ui->stoneList->addItem(qlwi);
        ui->stoneList->setItemWidget(qlwi,ibw);
    }
}

SystemStore::~SystemStore()
{
    delete ui;
}

void SystemStore::on_stoneList_itemClicked(QListWidgetItem *item)
{
    this->flag=false;
    this->selectItem=item;
    ui->itemName->setText((*this->itemList)[ui->stoneList->row(item)]->getName());
    ui->describe->setText((*this->itemList)[ui->stoneList->row(item)]->getDescribe());
    ui->itemFunction->setText((*this->itemList)[ui->stoneList->row(item)]->getItemFunction());
    ui->itemType->setText((*this->itemList)[ui->stoneList->row(item)]->getItemType());
    this->item=(*this->itemList)[ui->stoneList->row(item)];
    ui->count->setMinimum(0);
    ui->count->setValue(1);
    for(size_t i=0;i<player->getItemList()->size();i++){
        if((*player->getItemList())[i]->getName()==(*this->itemList)[ui->stoneList->row(item)]->getName()){
            this->flag=true;
            this->item=(*player->getItemList())[i];
            ui->count->setMinimum((*player->getItemList())[i]->getCount());
            ui->count->setValue(ui->count->minimum()+1);
            break;
        }
    }
    ui->money->setText("所花点数:"+QString::number((*this->itemList)[ui->stoneList->row(item)]->getMoney()*(ui->count->value()-ui->count->minimum())));
}


void SystemStore::on_count_valueChanged(int)
{
    ui->money->setText("所花点数:"+QString::number(item->getMoney()*(ui->count->value())-ui->count->minimum()));
}


void SystemStore::on_buy_clicked()
{
    if(player->getPoint()>=(item->getMoney()*(ui->count->value())-ui->count->minimum())){
        if(ui->count->value()!=0){
            item->setCount(ui->count->value());
            if(!this->flag){
                player->getVariableItemList()->push_back(item);
            }
            this->player->setPoint(player->getPoint()-item->getMoney()*(ui->count->value()-ui->count->minimum()));
        }
        ui->point->setText(tr("系统点数:")+QString::number(this->player->getPoint()));
    }
    else{
        QMessageBox::critical(this,tr("错误"),tr("系统点数不足无法购买!!!"));
    }
    this->on_stoneList_itemClicked(selectItem);
}
