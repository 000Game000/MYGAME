#include "ItemList.h"
#include "ui_ItemList.h"
#include "ItemBaseWidget.h"
ItemList::ItemList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemList)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
}

ItemList::ItemList(MYGAME::Player *player, QWidget *parent):ItemList(parent)
{
    this->player=player;
    itemList=player->getItemList();
    for(size_t i=0;i<itemList->size();i++){
        QListWidgetItem*qlwi=new QListWidgetItem();
        ItemBaseWidget*ibw=new ItemBaseWidget((*this->itemList)[i]);
        qlwi->setSizeHint(ibw->size());
        ui->itemList->addItem(qlwi);
        ui->itemList->setItemWidget(qlwi,ibw);
    }
}

ItemList::~ItemList()
{
    delete ui;
}

void ItemList::on_itemList_itemClicked(QListWidgetItem *item)
{
    ui->itemName->setText((*this->itemList)[ui->itemList->row(item)]->getName());
    ui->describe->setText((*this->itemList)[ui->itemList->row(item)]->getDescribe());
    ui->itemFunction->setText((*this->itemList)[ui->itemList->row(item)]->getItemFunction());
    ui->itemType->setText("物品类别:"+(*this->itemList)[ui->itemList->row(item)]->getItemType());
    ui->count->setText("所持数量:"+QString::number((*this->itemList)[ui->itemList->row(item)]->getCount()));
}

