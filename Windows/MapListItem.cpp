#include "MapListItem.h"
#include "ui_MapListItem.h"

MapListItem::MapListItem(QString name, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MapListItem)
{
    ui->setupUi(this);
    ui->name->setText(name);
}

MapListItem::~MapListItem()
{
    delete ui;
}
