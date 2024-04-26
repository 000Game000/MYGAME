#include "LoadItem.h"
#include "ui_LoadItem.h"

#include <QFile>

LoadItem::LoadItem(QString dir,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadItem)
{
    this->dir=dir;
    ui->setupUi(this);
    QFile file(dir);
    file.open(QIODevice::ReadOnly);
    QStringList sList = this->dir.split("/");
    ui->name->setText("文件名称:"+sList[sList.size()-1]);
    QTextStream in(&file);
    QString line=in.readLine();
    ui->time->setText("保存时间:"+line.split(":")[1]);
    line=in.readLine();
    ui->versionNumber->setText("游戏版本:"+line.split(":")[1]);
}

LoadItem::~LoadItem()
{
    delete ui;
}
