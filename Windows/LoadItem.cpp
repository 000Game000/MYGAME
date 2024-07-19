#include "LoadItem.h"
#include "ui_LoadItem.h"
#include "Modules/Global.h"

#include <QFile>
#include <QJsonObject>
#include <QMessageBox>
#include <QJsonParseError>

LoadItem::LoadItem(QString dir,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoadItem)
{
    this->dir=dir;
    ui->setupUi(this);
    QFile file(dir);
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);
    QString str=stream.readAll();
    QJsonParseError jsonError;
    QJsonDocument doc=QJsonDocument::fromJson(str.toUtf8(),&jsonError);
    if(jsonError.error!=QJsonParseError::NoError){
        QMessageBox::critical(this,"严重错误","存档解析失败,请不要在存档文件夹放非存档文件!!!",QMessageBox::Ok);
    }
    QStringList sList = this->dir.split("/");
    ui->name->setText("文件名称:"+sList[sList.size()-1]);
    QJsonObject rootObj=doc.object();
    ui->time->setText("保存时间:"+rootObj.value("Time").toString());
    QString version=rootObj.value("Version").toString();
    if(MYGAME::Version.compare(version)!=0){
        ui->versionNumber->setText("游戏版本:"+ QObject::tr("<font color = red>%1</font>").arg(version));
    }else{
        ui->versionNumber->setText("游戏版本:"+ QObject::tr("<font color = blue>%1</font>").arg(version));
    }
    file.close();
}

LoadItem::~LoadItem()
{
    delete ui;
}
