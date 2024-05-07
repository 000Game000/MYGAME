#include "MapList.h"
#include "MapListItem.h"
#include "ui_MapList.h"
MapList::MapList(QDialog *parent)
    : QDialog(parent)
    , ui(new Ui::MapList)
{
    ui->setupUi(this);
    this->setWindowModality(Qt::ApplicationModal);
    this->setAttribute(Qt::WA_DeleteOnClose, true);
}

MapList::MapList(QDateTime *time, MYGAME::Player*play, QString Type,QTextBrowser*text,QDialog *parent)
    :MapList(parent)
{
    this->time=time;
    this->play=play;
    this->type=Type;
    this->text=text;
    if(this->type.compare("移动")==0){
        this->mapList=this->play->getCurrentPosition()->getSuperiorMap()->getList();
    }else if(this->type.compare("楼层移动")==0){
        this->mapList=this->play->getCurrentPosition()->getSuperiorMap()->getSuperiorMap()->getList();
    }
    for(size_t i=0;i<this->mapList->size();i++){
        QListWidgetItem*qlwi=new QListWidgetItem();
        MapListItem*ibw=new MapListItem((*this->mapList)[i]->getName());
        qlwi->setSizeHint(ibw->size());
        ui->mapList->addItem(qlwi);
        ui->mapList->setItemWidget(qlwi,ibw);
    }
}

MapList::~MapList()
{
    delete ui;
}

void MapList::on_mapList_itemDoubleClicked(QListWidgetItem *item)
{
    int i=0;
    QString currentName;
    if(this->type.compare("移动")==0){
        currentName=this->play->getCurrentPosition()->getName();
    }else if(this->type.compare("楼层移动")==0){
        currentName=this->play->getCurrentPosition()->getSuperiorMap()->getName();
    }
    for(i=0;i<(int)this->mapList->size();i++){
         if(currentName.compare((*this->mapList)[i]->getName())==0){
            break;
        }
    }
    int distance=std::abs(i-ui->mapList->row(item));
    if(distance)
    {
        this->play->setCurrentPosition((*this->mapList)[ui->mapList->row(item)]);
        if(this->type.compare("楼层移动")==0){
            qDebug()<<play->getCurrentPosition()->getName();
            this->play->setCurrentPosition((*this->play->getCurrentPosition()->getList())[0]);
        }
        if(this->play->getCurrentPosition()->getType().compare("地点分区")==0){
            (*this->time)=this->time->addSecs(60*distance);
        }
        this->text->append("移动到:"+play->getCurrentPosition()->getName());

    }
    this->close();
}

