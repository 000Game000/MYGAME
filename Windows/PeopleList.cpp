#include "PeopleList.h"
#include "ui_PeopleList.h"

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

PeopleList::PeopleList(MYGAME::Player *player, std::vector<MYGAME::People *> *peopleList,QWidget *parent) : PeopleList(parent)
{
    this->player=player;
    this->peopleList=peopleList;
}
