#include "PeopleList.h"
#include "ui_PeopleList.h"
#include "PeopleListItem.h"
PeopleList::PeopleList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PeopleList)
{
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
}

PeopleList::~PeopleList()
{
    delete ui;
}

PeopleList::PeopleList(std::vector<MYGAME::People *> *peopleList,QWidget *parent) : PeopleList(parent)
{
    this->peopleList=peopleList;
    PeopleListItem*P=new PeopleListItem(dynamic_cast<MYGAME::Girl*>((*this->peopleList)[0]));
    QListWidgetItem*qlwi=new QListWidgetItem();
    qlwi->setSizeHint(P->size());
    ui->listWidget->addItem(qlwi);
    ui->listWidget->setItemWidget(qlwi,P);
}
