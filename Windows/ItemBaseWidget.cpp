#include "ItemBaseWidget.h"
#include "ui_ItemBaseWidget.h"

ItemBaseWidget::ItemBaseWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ItemBaseWidget)
{
    ui->setupUi(this);
}

ItemBaseWidget::ItemBaseWidget(MYGAME::ItemBase *item, QWidget *parent):ItemBaseWidget(parent)
{
    this->item=item;
    ui->name->setText(this->item->getName());
    ui->describe->setText(this->item->getDescribe());
    ui->money->setText("价格:"+QString::number(this->item->getMoney()));
}

ItemBaseWidget::~ItemBaseWidget()
{
    delete ui;
}

MYGAME::ItemBase *ItemBaseWidget::getItem() const
{
    return item;
}

void ItemBaseWidget::setItem(MYGAME::ItemBase *newItem)
{
    item = newItem;
}
