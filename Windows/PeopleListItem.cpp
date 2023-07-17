#include "PeopleListItem.h"
#include "ui_PeopleListItem.h"

PeopleListItem::PeopleListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PeopleListItem)
{
    ui->setupUi(this);
}

PeopleListItem::~PeopleListItem()
{
    delete ui;
}
