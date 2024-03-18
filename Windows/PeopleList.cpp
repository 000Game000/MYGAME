#include "PeopleList.h"
#include "ui_PeopleList.h"
#include "PeopleListItem.h"
#include "Windows/CharacterDetails.h"
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

PeopleList::PeopleList(std::vector<MYGAME::People *> *peopleList,const QDateTime* const time,QWidget *parent) : PeopleList(parent)
{
    this->peopleList=peopleList;
    for(size_t i=0;i<this->peopleList->size();i++){
        QListWidgetItem*qlwi=new QListWidgetItem();
        PeopleListItem*P=new PeopleListItem(dynamic_cast<MYGAME::Girl*>((*this->peopleList)[i]),time,this);
        qlwi->setSizeHint(P->size());
        ui->listWidget->addItem(qlwi);
        ui->listWidget->setItemWidget(qlwi,P);
    }
}


void PeopleList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    CharacterDetails*windows=new CharacterDetails(dynamic_cast<MYGAME::Girl*>((*this->peopleList)[ui->listWidget->row(item)]));
    windows->show();
}

