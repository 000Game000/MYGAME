#ifndef MAPLIST_H
#define MAPLIST_H

#include "Map/Map.h"
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
    MapList(QDateTime*time,MYGAME::Player*play,QString Type,QTextBrowser*text,QDialog *parent = nullptr);
    ~MapList();

private slots:
    void on_mapList_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::MapList *ui;
    QString type;
    QDateTime*time;
    QTextBrowser*text;
    MYGAME::Player*play;
    std::vector<MYGAME::Map*>*mapList;
};

#endif // MAPLIST_H
