#include "MapList.h"
#include "Windows/MapListItem.h"
#include "ui_MapList.h"

#include <QMessageBox>
MapList::MapList(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::MapList)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
}

MapList::MapList(QDateTime *time, MYGAME::Player*play, QTextBrowser*text,const std::unordered_map<QString,MYGAME::Node*>*mapList,QDialog *parent)
    :MapList(parent)
{
    this->time=time;
    this->play=play;
    this->text=text;
    this->mapList=mapList;
    this->money=0;
    this->timeAdd=0;
    this->pathList.clear();
    this->n=mapList->at(this->play->getCurrentPosition());
    this->Refresh(this->n);
}

MapList::~MapList()
{
    delete ui;
}

void MapList::Refresh(const MYGAME::Node*n)
{
    ui->mapList->clear();
    this->setWindowTitle("当前所在地点:"+n->getName());
    for(size_t i=0;i<n->getPathList()->size()+2;i++){
        if(i==n->getPathList()->size()){
            QListWidgetItem*qlwi=new QListWidgetItem();
            MapListItem*mli=new MapListItem("返回上一地点",0,0);
            qlwi->setSizeHint(mli->size());
            ui->mapList->addItem(qlwi);
            ui->mapList->setItemWidget(qlwi,mli);
        }else if(i==n->getPathList()->size()+1){
            QListWidgetItem*qlwi=new QListWidgetItem();
            MapListItem*mli=new MapListItem("确定移动",this->money,this->timeAdd);
            qlwi->setSizeHint(mli->size());
            ui->mapList->addItem(qlwi);
            ui->mapList->setItemWidget(qlwi,mli);
        }else{
            QListWidgetItem*qlwi=new QListWidgetItem();
            MapListItem*mli=new MapListItem(this->mapList->at((*n->getPathList())[i]->getDest())->getName(),(*n->getPathList())[i]->getMoneyCost(),(*n->getPathList())[i]->getTimeCost());
            qlwi->setSizeHint(mli->size());
            ui->mapList->addItem(qlwi);
            ui->mapList->setItemWidget(qlwi,mli);
        }
    }
}

void MapList::on_mapList_itemDoubleClicked(QListWidgetItem *item)
{
    if(this->n->getPathList()->size()==(size_t)ui->mapList->row(item)){
        if(this->pathList.empty()){
            return;
        }else{
            this->n=this->mapList->at(this->pathList.back()->getSource());
            this->money-=this->pathList.back()->getMoneyCost();
            this->timeAdd-=this->pathList.back()->getTimeCost();
            this->pathList.pop_back();
            this->Refresh(n);
        }
    }else if(this->n->getPathList()->size()+1==(size_t)ui->mapList->row(item)){
        if(this->money<=this->play->getMoney()){
            this->play->setMoney(this->play->getMoney()-this->money);
            (*this->time)=this->time->addSecs(60*this->timeAdd);
            this->play->setCurrentPosition(this->n->getId());
            this->close();
        }else{
            QMessageBox::critical(this,"错误","所持金钱不足无法移动!!!",QMessageBox::Ok);
            return;
        }
    }else{
        this->pathList.push_back(this->n->getPathList()->at(ui->mapList->row(item)));
        this->n=this->mapList->at(this->pathList.back()->getDest());
        this->money+=this->pathList.back()->getMoneyCost();
        this->timeAdd+=this->pathList.back()->getTimeCost();
        this->Refresh(this->n);
        return;
    }
}
