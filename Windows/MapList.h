#ifndef MAPLIST_H
#define MAPLIST_H

#include "Map/Node.h"
#include <QDialog>
#include <QListWidgetItem>
#include <QTextBrowser>
#include <Person/Player.h>

namespace Ui {
class MapList;
}

class MapList : public QDialog
{
    Q_OBJECT

public:
    explicit MapList(QDialog *parent = nullptr);
    MapList(QDateTime*time,MYGAME::Player*play,QTextBrowser*text,const std::unordered_map<QString,MYGAME::Node*>*mapList,QDialog *parent = nullptr);
    ~MapList();
    void Refresh(const MYGAME::Node*n);

private slots:
    void on_mapList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MapList *ui;
    QDateTime*time;
    unsigned long long money;
    unsigned long long timeAdd;
    QTextBrowser*text;
    MYGAME::Player*play;
    const MYGAME::Node*n;
    std::vector<MYGAME::Path*> pathList;
    const std::unordered_map<QString,MYGAME::Node*>*mapList;
};

#endif // MAPLIST_H
