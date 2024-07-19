#include "MapListItem.h"
#include "ui_MapListItem.h"

MapListItem::MapListItem(QString name,long long money,long long time, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MapListItem)
{
    ui->setupUi(this);
    ui->name->setText(name);
    ui->money->setText("消耗金钱:"+QString::number(money));
    ui->time->setText("消耗时间:"+QString::number(time)+"分");
}

MapListItem::~MapListItem()
{
    delete ui;
}
