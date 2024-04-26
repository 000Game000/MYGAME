#include "Load.h"
#include "LoadItem.h"
#include "ui_Load.h"

#include <QDir>
#include <QMessageBox>

Load::Load(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Load)
{
    setAttribute(Qt::WA_DeleteOnClose, true);
    this->setWindowModality(Qt::ApplicationModal);
    ui->setupUi(this);
    this->getDirs();
}

Load::~Load()
{
    delete ui;
}

void Load::getDirs()
{
    QString sdir=QDir::currentPath()+"/save";
    QDir dir(sdir);
    dir.setFilter(QDir::Files|QDir::Hidden|QDir::NoSymLinks);
    dir.setSorting(QDir::Name|QDir::Reversed);
    this->fileList=dir.entryInfoList();
    for(int i=0;i<fileList.size();i++){
        QFileInfo info=fileList.at(i);
        if(info.suffix().compare("save")){
            continue;
        }
        if(info.size()==0){
            continue;
        }
        QListWidgetItem*qlwi=new QListWidgetItem();
        LoadItem*LI=new LoadItem(info.filePath());
        qlwi->setSizeHint(LI->size());
        ui->listWidget->addItem(qlwi);
        ui->listWidget->setItemWidget(qlwi,LI);
    }
}

void Load::on_listWidget_itemClicked(QListWidgetItem *item)
{
    QMessageBox::StandardButton b;
    b=QMessageBox::question(this,"提示!!!","你是否选择读取这个文件?",QMessageBox::Yes|QMessageBox::No);
    if(b==QMessageBox::Yes){
        emit this->sdir(this->fileList.at(ui->listWidget->row(item)).filePath());
        this->close();
    }
}

